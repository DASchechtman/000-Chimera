#include "../Number.hpp"

class Double : public Number { 
private:
protected:
public:

    Double();
    Double(double data);

    int Set(int &data);
    int Set(float &data);
    int Set(long double &data);
    int Set(unsigned char &data);

    int Get(long double &data);

    int Add(Number &other);
    int Subtract(Number &other);
    int Multiply(Number &other);
    int Divide(Number &other);
    int Pow(Number &other);

    ChimeraObject* Clone();

    string ToStr();
    unsigned char ToChar();
    int ToInt();
    float ToFloat();
    long double ToDouble();
    bool ToBool();
};