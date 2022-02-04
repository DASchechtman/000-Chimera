#pragma once

#include "../ChimeraObject.hpp"
#include <string>
#include <vector>

using namespace std;

/*
base class for any type that is a collection of other, more primative types
*/

class Container : public ChimeraObject {
private:
    string set_err_msg = "Error: cannot create item with index type of '%s'\n";
    string get_err_msg = "Error: cannot access item with index type of '%s'\n";

protected:
    vector<vector<bool>> m_storable_types;

public:

    Container();

    virtual int PutItem(ChimeraObject *data);
    virtual size_t Size();
    virtual void SetToNewContainer(Container *new_container) = 0;

    virtual int SetItem(int64 index, ChimeraObject *data);
    virtual int SetItem(float index, ChimeraObject *data);
    virtual int SetItem(dbl128 index, ChimeraObject *data);
    virtual int SetItem(char32_t index, ChimeraObject *data);
    virtual int SetItem(string index, ChimeraObject *data);
    virtual int SetItem(bool index, ChimeraObject *data);

    virtual ChimeraObject* GetItem(int64 index);
    virtual ChimeraObject* GetItem(float index);
    virtual ChimeraObject* GetItem(dbl128 index);
    virtual ChimeraObject* GetItem(char32_t index);
    virtual ChimeraObject* GetItem(string index);
    virtual ChimeraObject* GetItem(bool index);
};