#include "SymbolTable.hpp"
#include <iostream>
#include <vector>

using namespace std;

void SymbolTable::UpdateCurReg() {
    m_cur_reg = m_reg;
    m_reg++;
}

void SymbolTable::DecreaseRefCount(ChimeraObject *object) {
    m_ref_counter[object]--;
    if (m_ref_counter[object] == 0) {
        delete object;
    }
}

SymbolTable::SymbolTable() {}

SymbolTable::SymbolTable(const SymbolTable &old) {
    auto it = old.m_table.begin();
    m_ref_counter = old.m_ref_counter;

    while (it != old.m_table.end()) {
        AddOrUpdateRef(it->first, it->second.item);
        m_table[it->first].is_temp = it->second.is_temp;
        m_table[it->first].is_ref = it->second.is_ref;
        it++;
    }
}

SymbolTable::~SymbolTable() {
    auto it = m_table.begin();
    auto end = m_table.end();

    while (it != end) {
        DecreaseRefCount(it->second.item);
        it++;
    }
}

bool SymbolTable::Has(string var_id) {
    return !var_id.empty() && m_table.find(var_id) != m_table.end();
}

bool SymbolTable::IsTemp(string var_id) {
    if (!Has(var_id)) {
        return true;
    }
    return m_table[var_id].created_from.empty();
}

bool SymbolTable::IsRef(string var_id) {
    return Has(var_id) && m_table[var_id].is_ref;
}

void SymbolTable::SetParent(string var_id, string parent_id) {
    if (Has(var_id)) {
        m_table[var_id].created_from = parent_id;
    }
}

string SymbolTable::GetParent(string var_id) {
    if (!Has(var_id)) {
        return "";
    }
    return m_table[var_id].created_from;
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
        m_table[var_id].is_ref = false;
        m_ref_counter[object] = 1;
    }

    return var_id;
}

string SymbolTable::AddOrUpdateRef(string var_id, ChimeraObject *object) {

    if (Has(var_id) && !m_table[var_id].is_ref) {
        return EMPTY_VAR_NAME;
    }

    bool is_tmp = var_id.empty();
    if (is_tmp) {
        UpdateCurReg();
        var_id = to_string(m_cur_reg);
    }

    if (Has(var_id)) {
        m_ref_counter[m_table[var_id].item]--;
    }

    m_table[var_id].item = object;
    m_table[var_id].is_temp = is_tmp;
    m_table[var_id].is_ref = true;
    m_ref_counter[object]++;

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
        DecreaseRefCount(old);
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