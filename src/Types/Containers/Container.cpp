#include "Container.hpp"
#include <stdio.h>

using namespace std;

Container::Container() {
    SetGeneralType(COLLECTION_DATA_TYPE);
}

int Container::PutItem(ChimeraObject *item) {
    printf("Error: 'PutItem' is not implemented yet\n");
    return FAIL;
}

size_t Container::Size() {
    printf("Error: 'Size' is not implemented yet\n");
    return FAIL;
}

int Container::SetItem(int64 index, ChimeraObject *item) {
    printf(set_err_msg.c_str(), INT_TYPE_NAME.c_str());
    return FAIL;
}

int Container::SetItem(float index, ChimeraObject *item) {
    printf(set_err_msg.c_str(), FLOAT_TYPE_NAME.c_str());
    return FAIL;
}

int Container::SetItem(dbl128 index, ChimeraObject *item) {
    printf(set_err_msg.c_str(), DOUBLE_TYPE_NAME.c_str());
    return FAIL;
}

int Container::SetItem(char32_t index, ChimeraObject *item) {
    printf(set_err_msg.c_str(), CHAR_TYPE_NAME.c_str());
    return FAIL;
}

int Container::SetItem(string index, ChimeraObject *item) {
    printf(set_err_msg.c_str(), STRING_TYPE_NAME.c_str());
    return FAIL;
}

int Container::SetItem(bool index, ChimeraObject *item) {
    printf(set_err_msg.c_str(), BOOL_TYPE_NAME.c_str());
    return FAIL;
}


ChimeraObject* Container::GetItem(int64 index) {
    printf(get_err_msg.c_str(), INT_TYPE_NAME.c_str());
    return nullptr;
}

ChimeraObject* Container::GetItem(float index) {
    printf(get_err_msg.c_str(), FLOAT_TYPE_NAME.c_str());
    return nullptr;
}

ChimeraObject* Container::GetItem(dbl128 index) {
    printf(get_err_msg.c_str(), DOUBLE_TYPE_NAME.c_str());
    return nullptr;
}

ChimeraObject* Container::GetItem(string index) {
    printf(get_err_msg.c_str(), STRING_TYPE_NAME.c_str());
    return nullptr;
}

ChimeraObject* Container::GetItem(char32_t index) {
    printf(get_err_msg.c_str(), CHAR_TYPE_NAME.c_str());
    return nullptr;
}

ChimeraObject* Container::GetItem(bool index) {
    printf(get_err_msg.c_str(), BOOL_TYPE_NAME.c_str());
    return nullptr;
}