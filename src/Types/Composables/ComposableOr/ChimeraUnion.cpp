#include "ChimeraUnion.hpp"
#include <algorithm>

using namespace std;

//PRIVATE METHODS BELOW -------------------------------------------------------------------------------------------------------------------------------------------

bool ChimeraUnion::IsAllowableType(VAR_TYPES cur_type, vector<string> allowed_types) {
    bool is_allowed = false;

    if (cur_type == INT_DATA_TYPE) {
        is_allowed = find(allowed_types.begin(), allowed_types.end(), INT_TYPE_NAME) != allowed_types.end();
    }
    else if (cur_type == FLOAT_DATA_TYPE) {
        is_allowed = find(allowed_types.begin(), allowed_types.end(), FLOAT_TYPE_NAME) != allowed_types.end();
    }
    else if (cur_type == DOUBLE_DATA_TYPE) {
        is_allowed = find(allowed_types.begin(), allowed_types.end(), DOUBLE_TYPE_NAME) != allowed_types.end();
    }
    else if (cur_type == CHAR_DATA_TYPE) {
        is_allowed = find(allowed_types.begin(), allowed_types.end(), CHAR_TYPE_NAME) != allowed_types.end();
    }
    else if (cur_type == STRING_DATA_TYPE) {
        is_allowed = find(allowed_types.begin(), allowed_types.end(), STRING_TYPE_NAME) != allowed_types.end();
    }
    else if (cur_type == BOOL_DATA_TYPE) {
        is_allowed = find(allowed_types.begin(), allowed_types.end(), BOOL_TYPE_NAME) != allowed_types.end();
    }

    return is_allowed;
}

//PRIVATE METHODS ABOVE -------------------------------------------------------------------------------------------------------------------------------------------

//PUBLIC METHODS BELOW --------------------------------------------------------------------------------------------------------------------------------------------

ChimeraUnion::ChimeraUnion(vector<string> types, ChimeraObject *val) {

    SetType(UNDEFINED_DATA_TYPE);
    SetGeneralType(UNION_DATA_TYPE);

    for(int i = OBJECT_DATA_TYPE; i < UNDEFINED_DATA_TYPE; i++) {
        VAR_TYPES key = static_cast<VAR_TYPES>(i);
        m_allowable_types[key] = IsAllowableType(key, types);
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

int ChimeraUnion::Set(int64 &data) {
    return SetTo(INT_DATA_TYPE, INT_TYPE_NAME, data);
}

int ChimeraUnion::Set(float &data) {
    return SetTo(FLOAT_DATA_TYPE, FLOAT_TYPE_NAME, data);
}

int ChimeraUnion::Set(long double &data) {
    return SetTo(DOUBLE_DATA_TYPE, DOUBLE_TYPE_NAME, data);
}

int ChimeraUnion::Set(char32_t &data) {
    return SetTo(CHAR_DATA_TYPE, CHAR_TYPE_NAME, data);
}

int ChimeraUnion::Set(bool &data) {
    return SetTo(BOOL_DATA_TYPE, BOOL_TYPE_NAME, data);
}

int ChimeraUnion::Set(string &data) {
    return SetTo(STRING_DATA_TYPE, STRING_TYPE_NAME, data);
}

int ChimeraUnion::Get(int64 &data) {
    return GetFrom(data);
}

int ChimeraUnion::Get(float &data) {
    return GetFrom(data);
}

int ChimeraUnion::Get(long double &data) {
    return GetFrom(data);
}

int ChimeraUnion::Get(char32_t &data) {
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

int64 ChimeraUnion::ToInt() {
    if (m_var == nullptr) {
        return 0;
    }
    return m_var->ToInt();
}

float ChimeraUnion::ToFloat() {
    if (m_var == nullptr) {
        return 0;
    }
    return m_var->ToFloat();
}

long double ChimeraUnion::ToDouble() {
    if(m_var == nullptr) {
        return 0;
    }
    return m_var->ToDouble();
}

char32_t ChimeraUnion::ToChar() {
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
