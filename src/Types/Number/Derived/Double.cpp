#include "Double.hpp"
#include <iostream>
#include <cmath>

using namespace std;


Double::Double() {
    m_data.decimal = 0;
    SetType(DOUBLE_DATA_TYPE);
}

Double::Double(double data) {
    m_data.decimal = data;
    SetType(DOUBLE_DATA_TYPE);
}

int Double::Set(chmr_int &data) {
    m_data.decimal = data;
    return SUCCEED;
}

int Double::Set(chmr_flt &data) {
    m_data.decimal = data;
    return SUCCEED;
}

int Double::Set(chmr_dbl &data) {
    m_data.decimal = data;
    return SUCCEED;
}

int Double::Set(chmr_char &data) {
    m_data.decimal = data;
    return SUCCEED;
}


int Double::Get(chmr_dbl &data) {
    data = m_data.decimal;
    return SUCCEED;
}

int Double::Add(Number &other) {
    m_data.decimal += GetOtherNumber(other);
    return SUCCEED;
}

int Double::Subtract(Number &other) {
    m_data.decimal -= GetOtherNumber(other);
    return SUCCEED;
}

int Double::Multiply(Number &other) {
    m_data.decimal *= GetOtherNumber(other);
    return SUCCEED;
}

int Double::Divide(Number &other) {
    try {
        m_data.decimal /= DivideByZeroGuard(other);
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

int Double::Pow(Number &other) {
    try {
        chmr_dbl other_num = GetOtherNumber(other);
        m_data.decimal = pow(m_data.decimal, other_num);
    }
    catch (const char *msg) {
        cout << msg;
        return FAIL;
    }

    return SUCCEED;
}


ChimeraObject* Double::Clone() {
    return new Double(m_data.decimal);
}

string Double::ToStr() {
    return to_string(m_data.decimal);
}

chmr_char Double::ToChar() {
    char to_char = 0;

    if (m_data.decimal < 0) {
        to_char = 0;
    }
    else if (m_data.decimal > 255) {
        to_char = 255;
    }
    else {
        to_char = m_data.decimal;
    }

    return to_char;
}

chmr_int Double::ToInt() {
    return (int32_t)m_data.decimal;
}

chmr_flt Double::ToFloat() {
    return (chmr_flt)m_data.decimal;
}

chmr_dbl Double::ToDouble() {
    return m_data.decimal;
}

bool Double::ToBool() {
    return m_data.decimal != 0;
}