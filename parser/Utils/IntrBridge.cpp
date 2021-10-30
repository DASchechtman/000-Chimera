#include "IntrBridge.hpp"
#include <functional>
#include <iostream>

using namespace std;

string PerformOper(
    StrWrapper var_id_1,
    StrWrapper var_id_2,
    int (ChmrInterpreter::*callback)(string, string),
    ChmrInterpreter *i)
{
    if (var_id_1.GetFinalResult().empty() && var_id_1.HasPendingData())
    {
        auto tmp = var_id_1[0];
        auto size = var_id_1.PendingDataSize();
        for (unsigned int index = 1; index < size; index++)
        {
            if ((i->*callback)(tmp, var_id_1[index]) == 1)
            {
                return "";
            }
        }
        var_id_1 = tmp;
    }

    if ((i->*callback)(var_id_1, var_id_2[0]) == 1)
    {
        return "";
    }

    for (unsigned int index = 1; index < var_id_2.PendingDataSize(); index++)
    {
        if ((i->*callback)(var_id_1, var_id_2[index]) == 1)
        {
            return "";
        }
    }

    while (var_id_1.HasPendingData())
    {
        var_id_1.RemoveFromPending(0);
    }

    return var_id_1;
}

string PerformOper(
    StrWrapper var_id,
    int (ChmrInterpreter::*callback)(string, string),
    ChmrInterpreter *i)
{
    if (!var_id.HasPendingData())
    {
        cout << "Error: cannot expand expression\n";
        return "";
    }

    string tmp = var_id[0];
    for (unsigned int index = 1; index < var_id.PendingDataSize(); index++)
    {
        if ((i->*callback)(tmp, var_id[index]) == 1)
        {
            return "";
        };
    }

    return tmp;
}

string Assign(string new_var, string data_var, string type, ChmrInterpreter &i)
{
    return i.Bind(new_var, data_var, type);
}

string Reassign(string var, string data_var, ChmrInterpreter &i)
{
    return i.Rebind(var, data_var);
}

string CloneToTemp(string id, ChmrInterpreter &i)
{
    return i.CloneToTemp(id);
}

int Print(string var_id, char end, ChmrInterpreter &i)
{
    return i.PrintVar(var_id, end);
}

string Add(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i)
{
    return PerformOper(var_id_1, var_id_2, &ChmrInterpreter::Add, &i);
}

string Subtract(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i)
{
    return PerformOper(var_id_1, var_id_2, &ChmrInterpreter::Subtract, &i);
}

string Multiply(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i)
{
    return PerformOper(var_id_1, var_id_2, &ChmrInterpreter::Multiply, &i);
}

string Divide(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i)
{
    return PerformOper(var_id_1, var_id_2, &ChmrInterpreter::Divide, &i);
}

string Add(StrWrapper var_id, ChmrInterpreter &i)
{
    return PerformOper(var_id, &ChmrInterpreter::Add, &i);
}

string Subtract(StrWrapper var_id, ChmrInterpreter &i)
{
    return PerformOper(var_id, &ChmrInterpreter::Subtract, &i);
}

string Multiply(StrWrapper var_id, ChmrInterpreter &i)
{
    return PerformOper(var_id, &ChmrInterpreter::Multiply, &i);
}

string Divide(StrWrapper var_id, ChmrInterpreter &i)
{
    return PerformOper(var_id, &ChmrInterpreter::Divide, &i);
}

string Cast(StrWrapper &store, StrWrapper var_id, string type, ChmrInterpreter &i)
{
    string tmp;
    for (unsigned int index = 0; index < var_id.PendingDataSize(); index++)
    {
        tmp = i.Cast(var_id[index], type);
        if (tmp.empty())
        {
            cout << "Error: during cast bridge " << index << '\n';
            return "";
        }
        store.AddPending(tmp);
    }
    return tmp;
}

string And(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i) {
    return i.And(var_id_1, var_id_2);
}

string Or(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i) {
    return i.Or(var_id_1, var_id_2);
}

string Not(StrWrapper var_id_1, ChmrInterpreter &i) {
    return i.Not(var_id_1);
}

string Less(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i) {
    return i.Less(var_id_1, var_id_2);
}

string LessEqual(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i) {
    return i.LessEqual(var_id_1, var_id_2);
}

string Greater(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i) {
    return i.Greater(var_id_1, var_id_2);
}

string GreaterEqual(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i) {
    return i.GreaterEqual(var_id_1, var_id_2);
}

string Equal(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i) {
    return i.Equal(var_id_1, var_id_2);
}

string NotEqual(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i) {
    string res_var_name = i.Equal(var_id_1, var_id_2);
    if (res_var_name.empty()) {
        return "";
    }
    return i.Not(res_var_name);
}