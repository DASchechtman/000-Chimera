#include "String.hpp"
#include <string.h>
#include <iostream>

using namespace std;

double String::Hash() {
    double sum = 0;
    for(unsigned int i = 0; i < m_data.str->length(); i++) {
        sum += m_data.str->at(i);
    }

    return sum;
}

String::String() {
    m_data.str = new string();
    SetType(STRING_DATA_TYPE);
}

String::String(string data) {
    m_data.str = new string(data);
    SetType(STRING_DATA_TYPE);
}

String::~String() {
    delete m_data.str;
}

int String::Set(string &data) {
    m_data.str->assign(data);
    return 0;
}

int String::Set(unsigned char &data) {
    char *c_str = new char[2];
    c_str[0] = data;
    c_str[1] = '\0';
    m_data.str->assign(c_str);
    delete[] c_str;
    return 0;
}

int String::Get(string &data) {
    data = *m_data.str;
    return 0;
}

int String::Add(Text &other) {
    m_data.str->append(other.GetText());
    return 0;
}

int String::Subtract(Text &other) {
    string other_text = other.GetText();
    size_t start = m_data.str->find(other_text);

    if (start != string::npos) {
        m_data.str->erase(start, other_text.length());
    }
    return 0;
}


ChimeraObject* String::Clone() {
   return new String(*m_data.str);
}

string String::GetText() {
    return *m_data.str;
}

string String::ToStr() {
    return *m_data.str;
}

unsigned char String::ToChar() {
    return m_data.str->at(0);
}

int String::ToInt() {
    int to_num = atoi(m_data.str->c_str());

    if (to_num == 0) {
        to_num = (int)Hash();
    }

    return to_num;
}

float String::ToFloat() {
    int to_float = atof(m_data.str->c_str());

    if (to_float == 0) {
        to_float = (float)Hash();
    }

    return to_float;
}

long double String::ToDouble() {
    long double to_double = strtod(m_data.str->c_str(), nullptr);

    if (to_double == 0) {
        to_double = Hash();
    }

    return to_double;
}

bool String::ToBool() {
    return !m_data.str->empty();
}