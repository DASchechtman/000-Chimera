#include "Char.hpp"

Char::Char() {
    m_data.character = '\0';
    SetType(CHAR_DATA_TYPE);
}

Char::Char(char data) {
    m_data.character = data;
    SetType(CHAR_DATA_TYPE);
}


int Char::Set(int &data) {
    m_data.character = (char)data;
    return 0;
}

int Char::Set(float &data) {
    m_data.character = (char)(int)data;
    return 0;
}


int Char::Set(long double &data) {
    m_data.character = (char)(int)(float)data;
    return 0;
}


int Char::Set(unsigned char &data) {
    m_data.character = data;
    return 0;
}


int Char::Get(unsigned char &data) {
    data = m_data.character;
    return 0;
}

int Char::Add(Number &other) {
    m_data.character += (char)(int)(float)GetOtherNumber(other);
    return 0;
}

int Char::Subtract(Number &other) {
    m_data.character -= (char)(int)(float)GetOtherNumber(other);
    return 0;
}

int Char::Multiply(Number &other) {
    m_data.character *= (char)(int)(float)GetOtherNumber(other);
    return 0;
}

int Char::Divide(Number &other) {
    try {
        m_data.character /= (char)(int)(float)DivideByZeroGuard(other);
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

ChimeraObject* Char::Clone() {
    return new Char(m_data.character);
}

string Char::ToStr() {
    string to_str;
    to_str += m_data.character;
    return to_str;
}

unsigned char Char::ToChar() {
    return m_data.character;
}

int Char::ToInt() {
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