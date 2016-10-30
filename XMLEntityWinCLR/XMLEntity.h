#pragma once

#include "stdafx.h" // ✝

class WCharString
{
private:

    string value;

    void Assign(char * arg);

    void Assign(wchar_t * arg);

    void Assign(string arg);

    void Assign(string * arg);

    void Assign(const char * arg);

    void Assign(const wchar_t * arg);

    void Assign(const string * arg);

public:

    WCharString Append(char * arg);

    WCharString Append(wchar_t * arg);

    WCharString Append(string arg);

    WCharString Append(string * arg);

    WCharString Append(const char * arg);

    WCharString Append(const wchar_t * arg);

    WCharString Append(const string * arg);

    WCharString Value(char * arg);

    WCharString Value(wchar_t * arg);

    WCharString Value(string arg);

    WCharString Value(string * arg);

    WCharString Value(const char * arg);

    WCharString Value(const wchar_t * arg);

    WCharString Value(const string * arg);

    unique_ptr<wchar_t> ToWChar();

    string ToString();

    bool WChar_tStartsWith(wchar_t * arg1eval, string arg2test);

    void SysErrWinAPI();

    WCharString();

    ~WCharString();
};

class AttributeEntity
{
private:

    string attrName;

    string attrValue;

    bool disposed;

public:

    void SetAttrName(string arg);

    string GetAttrName();

    string * CloneAttrName();

    void SetAttrValue(string arg);

    string GetAttrValue();

    string * CloneAttrValue();

    bool NameEquals(string arg);

    bool ValueEquals(string arg);

    AttributeEntity * Clone();

    AttributeEntity();

    void Dispose();

    ~AttributeEntity();
};

class NodeEntity
{
private:

    string nodeName;

    int nodeId;

    string nodeValue;

    vector<AttributeEntity *> * attrList;

    vector<NodeEntity *> * childList;

    NodeEntity * Find(NodeEntity * node, string tagName);

    NodeEntity * Find(NodeEntity * node, string tagName, string attrName, string attrValue);

    NodeEntity * Find(NodeEntity * node, string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value);

    NodeEntity * FindFromTail(NodeEntity * node, vector<string> tree);

    NodeEntity * FindFromTail(NodeEntity * node, vector<string> tree, string leafName);

    int FindChildIndexByName(NodeEntity * node, string name);

    bool disposed;

    void DisposeAttrList();

    void DisposeChildList();

public:

    void SetNodeName(string arg);

    string GetNodeName();

    void SetNodeID(int arg);

    int GetNodeID();

    void SetNodeValue(string arg);

    string GetNodeValue();

    void SetAttrList(vector<AttributeEntity *> * arg);

    vector<AttributeEntity *> * GetAttrList();

    void AddAttribute(AttributeEntity * arg);

    void SetChildList(vector<NodeEntity *> * arg);

    vector<NodeEntity *> * GetChildList();

    void AddChild(NodeEntity * arg);

    bool AttrExists(string name);

    string AttrByName(string name);

    NodeEntity * Find(string tagName);

    NodeEntity * Find(string tagName, string attrName, string attrValue);

    NodeEntity * Find(string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value);

    NodeEntity * FindFromTail(vector<string> * tree);

    NodeEntity * FindFromTail(vector<string> * tree, string leafName);

    NodeEntity * Dir(string name);

    NodeEntity * File(string name);

    NodeEntity * Tag(string name);

    NodeEntity * Attr(string name);

    NodeEntity * Table(string name);

    NodeEntity * SubCategory(string name);

    NodeEntity * SubCategory(string childName, string grandChildName);

    NodeEntity * SubCategory(string childName, string grandChildName, string greatGrandChildName);

    NodeEntity * Clone();

    NodeEntity();

    void Dispose();

    ~NodeEntity();
};

class XMLEntity
{
private:

    WCharString wc;

    string directory;

    string fileName;

    NodeEntity * myNode;

    int nodeId;

    IStream * stream;

    IXmlReader * reader;

    bool prepared;

    bool parseSucceeded;

    string errorMessage;

    void ParseElement(IXmlReader * reader, vector<string> * tree);

    void ParseText(IXmlReader * reader, vector<string> * tree);

    void ParseCDATA(IXmlReader * reader, vector<string> * tree);

    void ParseEndElement(IXmlReader * reader, vector<string> * tree);

    void ParseAttributes(IXmlReader * reader, vector<string> * tree, string name);

    bool disposed;

public:

    void SetDirectory(string arg);

    string GetDirectory();

    void SetFileName(string arg);

    string GetFileName();

    NodeEntity * GetNode();

    void Prepare();

    bool IsPrepared();

    void Parse();

    bool IsParseSucceeded();

    string GetErrorMessage();

    XMLEntity();

    void Dispose();

    ~XMLEntity();
};
