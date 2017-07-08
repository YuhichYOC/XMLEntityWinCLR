/*
*
* AttributeEntity.h
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

class AttributeEntity
{
private:

    string attrName;

    string attrValue;

public:

    XMLENTITYWINCLR_API void SetAttrName(string arg);

    XMLENTITYWINCLR_API string GetAttrName();

    XMLENTITYWINCLR_API void SetAttrValue(string arg);

    XMLENTITYWINCLR_API string GetAttrValue();

    XMLENTITYWINCLR_API bool NameEquals(string arg);

    XMLENTITYWINCLR_API bool ValueEquals(string arg);

    XMLENTITYWINCLR_API AttributeEntity * Clone();

    XMLENTITYWINCLR_API AttributeEntity();

    XMLENTITYWINCLR_API ~AttributeEntity();
};
