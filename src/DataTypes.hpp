#pragma once

#include <string>

using namespace std;

enum VAR_TYPES {
    OBJECT_DATA_TYPE, 
    NUMBER_DATA_TYPE, 
    TEXT_DATA_TYPE,
    COLLECTION_DATA_TYPE,
    UNION_DATA_TYPE,
    REF_DATA_TYPE,
    LIST_DATA_TYPE,
    MAP_DATA_TYPE,
    FUNC_DATA_TYPE, 
    INT_DATA_TYPE, 
    DOUBLE_DATA_TYPE, 
    FLOAT_DATA_TYPE, 
    CHAR_DATA_TYPE, 
    STRING_DATA_TYPE, 
    BOOL_DATA_TYPE,
    UNKNOWN_DATA_TYPE,
    UNDEFINED_DATA_TYPE, 
};

const string INT_TYPE_NAME = "int";
const string FLOAT_TYPE_NAME = "float";
const string DOUBLE_TYPE_NAME = "double";
const string CHAR_TYPE_NAME = "char";
const string STRING_TYPE_NAME = "string";
const string BOOL_TYPE_NAME = "bool";
const string LIST_TYPE_NAME = "list";
const string OBJECT_TYPE_NAME = "object";
const string UNDEFINED_TYPE_NAME = "undefined";
const string TEXT_TYPE_NAME = "text";
const string NUMBER_TYPE_NAME = "number";
const string MAP_TYPE_NAME = "map";
const string UNKNOWN_TYPE_NAME = "unknown";