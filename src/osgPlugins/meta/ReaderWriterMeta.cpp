/* -*-c++-*- OpenSceneGraph - Copyright (C) Cedric Pinson
 *
 * This application is open source and may be redistributed and/or modified
 * freely and without restriction, both in commercial and non commercial
 * applications, as long as this copyright notice is maintained.
 *
 * This application is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
*/

#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <utility> //pair

#include <osg/NodeVisitor>
#include <osg/Texture2D>
#include <osg/Image>
#include <osg/StateSet>
#include <osg/Geode>
#include <osg/ValueObject>
#include <osgDB/ReadFile>
#include <osgDB/ReaderWriter>
#include <osgDB/FileNameUtils>
#include <osgDB/FileUtils>
#include <osgDB/WriteFile>
#include <osgDB/Registry>

#include "picojson.h"

class MetaDataExtractor : public osg::NodeVisitor
{
public:
    typedef std::set<std::string> texture_set;
    typedef std::pair<std::string, picojson::value> json_object_pair;

    MetaDataExtractor(std::string modelDir, bool useRelativePath) :
            osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
            _modelDir(modelDir),
            _useRelativePath(useRelativePath),
            _orphanTextureId(0)
    {}

    void applyStateSet(osg::StateSet* ss)
    {
        if (ss) {
            if(_source.empty()) ss->getUserValue("source_tool", _source);

            int textureListSize = ss->getTextureAttributeList().size();
            for (int i = 0 ; i < textureListSize ; ++i) {
                osg::Texture2D* tex = dynamic_cast<osg::Texture2D*>(
                                                      ss->getTextureAttribute(i, osg::StateAttribute::TEXTURE));
                if (tex && tex->getImage()) {
                    osg::Image* image = tex->getImage();
                    std::string fileName = image->getFileName();
                    osg::notify(osg::NOTICE) << "* image: '" << fileName << "' "
                                             << "[width:" << image->s() << " x "
                                             << "height:" << image->t() << "]"
                                             << std::endl;
                    // ForceReadingImage should be passed as osgconv option
                    // so that we always have the original filename even for
                    // unreadable images (when converting osg2 models)
                    if(fileName.empty())
                      fileName = createTextureFileName();

                    if(osgDB::findDataFile(fileName).empty())
                    {
                      // need to dump image on disk
                      osgDB::writeImageFile(*image, fileName);
                      // alter stateset to reference external file
                      image->setWriteHint(osg::Image::EXTERNAL_FILE);
                    }

                    transcodeImage(fileName, image);

                    std::string imagePath = getImagePath(fileName);
                    image->setFileName(imagePath);
                    _textures.insert(imagePath);
                }
            }
        }
    }

    void transcodeImage(std::string& fileName, osg::Image const* image)
    {
        // transcode specific formats that are not usually readable
        // by image tools
        std::string extension = osgDB::getFileExtension(fileName);
        std::string const transcoded_extension = "dds";

        if(extension == std::string("vtf")) {
            fileName = fileName + "." + transcoded_extension;
            osgDB::writeImageFile(*image, fileName);
        }
    }

    std::string getImagePath(std::string const& name)
    {
        std::string absolutePath = osgDB::findDataFile(name);
        if(absolutePath.empty()) // if image is missing we still need a path
            absolutePath = osgDB::concatPaths(_modelDir, name);

        if(!_useRelativePath)
            return absolutePath;

        std::string relativePath = osgDB::getPathRelative(_modelDir,
                                                          absolutePath);
        // if textures are in a folder that is *not* a subfolder of
        // _modelDir, osg adds a / at the beginning ot the path
        // e.g.
        // folder
        //  L model / model.ext
        //  L images / textures.png
        //  gives /../images/textures.png instead of ../images/textures.png
        while(osgDB::findDataFile(relativePath).empty() &&
              relativePath[0] == '/')
            relativePath = relativePath.erase(0, 1);
        return relativePath;
    }

    std::string createTextureFileName()
    {
        std::ostringstream name;
        name << "skfb_texture_extract_" << _orphanTextureId << ".jpg";
        ++ _orphanTextureId;

        return osgDB::concatPaths(_modelDir, name.str());
    }

    void apply(osg::Geode& node)
    {
        osg::StateSet* ss = node.getStateSet();
        if (ss) {
            applyStateSet(ss);
        }
        for (unsigned int i = 0; i < node.getNumDrawables(); ++i) {
            osg::Drawable* drawable = node.getDrawable(i);
            if (drawable && drawable->getStateSet()) {
                applyStateSet(drawable->getStateSet());
            }
        }
        traverse(node);
    }

    void apply(osg::Node& node)
    {
        osg::StateSet* ss = node.getStateSet();
        if (ss)
            applyStateSet(ss);
        traverse(node);
    }

    std::string getMetaDataJson() const
    {
        picojson::object json;
        json.insert(json_object_pair("source", picojson::value(_source)));

        picojson::array texArray;
        for(texture_set::const_iterator tex = _textures.begin() ;
            tex != _textures.end() ; ++ tex)
            texArray.push_back(picojson::value(*tex));

        json.insert(json_object_pair("textures", picojson::value(texArray)));
        return picojson::value(json).serialize();
    }

    void dumpMeta(std::string const& output) const
    {
        std::ofstream metaFile(output.c_str());
        metaFile << getMetaDataJson() << std::endl;
    }


protected:
    std::string _modelDir;
    bool _useRelativePath;
    int _orphanTextureId;
    texture_set _textures;
    std::string _source;
};


class ReaderWriterMeta : public osgDB::ReaderWriter
{
public:
    struct OptionsStruct {
        bool useRelativePath;
        std::string output;

        OptionsStruct() {
            useRelativePath = false;
            output = "meta.json";
        }
    };

    ReaderWriterMeta()
    {
        supportsExtension("meta","Pseudo-loader to extract model metadata.");
        supportsOption("useRelativePath","All path are relative to the model");
        supportsOption("output","Path to where metadata json file should be written");
    }

    virtual const char* className() const { return "ReaderWriterMeta"; }


    virtual ReadResult readNode(const std::string& fileName, const osgDB::ReaderWriter::Options* options) const
    {
        std::string ext = osgDB::getLowerCaseFileExtension(fileName);
        if (!acceptsExtension(ext)) return ReadResult::FILE_NOT_HANDLED;

        // strip the pseudo-loader extension
        std::string subLocation = osgDB::getNameLessExtension( fileName );
        if ( subLocation.empty() )
            return ReadResult::FILE_NOT_HANDLED;

        OptionsStruct _options;
        _options = parseOptions(options);

        // recursively load the subfile.
        osg::ref_ptr<osg::Node> node = osgDB::readNodeFile( subLocation, options );
        if( !node.valid() )
        {
            // propagate the read failure upwards
            osg::notify(osg::WARN) << "Subfile \"" << subLocation << "\" could not be loaded" << std::endl;
            return ReadResult::FILE_NOT_HANDLED;
        }

        // look for physical file
        std::string path;
        std::string name(fileName);
        do
        {
            path = osgDB::findDataFile(name);
            name = osgDB::getNameLessExtension(name);
        }
        while(!osgDB::fileExists(path)); // path is an absolute path


        std::string modelDir = osgDB::getFilePath(path);
        MetaDataExtractor visitor(modelDir, _options.useRelativePath);
        node->accept(visitor);
        visitor.dumpMeta(_options.output);

        return node.release();
    }


    ReaderWriterMeta::OptionsStruct parseOptions(const osgDB::ReaderWriter::Options* options) const
    {
        OptionsStruct localOptions;

        if (options)
        {
            osg::notify(osg::NOTICE) << "options " << options->getOptionString() << std::endl;
            std::istringstream iss(options->getOptionString());
            std::string opt;
            while (iss >> opt)
            {
                // split opt into pre= and post=
                std::string pre_equals;
                std::string post_equals;

                size_t found = opt.find("=");
                if(found != std::string::npos)
                {
                    pre_equals = opt.substr(0,found);
                    post_equals = opt.substr(found+1);
                }
                else
                    pre_equals = opt;

                if (pre_equals == "useRelativePath")
                    localOptions.useRelativePath = true;
                else if (pre_equals == "output")
                    localOptions.output = post_equals;
            }
        }
        return localOptions;
    }
};


// Add ourself to the Registry to instantiate the reader/writer.
REGISTER_OSGPLUGIN(meta, ReaderWriterMeta)