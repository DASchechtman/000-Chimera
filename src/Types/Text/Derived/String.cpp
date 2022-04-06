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

String::String(bool is_const) {
    m_data.str = new string();
    SetType(STRING_DATA_TYPE);
    this->is_const = is_const;
}

String::String(string data, bool is_const) {
    m_data.str = new string(data);
    SetType(STRING_DATA_TYPE);
    this->is_const = is_const;
}

String::~String() {
    delete m_data.str;
}

int String::Set(string &data) {
    if (is_const) {
        return SUCCEED;
    }
    m_data.str->assign(data);
    return SUCCEED;
}

int String::Set(chmr_char &data) {
    if (is_const) {
        return SUCCEED;
    }

    char *c_str = new char[2];
    c_str[0] = data;
    c_str[1] = '\0';
    m_data.str->assign(c_str);
    delete[] c_str;
    return SUCCEED;
}

int String::Get(string &data) {
    data = *m_data.str;
    return SUCCEED;
}

int String::Add(Text &other) {
    if (is_const) {
        return SUCCEED;
    }
    m_data.str->append(other.GetText());
    return SUCCEED;
}

int String::Subtract(Text &other) {
    string other_text = other.GetText();
    size_t start = m_data.str->find(other_text);

    if (start != string::npos) {
        m_data.str->erase(start, other_text.length());
    }
    return SUCCEED;
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

chmr_char String::ToChar() {
    return m_data.str->at(0);
}

chmr_int String::ToInt() {
    int to_num = atoi(m_data.str->c_str());

    if (to_num == 0) {
        to_num = (chmr_int)Hash();
    }

    return to_num;
}

chmr_flt String::ToFloat() {
    int to_float = atof(m_data.str->c_str());

    if (to_float == 0) {
        to_float = (chmr_flt)Hash();
    }

    return to_float;
}

chmr_dbl String::ToDouble() {
    chmr_dbl to_double = strtod(m_data.str->c_str(), nullptr);

    if (to_double == 0) {
        to_double = Hash();
    }

    return to_double;
}

bool String::ToBool() {
    return !m_data.str->empty();
}