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
    virtual bool HasItem(ChimeraObject *item) = 0;
    virtual int RemoveItem(ChimeraObject *item) = 0;
    virtual int SetToNewContainer(Container *new_container) = 0;

    virtual int SetItem(chmr_int index, ChimeraObject *data);
    virtual int SetItem(chmr_flt index, ChimeraObject *data);
    virtual int SetItem(chmr_dbl index, ChimeraObject *data);
    virtual int SetItem(chmr_char index, ChimeraObject *data);
    virtual int SetItem(string index, ChimeraObject *data);
    virtual int SetItem(bool index, ChimeraObject *data);

    virtual ChimeraObject* GetItem(chmr_int index);
    virtual ChimeraObject* GetItem(chmr_flt index);
    virtual ChimeraObject* GetItem(chmr_dbl index);
    virtual ChimeraObject* GetItem(chmr_char index);
    virtual ChimeraObject* GetItem(string index);
    virtual ChimeraObject* GetItem(bool index);
};