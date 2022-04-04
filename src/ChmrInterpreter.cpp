#include "ChmrInterpreter.hpp"
#include "Types/Number/Number.hpp"
#include "Types/Text/Text.hpp"
#include <iostream>
#include <math.h>

using namespace std;

// PRIVATE METHODS BELOW ---------------------------------------------------------------------------

void FillEmptyStack(stack<Context> &context_stack)
{
    if (context_stack.size() == 0)
    {
        context_stack.push(Context(0, "base", nullptr));
    }
}

ChmrInterpreter::ChmrInterpreter()
{
    run_time_context.push(Context(0, "base", nullptr));
    base_context = &run_time_context.top();
    GenerateCallbacks();
}

ChmrInterpreter::~ChmrInterpreter()
{
    struct deleted
    {
        bool yes = false;
    };
    map<AstNode *, deleted> was_deleted;

    for (AstNode *node : ast_trees)
    {
        delete node;
    }
}

string ChmrInterpreter::MakeBind(string to, string from, string type)
{
    ChimeraObject *obj = ProgramMem().GetData(ORIGINAL, from);
    if (obj == nullptr)
    {
        cout << "Error: can't bind data to nonexistant symbol\n";
        return EMPTY_VAR_NAME;
    }

    string var_id = EMPTY_VAR_NAME;

    switch (obj->GetType())
    {
    case INT_DATA_TYPE:
    {
        int64 data = 0;
        obj->Get(data);
        var_id = CloneOrCreateVar(to, type, data);
        break;
    }
    case FLOAT_DATA_TYPE:
    {
        float data = 0;
        obj->Get(data);
        var_id = CloneOrCreateVar(to, type, data);
        break;
    }
    case DOUBLE_DATA_TYPE:
    {
        long double data = 0;
        obj->Get(data);
        var_id = CloneOrCreateVar(to, type, data);
        break;
    }
    case CHAR_DATA_TYPE:
    {
        char32_t data = 'a';
        obj->Get(data);
        var_id = CloneOrCreateVar(to, type, data);
        break;
    }
    case STRING_DATA_TYPE:
    {
        string data;
        obj->Get(data);
        var_id = CloneOrCreateVar(to, type, data);
        break;
    }
    case BOOL_DATA_TYPE:
    {
        bool data = false;
        obj->Get(data);
        var_id = CloneOrCreateVar(to, type, data);
        break;
    }
    case LIST_DATA_TYPE:
    {
        if (type != LIST_TYPE_NAME)
        {
            cout << "Error: cannot assign '" << type << "' to list\n";
            var_id = EMPTY_VAR_NAME;
            break;
        }

        ChimeraObject *container = ProgramMem().GetData(ORIGINAL, to);
        if (container == nullptr)
        {
            ProgramMem().CreateData(to, LIST_DATA_TYPE);
        }

        container = ProgramMem().GetData(ORIGINAL, to);
        ((List*)container)->SetToNewContainer((List*)obj);

        var_id = to;

        break;
    }
    case MAP_DATA_TYPE:
    {
        if (type != MAP_TYPE_NAME)
        {
            cout << "Error: cannot assign '" << type << "' to map\n";
            var_id = EMPTY_VAR_NAME;
            break;
        }

        ChimeraObject *container = ProgramMem().GetData(ORIGINAL, to);
        if (container == nullptr)
        {
            ProgramMem().CreateData(to, MAP_DATA_TYPE);
        }
        
        Map *map_obj = (Map *)ProgramMem().GetData(ORIGINAL, to);
        map_obj->SetToNewContainer((Container *)obj);
        
        break;
    }
    default:
    {
        cout << "Error: cannot create var of type " << type << endl;
    }
    }

    return var_id;
}

Memory& ChmrInterpreter::ProgramMem()
{
    return CurScopes().GetMemory();
}

void ChmrInterpreter::GoTo(size_t jump_point, bool adjust_val)
{
    for (size_t i = 0; i < CurJumpPoints().size(); i++)
    {
        if (CurJumpPoints()[i].jump_point == jump_point)
        {
            cur_jump_point = i;
            break;
        }
    }
    CurInstruction() = jump_point - adjust_val;
}

size_t ChmrInterpreter::ScopeLevel()
{
    return CurScopeLevel();
}

void ChmrInterpreter::IncreaseScopeLevel()
{
    CurScopeLevel()++;
}

void ChmrInterpreter::DecreaseScopeLevel()
{
    CurScopeLevel()--;
}

void ChmrInterpreter::ProcessCtrlStructure(AstNode *node)
{
    if (node->Type() == CTRL_BLOCK_CMD && CurScopeLevel() != SIZE_MAX)
    {
        bool is_start = (node->GetFromLeftNodes()->Type() == IF_BLOCK_CMD || node->GetFromLeftNodes()->Type() == WHILE_BLOCK_CMD);
        CurScopeLevel() = CurScopeLevel() + is_start;

        JumpInfo ji;
        ji.jump_point = CurInstruction();
        ji.depth = CurScopeLevel();

        CurJumpPoints().push_back(ji);
    }
    else if (node->Type() == FUNC_END_CMD && CurScopeLevel() == SIZE_MAX)
    {
        CurScopeLevel() = 0;
    }
    else if (node->Type() == MAKE_FUNC_CMD)
    {
        CurScopeLevel() = SIZE_MAX;
    }
    else if (node->Type() == END_BLOCK_CMD && CurScopeLevel() != SIZE_MAX)
    {
        JumpInfo ji;
        ji.jump_point = CurInstruction();
        ji.depth = CurScopeLevel();

        CurJumpPoints().push_back(ji);
        CurScopeLevel() = ji.depth - 1;
    }
}

void ChmrInterpreter::ConvertJumpPointsToScopeTree()
{
    for (JumpInfo point : CurJumpPoints())
    {
        AstNode *point_type = ast_trees[point.jump_point];

        if (point_type->Type() == CTRL_BLOCK_CMD)
        {
            if (
                point_type->GetFromLeftNodes()->Type() == IF_BLOCK_CMD || point_type->GetFromLeftNodes()->Type() == WHILE_BLOCK_CMD)
            {
                bool is_if_stmt_outside_other_scopes = (point_type->GetFromLeftNodes()->Type() == IF_BLOCK_CMD && CurScopeTree().Size() == 0);

                CurScopeTree().CreateNewBlock(is_if_stmt_outside_other_scopes);
                CurScopeTree().AddJpToBlock(point.jump_point);
            }
            else if (
                point_type->GetFromLeftNodes()->Type() == ELIF_BLOCK_CMD || point_type->GetFromLeftNodes()->Type() == ELSE_BLOCK_CMD)
            {
                CurScopeTree().AddJpToBlock(point.jump_point);
                CurScopeTree().CloseBlock();
                CurScopeTree().CreateNewBlock(true);
                CurScopeTree().AddJpToBlock(point.jump_point);
            }
        }
        else if (point_type->Type() == END_BLOCK_CMD)
        {
            CurScopeTree().AddJpToBlock(point.jump_point);
            CurScopeTree().CloseBlock();
        }
    }
}

// PRIVATE METHODS ABOVE ---------------------------------------------------------------------------

// PROTECTED METHODS BELOW -------------------------------------------------------------------------
// PROTECTED METHODS ABOVE -------------------------------------------------------------------------

// PUBLIC METHODS BELOW -----------------------------------------------------------------------------

string ChmrInterpreter::Bind(string to, string from, string type)
{
    if (ProgramMem().HasDataInLocalScope(to))
    {
        cout << "Error: var " << to << " already exists\n";
        return EMPTY_VAR_NAME;
    }
    else
    {
        return MakeBind(to, from, type);
    }
}

string ChmrInterpreter::Rebind(string to, string from)
{
    ChimeraObject *dest = ProgramMem().GetData(ORIGINAL, to);
    ChimeraObject *src = ProgramMem().GetData(ORIGINAL, from);

    if (dest == nullptr || src == nullptr)
    {
        cout << "Error: couldn't clone var" << endl;
        return EMPTY_VAR_NAME;
    }

    if (dest->GetGeneralType() == COLLECTION_DATA_TYPE)
    {
        return ReassignContainer(to, from, ProgramMem());
    }

    if (dest->Set(src) == FAIL)
    {
        cout << "Error: could not bind " << dest->GetTypeName() << " to " << src->GetTypeName() << endl;
        to = EMPTY_VAR_NAME;
    }

    return to;
}

string ChmrInterpreter::RefBind(string ref_id, string var_id, string ref_type)
{

    string ref_id_copy = ref_id;
    string var_id_copy = var_id;

    if (!ProgramMem().HasData(var_id_copy))
    {
        cout << "Error: cannot bind a reference to a nonexistent var\n";
        return EMPTY_VAR_NAME;
    }
    else if (ProgramMem().IsTemp(var_id_copy) || ProgramMem().IsConst(var_id_copy))
    {
        cout << "Error: cannot bind ref to a temp value\n";
        return EMPTY_VAR_NAME;
    }

    // makes sure that the reference id is valid in cases
    // that a reference is being rebound
   
    if (ref_type.empty() && ProgramMem().HasData(ref_id_copy))
    {
        ref_type = ProgramMem().GetData(ORIGINAL, ref_id)->GetTypeName();
    }
    else if (ref_type.empty())
    {
        cout << "Error: can't rebind a nonexistent ref\n";
        return EMPTY_VAR_NAME;
    }

    // makes sure that the right time of variable is being bound
    // to the same type of reference
    ChimeraObject *var = ProgramMem().GetData(ORIGINAL, var_id);
    if (var->GetTypeName() != ref_type)
    {
        cout << "Error: cannot reference type '" << var->GetTypeName() << "' as " << ref_type << "-ref\n";
        return EMPTY_VAR_NAME;
    }
    else if (var->GetGeneralType() == UNION_DATA_TYPE)
    {
        cout << "Error: cannot make a reference to dynamic types 'unions'" << endl;
        return EMPTY_VAR_NAME;
    }
    else if (ProgramMem().HasData(ref_id_copy) && !ProgramMem().IsRef(ref_id_copy)) {
        cout << "Error: cannot use non reference var to reference data" << endl;
        return EMPTY_VAR_NAME;
    }

    ProgramMem().CreateRef(ref_id_copy, var_id_copy);
    return ref_id;
}

string ChmrInterpreter::MakeUnion(string var_id, vector<string> types, string var_id_2, bool unknown)
{

    ChimeraObject *union_data_var = ProgramMem().GetData(ORIGINAL, var_id_2);
    if (union_data_var == nullptr)
    {
        cout << "Error: cannot make a union type, var " << var_id_2 << " doesn't exist\n";
        return EMPTY_VAR_NAME;
    }

    vector<string> type_list = types;

    if (unknown)
    {
        type_list = {
            INT_TYPE_NAME,
            FLOAT_TYPE_NAME,
            DOUBLE_TYPE_NAME,
            CHAR_TYPE_NAME,
            BOOL_TYPE_NAME,
            STRING_TYPE_NAME};
    }

    string union_name = ProgramMem().CreateUnionData(var_id, type_list, union_data_var);
    ChimeraObject *union_var = ProgramMem().GetData(ORIGINAL, union_name);

    if (union_var->GetType() == UNDEFINED_DATA_TYPE)
    {
        cout << "Error: initalized union with non-allowable type\n";
        ProgramMem().EraseData(union_name);
        return EMPTY_VAR_NAME;
    }

    return union_name;
}

string ChmrInterpreter::CloneVarToTempVar(string var_id)
{

    ChimeraObject *var = ProgramMem().GetData(CLONED, var_id);
    if (var == nullptr)
    {
        cout << "Error: var doesn't exist\n";
        return EMPTY_VAR_NAME;
    }

    return var_id;
}

string ChmrInterpreter::CastVarTo(string var_id, string type)
{
    if (ProgramMem().CastData(var_id, type) == FAIL) {
        if (var_id.empty()) {
            cout << "Error: " << var_id << " can't be cast because it doesn't exist" << endl;
        }
        else if (type.empty()) {
            cout << "Error: trying to cast to invalid type '" << type << "'" << endl;
        }
        return EMPTY_VAR_NAME;
    }
    
    return var_id;
}

void ChmrInterpreter::GarbageCollect()
{
    ProgramMem().CleanUp();
}

void ChmrInterpreter::CreateScope(string type)
{
    CurScopes().CreateScope(type);
}

void ChmrInterpreter::DestroyScope()
{
    CurScopes().DestroyScope();
}

int ChmrInterpreter::PrintVar(string var_id, char end)
{

    ChimeraObject *var = ProgramMem().GetData(ORIGINAL, var_id);
    if (var == nullptr)
    {
        cout << "Error: cannot print var " << var_id << '\n';
        return FAIL;
    }

    cout << *var << end;

    return SUCCEED;
}

void ChmrInterpreter::EatAst(AstNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    ast_trees.push_back(root);
    RunCurInstruction();
}

string ChmrInterpreter::RunAst(AstNode *root)
{
    return callbacks[root->Type()](root, this);
}

string ChmrInterpreter::RunAst(shared_ptr<AstNode> &root)
{
    return callbacks[root->Type()](root.get(), this);
}

void ChmrInterpreter::RunCurInstruction(size_t end, bool is_base_call)
{
    if (end == 0 || end >= ast_trees.size())
    {
        end = ast_trees.size();
    }

    const int IN_PROCESS = 1;
    auto ComputeScopeTree = [&](AstNode *&node, ChmrInterpreter *i, size_t end)
    {

        bool ctrl_struct_being_ran = CurScopeTree().Size() > 0;
        if (ctrl_struct_being_ran) {
            return -1;
        }

        size_t cur_level = CurScopeLevel();

        i->ProcessCtrlStructure(node);
        
        while (true)
        {
            if (node->Type() == MAKE_FUNC_CMD)
            {
                i->RunAst(node);
            }

            if (i->CurScopeLevel() == 0)
            {
                break;
            }

            if (++i->CurInstruction() == end) {
                return IN_PROCESS;
            }

            node = i->ast_trees[i->CurInstruction()];
            i->ProcessCtrlStructure(node);
        }

        if (CurJumpPoints().size() > 0 && CurScopeLevel() == 0) {
            i->CurInstruction() = i->CurJumpPoints().front().jump_point;
            node = ast_trees[CurInstruction()];
            i->ConvertJumpPointsToScopeTree();
        }

        bool is_ret = (node->Type() == FUNC_RETR_CMD) && cur_level == SIZE_MAX;
        CurInstruction() += is_ret;
        return (int)is_ret;
    };

    while (CurInstruction() < end)
    {
        AstNode *node = ast_trees[CurInstruction()];

        int jump_tree_process_res = ComputeScopeTree(node, this, end);
        if (jump_tree_process_res == IN_PROCESS) {
            continue;
        }

        RunAst(node);
        if (node->Type() == FUNC_RETR_CMD) {
            break;
        }

        CurInstruction()++;

        bool end_of_ctrl_struct_found = (
            CurJumpPoints().size() > 0
            && CurInstruction() > CurJumpPoints().back().jump_point
        );

        if (end_of_ctrl_struct_found)
        {
            CurJumpPoints().clear();
            CurScopeTree().Clear();
        }

        will_mutate_source = false;
        GarbageCollect();
    }
}

size_t &ChmrInterpreter::CurInstruction()
{
    FillEmptyStack(run_time_context);
    return run_time_context.top().cur_instruction;
}

ScopeTree &ChmrInterpreter::CurScopeTree()
{
    FillEmptyStack(run_time_context);
    return run_time_context.top().tree;
}

vector<JumpInfo> &ChmrInterpreter::CurJumpPoints()
{
    FillEmptyStack(run_time_context);
    return run_time_context.top().jump_points;
}

size_t &ChmrInterpreter::CurScopeLevel()
{
    FillEmptyStack(run_time_context);
    return run_time_context.top().cur_scope_level;
}

stack<size_t> &ChmrInterpreter::ScopesRan() {
    FillEmptyStack(run_time_context);
    return run_time_context.top().scope_branches_entered;
}

ScopeStack &ChmrInterpreter::CurScopes() {
    FillEmptyStack(run_time_context);
    return run_time_context.top().scopes;
}

AstNode *ChmrInterpreter::MostRecentAst() {
    if (ast_trees.size() == 0) {
        return nullptr;
    }

    return ast_trees.back();
}

// PUBLIC METHODS ABOVE -----------------------------------------------------------------------------