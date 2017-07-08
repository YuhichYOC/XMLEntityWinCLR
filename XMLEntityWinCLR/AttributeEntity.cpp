/*
*
* AttributeEntity.cpp
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

#include "stdafx.h"

#include "AttributeEntity.h"

void AttributeEntity::SetAttrName(string arg)
{
    attrName.assign(arg);
}

string AttributeEntity::GetAttrName()
{
    return attrName;
}

void AttributeEntity::SetAttrValue(string arg)
{
    attrValue.assign(arg);
}

string AttributeEntity::GetAttrValue()
{
    return attrValue;
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
    AttributeEntity * ret = new AttributeEntity();
    ret->SetAttrName(attrName);
    ret->SetAttrValue(attrValue);
    return ret;
}

AttributeEntity::AttributeEntity()
{
}

AttributeEntity::~AttributeEntity()
{
}