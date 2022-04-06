#pragma once

#include "../Number.hpp"
#include <iostream>

using namespace std;

class Int : public Number {
private:
    bool m_in_u_mode = false;
protected:
public:
    Int();
    Int(int data);
    ~Int();

    int Set(chmr_int &data);
    int Set(chmr_flt &data);
    int Set(chmr_dbl &data);
    int Set(chmr_char &data);

    int Get(chmr_int &data);

    int Add(Number &other);
    int Subtract(Number &other);
    int Multiply(Number &other);
    int Divide(Number &other);
    int Pow(Number &other);

    string ToStr();
    chmr_char ToChar();
    chmr_int ToInt();
    chmr_flt ToFloat();
    chmr_dbl ToDouble();
    bool ToBool();

    ChimeraObject* Clone();

};