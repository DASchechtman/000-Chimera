#include "Int.hpp"
#include <iostream>

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
    return 0;
}

int Int::Set(float &data) {
    m_data.integer = (int)data;
    return 0;
}

int Int::Set(long double &data) {
    m_data.integer = (int)(float)data;
    return 0;
}

int Int::Set(unsigned char &data) {
    m_data.integer = data;
    return 0;
}


int Int::Get(int &data) {
    data = m_data.integer;
    return 0;
}

int Int::Add(Number &other) {
    m_data.integer += (int)(float)GetOtherNumber(other);
    return 0;
}

int Int::Subtract(Number &other) {
    m_data.integer -= (int)(float)GetOtherNumber(other);
    return 0;
}

int Int::Multiply(Number &other) {
    m_data.integer *= (int)(float)GetOtherNumber(other);
    return 0;
}

int Int::Divide(Number &other) {
    try {
        m_data.integer /= (int)(float)DivideByZeroGuard(other);
    }
    catch(const char* msg){
        cout << msg;
        return 1;
    }
    catch (int err) {
        return 1;
    }
    
    return 0;
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