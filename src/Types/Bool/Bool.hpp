#include "../ChimeraObject.hpp"

class Bool : public ChimeraObject {
private:
protected:
public:

    Bool();
    Bool(bool data);

    int Set(bool &data);
    int Get(bool &data);

    string ToStr();
    unsigned char ToChar();
    int ToInt();
    float ToFloat();
    long double ToDouble();
    bool ToBool();

    ChimeraObject* Clone();

};