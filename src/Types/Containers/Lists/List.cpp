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

int List::SetItem(int64 index, ChimeraObject *item)
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

ChimeraObject *List::GetItem(int64 index)
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
        int completed = SetItem((int64)i, new_list->GetItem((int64)i));
        if (completed == FAIL)
        {
            return FAIL;
        }
    }

    return SUCCEED;
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

int64 List::ToInt()
{
    int64 sum = 0;
    for (ChimeraObject *const &item : m_list)
    {
        sum += item->ToInt();
    }
    return sum;
}

float List::ToFloat()
{
    float sum = 0;
    for (ChimeraObject *const &item : m_list)
    {
        sum += item->ToFloat();
    }
    return sum;
}

dbl128 List::ToDouble()
{
    dbl128 sum = 0;
    for (ChimeraObject *const &item : m_list)
    {
        sum += item->ToDouble();
    }
    return sum;
}

char32_t List::ToChar()
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
