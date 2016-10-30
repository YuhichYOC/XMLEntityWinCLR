#include "stdafx.h" // ✝

#include "XMLEntity.h"

void WCharString::Assign(char * arg)
{
    value.assign(arg);
}

void WCharString::Assign(wchar_t * arg)
{
    wstring castedArg = arg;
    size_t argSize = castedArg.length() + 1;
    size_t cnvSize = 0;
    unique_ptr<char> mbArg(new char[argSize]);
    wcstombs_s(&cnvSize, mbArg.get(), argSize, arg, _TRUNCATE);
    value.assign(mbArg.get());
}

void WCharString::Assign(string arg)
{
    value.assign(arg);
}

void WCharString::Assign(string * arg)
{
    value.assign(*arg);
}

void WCharString::Assign(const char * arg)
{
    value.assign(arg);
}

void WCharString::Assign(const wchar_t * arg)
{
    wstring castedArg = arg;
    size_t argSize = castedArg.length() + 1;
    size_t cnvSize = 0;
    unique_ptr<char> mbArg(new char[argSize]);
    wcstombs_s(&cnvSize, mbArg.get(), argSize, arg, _TRUNCATE);
    value.assign(mbArg.get());
}

void WCharString::Assign(const string * arg)
{
    value.assign(*arg);
}

WCharString WCharString::Append(char * arg)
{
    value.append(arg);
    return *this;
}

WCharString WCharString::Append(wchar_t * arg)
{
    wstring castedArg = arg;
    size_t argSize = castedArg.length() + 1;
    size_t cnvSize = 0;
    unique_ptr<char> mbArg(new char[argSize]);
    wcstombs_s(&cnvSize, mbArg.get(), argSize, arg, _TRUNCATE);
    value.append(mbArg.get());
    return *this;
}

WCharString WCharString::Append(string arg)
{
    value.append(arg);
    return *this;
}

WCharString WCharString::Append(string * arg)
{
    value.append(*arg);
    return *this;
}

WCharString WCharString::Append(const char * arg)
{
    value.append(arg);
    return *this;
}

WCharString WCharString::Append(const wchar_t * arg)
{
    wstring castedArg = arg;
    size_t argSize = castedArg.length() + 1;
    size_t cnvSize = 0;
    unique_ptr<char> mbArg(new char[argSize]);
    wcstombs_s(&cnvSize, mbArg.get(), argSize, arg, _TRUNCATE);
    value.append(mbArg.get());
    return *this;
}

WCharString WCharString::Append(const string * arg)
{
    value.append(*arg);
    return *this;
}

WCharString WCharString::Value(char * arg)
{
    Assign(arg);
    return *this;
}

WCharString WCharString::Value(wchar_t * arg)
{
    Assign(arg);
    return *this;
}

WCharString WCharString::Value(string arg)
{
    Assign(arg);
    return *this;
}

WCharString WCharString::Value(string * arg)
{
    Assign(arg);
    return *this;
}

WCharString WCharString::Value(const char * arg)
{
    Assign(arg);
    return *this;
}

WCharString WCharString::Value(const wchar_t * arg)
{
    Assign(arg);
    return *this;
}

WCharString WCharString::Value(const string * arg)
{
    Assign(arg);
    return *this;
}

unique_ptr<wchar_t> WCharString::ToWChar()
{
    size_t retSize = value.length() + 1;
    size_t cnvSize = 0;
    unique_ptr<wchar_t> ret(new wchar_t[retSize]);
    mbstowcs_s(&cnvSize, ret.get(), retSize, value.c_str(), _TRUNCATE);
    return ret;
}

string WCharString::ToString()
{
    return value;
}

bool WCharString::WChar_tStartsWith(wchar_t * arg1eval, string arg2test)
{
    wstring castedArg1 = arg1eval;
    if (castedArg1.length() < arg2test.length()) {
        return false;
    }
    for (size_t i = 0; i < arg2test.length(); i++) {
        if (castedArg1.at(i) != arg2test.at(i)) {
            return false;
        }
    }
    return true;
}

void WCharString::SysErrWinAPI()
{
    LPVOID msg = NULL;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL,
        GetLastError(),
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&msg,
        0,
        NULL);
    string out = this->Value((const wchar_t *)msg).ToString();
    if (out.substr(out.length() - 2, 2) == string("\r\n")) {
        out = out.substr(0, out.length() - 2);
    }
    cout << out << "\n";
}

WCharString::WCharString()
{
}

WCharString::~WCharString()
{
}

void AttributeEntity::SetAttrName(string arg)
{
    attrName.assign(arg);
}

string AttributeEntity::GetAttrName()
{
    return attrName;
}

string * AttributeEntity::CloneAttrName()
{
    string * cloneName = new string();
    cloneName->assign(attrName);
    return cloneName;
}

void AttributeEntity::SetAttrValue(string arg)
{
    attrValue.assign(arg);
}

string AttributeEntity::GetAttrValue()
{
    return attrValue;
}

string * AttributeEntity::CloneAttrValue()
{
    string * cloneValue = new string();
    cloneValue->assign(attrValue);
    return cloneValue;
}

bool AttributeEntity::NameEquals(string arg)
{
    if ((attrName.compare(arg)) == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool AttributeEntity::ValueEquals(string arg)
{
    if ((attrValue.compare(arg)) == 0) {
        return true;
    }
    else {
        return false;
    }
}

AttributeEntity * AttributeEntity::Clone()
{
    AttributeEntity * clone = new AttributeEntity();
    clone->SetAttrName(*CloneAttrName());
    clone->SetAttrValue(*CloneAttrValue());
    return clone;
}

AttributeEntity::AttributeEntity()
{
    disposed = false;
}

void AttributeEntity::Dispose()
{
    disposed = true;
}

AttributeEntity::~AttributeEntity()
{
    if (!disposed) {
        Dispose();
    }
}

NodeEntity * NodeEntity::Find(NodeEntity * node, string tagName)
{
    if (node == nullptr) {
        node = this;
    }
    if ((node->GetNodeName().compare(tagName)) == 0) {
        return node;
    }
    for (size_t i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(node->GetChildList()->at(i), tagName);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(NodeEntity * node, string tagName, string attrName, string attrValue)
{
    if (node == nullptr) {
        node = this;
    }
    if ((node->GetNodeName().compare(tagName)) == 0) {
        if (node->AttrExists(attrName) && (node->AttrByName(attrName).compare(attrValue) == 0)) {
            return node;
        }
    }
    for (size_t i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(node->GetChildList()->at(i), tagName, attrName, attrValue);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(NodeEntity * node, string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value)
{
    if (node == nullptr) {
        node = this;
    }
    if ((node->GetNodeName().compare(tagName)) == 0) {
        if (node->AttrExists(attr1Name) && node->AttrExists(attr2Name) && (node->AttrByName(attr1Name).compare(attr1Value) == 0) && (node->AttrByName(attr2Name).compare(attr2Value) == 0)) {
            return node;
        }
    }
    for (size_t i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(node->GetChildList()->at(i), tagName, attr1Name, attr1Value, attr2Name, attr2Value);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::FindFromTail(NodeEntity * node, vector<string> tree)
{
    if (node == nullptr) {
        node = this;
    }
    if (tree.size() == 0) {
        return node;
    }
    int pos = FindChildIndexByName(node, tree.at(0));
    tree.erase(tree.begin());
    if (pos >= 0) {
        return FindFromTail(node->GetChildList()->at(pos), tree);
    }
    else {
        return nullptr;
    }
}

NodeEntity * NodeEntity::FindFromTail(NodeEntity * node, vector<string> tree, string leafName)
{
    if (node == nullptr) {
        node = this;
    }
    if (tree.size() == 0) {
        int retPos = FindChildIndexByName(node, leafName);
        if (retPos >= 0) {
            return node->GetChildList()->at(retPos);
        }
        else {
            return nullptr;
        }
    }
    int pos = FindChildIndexByName(node, tree.at(0));
    tree.erase(tree.begin());
    if (pos >= 0) {
        return FindFromTail(node->GetChildList()->at(pos), tree, leafName);
    }
    else {
        return nullptr;
    }
}

int NodeEntity::FindChildIndexByName(NodeEntity * node, string name)
{
    int pos = -1;
    int iLoopCount = (int)node->GetChildList()->size();
    for (int i = 0; i < iLoopCount; i++) {
        if ((node->GetChildList()->at(i)->GetNodeName().compare(name)) == 0) {
            pos = i;
        }
    }
    return pos;
}

void NodeEntity::DisposeAttrList()
{
    int iLoopCount = attrList->size();
    for (int i = 0; i < iLoopCount; i++) {
        attrList->at(i)->Dispose();
        delete attrList->at(i);
    }
    delete attrList;
}

void NodeEntity::DisposeChildList()
{
    int iLoopCount = childList->size();
    for (int i = 0; i < iLoopCount; i++) {
        childList->at(i)->Dispose();
        delete childList->at(i);
    }
    delete childList;
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

void NodeEntity::SetAttrList(vector<AttributeEntity *> * arg)
{
    attrList = arg;
}

vector<AttributeEntity *> * NodeEntity::GetAttrList()
{
    return attrList;
}

void NodeEntity::AddAttribute(AttributeEntity * arg)
{
    attrList->push_back(arg);
}

void NodeEntity::SetChildList(vector<NodeEntity *> * arg)
{
    childList = arg;
}

vector<NodeEntity *> * NodeEntity::GetChildList()
{
    return childList;
}

void NodeEntity::AddChild(NodeEntity * arg)
{
    childList->push_back(arg);
}

bool NodeEntity::AttrExists(string name)
{
    bool ret = false;
    for (size_t i = 0; i < attrList->size(); i++) {
        if (attrList->at(i)->NameEquals(name)) {
            ret = true;
        }
    }
    return ret;
}

string NodeEntity::AttrByName(string name)
{
    string ret;
    for (size_t i = 0; i < attrList->size(); i++) {
        if (attrList->at(i)->NameEquals(name)) {
            ret = attrList->at(i)->GetAttrValue();
        }
    }
    return ret;
}

NodeEntity * NodeEntity::Find(string tagName)
{
    NodeEntity * node = this;
    if ((node->GetNodeName().compare(tagName) == 0)) {
        return node;
    }
    for (size_t i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * ret = Find(node->GetChildList()->at(i), tagName);
        if (ret != nullptr) {
            return ret;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(string tagName, string attrName, string attrValue)
{
    NodeEntity * node = this;
    if ((node->GetNodeName().compare(tagName) == 0)) {
        if (node->AttrExists(attrName) && (node->AttrByName(attrName).compare(attrValue) == 0)) {
            return node;
        }
    }
    for (size_t i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * ret = Find(node->GetChildList()->at(i), tagName, attrName, attrValue);
        if (ret != nullptr) {
            return ret;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::Find(string tagName, string attr1Name, string attr1Value, string attr2Name, string attr2Value)
{
    NodeEntity * node = this;
    if ((node->GetNodeName().compare(tagName) == 0)) {
        if (node->AttrExists(attr1Name) && node->AttrExists(attr2Name) && (node->AttrByName(attr1Name).compare(attr1Value) == 0) && (node->AttrByName(attr2Name).compare(attr2Value) == 0)) {
            return node;
        }
    }
    for (size_t i = 0; i < node->GetChildList()->size(); i++) {
        NodeEntity * retVal = Find(node->GetChildList()->at(i), tagName, attr1Name, attr1Value, attr2Name, attr2Value);
        if (retVal != nullptr) {
            return retVal;
        }
    }
    return nullptr;
}

NodeEntity * NodeEntity::FindFromTail(vector<string> * tree)
{
    NodeEntity * node = this;
    if (tree->size() <= 1) {
        return node;
    }
    else {
        vector<string> subtree = *tree;
        subtree.erase(subtree.begin());
        return FindFromTail(node, subtree);
    }
}

NodeEntity * NodeEntity::FindFromTail(vector<string> * tree, string leafName)
{
    NodeEntity * node = this;
    if (tree->size() <= 0) {
        return node;
    }
    else {
        if (leafName.length() == 0) {
            return FindFromTail(tree);
        }
        /*
        else if (tree->at(tree->size() - 1)->compare(*leafName) == 0) {
        return FindFromTail(tree);
        }
        */
        else {
            vector<string> subtree = *tree;
            subtree.erase(subtree.begin());
            return FindFromTail(node, subtree, leafName);
        }
    }
}

NodeEntity * NodeEntity::Dir(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3Dir = "Dir";
    string arg4Name = "name";
    return Find(arg1Item, arg2Type, arg3Dir, arg4Name, name);
}

NodeEntity * NodeEntity::File(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3File = "File";
    string arg4Name = "name";
    return Find(arg1Item, arg2Type, arg3File, arg4Name, name);
}

NodeEntity * NodeEntity::Tag(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3Tag = "Tag";
    string arg4Name = "name";
    return Find(arg1Item, arg2Type, arg3Tag, arg4Name, name);
}

NodeEntity * NodeEntity::Attr(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3Attr = "Attr";
    string arg4Name = "name";
    return Find(arg1Item, arg2Type, arg3Attr, arg4Name, name);
}

NodeEntity * NodeEntity::Table(string name)
{
    string arg1Item = "Item";
    string arg2Type = "type";
    string arg3Table = "Table";
    string arg4Name = "name";
    return Find(arg1Item, arg2Type, arg3Table, arg4Name, name);
}

NodeEntity * NodeEntity::SubCategory(string name)
{
    string arg1Category = "Category";
    string arg2Name = "name";
    return Find(arg1Category, arg2Name, name);
}

NodeEntity * NodeEntity::SubCategory(string childName, string grandChildName)
{
    string arg1Category = "Category";
    string arg2Name = "name";
    string arg3Category = "Category";
    string arg4Name = "name";
    return Find(arg1Category, arg2Name, childName)->Find(arg3Category, arg4Name, grandChildName);
}

NodeEntity * NodeEntity::SubCategory(string childName, string grandChildName, string greatGrandChildName)
{
    string arg1Category = "Category";
    string arg2Name = "name";
    string arg3Category = "Category";
    string arg4Name = "name";
    string arg5Category = "Category";
    string arg6Name = "name";
    return Find(arg1Category, arg2Name, childName)->Find(arg3Category, arg4Name, grandChildName)->Find(arg5Category, arg6Name, greatGrandChildName);
}

NodeEntity * NodeEntity::Clone()
{
    NodeEntity * clone = new NodeEntity();

    for (size_t i = 0; i < attrList->size(); i++) {
        AttributeEntity * cloneAttr = attrList->at(i)->Clone();
        clone->AddAttribute(cloneAttr);
    }

    for (size_t j = 0; j < childList->size(); j++) {
        clone->AddChild(childList->at(j)->Clone());
    }

    clone->SetNodeName(this->GetNodeName());
    clone->SetNodeID(this->GetNodeID());
    clone->SetNodeValue(this->GetNodeValue());

    return clone;
}

NodeEntity::NodeEntity()
{
    attrList = new vector<AttributeEntity *>();
    childList = new vector<NodeEntity *>();
    disposed = false;
}

void NodeEntity::Dispose()
{
    DisposeAttrList();
    DisposeChildList();
    disposed = true;
}

NodeEntity::~NodeEntity()
{
    if (!disposed) {
        Dispose();
    }
}

void XMLEntity::SetDirectory(string arg)
{
    directory.assign(arg);
}

string XMLEntity::GetDirectory()
{
    return directory;
}

void XMLEntity::SetFileName(string arg)
{
    fileName.assign(arg);
}

string XMLEntity::GetFileName()
{
    return fileName;
}

NodeEntity * XMLEntity::GetNode()
{
    return myNode;
}

void XMLEntity::Prepare()
{
    if (fileName.length() == 0) {
        errorMessage.assign("SettingReader::Prepare -- File name is not set. Method : Parse");
        prepared = false;
        return;
    }
    if (FAILED(SHCreateStreamOnFile((LPCWSTR)(wc.Value(directory).Append("\\").Append(fileName).ToWChar().get()), STGM_READ, &stream))) {
        errorMessage.assign("SettingReader::Prepare -- File reader can't be create. Method : SHCreateStreamOnFile");
        prepared = false;
        return;
    }
    if (FAILED(CreateXmlReader(__uuidof(IXmlReader), (void**)&reader, NULL))) {
        errorMessage.assign("SettingReader::Prepare -- Xml reader can't be create. Method : CreateXmlReader");
        prepared = false;
        return;
    }
    if (FAILED(reader->SetProperty(XmlReaderProperty_DtdProcessing, DtdProcessing_Prohibit))) {
        errorMessage.assign("SettingReader::Prepare -- Reader property can't set. Method : SetProperty");
        prepared = false;
        return;
    }
    if (FAILED(reader->SetInput(stream))) {
        errorMessage.assign("SettingReader::Prepare -- Reader stream can't set. Method : SetInput");
        parseSucceeded = false;
        return;
    }

    prepared = true;
}

bool XMLEntity::IsPrepared()
{
    return prepared;
}

void XMLEntity::Parse()
{
    nodeId = 0;

    vector<string> * tree = new vector<string>();

    XmlNodeType nodeType;
    while (reader->Read(&nodeType) == S_OK) {
        switch (nodeType) {
        case XmlNodeType_None:
            break;
        case XmlNodeType_Element:
            ParseElement(reader, tree);
            break;
        case XmlNodeType_Attribute:
            break;
        case XmlNodeType_Text:
            ParseText(reader, tree);
            break;
        case XmlNodeType_CDATA:
            ParseCDATA(reader, tree);
            break;
        case XmlNodeType_ProcessingInstruction:
            break;
        case XmlNodeType_Comment:
            break;
        case XmlNodeType_DocumentType:
            break;
        case XmlNodeType_Whitespace:
            break;
        case XmlNodeType_EndElement:
            ParseEndElement(reader, tree);
            break;
        case XmlNodeType_XmlDeclaration:
            break;
        default:
            break;
        }
    }

    parseSucceeded = true;
}

void XMLEntity::ParseElement(IXmlReader * reader, vector<string> * tree)
{
    const wchar_t * prefix;
    const wchar_t * localName;
    uint32_t prefixLength;
    if (FAILED(reader->GetPrefix(&prefix, &prefixLength))) {
        return;
    }
    if (FAILED(reader->GetLocalName(&localName, NULL))) {
        return;
    }

    nodeId++;

    NodeEntity * newNode = new NodeEntity();
    newNode->SetNodeName(wc.Value(localName).ToString());
    newNode->SetNodeID(nodeId);

    if (nodeId == 1) {
        myNode = newNode;
    }
    else {
        if (reader->IsEmptyElement()) {
            tree->pop_back();
        }
        myNode->FindFromTail(tree)->AddChild(newNode);
    }
    ParseAttributes(reader, tree, newNode->GetNodeName());
    tree->push_back(newNode->GetNodeName());
}

void XMLEntity::ParseText(IXmlReader * reader, vector<string> * tree)
{
    const wchar_t * value;
    if (FAILED(reader->GetValue(&value, NULL))) {
        return;
    }
    myNode->FindFromTail(tree)->SetNodeValue(wc.Value(value).ToString());
}

void XMLEntity::ParseCDATA(IXmlReader * reader, vector<string> * tree)
{
    const wchar_t * value;
    if (FAILED(reader->GetValue(&value, NULL))) {
        return;
    }
    myNode->FindFromTail(tree)->SetNodeValue(wc.Value(value).ToString());
}

void XMLEntity::ParseEndElement(IXmlReader * reader, vector<string> * tree)
{
    tree->pop_back();
}

void XMLEntity::ParseAttributes(IXmlReader * reader, vector<string> * tree, string name)
{
    const wchar_t * prefix;
    const wchar_t * localName;
    const wchar_t * value;
    uint32_t prefixLength;

    if (FAILED(reader->MoveToFirstAttribute())) {
        return;
    }
    while (true) {
        if (!reader->IsDefault()) {
            if (FAILED(reader->GetPrefix(&prefix, &prefixLength))) {
                continue;
            }
            if (FAILED(reader->GetLocalName(&localName, NULL))) {
                continue;
            }
            if (FAILED(reader->GetValue(&value, NULL))) {
                continue;
            }
            AttributeEntity * newAttr = new AttributeEntity();
            newAttr->SetAttrName(wc.Value(localName).ToString());
            newAttr->SetAttrValue(wc.Value(value).ToString());
            myNode->FindFromTail(tree, name)->AddAttribute(newAttr);
        }
        if (S_OK != reader->MoveToNextAttribute()) {
            break;
        }
    }
}

bool XMLEntity::IsParseSucceeded()
{
    return parseSucceeded;
}

string XMLEntity::GetErrorMessage()
{
    return errorMessage;
}

XMLEntity::XMLEntity()
{
    myNode = new NodeEntity();
    stream = nullptr;
    reader = nullptr;
    disposed = false;
}

void XMLEntity::Dispose()
{
    myNode->Dispose();
    if (stream != nullptr) {
        delete stream;
    }
    if (reader != nullptr) {
        delete reader;
    }
    disposed = true;
}

XMLEntity::~XMLEntity()
{
    if (!disposed) {
        Dispose();
    }
}