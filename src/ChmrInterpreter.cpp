#include "ChmrInterpreter.hpp"
#include "Types/Number/Number.hpp"
#include "Types/Text/Text.hpp"
#include <iostream>
#include <math.h>

using namespace std;

// PRIVATE METHODS BELOW ---------------------------------------------------------------------------

ChmrInterpreter::ChmrInterpreter()
{
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
        cout << "Error: cannot create var of type " << type << "\n";
    }
    }

    return var_id;
}

SymbolTable *ChmrInterpreter::Table()
{
    return scopes.GetTable();
}

void ChmrInterpreter::GoTo(size_t jump_point, bool adjust_val)
{
    for (size_t i = 0; i < jump_points.size(); i++)
    {
        if (jump_points[i].jump_point == jump_point)
        {
            cur_jump_point = i;
            break;
        }
    }
    cur_instruction = jump_point - adjust_val;
}

size_t ChmrInterpreter::ScopeLevel()
{
    return cur_scope_level;
}

void ChmrInterpreter::IncreaseScopeLevel()
{
    cur_scope_level++;
}

void ChmrInterpreter::DecreaseScopeLevel()
{
    cur_scope_level--;
}

void ChmrInterpreter::ProcessCtrlStructure(AstNode *node)
{
    if (node->Type() == CTRL_BLOCK_CMD)
    {
        bool is_start = (node->GetFromLeftNodes()->Type() == IF_BLOCK_CMD || node->GetFromLeftNodes()->Type() == WHILE_BLOCK_CMD);
        cur_scope_level = is_start ? cur_scope_level + 1 : cur_scope_level;

        JumpInfo ji;
        ji.jump_point = ast_trees.size() - 1;
        ji.depth = cur_scope_level;

        jump_points.push_back(ji);
    }
    else if (node->Type() == FUNC_RETR_CMD && cur_scope_level == SIZE_MAX) {
        cur_scope_level = 0;
        cur_instruction++;
    }
    else if (node->Type() == END_BLOCK_CMD)
    {
        JumpInfo ji;
        ji.jump_point = ast_trees.size() - 1;
        ji.depth = cur_scope_level;

        jump_points.push_back(ji);
        cur_scope_level = ji.depth - 1;
    }
}

void ChmrInterpreter::ConvertJumpPointsToScopeTree()
{
    for (JumpInfo point : jump_points)
    {
        AstNode *point_type = ast_trees[point.jump_point];

        if (point_type->Type() == CTRL_BLOCK_CMD)
        {
            if (
                point_type->GetFromLeftNodes()->Type() == IF_BLOCK_CMD || point_type->GetFromLeftNodes()->Type() == WHILE_BLOCK_CMD)
            {
                bool is_if_stmt_outside_other_scopes = (point_type->GetFromLeftNodes()->Type() == IF_BLOCK_CMD && scope_tree.Size() == 0);

                scope_tree.CreateNewBlock(is_if_stmt_outside_other_scopes);
                scope_tree.AddJpToBlock(point.jump_point);
            }
            else if (
                point_type->GetFromLeftNodes()->Type() == ELIF_BLOCK_CMD || point_type->GetFromLeftNodes()->Type() == ELSE_BLOCK_CMD)
            {
                scope_tree.AddJpToBlock(point.jump_point);
                scope_tree.CloseBlock();
                scope_tree.CreateNewBlock(true);
                scope_tree.AddJpToBlock(point.jump_point);
            }
        }
        else if (point_type->Type() == END_BLOCK_CMD)
        {
            scope_tree.AddJpToBlock(point.jump_point);
            scope_tree.CloseBlock();
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

    if (obj->Set(obj_2) == FAIL) {
        cout << "Error: could not bind " << obj->GetTypeName() << " to " << obj_2->GetTypeName() << "\n";
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
        cout << "Error: cannot make a reference to dynamic types 'unions'\n";
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
        cout << "Error: trying to convert to non-supported type " << type << '\n';
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
    scopes.CreateScope(type);
}

void ChmrInterpreter::DestroyScope()
{
    scopes.DestroyScope();
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

    ProcessCtrlStructure(root);

    if (cur_scope_level == 0)
    {
        if (jump_points.size() > 0)
        {
            ConvertJumpPointsToScopeTree();
        }

        RunCurInstruction();

        if (jump_points.size() > 0)
        {
            jump_points.clear();
            scope_tree.Clear();
        }
    }
    else if (cur_scope_level == SIZE_MAX)
    {
        cur_instruction++;
    }
}

string ChmrInterpreter::RunAst(AstNode *root)
{
    return callbacks[root->Type()](root, this);
}

string ChmrInterpreter::RunAst(shared_ptr<AstNode> &root)
{
    return callbacks[root->Type()](root.get(), this);
}

void ChmrInterpreter::RunCurInstruction(size_t end)
{
    if (end == 0 || end >= ast_trees.size()) {
        end = ast_trees.size();
    }

    size_t cur_i = cur_instruction;

    while (cur_i < end)
    {
        RunAst(ast_trees[cur_i]);
        cur_i++;
        will_mutate_source = false;
        GarbageCollect();
    }

    cur_instruction = cur_i;
}

// PUBLIC METHODS ABOVE -----------------------------------------------------------------------------