#pragma once

#include "../Number.hpp"


class Char : public Number {
private:
protected:
public:

    Char();
    Char(char data);

    int Set(int64 &data);
    int Set(float &data);
    int Set(long double &data);
    int Set(char32_t &data);

    int Get(char32_t &data);

    int Add(Number &other);
    int Subtract(Number &other);
    int Multiply(Number &other);
    int Divide(Number &other);

    ChimeraObject* Clone();

    string ToStr();
    char32_t ToChar();
    int64 ToInt();
    float ToFloat();
    long double ToDouble();
    bool ToBool();
};