#include "Char.hpp"

Char::Char() {
    m_data.character = '\0';
    SetType(CHAR_DATA_TYPE);
}

Char::Char(char data) {
    m_data.character = data;
    SetType(CHAR_DATA_TYPE);
}


int Char::Set(chmr_int &data) {
    m_data.character = data;
    return SUCCEED;
}

int Char::Set(chmr_flt &data) {
    m_data.character = data;
    return SUCCEED;
}


int Char::Set(chmr_dbl &data) {
    m_data.character = data;
    return SUCCEED;
}


int Char::Set(chmr_char &data) {
    m_data.character = data;
    return SUCCEED;
}


int Char::Get(chmr_char &data) {
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

chmr_char Char::ToChar() {
    return m_data.character;
}

chmr_int Char::ToInt() {
    return m_data.character;
}

chmr_flt Char::ToFloat() {
    return m_data.character;
}

chmr_dbl Char::ToDouble() {
    return m_data.character;
}

bool Char::ToBool() {
    return m_data.character != 0;
}