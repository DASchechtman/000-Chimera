#pragma once

#include <type_traits>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Ast.hpp"
#include "DataStructs/ScopeStack.hpp"
#include "DataStructs/ScopeTree.hpp"
#include "DataStructs/CircularList.hpp"
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
#include "InterpreterOpers/Math.hpp"
#include "InterpreterOpers/Boolean.hpp"
#include "InterpreterOpers/ContainerOpers.hpp"
#include "InterpreterOpers/CompareOper.hpp"

using namespace std;

/*
note: in the interpreter, if a string returning method returns an empty string. that means the string failed
*/

class ChmrInterpreter
{
private:
    ScopeStack scopes;
    vector<AstNode*> ast_trees;
    size_t cur_scope_level = 0;
    size_t cur_instruction = 0;
    vector<JumpInfo> jump_points;
    ScopeTree scope_tree; 
    stack<size_t> cur_stack_level;
    size_t cur_jump_point = 0;

    /* used to put a lot of boilerplate into one place for the assign/reassign actions */
    string MakeBind(string to, string from, string type);
    SymbolTable* Table();
    void ProcessCtrlStructure(AstNode *node);
    void ConvertJumpPointsToScopeTree();
    void GoTo(size_t jump_point);
    size_t ScopeLevel();
    void IncreaseScopeLevel();
    void DecreaseScopeLevel();
    string Bind(string to, string from, string type);
    string Rebind(string to, string from);
    string RefBind(string ref_id, string var_id, string type="");
    string MakeUnion(string var_id, vector<string> types, string var_id_2, bool unknown=false);
    string CloneVarToTempVar(string var_id);
    string CastVarTo(string var_id, string type);
    void GarbageCollect();
    void CreateScope(string scope_type);
    void DestroyScope();
    int PrintVar(string var_id, char end);
    string RunAst(AstNode* root);

    template <class T>
    string CreateTmpVar(T data);

    /* boilerplate for creating variable bindings */
    template <class T>
    string Create(string var_id, string type, T data);

    template <class T>
    string CloneOrCreateVar(string to, string type, T data);

public:

    void EatAst(AstNode* root);
    ~ChmrInterpreter();
};

// PRIVATE TEMPLATE METHODS BELOW ----------------------------------------------------------------------------------------------------------------------------------
template <class T>
string ChmrInterpreter::Create(string var_id, string type, T data)
{
    string new_var_name;
    SymbolTable *tbl = Table();

    if (type == INT_TYPE_NAME)
    {
        new_var_name = tbl->AddEntry(var_id, new Int());
    }
    else if (type == FLOAT_TYPE_NAME)
    {
        new_var_name = tbl->AddEntry(var_id, new Float());
    }
    else if (type == DOUBLE_TYPE_NAME)
    {
        new_var_name = tbl->AddEntry(var_id, new Double());
    }
    else if (type == CHAR_TYPE_NAME)
    {
        new_var_name = tbl->AddEntry(var_id, new Char());
    }
    else if (type == STRING_TYPE_NAME)
    {
        new_var_name = tbl->AddEntry(var_id, new String());
    }
    else if (type == BOOL_TYPE_NAME)
    {
        new_var_name = tbl->AddEntry(var_id, new Bool());
    }
    else {
        cout << "Error: cannot not make data of type " << type << '\n';
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *entry = tbl->GetEntry(new_var_name);

    if (new_var_name.empty() || entry->Set(data) == 1)
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

    return new_var_name;
};

template <class T>
string ChmrInterpreter::CloneOrCreateVar(string to, string type, T data)
{
    if (!Table()->Has(to))
    {
        return Create(to, type, data);
    }
    else
    {
        ChimeraObject *obj = Table()->GetEntry(to);
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
    if (is_same<T, int64>::value)
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