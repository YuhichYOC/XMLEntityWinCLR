/*
*
* NodeEntity.cpp
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

#include "stdafx.h"

#include "NodeEntity.h"

NodeEntity * NodeEntity::Find(NodeEntity * node, string tagName)
{
    if ((node->GetNodeName().compare(tagName)) == 0) {
        return node;
    }
    size_t loop = node->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        NodeEntity * ret = nullptr;
        ret = Find(node->GetChildren().at(i), tagName);
        if (ret != nullptr) { return ret; }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(NodeEntity * node, string tagName, string attrName, string attrValue)
{
    if (node->GetNodeName().compare(tagName) == 0 && node->AttrExists(attrName) && node->AttrByName(attrName).compare(attrValue) == 0) {
        return node;
    }
    size_t loop = node->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        NodeEntity * ret = nullptr;
        ret = Find(node->GetChildren().at(i), tagName, attrName, attrValue);
        if (ret != nullptr) { return ret; }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(NodeEntity * node, string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value)
{
    if (node->GetNodeName().compare(tagName) == 0 && node->AttrExists(attr1Name) && node->AttrByName(attr1Name).compare(attr1Value) == 0 && node->AttrExists(attr2Name) && node->AttrByName(attr2Name).compare(attr2Value) == 0) {
        return node;
    }
    size_t loop = node->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        NodeEntity * ret = nullptr;
        ret = Find(node->GetChildren().at(i), tagName, attr1Name, attr1Value, attr2Name, attr2Value);
        if (ret != nullptr) { return ret; }
    }
    return nullptr;
}

NodeEntity * NodeEntity::FindTail(NodeEntity * node, int depth)
{
    if (depth == 1) {
        return node;
    }
    else {
        depth--;
        size_t count = node->GetChildren().size();
        return FindTail(node->GetChildren().at(count - 1), depth);
    }
}

void NodeEntity::SetNodeName(string arg)
{
    nodeName.assign(arg);
}

string NodeEntity::GetNodeName()
{
    return nodeName;
}

void NodeEntity::SetNodeID(int arg)
{
    nodeId = arg;
}

int NodeEntity::GetNodeID()
{
    return nodeId;
}

void NodeEntity::SetNodeValue(string arg)
{
    nodeValue.assign(arg);
}

string NodeEntity::GetNodeValue()
{
    return nodeValue;
}

void NodeEntity::AddAttribute(AttributeEntity * arg)
{
    attrList.push_back(arg);
}

vector<AttributeEntity *> NodeEntity::GetAttrList()
{
    return attrList;
}

void NodeEntity::AddChild(NodeEntity * arg)
{
    children.push_back(arg);
}

vector<NodeEntity *> NodeEntity::GetChildren()
{
    return children;
}

bool NodeEntity::AttrExists(string name)
{
    bool ret = false;
    size_t loop = attrList.size();
    for (size_t i = 0; i < loop; i++) {
        if (attrList.at(i)->NameEquals(name)) {
            ret = true;
        }
    }
    return ret;
}

string NodeEntity::AttrByName(string name)
{
    string ret;
    size_t loop = attrList.size();
    for (size_t i = 0; i < loop; i++) {
        if (attrList.at(i)->NameEquals(name)) {
            ret = attrList.at(i)->GetAttrValue();
        }
    }
    return ret;
}

bool NodeEntity::NameEquals(string name)
{
    if (nodeName.compare(name) == 0) {
        return true;
    }
    else {
        return false;
    }
}

NodeEntity * NodeEntity::Find(string tagName)
{
    if ((this->GetNodeName().compare(tagName) == 0)) {
        return this;
    }
    size_t loop = this->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        NodeEntity * ret = nullptr;
        ret = Find(this->GetChildren().at(i), tagName);
        if (ret != nullptr) { return ret; }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(string tagName, string attrName, string attrValue)
{
    if ((this->GetNodeName().compare(tagName) == 0) && this->AttrExists(attrName) && this->AttrByName(attrName).compare(attrValue) == 0) {
        return this;
    }
    size_t loop = this->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        NodeEntity * ret = nullptr;
        ret = Find(this->GetChildren().at(i), tagName, attrName, attrValue);
        if (ret != nullptr) { return ret; }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value)
{
    if (this->GetNodeName().compare(tagName) == 0 && this->AttrExists(attr1Name) && this->AttrByName(attr1Name).compare(attr1Value) == 0 && this->AttrExists(attr2Name) && this->AttrByName(attr2Name).compare(attr2Value) == 0) {
        return this;
    }
    size_t loop = this->GetChildren().size();
    for (size_t i = 0; i < loop; i++) {
        NodeEntity * ret = nullptr;
        ret = Find(this->GetChildren().at(i), tagName, attr1Name, attr1Value, attr2Name, attr2Value);
        if (ret != nullptr) { return ret; }
    }
    return nullptr;
}

NodeEntity * NodeEntity::FindTail(int depth)
{
    if (depth == 1) { return this; }
    depth--;
    size_t count = this->GetChildren().size();
    return FindTail(this->GetChildren().at(count - 1), depth);
}

NodeEntity * NodeEntity::Clone()
{
    NodeEntity * ret = new NodeEntity();

    size_t iloop = attrList.size();
    for (size_t i = 0; i < iloop; i++) {
        ret->AddAttribute(attrList.at(i)->Clone());
    }
    size_t jloop = children.size();
    for (size_t j = 0; j < jloop; j++) {
        ret->AddChild(children.at(j)->Clone());
    }

    ret->SetNodeName(nodeName);
    ret->SetNodeID(nodeId);
    ret->SetNodeValue(nodeValue);

    return ret;
}

NodeEntity * NodeEntity::Dir(string name)
{
    return Find("Item", "type", "Dir", "name", name);
}

NodeEntity * NodeEntity::File(string name)
{
    return Find("Item", "type", "File", "name", name);
}

NodeEntity * NodeEntity::Tag(string name)
{
    return Find("Item", "type", "Tag", "name", name);
}

NodeEntity * NodeEntity::Attr(string name)
{
    return Find("Item", "type", "Attr", "name", name);
}

NodeEntity * NodeEntity::SubCategory(string name)
{
    return Find("Category", "name", name);
}

NodeEntity * NodeEntity::SubCategory(string par1Name, string par2Name)
{
    return Find("Category", "name", par1Name)->Find("Category", "name", par2Name);
}

NodeEntity * NodeEntity::SubCategory(string par1Name, string par2Name, string par3Name)
{
    return Find("Category", "name", par1Name)->Find("Category", "name", par2Name)->Find("Category", "name", par3Name);
}

NodeEntity * NodeEntity::Command(string name)
{
    return Find("Command", "name", name);
}

NodeEntity * NodeEntity::Param(string name)
{
    return Find("Param", "name", name);
}

NodeEntity * NodeEntity::Param(string par1Name, string par2Name)
{
    return Command(par1Name)->Param(par2Name);
}

NodeEntity::NodeEntity()
{
    disposed = false;
}

void NodeEntity::Dispose()
{
    size_t iloop = attrList.size();
    for (size_t i = 0; i < iloop; i++) {
        delete attrList.at(i);
    }
    size_t jloop = children.size();
    for (size_t j = 0; j < jloop; j++) {
        delete children.at(j);
    }
    disposed = true;
}

NodeEntity::~NodeEntity()
{
    if (!disposed) {
        Dispose();
    }
}