#pragma once

#include "../ChimeraObject.hpp"


class Number : public ChimeraObject {
private:
protected:
    chmr_dbl GetOtherNumber(Number &other);
    chmr_dbl DivideByZeroGuard(Number &other);

public:

    Number();

    chmr_dbl GetNumber();

    virtual int Add(Number &other);
    virtual int Subtract(Number &other);
    virtual int Multiply(Number &other);
    virtual int Divide(Number &other);
    virtual int Pow(Number &other);
};