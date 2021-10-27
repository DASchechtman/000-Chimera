#include "../Number.hpp"
#include <iostream>

using namespace std;

class Float : public Number {
private:
protected:
public:

    Float();
    Float(float data);

    int Set(int &data);
    int Set(float &data);
    int Set(long double &data);
    int Set(unsigned char &data);

    int Get(float &data);

    int Add(Number &other);
    int Subtract(Number &other);
    int Multiply(Number &other);
    int Divide(Number &other);

    string ToStr();
    unsigned char ToChar();
    int ToInt();
    float ToFloat();
    long double ToDouble();
    bool ToBool();

    ChimeraObject* Clone();
};