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
    int SetItem(int64 index, ChimeraObject *item);
    ChimeraObject* GetItem(int64 index);
    size_t Size();
    int SetToNewContainer(Container *new_container);

    string ToStr();
    int64 ToInt();
    float ToFloat();
    dbl128 ToDouble();
    char32_t ToChar();
    bool ToBool();
    ChimeraObject* Clone();

};