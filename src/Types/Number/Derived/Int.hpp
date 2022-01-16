#pragma once

#include "../Number.hpp"
#include <iostream>

using namespace std;

class Int : public Number {
private:
protected:
public:
    Int();
    Int(int data);
    ~Int();

    int Set(int64 &data);
    int Set(float &data);
    int Set(long double &data);
    int Set(char32_t &data);

    int Get(int64 &data);

    int Add(Number &other);
    int Subtract(Number &other);
    int Multiply(Number &other);
    int Divide(Number &other);
    int Pow(Number &other);

    string ToStr();
    char32_t ToChar();
    int64 ToInt();
    float ToFloat();
    long double ToDouble();
    bool ToBool();

    ChimeraObject* Clone();

};