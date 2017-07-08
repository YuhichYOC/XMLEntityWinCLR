/*
*
* SAXWrapper.h
*
* Copyright 2016 Yuichi Yoshii
*     吉井雄一 @ 吉井産業  you.65535.kir@gmail.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#pragma once

#ifdef XMLENTITYWINCLR_EXPORTS
#define XMLENTITYWINCLR_API __declspec(dllexport)
#else
#define XMLENTITYWINCLR_API __declspec(dllimport)
#endif

#include "stdafx.h"

#include "NodeEntity.h"

#include "WCharString.h"

class SAXWrapper
{
private:

    string directory;

    string fileName;

    unique_ptr<NodeEntity> myNode;

    int depth;

    int nodeId;

    IStream * stream;

    IXmlReader * reader;

    bool prepared;

    bool parseSucceeded;

    string errorMessage;

    void ParseElement(IXmlReader * reader, XmlNodeType nodeType);

    NodeEntity * ParseAttributes(IXmlReader * reader, NodeEntity * node);

    void ParseText(IXmlReader * reader, XmlNodeType nodeType);

    void ParseCDATA(IXmlReader * reader, XmlNodeType nodeType);

    void ParseEndElement(IXmlReader * reader, XmlNodeType nodeType);

    bool disposed;

public:

    XMLENTITYWINCLR_API void SetDirectory(string arg);

    XMLENTITYWINCLR_API string GetDirectory();

    XMLENTITYWINCLR_API void SetFileName(string arg);

    XMLENTITYWINCLR_API string GetFileName();

    XMLENTITYWINCLR_API NodeEntity * GetNode();

    XMLENTITYWINCLR_API void Prepare();

    XMLENTITYWINCLR_API bool IsPrepared();

    XMLENTITYWINCLR_API void Parse();

    XMLENTITYWINCLR_API bool IsParseSucceeded();

    XMLENTITYWINCLR_API string GetErrorMessage();

    XMLENTITYWINCLR_API SAXWrapper();

    XMLENTITYWINCLR_API void Dispose();

    XMLENTITYWINCLR_API ~SAXWrapper();
};
