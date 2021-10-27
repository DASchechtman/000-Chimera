#include "Bool.hpp"
#include <iostream>

using namespace std;

Bool::Bool() {
    m_data.boolean = false;
    SetType(BOOL_DATA_TYPE);
}

Bool::Bool(bool data) {
    m_data.boolean = data;
    SetType(BOOL_DATA_TYPE);
}

int Bool::Set(bool &data) {
    m_data.boolean = data;
    return 0;
}

int Bool::Get(bool &data) {
    data = m_data.boolean;
    return 0;
}

ChimeraObject* Bool::Clone() {
    return new Bool(m_data.boolean);
}

string Bool::ToStr() {
    if (m_data.boolean) {
        return "true";
    }
    else {
        return "false";
    }
}

unsigned char Bool::ToChar() {
    if (m_data.boolean) {
        return 't';
    }
    else {
        return 'f';
    }
}

int Bool::ToInt() {
    return m_data.boolean;
}

float Bool::ToFloat() {
    return m_data.boolean;
}

long double Bool::ToDouble() {
    return m_data.boolean;
}

bool Bool::ToBool() {
    return m_data.boolean;
}