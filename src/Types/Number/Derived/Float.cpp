#include "Float.hpp"
#include <cmath>
#include <iostream>

using namespace std;

Float::Float() {
    m_data.floating = 0;
    SetType(FLOAT_DATA_TYPE);
}

Float::Float(chmr_flt data) {
    m_data.floating = data;
    SetType(FLOAT_DATA_TYPE);
}

int Float::Set(chmr_int &data) {
    m_data.floating = data;
    return SUCCEED;
}

int Float::Set(chmr_flt &data) {
    m_data.floating = data;
    return SUCCEED;
}

int Float::Set(chmr_dbl &data) {
    m_data.floating = data;
    return SUCCEED;
}

int Float::Set(chmr_char &data) {
    m_data.floating = data;
    return SUCCEED;
}


int Float::Get(chmr_flt &data) {
    data = m_data.floating;
    return SUCCEED;
}

int Float::Add(Number &other) {
    m_data.floating += GetOtherNumber(other);
    return SUCCEED;
}

int Float::Subtract(Number &other) {
    m_data.floating -= GetOtherNumber(other);
    return SUCCEED;
}

int Float::Multiply(Number &other) {
    m_data.floating *= GetOtherNumber(other);
    return SUCCEED;
}

int Float::Divide(Number &other) {
    try {
        m_data.floating /= DivideByZeroGuard(other);
    }
    catch(const char* msg){
        cout << msg;
        return FAIL;
    }
    catch (int err) {
        return FAIL;
    }
    
    return SUCCEED;
}

int Float::Pow(Number &other) {
    try {
        chmr_dbl other_num = GetOtherNumber(other);
        m_data.floating = pow(m_data.floating, other_num);
    }
    catch (const char *msg) {
        cout << msg;
        return FAIL;
    }

    return SUCCEED;
}


ChimeraObject* Float::Clone() {
    return new Float(m_data.floating);
}

string Float::ToStr() {
    return to_string(m_data.floating);
}

chmr_char Float::ToChar() {
    char to_char = 0;

    if (m_data.floating < 0) {
        to_char = 0;
    }
    else if (m_data.floating > 255) {
        to_char = 255;
    }
    else {
        to_char = m_data.floating;
    }

    return to_char;
}

chmr_int Float::ToInt() {
    return (chmr_int)m_data.floating;
}

chmr_flt Float::ToFloat() {
    return m_data.floating;
}

chmr_dbl Float::ToDouble() {
    return m_data.floating;
}

bool Float::ToBool() {
    return m_data.floating != 0;
}