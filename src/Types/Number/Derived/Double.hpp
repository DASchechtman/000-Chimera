#pragma once
#include "../Number.hpp"

class Double : public Number { 
private:
protected:
public:

    Double();
    Double(double data);

    int Set(chmr_int &data);
    int Set(chmr_flt &data);
    int Set(chmr_dbl &data);
    int Set(chmr_char &data);

    int Get(chmr_dbl &data);

    int Add(Number &other);
    int Subtract(Number &other);
    int Multiply(Number &other);
    int Divide(Number &other);
    int Pow(Number &other);

    ChimeraObject* Clone();

    string ToStr();
    chmr_char ToChar();
    chmr_int ToInt();
    chmr_flt ToFloat();
    chmr_dbl ToDouble();
    bool ToBool();
};