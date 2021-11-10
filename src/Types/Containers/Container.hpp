#pragma once

#include "../ChimeraObject.hpp"
#include <string>

using namespace std;

class Container : public ChimeraObject {
private:

protected:

public:

    

    virtual int Set(int64 index, ChimeraObject *data);
    virtual int Set(float index, ChimeraObject *data);
    virtual int Set(dbl128 index, ChimeraObject *data);
    virtual int Set(char32_t index, ChimeraObject *data);
    virtual int Set(string index, ChimeraObject *data);
    virtual int Set(bool index, ChimeraObject *data);

    virtual ChimeraObject* Get(int64 index);
    virtual ChimeraObject* Get(float index);
    virtual ChimeraObject* Get(dbl128 index);
    virtual ChimeraObject* Get(char32_t index);
    virtual ChimeraObject* Get(string index);
    virtual ChimeraObject* Get(bool index);

};