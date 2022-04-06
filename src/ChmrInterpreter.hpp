#pragma once

#include <type_traits>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <memory>
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
#include "Types/Functions/Funcs.hpp"
#include "InterpreterOpers/Math.hpp"
#include "InterpreterOpers/Boolean.hpp"
#include "InterpreterOpers/ContainerOpers.hpp"
#include "InterpreterOpers/CompareOper.hpp"
#include "Context.hpp"
#include "InterpreterOpers/FuncOpers.hpp"
#include "InterpreterOpers/StringOper.hpp"

using namespace std;

/*
note: in the interpreter, if a string returning method returns an empty string. that means the string failed
*/

#define NUM_O_CALLBACK END_SCOPE_CMD + 1

class ChmrInterpreter
{
private:
    vector<AstNode*> ast_trees;
    size_t cur_jump_point = 0;
    string (*callbacks[NUM_O_CALLBACK])(AstNode*, ChmrInterpreter*);
    bool will_mutate_source = false;
    ChmrFunc *cur_func_running = nullptr; 
    stack<Context> run_time_context;
    Context *base_context = nullptr;

    /* used to put a lot of boilerplate into one place for the assign/reassign actions */
    string MakeBind(string to, string from, string type);
    Memory& ProgramMem();
    void ProcessCtrlStructure(AstNode *node);
    void ConvertJumpPointsToScopeTree();
    void GoTo(size_t jump_point, bool adjust_val = true);
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
    string RunAst(shared_ptr<AstNode> &root);
    void RunCurInstruction(size_t end = 0, bool is_base_call = true);
    size_t &CurInstruction();
    ScopeTree &CurScopeTree();
    vector<JumpInfo> &CurJumpPoints();
    size_t &CurScopeLevel();
    stack<size_t> &ScopesRan();
    ScopeStack &CurScopes();

    void GenerateCallbacks();

    template <class T>
    string CreateTmpVar(T data);

    /* boilerplate for creating variable bindings */
    template <class T>
    string Create(string var_id, string type, T data);

    template <class T>
    string CloneOrCreateVar(string to, string type, T data);

public:

    void EatAst(AstNode* root);
    AstNode *MostRecentAst();
    ChmrInterpreter();
    ~ChmrInterpreter();
};

// PRIVATE TEMPLATE METHODS BELOW ----------------------------------------------------------------------------------------------------------------------------------
template <class T>
string ChmrInterpreter::Create(string var_id, string type, T data)
{
    string new_var_name = ProgramMem().CreateData(var_id, type);
    if (ProgramMem().InitData(data, var_id) == FAIL) {
        ChimeraObject *var = ProgramMem().GetData(ORIGINAL, new_var_name);
        cout << "Error: cannot create data of " << var->GetTypeName() << " with '" << type << "'" << endl;
        return EMPTY_VAR_NAME;
    }
    return new_var_name;
};

template <class T>
string ChmrInterpreter::CloneOrCreateVar(string to, string type, T data)
{
    string ret;
    if (!ProgramMem().HasData(to))
    {
        ret = Create(to, type, data);
    }
    else
    {
        ChimeraObject *obj = ProgramMem().GetData(ORIGINAL, to);
        if (obj->GetTypeName() != type)
        {
            return EMPTY_VAR_NAME;
        }
        obj->Set(data);
        ret = to;
    }
    return ret;
};
// PRIVATE TEMPLATE METHODS ABOVE -----------------------------------------------------------------------------------------------------------------------

// PUBLIC TEMPLATE METHODS BELOW ------------------------------------------------------------------------------------------------------------------------

template <class T>
string ChmrInterpreter::CreateTmpVar(T data)
{
    if (is_same<T, chmr_int>::value)
    {
        return Create(EMPTY_VAR_NAME, INT_TYPE_NAME, data);
    }
    else if (is_same<T, chmr_flt>::value)
    {
        return Create(EMPTY_VAR_NAME, FLOAT_TYPE_NAME, data);
    }
    else if (is_same<T, chmr_dbl>::value)
    {
        return Create(EMPTY_VAR_NAME, DOUBLE_TYPE_NAME, data);
    }
    else if (is_same<T, chmr_char>::value)
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