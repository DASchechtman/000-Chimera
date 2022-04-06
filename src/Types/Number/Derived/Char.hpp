#pragma once

#include "../Number.hpp"


class Char : public Number {
private:
protected:
public:

    Char();
    Char(char data);

    int Set(chmr_int &data);
    int Set(chmr_flt &data);
    int Set(chmr_dbl &data);
    int Set(chmr_char &data);

    int Get(chmr_char &data);

    int Add(Number &other);
    int Subtract(Number &other);
    int Multiply(Number &other);
    int Divide(Number &other);

    ChimeraObject* Clone();

    string ToStr();
    chmr_char ToChar();
    chmr_int ToInt();
    chmr_flt ToFloat();
    chmr_dbl ToDouble();
    bool ToBool();
};