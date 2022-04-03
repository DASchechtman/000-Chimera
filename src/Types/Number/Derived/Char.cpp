#include "Char.hpp"

Char::Char() {
    m_data.character = '\0';
    SetType(CHAR_DATA_TYPE);
}

Char::Char(char data) {
    m_data.character = data;
    SetType(CHAR_DATA_TYPE);
}


int Char::Set(int64 &data) {
    m_data.character = data;
    return SUCCEED;
}

int Char::Set(float &data) {
    m_data.character = data;
    return SUCCEED;
}


int Char::Set(long double &data) {
    m_data.character = data;
    return SUCCEED;
}


int Char::Set(char32_t &data) {
    m_data.character = data;
    return SUCCEED;
}


int Char::Get(char32_t &data) {
    data = m_data.character;
    return SUCCEED;
}

int Char::Add(Number &other) {
    m_data.character += GetOtherNumber(other);
    return SUCCEED;
}

int Char::Subtract(Number &other) {
    m_data.character -= GetOtherNumber(other);
    return SUCCEED;
}

int Char::Multiply(Number &other) {
    m_data.character *= GetOtherNumber(other);
    return SUCCEED;
}

int Char::Divide(Number &other) {
    
    try {
        m_data.character /= DivideByZeroGuard(other);
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

ChimeraObject* Char::Clone() {
    return new Char(m_data.character);
}

string Char::ToStr() {
    string to_str;
    to_str += m_data.character;
    return to_str;
}

char32_t Char::ToChar() {
    return m_data.character;
}

int64 Char::ToInt() {
    return m_data.character;
}

float Char::ToFloat() {
    return m_data.character;
}

long double Char::ToDouble() {
    return m_data.character;
}

bool Char::ToBool() {
    return m_data.character != 0;
}