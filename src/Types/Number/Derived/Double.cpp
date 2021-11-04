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

int Double::Set(int &data) {
    m_data.decimal = data;
    return SUCCEED;
}

int Double::Set(float &data) {
    m_data.decimal = data;
    return SUCCEED;
}

int Double::Set(long double &data) {
    m_data.decimal = data;
    return SUCCEED;
}

int Double::Set(unsigned char &data) {
    m_data.decimal = data;
    return SUCCEED;
}


int Double::Get(long double &data) {
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
        auto other_num = GetOtherNumber(other);
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

unsigned char Double::ToChar() {
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

int Double::ToInt() {
    return (int)m_data.decimal;
}

float Double::ToFloat() {
    return (float)m_data.decimal;
}

long double Double::ToDouble() {
    return m_data.decimal;
}

bool Double::ToBool() {
    return m_data.decimal != 0;
}