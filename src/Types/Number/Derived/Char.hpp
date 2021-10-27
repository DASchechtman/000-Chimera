#pragma once

#include "../Number.hpp"


class Char : public Number {
private:
protected:
public:

    Char();
    Char(char data);

    int Set(int &data);
    int Set(float &data);
    int Set(long double &data);
    int Set(unsigned char &data);

    int Get(unsigned char &data);

    int Add(Number &other);
    int Subtract(Number &other);
    int Multiply(Number &other);
    int Divide(Number &other);

    ChimeraObject* Clone();

    string ToStr();
    unsigned char ToChar();
    int ToInt();
    float ToFloat();
    long double ToDouble();
    bool ToBool();
};