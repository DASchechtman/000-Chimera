#include "SymbolTable.hpp"
#include <iostream>
#include <vector>

using namespace std;

void SymbolTable::UpdateCurReg() {
    m_cur_reg = m_reg;
    m_reg++;
}

SymbolTable::SymbolTable() {}

SymbolTable::SymbolTable(const SymbolTable &old) {
    auto it = old.m_table.begin();

    while (it != old.m_table.end()) {
        m_table[it->first].item = it->second.item->Clone();
        m_table[it->first].is_temp = it->second.is_temp;
        it++;
    }
}

SymbolTable::~SymbolTable() {
    auto it = m_table.begin();

    while (it != m_table.end()) {
        delete it->second.item;
        it++;
    }
}

bool SymbolTable::Has(string var_id) {
    return !var_id.empty() && m_table.find(var_id) != m_table.end();
}


string SymbolTable::AddEntry(string var_id, ChimeraObject *object) {
    bool is_tmp = false;


    if (var_id.length() == 0) {
        UpdateCurReg();
        var_id = to_string(m_cur_reg).c_str();
        is_tmp = true;
    }


    if (!Has(var_id)) {
        m_table[var_id].item = object;
        m_table[var_id].is_temp = is_tmp;
    }

    return var_id;
}

ChimeraObject* SymbolTable::GetEntry(string var_id) {
    ChimeraObject *obj = nullptr;
    if (Has(var_id)) {
        obj = m_table[var_id].item;
    }

    return obj;
}

void SymbolTable::RemoveEntry(string var_id) {
    if (Has(var_id)) {
        ChimeraObject *old = m_table[var_id].item;
        m_table.erase(var_id);
        delete old;
    }
}

void SymbolTable::FreeTempItems() {
    auto it = m_table.begin();
    vector<string> item_names;

    while(it != m_table.end()) {
        if (it->second.is_temp) {
            item_names.push_back(it->first);
        }
        it++;
    }

    for (const string &name : item_names) {
        RemoveEntry(name);
    }
}