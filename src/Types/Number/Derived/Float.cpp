#include "Float.hpp"

Float::Float() {
    m_data.floating = 0;
    SetType(FLOAT_DATA_TYPE);
}

Float::Float(float data) {
    m_data.floating = data;
    SetType(FLOAT_DATA_TYPE);
}

int Float::Set(int &data) {
    m_data.floating = data;
    return 0;
}

int Float::Set(float &data) {
    m_data.floating = data;
    return 0;
}

int Float::Set(long double &data) {
    m_data.floating = (float)data;
    return 0;
}

int Float::Set(unsigned char &data) {
    m_data.floating = data;
    return 0;
}


int Float::Get(float &data) {
    data = m_data.floating;
    return 0;
}

int Float::Add(Number &other) {
    m_data.floating += (float)GetOtherNumber(other);
    return 0;
}

int Float::Subtract(Number &other) {
    m_data.floating -= (float)GetOtherNumber(other);
    return 0;
}

int Float::Multiply(Number &other) {
    m_data.floating *= (float)GetOtherNumber(other);
    return 0;
}

int Float::Divide(Number &other) {
    try {
        m_data.floating /= (float)DivideByZeroGuard(other);
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


ChimeraObject* Float::Clone() {
    return new Float(m_data.floating);
}

string Float::ToStr() {
    return to_string(m_data.floating);
}

unsigned char Float::ToChar() {
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

int Float::ToInt() {
    return (int)m_data.floating;
}

float Float::ToFloat() {
    return m_data.floating;
}

long double Float::ToDouble() {
    return m_data.floating;
}

bool Float::ToBool() {
    return m_data.floating != 0;
}