#pragma once

#include "../Text.hpp"
#include <string>
#include <iostream>

using namespace std;

class String : public Text {
private:

    double Hash();

protected:

public:

    String(bool is_const = false);
    String(string data, bool is_const = false);
    ~String();

    int Set(string &data);
    int Set(chmr_char &data);

    int Get(string &data);

    int Add(Text &other);
    int Subtract(Text &other);

    ChimeraObject* Clone();
    string GetText();

    string   ToStr();
    chmr_char ToChar();
    chmr_int    ToInt();
    chmr_flt    ToFloat();
    chmr_dbl ToDouble();
    bool ToBool();

};