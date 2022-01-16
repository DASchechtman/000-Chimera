#pragma once
#include "../ChimeraObject.hpp"

class Bool : public ChimeraObject {
private:
protected:
public:

    Bool();
    Bool(bool data);

    int Set(bool &data);
    int Get(bool &data);

    string ToStr();
    char32_t ToChar();
    int64 ToInt();
    float ToFloat();
    long double ToDouble();
    bool ToBool();

    ChimeraObject* Clone();

};