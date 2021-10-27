#include "../Text.hpp"
#include <string>
#include <iostream>

using namespace std;

class String : public Text {
private:

    double Hash();

protected:

public:

    String();
    String(string data);
    ~String();

    int Set(string &data);
    int Set(unsigned char &data);

    int Get(string &data);

    int Add(Text &other);
    int Subtract(Text &other);

    ChimeraObject* Clone();
    string GetText();

    string ToStr();
    unsigned char ToChar();
    int ToInt();
    float ToFloat();
    long double ToDouble();
    bool ToBool();

};