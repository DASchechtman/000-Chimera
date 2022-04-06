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
    chmr_char ToChar();
    chmr_int ToInt();
    chmr_flt ToFloat();
    chmr_dbl ToDouble();
    bool ToBool();

    ChimeraObject* Clone();

};