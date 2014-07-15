#ifndef CARRAY_H
#define CARRAY_H

// STL
#include <vector>
#include <deque>
#include <fstream>
#include <set>
// OSG
#include <osg/Array>
#include <osg/BoundingBox>

class CArray
{
  public:
    enum Mode {
      quantization = 1 << 0,
      prediction   = 1 << 1
    };
};

template<typename C>
class CBaseArray : public CArray
{
  typedef typename C::ElementDataType T;

  public:

    CBaseArray(T const &, T const&, int, int);
    ~CBaseArray();

    // default (de)compression method using an optional vector of strips for prediction
    void compress(C const*,
                  std::vector< std::vector<size_t> >const& strips = std::vector< std::vector<size_t> >());
    void decompress(C const*,
                    std::vector< std::vector<size_t> >const& strips = std::vector< std::vector<size_t> >());

    osg::Array* getData() const
    { return _data.get(); }

    osg::BoundingBox getBoundingBox() const
    { return makeBoundingBox(_bbl, _ufr); }

  protected:
    bool useQuantization() const
    { return static_cast<bool>(_mode & quantization); }

    bool usePrediction() const
    { return static_cast<bool>(_mode & prediction); }

    void predictParallelogram(C*, C const*, std::vector< std::vector<size_t> > const&);
    void unpredictParallelogram(C*, C const*, std::vector< std::vector<size_t> > const&);

    template<typename U>
    inline U parallelogramPrediction(std::deque<U> const& window) const
    {
      return window[0] + window[2] - window[1];
    }

    template<typename U>
    U quantizationPrecision(U const& bbl, U const& ufr)
    {
      //TODO: quantization should **NOT** require any sign bit. This was due to
      //bad definition of the bounding box and should be removed when the proper
      //bounding box is used
      int bits = (_bytes << 3) - 1; // need 1 bit for sign during prediction step
      float precision = (1. / ((1 << bits) - 1));
      return (ufr - bbl) * precision;
    }

    template<typename K>
    void quantizeArray(K* result,
                       K const* buffer,
                       typename K::ElementDataType const& bbl,
                       typename K::ElementDataType const& ufr,
                       std::vector< std::vector<size_t> > const& strips=std::vector< std::vector<size_t> >())
    {
      typename K::ElementDataType h = quantizationPrecision<typename K::ElementDataType>(bbl, ufr);

      if(usePrediction() && !strips.empty())
      {
        std::set<size_t> strips_vertices;
        for(std::vector< std::vector<size_t> >::const_iterator it_strip = strips.begin() ;
            it_strip != strips.end() ; ++ it_strip)
        {
          for(std::vector<size_t>::const_iterator it_vtx = it_strip->begin() ;
              it_vtx != it_strip->begin() + 3 ; ++ it_vtx)
            strips_vertices.insert(*it_vtx);
        }

        // only quantize strips that do *not* start a strip
        size_t ii = 0;
        for(typename K::const_iterator it = buffer->begin() ;
            it != buffer->end() ;
            ++ it, ++ ii)
        {
          if(strips_vertices.find(ii) == strips_vertices.end())
            result->push_back(quantize(*it, h, bbl));
          else
            result->push_back(*it);
        }
      }
      else
      {
        for(typename K::const_iterator it = buffer->begin() ; it != buffer->end() ; ++ it)
          result->push_back(quantize(*it, h, bbl));
      }
    }

    template<typename K>
    void unquantizeArray(K* result,
                         K const* buffer,
                         typename K::ElementDataType const& bbl,
                         typename K::ElementDataType const& ufr,
                         std::vector< std::vector<size_t> > const& strips=std::vector< std::vector<size_t> >())
    {
      typename K::ElementDataType h = quantizationPrecision<typename K::ElementDataType>(bbl, ufr);

      if(usePrediction() && !strips.empty())
      {
        size_t ii = 0;
        std::set<size_t> strips_vertices;
        for(std::vector< std::vector<size_t> >::const_iterator it_strip = strips.begin() ;
            it_strip != strips.end() ; ++ it_strip)
        {
          for(std::vector<size_t>::const_iterator it_vtx = it_strip->begin() ;
              it_vtx != it_strip->begin() + 3 ; ++ it_vtx)
            strips_vertices.insert(*it_vtx);
        }

        // only quantize strips that do *not* start a strip
        for(typename K::const_iterator it = buffer->begin() ;
            it != buffer->end() ;
            ++ it, ++ ii)
        {
          if(strips_vertices.find(ii) == strips_vertices.end())
            result->push_back(unquantize(*it, h, bbl));
          else
            result->push_back(*it);
        }

      }
      else
      {
        for(typename K::const_iterator it = buffer->begin() ; it != buffer->end() ; ++ it)
          result->push_back(unquantize(*it, h, bbl));
      }
    }

    osg::Vec2 quantize(osg::Vec2 const&, osg::Vec2 const&, osg::Vec2 const&) const;
    osg::Vec3 quantize(osg::Vec3 const&, osg::Vec3 const&, osg::Vec3 const&) const;

    osg::Vec2 unquantize(osg::Vec2 const&, osg::Vec2 const&, osg::Vec2 const&) const;
    osg::Vec3 unquantize(osg::Vec3 const&, osg::Vec3 const&, osg::Vec3 const&) const;

    //some vector utils
    osg::Vec3 vectorMin(osg::Vec3 const&, osg::Vec3 const&) const;
    osg::Vec2 vectorMin(osg::Vec2 const&, osg::Vec2 const&) const;
    osg::Vec3 vectorMax(osg::Vec3 const&, osg::Vec3 const&) const;
    osg::Vec2 vectorMax(osg::Vec2 const&, osg::Vec2 const&) const;
    void setMinVector(osg::Vec3&) const;
    void setMinVector(osg::Vec2&) const;
    void setMaxVector(osg::Vec3&) const;
    void setMaxVector(osg::Vec2&) const;

    osg::BoundingBox makeBoundingBox(osg::Vec3 const&, osg::Vec3 const&) const;
    osg::BoundingBox makeBoundingBox(osg::Vec2 const&, osg::Vec2 const&) const;

  protected:
    osg::ref_ptr<osg::Array> _data;
    T _bbl; // Bounding box corner 0
    T _ufr; // Bounding box corner 7
    int _mode;
    int _bytes; // quantization precision
};

#include "CArray.hxx"

class CVertexArray : public CBaseArray<osg::Vec3Array>
{
  public:
    CVertexArray(osg::Vec3 const& bbl, osg::Vec3 const& ufr, int bytes, int mode) :
      CBaseArray<osg::Vec3Array>(bbl, ufr, bytes, mode)
    {}
};

class CNormalArray : public CBaseArray<osg::Vec3Array>
{
  public:
    CNormalArray(osg::Vec3 const& bbl, osg::Vec3 const& ufr, int bytes, int mode) :
      CBaseArray<osg::Vec3Array>(bbl, ufr, bytes, mode)
    {}

    // note that normal compression may induce a space projection (if prediction is used)
    // hence we pass osg::Array and not specific osg::VecXArray pointers
    void compress(osg::Array const*);
    void decompress(osg::Array const*);

  private:
    void project(osg::Vec2Array* projections, osg::Vec3Array const* normals)
    { return projectAzimuth(projections, normals); }

    void unproject(osg::Vec3Array* normals, osg::Vec2Array const* projections)
    { return unprojectAzimuth(normals, projections); }

    void projectAzimuth(osg::Vec2Array* projections, osg::Vec3Array const* normals);
    void unprojectAzimuth(osg::Vec3Array* normals, osg::Vec2Array const* projections);
};

class CUVArray : public CBaseArray<osg::Vec2Array>
{
  public:
    CUVArray(osg::Vec2 const& bbl, osg::Vec2 const& ufr, int bytes, int mode) :
      CBaseArray<osg::Vec2Array>(bbl, ufr, bytes, mode)
    {}
};

#endif