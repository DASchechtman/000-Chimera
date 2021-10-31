#pragma once

#include "../ChimeraObject.hpp"


class Number : public ChimeraObject {
private:
protected:
public:

    long double GetOtherNumber(Number &other);
    long double DivideByZeroGuard(Number &other);

    virtual int Add(Number &other);
    virtual int Subtract(Number &other);
    virtual int Multiply(Number &other);
    virtual int Divide(Number &other);
};