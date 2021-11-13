#include "List.hpp"
#include <iostream>

using namespace std;

List::List(VAR_TYPES type) {
    m_list_type = type;
    SetType(type);
    m_list_type_name = GetTypeName();
    SetType(LIST_DATA_TYPE);
}

List::~List() {
    for(auto item : m_list) {
        delete item;
    }
}

int List::PutItem(ChimeraObject *item) {
    if(item->GetType() != m_list_type) {
        cout << "Error: cannot add '" << item->GetTypeName() << "' to list<" << m_list_type_name << ">\n";
        return FAIL;
    }
    m_list.push_back(item->Clone());
    return SUCCEED;
}

int List::SetItem(int64 index, ChimeraObject *item) {
    if(item->GetType() != m_list_type) {
        cout << "Error: cannot add '" << item->GetTypeName() << "' to list<" << m_list_type_name << ">\n";
        return FAIL;
    }
    else if (index < 0 || (size_t)index >= m_list.size()) {
        cout << "Error: index out of bounds\n";
        return FAIL;
    }

    delete m_list[index];
    m_list[index] = item->Clone();
    return SUCCEED;
}

ChimeraObject* List::GetItem(int64 index) {
    if (index < 0 || (size_t)index >= m_list.size()) {
        cout << "Error: index out of bounds\n";
        return nullptr;
    }
    return m_list[index];
}

size_t List::Size() {
    return m_list.size();
}

void List::SetToNewContainer(Container *new_list) {
    m_list.resize(new_list->Size());

    for(size_t i = 0; i < new_list->Size(); i++) {
        int completed = SetItem((int64)i, new_list->GetItem((int64)i));
        if (completed == FAIL) {
            break;
        }
    }

}

string List::ToStr() {
    string str_rep = "[";
    for(size_t i = 0; i < m_list.size(); i++) {
        str_rep += m_list[i]->ToStr();
        if (i != m_list.size() - 1) {
            str_rep += ", ";
        }
    }
    str_rep += "]";
    return str_rep;
}

int64 List::ToInt() {
    int64 sum = 0;
    for(auto const &item : m_list) {
        sum += item->ToInt();
    }
    return sum;
}

float List::ToFloat() {
    float sum = 0;
    for(auto const &item : m_list) {
        sum += item->ToFloat();
    }
    return sum;
}

dbl128 List::ToDouble() {
    dbl128 sum = 0;
    for(auto const &item : m_list) {
        sum += item->ToDouble();
    }
    return sum;
}

char32_t List::ToChar() {
    return m_list[0]->ToChar();
}

bool List::ToBool() {
    bool sum = true;
    for(auto const &item : m_list) {
        sum = sum && item->ToBool();
    }
    return sum;
}

ChimeraObject* List::Clone() {
    List *list = new List(m_list_type);
    for(auto item : m_list) {
        list->PutItem(item->Clone());
    }
    return list;
}
