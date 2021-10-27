#pragma once

#include <type_traits>
#include <string>
#include "DataStructs/SymbolTable.hpp"
#include <iostream>
#include "./ChmrInterpreter.hpp"
#include "Types/Number/Derived/Int.hpp"
#include "Types/Number/Derived/Float.hpp"
#include "Types/Number/Derived/Double.hpp"
#include "Types/Bool/Bool.hpp"
#include "Types/Text/Derived/String.hpp"
#include "Types/Number/Derived/Char.hpp"

using namespace std;

class ChmrInterpreter
{
private:   

    SymbolTable m_table;

    string MakeBind(string to, string from, string type);
    string DoLogicOper(string var_id_1, string var_id_2, bool(*oper)(bool, bool));
    int DoMath(string var_id_1, string var_id_2, int (*oper)(ChimeraObject* obj_1, ChimeraObject* obj_2));

    template <class T>
    string Create(string var_id, string type, T data)
    {
        string save_name;

        if (type == INT_TYPE)
        {
            save_name = m_table.AddEntry(var_id, new Int());
        }
        else if (type == FLOAT_TYPE)
        {
            save_name = m_table.AddEntry(var_id, new Float());
        }
        else if (type == DOUBLE_TYPE)
        {
            save_name = m_table.AddEntry(var_id, new Double());
        }
        else if (type == CHAR_TYPE)
        {
            save_name = m_table.AddEntry(var_id, new Char());
        }
        else if (type == STRING_TYPE)
        {
            save_name = m_table.AddEntry(var_id, new String());
        }
        else if (type == BOOL_TYPE)
        {
            save_name = m_table.AddEntry(var_id, new Bool());
        }

        T tmp = data;
        if (save_name.empty() || m_table.GetEntry(save_name)->Set(tmp) == 1) {
            if (save_name.empty()) {
                cout << "didnt provide name\n";
            }
            else {
                m_table.RemoveEntry(save_name);
            }
            save_name = "";
        }

        return save_name;
    };

    template<class T>
    string CloneOrCreate(string to, string type, T data) {
        if (to.empty()) {
            return "";
        }

        if (!m_table.Has(to)) {
            return Create(to, type, data);
        }
        else {
            auto obj = m_table.GetEntry(to);
            if (obj->GetTypeName() != type) {
                return "";
            }
            obj->Set(data);
            return to;
        }
    }

public:

    string Bind(string to, string from, string type);
    string Rebind(string to, string from);
    string CloneToTemp(string var_id);

    int Add(string var_id_1, string var_id_2);
    int Subtract(string var_id_1, string var_id_2);
    int Multiply(string var_id_1, string var_id_2);
    int Divide(string var_id_1, string var_id_2);
    int Pow(string base_id, string exp_id);
    string Cast(string var_id, string type);
    
    void GarbageCollect();
    bool HasVar(string var_id);
    int PrintVar(string var_id, char end);

    string And(string var_id_1, string var_id_2);
    string Or(string var_id_1, string var_id_2);
    string Not(string var_id);

    string Less(string var_id_1, string var_id_2);
    string LessEqual(string var_id_1, string var_id_2);
    string Greater(string var_id_1, string var_id_2);
    string GreaterEqual(string var_id_1, string var_id_2);
    string Equal(string var_id_1, string var_id_2);


    template <class T>
    string CreateTmpVar(T data)
    {
        if (is_same<T, int>::value)
        {
            return Create("", INT_TYPE, data);
        }
        else if (is_same<T, float>::value)
        {
            return Create("", FLOAT_TYPE, data);
        }
        else if (is_same<T, long double>::value)
        {
            return Create("", DOUBLE_TYPE, data);
        }
        else if (is_same<T, unsigned char>::value)
        {
            return Create("", CHAR_TYPE, data);
        }
        else if (is_same<T, string>::value)
        {
            return Create("", STRING_TYPE, data);
        }
        else if (is_same<T, bool>::value)
        {
            return Create("", BOOL_TYPE, data);
        }
        else
        {
            cout << "Error: can not create unsupported type\n";
            return "";
        }
    };
};