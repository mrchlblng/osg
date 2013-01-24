//
//  Copyright (c) 2006 by Autodesk, Inc.
//
//  By using this code, you are agreeing to the terms and conditions of
//  the License Agreement included in the documentation for this code.
//
//  AUTODESK MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
//  OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT. AUTODESK
//  PROVIDES THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
//  LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
//  OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//  Use, duplication, or disclosure by the U.S. Government is subject to
//  restrictions set forth in FAR 52.227-19 (Commercial Computer Software
//  Restricted Rights) and DFAR 252.227-7013(c)(1)(ii) (Rights in Technical
//  Data and Computer Software), as applicable.
//
//  $Header: //DWF/Development/Components/Internal/DWF Toolkit/v7.7/develop/global/src/dwf/dwfx/ContentPart.cpp#1 $
//  $DateTime: 2011/02/14 01:16:30 $
//  $Author: caos $
//  $Change: 197964 $
//  $Revision: #1 $
//
//

#include "dwf/dwfx/ContentPart.h"
#include "dwf/package/Content.h"

using namespace DWFToolkit;


_DWFTK_API
DWFXContentPart::DWFXContentPart( DWFContent* pContent )
throw()
               : _pContent( pContent )
{
    setName( _pContent->href() );
}

_DWFTK_API
DWFXContentPart::~DWFXContentPart()
throw()
{
    // As an ownable class, we need to notify observers that we are about to be deleted
    _notifyDelete();
}

#ifndef DWFTK_READ_ONLY

_DWFTK_API
void DWFXContentPart::serializeXML( DWFXMLSerializer& rSerializer )
throw( DWFException )
{
    if (_pContent == NULL)
    {
        _DWFCORE_THROW( DWFNullPointerException, /*NOXLATE*/L"The content pointer cannot be null in a content part." );
    }

    _pContent->serializeXML( rSerializer, DWFPackageWriter::eGlobalContent );
}

#endif
