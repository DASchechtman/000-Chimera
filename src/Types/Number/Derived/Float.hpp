#include "../Number.hpp"
#include <iostream>

using namespace std;

class Float : public Number {
private:
protected:
public:

    Float();
    Float(float data);

    int Set(long long &data);
    int Set(float &data);
    int Set(long double &data);
    int Set(char32_t &data);

    int Get(float &data);

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