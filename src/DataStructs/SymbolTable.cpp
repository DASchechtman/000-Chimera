#include "SymbolTable.hpp"
#include <iostream>
#include <vector>

using namespace std;

void SymbolTable::UpdateCurReg() {
    m_cur_reg = m_reg;
    m_reg++;
}

bool SymbolTable::DecreaseRefCount(ChimeraObject *object) {

    m_ref_counter[object]--;
    if (m_ref_counter[object] == 0) {
        delete object;
        m_ref_counter.erase(object);
        return true;
    }

    return false;
}

SymbolTable::SymbolTable() {}

SymbolTable::SymbolTable(SymbolTable *old) {
    CopyTable(old);
}

SymbolTable::~SymbolTable() {
    auto it = m_table.begin();
    auto end = m_table.end();

    while (it != end) {
        if (it->second.is_weak) { it++; continue; }
        DecreaseRefCount(it->second.item);
        it++;
    }
    m_is_being_copied = false;
}

bool SymbolTable::Has(string var_id) {
    return !var_id.empty() && m_table.find(var_id) != m_table.end();
}

bool SymbolTable::CameFromVar(string var_id) {
    if (!Has(var_id)) {
        return true;
    }
    return !m_table[var_id].created_from.empty() || !m_table[var_id].is_temp;
}

bool SymbolTable::IsRef(string var_id) {
    return Has(var_id) && m_table[var_id].is_ref;
}

void SymbolTable::SetParent(string var_id, string parent_id) {
    if (Has(var_id)) {
        m_table[var_id].created_from = parent_id;
    }
}

void SymbolTable::SetCopyStat(bool is_copying) {
    m_is_being_copied = is_copying;
}

string SymbolTable::GetParent(string var_id) {
    if (!Has(var_id)) {
        return "";
    }
    return m_table[var_id].created_from;
}


string SymbolTable::AddEntry(string var_id, ChimeraObject *object) {
    bool is_tmp = false;

    if (var_id.empty()) {
        UpdateCurReg();
        var_id = to_string(m_cur_reg);
        is_tmp = true;
    }

    while(is_tmp && Has(var_id)) {
        UpdateCurReg();
        var_id = to_string(m_cur_reg);
   }


    if (!Has(var_id)) {
        m_table[var_id].item = object;
        m_table[var_id].is_temp = is_tmp;
        m_table[var_id].is_ref = false;
        m_ref_counter[object] = 1;
    }

    return var_id;
}

string SymbolTable::AddOrUpdateRef(string var_id, ChimeraObject *object, bool is_weak_ref) {

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
    m_table[var_id].is_weak = is_weak_ref;

    if (!is_weak_ref) {
        m_ref_counter[object]++;
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
        if (DecreaseRefCount(old)) {
            m_table.erase(var_id);
        }
    }
}

void SymbolTable::FreeTempItems() {
    if (m_table.size() == 0) {
        return;
    }
    
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

void SymbolTable::CopyTable(SymbolTable *old, bool full_copy) {
    for(auto start = old->m_table.begin(); start != old->m_table.end(); start++) {
        if (start->second.is_temp && !full_copy) {
            continue;
        }

        TableItem item;
        item.item = start->second.item;
        item.is_temp = false;
        item.is_ref = false;
        item.created_from = start->second.created_from;
        
        m_table[start->first] = item;
    }

    for(auto start = m_table.begin(); start != m_table.end(); start++) {
        m_ref_counter[start->second.item] = old->m_ref_counter[start->second.item] + 1;
    }
}

string SymbolTable::KeyToString(int64 key) {
    char first_letter[] = {'z', 'o', 't', 'r', 'f', 'i', 's', 'e', 'g', 'n'};
    string str_key;

    while(key >= 10) {
        str_key += first_letter[abs(key%10)];
        key /= 10;
    }

    if (key > 0 || str_key.empty()) {
        str_key += first_letter[abs(key)];
    }

    return str_key + '!';
}