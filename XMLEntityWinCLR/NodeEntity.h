/*
*
* NodeEntity.h
*
* Copyright 2016 Yuichi Yoshii
*     ‹gˆä—Yˆê @ ‹gˆäŽY‹Æ  you.65535.kir@gmail.com
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

#include "AttributeEntity.h"

class NodeEntity
{
private:

    string nodeName;

    int nodeId;

    string nodeValue;

    vector<AttributeEntity *> attrList;

    vector<NodeEntity *> children;

    NodeEntity * Find(NodeEntity * node, string tagName);

    NodeEntity * Find(NodeEntity * node, string tagName, string attrName, string attrValue);

    NodeEntity * Find(NodeEntity * node, string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value);

    NodeEntity * FindTail(NodeEntity * node, int depth);

    bool disposed;

public:

    XMLENTITYWINCLR_API void SetNodeName(string arg);

    XMLENTITYWINCLR_API string GetNodeName();

    XMLENTITYWINCLR_API void SetNodeID(int arg);

    XMLENTITYWINCLR_API int GetNodeID();

    XMLENTITYWINCLR_API void SetNodeValue(string arg);

    XMLENTITYWINCLR_API string GetNodeValue();

    XMLENTITYWINCLR_API void AddAttribute(AttributeEntity * arg);

    XMLENTITYWINCLR_API vector<AttributeEntity *> GetAttrList();

    XMLENTITYWINCLR_API void AddChild(NodeEntity * arg);

    XMLENTITYWINCLR_API vector<NodeEntity *> GetChildren();

    XMLENTITYWINCLR_API bool AttrExists(string name);

    XMLENTITYWINCLR_API string AttrByName(string name);

    XMLENTITYWINCLR_API bool NameEquals(string name);

    XMLENTITYWINCLR_API NodeEntity * Find(string tagName);

    XMLENTITYWINCLR_API NodeEntity * Find(string tagName, string attrName, string attrValue);

    XMLENTITYWINCLR_API NodeEntity * Find(string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value);

    XMLENTITYWINCLR_API NodeEntity * FindTail(int depth);

    XMLENTITYWINCLR_API NodeEntity * Clone();

    XMLENTITYWINCLR_API NodeEntity * Dir(string name);

    XMLENTITYWINCLR_API NodeEntity * File(string name);

    XMLENTITYWINCLR_API NodeEntity * Tag(string name);

    XMLENTITYWINCLR_API NodeEntity * Attr(string name);

    XMLENTITYWINCLR_API NodeEntity * SubCategory(string name);

    XMLENTITYWINCLR_API NodeEntity * SubCategory(string par1Name, string par2Name);

    XMLENTITYWINCLR_API NodeEntity * SubCategory(string par1Name, string par2Name, string par3Name);

    XMLENTITYWINCLR_API NodeEntity * Command(string name);

    XMLENTITYWINCLR_API NodeEntity * Param(string name);

    XMLENTITYWINCLR_API NodeEntity * Param(string par1Name, string par2Name);

    XMLENTITYWINCLR_API NodeEntity();

    XMLENTITYWINCLR_API void Dispose();

    XMLENTITYWINCLR_API ~NodeEntity();
};
