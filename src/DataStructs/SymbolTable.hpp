#pragma once

#include <map>
#include <string>
#include <type_traits>
#include <cmath>
#include "../Types/ChimeraObject.hpp"
#include "../Types/Bool/Bool.hpp"
#include "../Types/Number/Derived/Char.hpp"
#include "../Types/Number/Derived/Double.hpp"
#include "../Types/Number/Derived/Float.hpp"
#include "../Types/Number/Derived/Int.hpp"
#include "../Types/Text/Derived/String.hpp"

using namespace std;

struct TableItem
{
    ChimeraObject *item;
    bool is_temp;
    bool is_ref;
    bool is_weak;
    string created_from;

    TableItem(){};

    TableItem(const TableItem &old)
    {
        item = old.item;
        is_temp = old.is_temp;
        is_ref = old.is_ref;
        created_from = old.created_from;
    }
};

const string REF_SIGNLE = "a-ref";

class SymbolTable
{
private:
    map<string, TableItem> m_table;
    map<ChimeraObject *, uint32_t> m_ref_counter;
    unsigned long long m_cur_reg = 0;
    unsigned long long m_reg = 0;
    bool m_is_being_copied = false;

    void UpdateCurReg();
    bool DecreaseRefCount(ChimeraObject *object);

    template<class T>
    string GetConstEntry(T data, false_type);

    template<class T>
    string GetConstEntry(T data, true_type);
    string KeyToString(int64 key);
    

protected:
public:
    SymbolTable();
    SymbolTable(SymbolTable *old);
    ~SymbolTable();

    bool Has(string var_id);
    bool CameFromVar(string var_id);
    bool IsRef(string var_id);
    void SetParent(string var_id, string parent_id);
    void SetCopyStat(bool is_copying);
    string GetParent(string var_id);
    string AddEntry(string var_id, ChimeraObject *object);
    string AddOrUpdateRef(string var_id, ChimeraObject *object, bool is_weak_ref = false);
    ChimeraObject *GetEntry(string var_id);
    void RemoveEntry(string var_id);
    void FreeTempItems();
    void CopyTable(SymbolTable *old, bool full_copy = false);

    template <class T>
    string GetConstEntry(T data);
};

template <class T>
string SymbolTable::GetConstEntry(T data)
{
    return GetConstEntry(data, is_same<T, string>());
}

template<class T>
string SymbolTable::GetConstEntry(T data, true_type) {
    string key = data.empty() ? "empty" : data + '!';

    if (!Has(key))
    {
        
        ChimeraObject *val = new String();
        val->Set(data);
        AddEntry(key, val);
    }

    return key;
}

template<class T>
string SymbolTable::GetConstEntry(T data, false_type) {
    
    string key;

    if (is_same<T, int64>::value)
    {
        key = KeyToString(data);
    }
    if (is_same<T, float>::value)
    {
        int64 before_dec = data;
        dbl128 dec = data - before_dec;

        while(fmod(dec, 1))
        {
            dec *= 10;
        }

        key = KeyToString(before_dec) + KeyToString(dec);
    }
    if (is_same<T, dbl128>::value)
    {
        int64 before_dec = data;
        dbl128 dec = data - before_dec;

        while(fmod(dec, 1))
        {
            dec *= 10;
        }

        key = KeyToString(before_dec) + KeyToString(dec);

    }
    if (is_same<T, char32_t>::value)
    {
        key = KeyToString(data);
    }
    if (is_same<T, bool>::value)
    {
        if (data == true)
        {
            key = "t";
        }
        else
        {
            key = "f";
        }
    }

    if (!Has(key))
    {
        ChimeraObject *val = nullptr;
        if (is_same<T, int64>::value)
        {
            val = new Int();
        }
        else if (is_same<T, float>::value)
        {
            val = new Float();
        }
        else if (is_same<T, dbl128>::value)
        {
            val = new Double();
        }
        else if (is_same<T, char32_t>::value)
        {
            val = new Char();
        }
        else if (is_same<T, bool>::value)
        {
            val = new Bool();
        }
        else if (is_same<T, string>::value)
        {
            val = new String();
        }

        val->Set(data);
        AddEntry(key, val);
    }

    return key;
}