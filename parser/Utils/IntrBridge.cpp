#include "IntrBridge.hpp"
#include <functional>
#include <iostream>

using namespace std;


// FILE ONLY FUNCTIONS BELOW -----------------------------------------------------------------------

/*
used to reuse a lot of the boilerplate code that is needed to perform an operation
this overload used to perform operations when given 2 arguments (an operation could revieve one or 2 arguments
because some operations like cast don't return a single value, but operate on multiple values and return a list)
note: if this function fails it will return an empty string
*/
string PerformOper(
    StrWrapper var_id_1,
    StrWrapper var_id_2,
    int (ChmrInterpreter::*oper)(string, string),
    ChmrInterpreter *i)
{
    // checks for if there was multiple return values given
    // and does the passed in operator on all the given values
    if (var_id_1.GetFinalResult().empty() && var_id_1.HasPendingData())
    {
        auto oper_cumulative = var_id_1[0];
        auto size = var_id_1.PendingDataSize();

        for (unsigned int index = 1; index < size; index++)
        {
            if ((i->*oper)(oper_cumulative, var_id_1[index]) == 1)
            {
                // failed to perform operation
                // no error massage because the oper will
                // print one when it fails
                return "";
            }
        }
        var_id_1 = oper_cumulative;
    }

    // note start: applies to code between here and 'note end'
    // performs operation on the extra data in var_id_2
    // because an expression can be composed of something
    // with multiple data given i.d. (+ "hello" (cast ' ' 5 string))
    // so is making sure that all the data is computed 

    if ((i->*oper)(var_id_1, var_id_2[0]) == 1)
    {
        // failed to perform operation
        // no error massage because the oper will
        // print one when it fails
        return "";
    }


    for (unsigned int index = 1; index < var_id_2.PendingDataSize(); index++)
    {
        if ((i->*oper)(var_id_1, var_id_2[index]) == 1)
        {
            // failed to perform operation
            // no error massage because the oper will
            // print one when it fails
            return "";
        }
    }

    // note end

    return var_id_1;
}

/*
used to reuse a lot of the boilerplate code that is needed to perform an operation
this overload used to perform operations when given 1 argument (an operation could revieve 1 or 2 arguments
because some operations like cast don't return a single value, but operate on multiple values and return a list)
note: if this function fails it will return an empty string
*/
string PerformOper(
    StrWrapper var_id,
    int (ChmrInterpreter::*oper)(string, string),
    ChmrInterpreter *i)
{
    // gaurd to ensure there is data to operate on
    if (!var_id.HasPendingData())
    {
        cout << "Error: cannot expand expression\n";
        return "";
    }

    string accumulate = var_id[0];
    for (unsigned int index = 1; index < var_id.PendingDataSize(); index++)
    {
        if ((i->*oper)(accumulate, var_id[index]) == 1)
        {
            // failed oper
            // no error message because the oper will print one on fail
            return "";
        };
    }

    return accumulate;
}

// FILE ONLY FUNCTIONS ABOVE -----------------------------------------------------------------------


// IMPORTABLE FUNCTIONS BELOW ----------------------------------------------------------------------

// assignment funcs ----------------------------------------------------------

string Assign(StrWrapper new_var, StrWrapper data_var, StrWrapper type, ChmrInterpreter &i)
{
    string data = data_var.GetFinalResult();

    if (data.empty() && data_var.HasPendingData()) {
        if (data_var.PendingDataSize() > 1) {
            cout << "Error: can only assign var to one value\n";
            return "";
        }
        data = data_var.GetPending(0);
    }
    return i.Bind(new_var, data, type);
}

string Reassign(StrWrapper var_name, StrWrapper data_var, ChmrInterpreter &i)
{
    string data = data_var.GetFinalResult();

    if (data.empty() && data_var.HasPendingData()) {
        if (data_var.PendingDataSize() > 1) {
            cout << "Error: can only reassign a var to one value\n";
            return "";
        }
        data = data_var.GetPending(0);
    }

    return i.Rebind(var_name, data);
}

// assignment funcs -----------------------------------------------------------

string CloneToTemp(StrWrapper id, ChmrInterpreter &i)
{
    return i.CloneToTemp(id);
}

int Print(StrWrapper var_id, char end, ChmrInterpreter &i)
{
    int err = 2;
    for(unsigned int index = 0; index < var_id.PendingDataSize(); index++) {
        err = i.PrintVar(var_id[index], end);
        if (err == 1) {
            break;
        }
    }
    return err;
}


// two arg opers ---------------------------------------------------------

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

// two arg opers ----------------------------------------------------------

// one arg opers ----------------------------------------------------------

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

// one arg opers ------------------------------------------------------------

// logical opers ------------------------------------------------------------

string And(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i) {
    return i.And(var_id_1, var_id_2);
}

string Or(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i) {
    return i.Or(var_id_1, var_id_2);
}

string Not(StrWrapper var_id_1, ChmrInterpreter &i) {
    return i.Not(var_id_1);
}

// logical opers ------------------------------------------------------------

// compare opers ------------------------------------------------------------

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

// compare opers ---------------------------------------------------------------------

/*
will cast one or more peices of data to a single type
note: when fails to perform operation on any of the peices of data
will return an empty string
*/
string Cast(StrWrapper &store, StrWrapper var_id, StrWrapper type, ChmrInterpreter &i)
{
    string casted_var_id;
    for (unsigned int index = 0; index < var_id.PendingDataSize(); index++)
    {
        casted_var_id = i.Cast(var_id[index], type);
        if (casted_var_id.empty())
        {
            // cast operation failed to be performed for some reason
            return "";
        }
        store.AddPending(casted_var_id);
    }
    return casted_var_id;
}

// IMPORTABLE FUNCTIONS ABOVE -----------------------------------------------------------------------