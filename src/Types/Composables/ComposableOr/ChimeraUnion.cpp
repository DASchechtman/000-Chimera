#include "ChimeraUnion.hpp"
#include <algorithm>

using namespace std;

//PRIVATE METHODS BELOW -------------------------------------------------------------------------------------------------------------------------------------------

bool ChimeraUnion::IsAllowable(VAR_TYPES key, vector<string> value) {
    bool is_allowed = false;

    if (key == INT_DATA_TYPE) {
        is_allowed = find(value.begin(), value.end(), INT_TYPE_NAME) != value.end();
    }
    else if (key == FLOAT_DATA_TYPE) {
        is_allowed = find(value.begin(), value.end(), FLOAT_TYPE_NAME) != value.end();
    }
    else if (key == DOUBLE_DATA_TYPE) {
        is_allowed = find(value.begin(), value.end(), DOUBLE_TYPE_NAME) != value.end();
    }
    else if (key == CHAR_DATA_TYPE) {
        is_allowed = find(value.begin(), value.end(), CHAR_TYPE_NAME) != value.end();
    }
    else if (key == STRING_DATA_TYPE) {
        is_allowed = find(value.begin(), value.end(), STRING_TYPE_NAME) != value.end();
    }
    else if (key == BOOL_DATA_TYPE) {
        is_allowed = find(value.begin(), value.end(), BOOL_TYPE_NAME) != value.end();
    }

    return is_allowed;
}

//PRIVATE METHODS ABOVE -------------------------------------------------------------------------------------------------------------------------------------------

//PUBLIC METHODS BELOW --------------------------------------------------------------------------------------------------------------------------------------------

ChimeraUnion::ChimeraUnion(vector<string> types, ChimeraObject *val) {

    SetType(UNDEFINED_DATA_TYPE);

    for(int i = OBJECT_DATA_TYPE; i < UNDEFINED_DATA_TYPE; i++) {
        VAR_TYPES key = static_cast<VAR_TYPES>(i);
        m_allowable_types[key] = IsAllowable(key, types);
        if (m_allowable_types[key] && val->GetType() == key && m_var == nullptr) {
            SetType(key);
            m_var = val->Clone();
        }
    }

    m_type_list = types;
}

ChimeraUnion::~ChimeraUnion() {
    if (m_var != nullptr) {
        delete m_var;
    }
}

int ChimeraUnion::Set(int &data) {
    return SetTo(INT_DATA_TYPE, INT_TYPE_NAME, data);
}

int ChimeraUnion::Set(float &data) {
    return SetTo(FLOAT_DATA_TYPE, FLOAT_TYPE_NAME, data);
}

int ChimeraUnion::Set(long double &data) {
    return SetTo(DOUBLE_DATA_TYPE, DOUBLE_TYPE_NAME, data);
}

int ChimeraUnion::Set(unsigned char &data) {
    return SetTo(CHAR_DATA_TYPE, CHAR_TYPE_NAME, data);
}

int ChimeraUnion::Set(bool &data) {
    return SetTo(BOOL_DATA_TYPE, BOOL_TYPE_NAME, data);
}

int ChimeraUnion::Set(string &data) {
    return SetTo(STRING_DATA_TYPE, STRING_TYPE_NAME, data);
}

int ChimeraUnion::Get(int &data) {
    return GetFrom(data);
}

int ChimeraUnion::Get(float &data) {
    return GetFrom(data);
}

int ChimeraUnion::Get(long double &data) {
    return GetFrom(data);
}

int ChimeraUnion::Get(unsigned char &data) {
    return GetFrom(data);
}

int ChimeraUnion::Get(bool &data) {
    return GetFrom(data);
}

int ChimeraUnion::Get(string &data) {
    return GetFrom(data);
}

string ChimeraUnion::ToStr() {
    if (m_var == nullptr) {
        return "";
    }
    return m_var->ToStr();
}

int ChimeraUnion::ToInt() {
    if (m_var == nullptr) {
        return SUCCEED;
    }
    return m_var->ToInt();
}

float ChimeraUnion::ToFloat() {
    if (m_var == nullptr) {
        return SUCCEED;
    }
    return m_var->ToFloat();
}

long double ChimeraUnion::ToDouble() {
    if(m_var == nullptr) {
        return SUCCEED;
    }
    return m_var->ToDouble();
}

unsigned char ChimeraUnion::ToChar() {
    if (m_var == nullptr) {
        return '\0';
    }
    return m_var->ToChar();
}

bool ChimeraUnion::ToBool() {
    return m_var != nullptr && m_var->ToBool();
}

ChimeraObject* ChimeraUnion::Clone() {
    return new ChimeraUnion(m_type_list, m_var);
}

//PUBLIC METHODS ABOVE --------------------------------------------------------------------------------------------------------------------------------------------
