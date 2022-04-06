#pragma once

#include "../Container.hpp"
#include <vector>
#include <type_traits>

using namespace std;

class List : public Container {
private:
    vector<ChimeraObject*> m_list;
    vector<VAR_TYPES> m_list_type;
    string m_list_type_name;

    bool IsCorrectType(VAR_TYPES type);
protected:
public:

    List();
    List(vector<VAR_TYPES> types);
    ~List();

    int PutItem(ChimeraObject *item);
    int SetItem(chmr_int index, ChimeraObject *item);
    ChimeraObject* GetItem(chmr_int index);
    size_t Size();
    int SetToNewContainer(Container *new_container);
    bool HasItem(ChimeraObject *item);
    int RemoveItem(ChimeraObject *item);

    string ToStr();
    chmr_int ToInt();
    chmr_flt ToFloat();
    chmr_dbl ToDouble();
    chmr_char ToChar();
    bool ToBool();
    ChimeraObject* Clone();

};