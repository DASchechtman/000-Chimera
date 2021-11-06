#pragma once

#include "../ChimeraObject.hpp"

class Text : public ChimeraObject {
private:

protected:

public:

    Text();

    virtual int Add(Text &other);
    virtual int Subtract(Text &other); 

    virtual string GetText() = 0;
};