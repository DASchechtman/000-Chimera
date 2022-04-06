#include "List.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

List::List()
{
    SetType(LIST_DATA_TYPE);
}

List::List(vector<VAR_TYPES> types)
{
    int offset = BOOL_DATA_TYPE - LIST_DATA_TYPE;
    m_list_type.resize(offset + 1);


    for (size_t i = 0; i < m_list_type.size(); i++)
    {
        
        auto index = find(types.begin(), types.end(), LIST_DATA_TYPE + i);
        if (index != types.end())
        {
            auto var_type =  types[index - types.begin()];
            m_list_type[i] = types[var_type];

            SetType(m_list_type[i]);
            if (index != types.end() - 1)
            {
                m_list_type_name += VarTypeToStr(var_type);
                m_list_type_name.pop_back();
                m_list_type_name += " | ";
            }
            else
            {
                m_list_type_name += VarTypeToStr(var_type);
                m_list_type_name.pop_back();
            }
        }
        else
        {
            m_list_type[i] = UNDEFINED_DATA_TYPE;
        }
    }

    SetType(LIST_DATA_TYPE);
}

List::~List()
{
    for (ChimeraObject *item : m_list)
    {
        delete item;
    }
}

bool List::IsCorrectType(VAR_TYPES type)
{
    return m_list_type[type - LIST_DATA_TYPE] != UNDEFINED_DATA_TYPE;
}

int List::PutItem(ChimeraObject *item)
{
    m_list.push_back(item->Clone());
    return SUCCEED;
}

int List::SetItem(chmr_int index, ChimeraObject *item)
{
    if (index < 0 || (size_t)index >= m_list.size())
    {
        cout << "Error: index out of bounds\n";
        return FAIL;
    }

    delete m_list[index];
    m_list[index] = item->Clone();
    return SUCCEED;
}

ChimeraObject *List::GetItem(chmr_int index)
{
    if (index < 0 || (size_t)index >= m_list.size())
    {
        cout << "Error: index out of bounds\n";
        return nullptr;
    }
    return m_list[index];
}

size_t List::Size()
{
    return m_list.size();
}

int List::SetToNewContainer(Container *new_list)
{
    m_list.resize(new_list->Size());

    for (size_t i = 0; i < new_list->Size(); i++)
    {
        int completed = SetItem((chmr_int)i, new_list->GetItem((chmr_int)i));
        if (completed == FAIL)
        {
            return FAIL;
        }
    }

    return SUCCEED;
}

bool List::HasItem(ChimeraObject *item) {
    bool has = false;
    for (auto el : m_list) {
        has = el->GetType() == item->GetType() && el->ToStr() == item->ToStr();
        if (has) { break; }
    }
    return has;
}

int List::RemoveItem(ChimeraObject *item) {
    int removed = FAIL;
    for (size_t i = 0; i < m_list.size(); i++) {
        ChimeraObject *el = m_list[i];
        bool has = el->GetType() == item->GetType() && el->ToStr() == item->ToStr();
        
        if (has && removed == FAIL) {
            delete m_list[i];
            removed = SUCCEED;
        }

        if (removed == SUCCEED && i + 1 < m_list.size()) {
            m_list[i] = m_list[i+1];
        }
    }
    m_list.pop_back();
    return removed;
}

string List::ToStr()
{
    string str_rep = "[";
    for (size_t i = 0; i < m_list.size(); i++)
    {
        str_rep += m_list[i]->ToStr();
        if (i != m_list.size() - 1)
        {
            str_rep += ", ";
        }
    }
    str_rep += "]";
    return str_rep;
}

chmr_int List::ToInt()
{
    chmr_int sum = 0;
    for (ChimeraObject *const &item : m_list)
    {
        sum += item->ToInt();
    }
    return sum;
}

chmr_flt List::ToFloat()
{
    chmr_flt sum = 0;
    for (ChimeraObject *const &item : m_list)
    {
        sum += item->ToFloat();
    }
    return sum;
}

chmr_dbl List::ToDouble()
{
    chmr_dbl sum = 0;
    for (ChimeraObject *const &item : m_list)
    {
        sum += item->ToDouble();
    }
    return sum;
}

chmr_char List::ToChar()
{
    return m_list[0]->ToChar();
}

bool List::ToBool()
{
    return !m_list.empty();
}

ChimeraObject *List::Clone()
{
    List *list = new List();
    for (ChimeraObject *item : m_list)
    {
        list->PutItem(item);
    }
    return list;
}
