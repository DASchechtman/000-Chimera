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
        if (was_deleted[node].yes)
        {
            continue;
        }

        was_deleted[node].yes = true;
        delete node;
    }
}

string ChmrInterpreter::MakeBind(string to, string from, string type)
{
    if (!Table()->Has(from))
    {
        cout << "Error: can't bind data to nonexistant symbol\n";
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj = Table()->GetEntry(from);
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

        if (!Table()->Has(to))
        {
            to = Table()->AddEntry(to, obj->Clone());
        }
        else
        {
            List *list_obj = (List *)Table()->GetEntry(to);
            list_obj->SetToNewContainer((Container *)obj);
        }

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
        if (!Table()->Has(to))
        {
            to = Table()->AddEntry(to, obj->Clone());
        }
        else
        {
            Map *map_obj = (Map *)Table()->GetEntry(to);
            map_obj->SetToNewContainer((Container *)obj);
        }
        break;
    }
    default:
    {
        cout << "Error: cannot create var of type " << type << endl;
    }
    }

    return var_id;
}

SymbolTable *ChmrInterpreter::Table()
{
    return CurScopes().GetTable();
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
    else if (node->Type() == FUNC_RETR_CMD && CurScopeLevel() == SIZE_MAX)
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
    if (Table()->Has(to))
    {
        if (!Table()->GetParent(to).empty())
        {
            to = Table()->GetParent(to);
        }
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
    if (!Table()->Has(to) || !Table()->Has(from))
    {
        cout << "Error: couldn't clone var\n";
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj = Table()->GetEntry(to);
    ChimeraObject *obj_2 = Table()->GetEntry(from);

    if (obj->GetGeneralType() == COLLECTION_DATA_TYPE)
    {
        return ReassignContainer(to, from, Table());
    }

    if (obj->Set(obj_2) == FAIL)
    {
        cout << "Error: could not bind " << obj->GetTypeName() << " to " << obj_2->GetTypeName() << endl;
        to = EMPTY_VAR_NAME;
    }

    return to;
}

string ChmrInterpreter::RefBind(string ref_id, string var_id, string ref_type)
{

    // makes sure that the variable being bound to a ref
    // is valid
    if (!Table()->Has(var_id))
    {
        cout << "Error: cannot bind a reference to a nonexistent var\n";
        return EMPTY_VAR_NAME;
    }
    else if (!Table()->CameFromVar(var_id))
    {
        cout << "Error: cannot bind ref to a temp value\n";
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj = Table()->GetEntry(Table()->GetParent(var_id));

    if (obj == nullptr)
    {
        obj = Table()->GetEntry(var_id);
    }

    // makes sure that the reference id is valid in cases
    // that a reference is being rebound
    if (ref_type.empty() && Table()->Has(ref_id))
    {
        ref_type = Table()->GetEntry(ref_id)->GetTypeName();
    }
    else if (ref_type.empty() && !Table()->Has(ref_id))
    {
        cout << "Error: can't rebind a nonexistent ref\n";
        return EMPTY_VAR_NAME;
    }

    // makes sure that the right time of variable is being bound
    // to the same type of reference
    if (obj->GetTypeName() != ref_type)
    {
        cout << "Error: cannot reference type '" << obj->GetTypeName() << "' as " << ref_type << "-ref\n";
        return EMPTY_VAR_NAME;
    }
    else if (obj->GetGeneralType() == UNION_DATA_TYPE)
    {
        cout << "Error: cannot make a reference to dynamic types 'unions'" << endl;
        return EMPTY_VAR_NAME;
    }

    return Table()->AddOrUpdateRef(ref_id, obj);
}

string ChmrInterpreter::MakeUnion(string var_id, vector<string> types, string var_id_2, bool unknown)
{

    if (!Table()->Has(var_id_2))
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

    ChimeraObject *from = Table()->GetEntry(var_id_2);
    ChimeraObject *to = new ChimeraUnion(type_list, from);

    if (to->GetType() == UNDEFINED_DATA_TYPE)
    {
        cout << "Error: initalized union with non-allowable type\n";
        delete to;
        return EMPTY_VAR_NAME;
    }

    return Table()->AddEntry(var_id, to);
}

string ChmrInterpreter::CloneVarToTempVar(string var_id)
{

    if (!Table()->Has(var_id))
    {
        cout << "Error: var doesn't exist\n";
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj = Table()->GetEntry(var_id);
    string tmp = MakeBind(EMPTY_VAR_NAME, var_id, obj->GetTypeName());
    Table()->SetParent(tmp, var_id);
    return tmp;
}

string ChmrInterpreter::CastVarTo(string var_id, string type)
{

    if (!Table()->Has(var_id))
    {
        cout << "Error: var " << var_id << " doesn't exist\n";
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *var = Table()->GetEntry(var_id)->ConvertTo(type);

    if (var == nullptr)
    {
        cout << "Error: trying to convert to non-supported type " << type << endl;
        return EMPTY_VAR_NAME;
    }

    return Table()->AddEntry(EMPTY_VAR_NAME, var);
}

void ChmrInterpreter::GarbageCollect()
{
    Table()->FreeTempItems();
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

    if (!Table()->Has(var_id))
    {
        cout << "Error: cannot print var " << var_id << '\n';
        return FAIL;
    }

    ChimeraObject *obj = Table()->GetEntry(var_id);
    cout << *obj << end;

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