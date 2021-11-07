#pragma once

#include "../ChimeraObject.hpp"
#include <string>

using namespace std;

class Ref : public ChimeraObject {
private:
    ChimeraObject *m_ref_var = nullptr;

protected:

public:

    bool RebindRef(string parent_id, ChimeraObject *new_bind);
    
    int Set(int64 &data);
    int Set(float &data);
    int Set(dbl128 &data);
    int Set(char32_t &data);
    int Set(bool &data);
    int Set(string &data);

    int Get(int64 &data);
    int Get(float &data);
    int Get(dbl128 &data);
    int Get(char32_t &data);
    int Get(bool &data);
    int Get(string &data);

    string ToStr();
    int64 ToInt();
    float ToFloat();
    dbl128 ToDouble();
    char32_t ToChar();
    bool ToBool();

    ChimeraObject* Clone();

};