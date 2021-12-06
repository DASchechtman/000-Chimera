#pragma once

#include <type_traits>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include "DataStructs/SymbolTable.hpp"
#include "DataStructs/Scope.hpp"
#include "DataStructs/ScopeStack.hpp"
#include "./ChmrInterpreter.hpp"
#include "Types/Number/Derived/Int.hpp"
#include "Types/Number/Derived/Float.hpp"
#include "Types/Number/Derived/Double.hpp"
#include "Types/Bool/Bool.hpp"
#include "Types/Text/Derived/String.hpp"
#include "Types/Number/Derived/Char.hpp"
#include "Types/Composables/ComposableOr/ChimeraUnion.hpp"
#include "Types/Containers/Lists/List.hpp"
#include "Types/Containers/Maps/Map.hpp"

using namespace std;

enum OPER_CODE {ADD_CODE, SUBTRACT_CODE, MULTIPLY_CODE, DIVIDE_CODE, POW_CODE};

/*
note: in the interpreter, if a string returning method returns an empty string. that means the string failed
*/

class ChmrInterpreter
{
private:
    ScopeStack scopes;

    /* used to put a lot of boilerplate into one place for the assign/reassign actions */
    string MakeBind(string to, string from, string type);
    /* used to put boilerplate code into one place for logical (and, or) opers */
    string DoLogicOper(string var_id_1, string var_id_2, bool (*oper)(bool, bool));

    /* used to put boilerplate code into one place for math operators */
    int DoMath(string var_id_1, string var_id_2, OPER_CODE code, int (*oper)(ChimeraObject *obj_1, ChimeraObject *obj_2, bool is_num));
    ChimeraObject* GetListItem(Container *list, ChimeraObject *index);
    int SetData(ChimeraObject *to, ChimeraObject *from);
    VAR_TYPES TypeNameToNum(string type_name);
    SymbolTable* Table();

    /* boilerplate for creating variable bindings */
    template <class T>
    string Create(string var_id, string type, T data);

    /* 
    used to create clone versions of already defined variables
    for example (print|x|). x will cloned to a temp var, and that temp var would be printed to screen
    */
    template <class T>
    string CloneOrCreate(string to, string type, T data);

public:

    bool NonRunnableScope();

    // methods used to create bindings to user variables 
    string Bind(string to, string from, string type);
    string Rebind(string to, string from);
    string RefBind(string ref_id, string var_id, string type="");

    string MakeUnion(string var_id, vector<string> types, string var_id_2, bool unknown=false);
    
    string MakeList(string var_id, string type);
    string MakeMap(string var_id, string key_type, string val_type);
    
    string PutInContainer(string list_id, string item_id);
    string PutInMap(string map_id, string key_id, string val_id);
    string GetFromContainer(string list_id, string index_id);
    string SetInContainer(string list_id, string index_id, string new_item_id);
    string ReassignContainer(string list_id_1, string list_id_2);

    // method used to make clones of user defined vars
    // so that if you do say (print|(+ x 1)|). the actual
    // value of 'x' won't be affected

    string CloneToTemp(string var_id);

    int Add(string var_id_1, string var_id_2);
    int Subtract(string var_id_1, string var_id_2);
    int Multiply(string var_id_1, string var_id_2);
    int Divide(string var_id_1, string var_id_2);
    int Pow(string base_id, string exp_id);
    
    string Cast(string var_id, string type);

    string And(string var_id_1, string var_id_2);
    string Or(string var_id_1, string var_id_2);
    string Not(string var_id);

    string Less(string var_id_1, string var_id_2);
    string LessEqual(string var_id_1, string var_id_2);
    string Greater(string var_id_1, string var_id_2);
    string GreaterEqual(string var_id_1, string var_id_2);
    string Equal(string var_id_1, string var_id_2);

    void GarbageCollect();
    void CreateScope();
    void DestroyScope();
    int SetNextScopeRunState(string expr_id);
    int PrintVar(string var_id, char end);

    template <class T>
    string CreateTmpVar(T data);
};

// PRIVATE TEMPLATE METHODS BELOW ----------------------------------------------------------------------------------------------------------------------------------
template <class T>
string ChmrInterpreter::Create(string var_id, string type, T data)
{
    string new_var_name;

    if (type == INT_TYPE_NAME)
    {
        new_var_name = Table()->AddEntry(var_id, new Int());
    }
    else if (type == FLOAT_TYPE_NAME)
    {
        new_var_name = Table()->AddEntry(var_id, new Float());
    }
    else if (type == DOUBLE_TYPE_NAME)
    {
        new_var_name = Table()->AddEntry(var_id, new Double());
    }
    else if (type == CHAR_TYPE_NAME)
    {
        new_var_name = Table()->AddEntry(var_id, new Char());
    }
    else if (type == STRING_TYPE_NAME)
    {
        new_var_name = Table()->AddEntry(var_id, new String());
    }
    else if (type == BOOL_TYPE_NAME)
    {
        new_var_name = Table()->AddEntry(var_id, new Bool());
    }

    T *new_data = new T(data);

    if (new_var_name.empty() || Table()->GetEntry(new_var_name)->Set(*new_data) == 1)
    {
        if (new_var_name.empty())
        {
            cout << "Error: created variable with unsupported type '" << type << "'\n";
        }
        else
        {
            // no error message here because if Set fails it will print something
            Table()->RemoveEntry(new_var_name);
        }
        new_var_name = EMPTY_VAR_NAME;
    }

    delete new_data;

    return new_var_name;
};

template <class T>
string ChmrInterpreter::CloneOrCreate(string to, string type, T data)
{
    if (!Table()->Has(to))
    {
        return Create(to, type, data);
    }
    else
    {
        auto obj = Table()->GetEntry(to);
        if (obj->GetTypeName() != type)
        {
            return EMPTY_VAR_NAME;
        }
        obj->Set(data);
        return to;
    }
};
// PRIVATE TEMPLATE METHODS ABOVE -----------------------------------------------------------------------------------------------------------------------

// PUBLIC TEMPLATE METHODS BELOW ------------------------------------------------------------------------------------------------------------------------

template <class T>
string ChmrInterpreter::CreateTmpVar(T data)
{
    if (NonRunnableScope()) {
        return PLACE_HOLDER_NAME;
    }
    else if (is_same<T, int64>::value)
    {
        return Create(EMPTY_VAR_NAME, INT_TYPE_NAME, data);
    }
    else if (is_same<T, float>::value)
    {
        return Create(EMPTY_VAR_NAME, FLOAT_TYPE_NAME, data);
    }
    else if (is_same<T, long double>::value)
    {
        return Create(EMPTY_VAR_NAME, DOUBLE_TYPE_NAME, data);
    }
    else if (is_same<T, char32_t>::value)
    {
        return Create(EMPTY_VAR_NAME, CHAR_TYPE_NAME, data);
    }
    else if (is_same<T, string>::value)
    {
        return Create(EMPTY_VAR_NAME, STRING_TYPE_NAME, data);
    }
    else if (is_same<T, bool>::value)
    {
        return Create(EMPTY_VAR_NAME, BOOL_TYPE_NAME, data);
    }
    else
    {
        cout << "Error: can not create unsupported type\n";
        return EMPTY_VAR_NAME;
    }
};

// PUBLIC TEMPLATE METHODS ABOVE ------------------------------------------------------------------------------------------------------------------------