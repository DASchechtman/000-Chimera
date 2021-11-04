#include "Int.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Int::Int() {
    m_data.integer = 0;
    SetType(INT_DATA_TYPE);
}

Int::Int(int data) {
    m_data.integer = data;
    SetType(INT_DATA_TYPE);
}

int Int::Set(int &data) {
    m_data.integer = data;
    return SUCCEED;
}

int Int::Set(float &data) {
    m_data.integer = (int)data;
    return SUCCEED;
}

int Int::Set(long double &data) {
    m_data.integer = (int)(float)data;
    return SUCCEED;
}

int Int::Set(unsigned char &data) {
    m_data.integer = data;
    return SUCCEED;
}


int Int::Get(int &data) {
    data = m_data.integer;
    return SUCCEED;
}

int Int::Add(Number &other) {
    m_data.integer += (int)(float)GetOtherNumber(other);
    return SUCCEED;
}

int Int::Subtract(Number &other) {
    m_data.integer -= (int)(float)GetOtherNumber(other);
    return SUCCEED;
}

int Int::Multiply(Number &other) {
    m_data.integer *= (int)(float)GetOtherNumber(other);
    return SUCCEED;
}

int Int::Divide(Number &other) {
    try {
        m_data.integer /= (int)(float)DivideByZeroGuard(other);
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

int Int::Pow(Number &other) {
    try {
        auto other_num = GetOtherNumber(other);
        m_data.integer = pow(m_data.integer, other_num);
    }
    catch (const char *msg) {
        cout << msg;
        return FAIL;
    }

    return SUCCEED;
}

ChimeraObject* Int::Clone() {
    return new Int(m_data.integer);
}

string Int::ToStr() {
    return to_string(m_data.integer);
}

unsigned char Int::ToChar() {
    char to_char = 0;

    if (m_data.integer < 0) {
        to_char = 0;
    }
    else if (m_data.integer > 255) {
        to_char = 255;
    }
    else {
        to_char = m_data.integer;
    }

    return to_char;
}


int Int::ToInt() {
    return m_data.integer;
}

float Int::ToFloat() {
    return m_data.integer;
}

long double Int::ToDouble() {
    return m_data.integer;
}

bool Int::ToBool() {
    return m_data.integer != 0;
}