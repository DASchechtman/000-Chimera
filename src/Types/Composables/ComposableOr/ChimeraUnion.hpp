#pragma once

#include "../../ChimeraObject.hpp"
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class ChimeraUnion : public ChimeraObject {
private:
    map<VAR_TYPES, bool> m_allowable_types;
    vector<string> m_type_list;
    ChimeraObject *m_var = nullptr;

    bool IsAllowableType(VAR_TYPES cur_type, vector<string> allowed_types);

    template<class T>
    int SetTo(VAR_TYPES type, string type_name, T& data);
    
    template<class T>
    int GetFrom(T &data);

public:
    ChimeraUnion(vector<string> types, ChimeraObject *val);
    ~ChimeraUnion();


    ChimeraObject* GetObj();
    VAR_TYPES GetType();
    string GetTypeName();

    int Set(chmr_int &data);
    int Set(chmr_flt &data);
    int Set(chmr_dbl &data);
    int Set(chmr_char &data);
    int Set(bool &data);
    int Set(string &data);
    int Set(ChimeraObject *data);

    int Get(chmr_int &data);
    int Get(chmr_flt &data);
    int Get(chmr_dbl &data);
    int Get(chmr_char &data);
    int Get(bool &data);
    int Get(string &data);

    string ToStr();
    chmr_int ToInt();
    chmr_flt ToFloat();
    chmr_dbl ToDouble();
    chmr_char ToChar();
    bool ToBool();

    ChimeraObject* Clone();
};

template<class T>
int ChimeraUnion::SetTo(VAR_TYPES type, string type_name, T &data) {
    if (m_var == nullptr) {
        cout << "Error: composable type holds no data\n";
        return FAIL;
    }

    bool has_type = m_allowable_types.find(type) != m_allowable_types.end();
    bool can_cast = false;

    if (has_type) {
        can_cast = m_allowable_types[type];
    }

    if(has_type && can_cast) {
        if (m_var->GetType() != type) {
            SetType(type);
            ChimeraObject* new_type = m_var->ConvertTo(type_name);
            delete m_var;
            m_var = new_type;
        }
    }
    else {
        cout << "Error: attempt to set union to non-allowable type '" << type_name << endl;
        return FAIL;
    }

    return m_var->Set(data);
}

template<class T>
int ChimeraUnion::GetFrom(T &data) {
    if (m_var == nullptr) {
        cout << "Error: composable type holds no data\n";
        return FAIL;
    }

    return m_var->Get(data);
}