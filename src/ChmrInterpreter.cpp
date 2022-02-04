#include "ChmrInterpreter.hpp"
#include "Types/Number/Number.hpp"
#include "Types/Text/Text.hpp"
#include <iostream>
#include <math.h>

using namespace std;

// PRIVATE METHODS BELOW ---------------------------------------------------------------------------

ChmrInterpreter::ChmrInterpreter() {
    GenerateCallbacks();
}

ChmrInterpreter::~ChmrInterpreter()
{
    for (AstNode *node : ast_trees)
    {
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
        if (type != LIST_TYPE_NAME) {
            cout << "Error: cannot assign '" << type << "' to list\n";
            var_id = EMPTY_VAR_NAME;
            break;
        }

        if (!Table()->Has(to)) {
            to = Table()->AddEntry(to, obj->Clone());
        }
        else {
            List *list_obj = (List*)Table()->GetEntry(to);
            list_obj->SetToNewContainer((Container*)obj);
        }

        var_id = to;
      
        break;
    }
    case MAP_DATA_TYPE:
    {
        if (type != MAP_TYPE_NAME) {
            cout << "Error: cannot assign '" << type << "' to map\n";
            var_id = EMPTY_VAR_NAME;
            break;
        }
        if (!Table()->Has(to)) {
            to = Table()->AddEntry(to, obj->Clone());
        }
        else {
            Map *map_obj = (Map*)Table()->GetEntry(to);
            map_obj->SetToNewContainer((Container*)obj);
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

void ChmrInterpreter::GoTo(size_t jump_point)
{
    for (size_t i = 0; i < jump_points.size(); i++)
    {
        if (jump_points[i].jump_point == jump_point)
        {
            cur_jump_point = i;
            break;
        }
    }
    cur_instruction = jump_point - 1;
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

    obj->Set(obj_2);
    
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

        while (cur_instruction < ast_trees.size())
        {
            RunAst(ast_trees[cur_instruction]);
            cur_instruction++;
            will_mutate_source = false;
            GarbageCollect();
        }

        if (jump_points.size() > 0)
        {
            jump_points.clear();
            scope_tree.Clear();
        }
    }
}

string ChmrInterpreter::RunAst(AstNode *root)
{
    return callbacks[root->Type()](root, this);
}

// PUBLIC METHODS ABOVE -----------------------------------------------------------------------------
typedef ChmrInterpreter* CInter;

void ChmrInterpreter::GenerateCallbacks()
{
    auto Default = [](AstNode *root, CInter i) { return EMPTY_VAR_NAME; };
    for(int i = 0; i < NUM_O_CALLBACK; i++) {
        callbacks[i] = Default;
    }

    callbacks[NO_CMD] = [](AstNode *node, CInter i)
    { return EMPTY_VAR_NAME; };

    callbacks[RAW_DATA_CMD] = [](AstNode *root, CInter i)
    {
        string data_name;

        if (root->Value().type == INT_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().i);
            if(i->will_mutate_source) {
                data_name = i->CreateTmpVar(root->Value().i);
            }
        }
        else if (root->Value().type == FLOAT_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().f);
            if(i->will_mutate_source) {
                data_name = i->CreateTmpVar(root->Value().f);
            }
        }
        else if (root->Value().type == DOUBLE_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().d);
            if(i->will_mutate_source) {
                data_name = i->CreateTmpVar(root->Value().d);
            }
        }
        else if (root->Value().type == CHAR_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().c);
            if(i->will_mutate_source) {
                data_name = i->CreateTmpVar(root->Value().c);
            }
        }
        else if (root->Value().type == STRING_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().s);
            if(i->will_mutate_source) {
                data_name = i->CreateTmpVar(root->Value().s);
            }
        }
        else if (root->Value().type == BOOL_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().b);
            if(i->will_mutate_source) {
                data_name = i->CreateTmpVar(root->Value().b);
            }
        }
        else if (root->Value().type == ARRAY_NODE_TYPE)
        {
            string arr = MakeArray(EMPTY_VAR_NAME, UNKNOWN_TYPE_NAME, i->Table());
            for (size_t iter = 0; iter < root->Size(AstNode::LEFT); iter++)
            {
                PutInArray(arr, i->RunAst(root->GetFromLeftNodes(iter)), i->Table());
            }
            data_name = arr;
        }
        else if (root->Value().type == MAP_NODE_TYPE) {
            string map = MakeMap(EMPTY_VAR_NAME, UNKNOWN_TYPE_NAME, UNKNOWN_TYPE_NAME, i->Table());
            for(size_t iter = 0; iter < root->Size(AstNode::LEFT); iter++) {
                string key = i->RunAst(root->GetFromLeftNodes(iter));
                string val = i->RunAst(root->GetFromRightNodes(iter));
                PutInMap(map, key, val, i->Table());
            }
            data_name = map;
        }
        else if (root->Value().type == VAR_TYPE_NODE_TYPE)
        {
            data_name = root->Value().s;
        }
        else if (root->Value().type == ID_NODE_TYPE)
        {
            if (!i->Table()->Has(root->Value().s) || !i->will_mutate_source)
            {
                data_name = root->Value().s;
            }
            else if (i->Table()->Has(root->Value().s) && i->Table()->GetEntry(root->Value().s)->GetGeneralType() == COLLECTION_DATA_TYPE) {
                data_name = root->Value().s;
            }
            else
            {
                data_name = i->CloneVarToTempVar(root->Value().s);
            }
        }
        

        return data_name;
    };

    callbacks[BIND_CMD] = [](AstNode *root, CInter i)
    {
        string to = i->RunAst(root->GetFromLeftNodes());
        string from = i->RunAst(root->GetFromRightNodes());
        string type = i->RunAst(root->GetFromMiddleNodes());
       
        if (type == LIST_TYPE_NAME) {
            //return MakeArray(to, )
        }
        return i->Bind(to, from, type);
    };

    callbacks[REBIND_CMD] = [](AstNode *root, CInter i)
    {
        string to = i->RunAst(root->GetFromLeftNodes());
        string from = i->RunAst(root->GetFromRightNodes());

        return i->Rebind(to, from);
    };

    callbacks[REFBIND_CMD] = [](AstNode *root, CInter i)
    {
        string ref = i->RunAst(root->GetFromLeftNodes());
        string var = i->RunAst(root->GetFromRightNodes());
        string type = "";
        if (root->Size(AstNode::MIDDLE) > 0)
        {
            type = i->RunAst(root->GetFromMiddleNodes());
        }
        else
        {
            ref = i->Table()->GetParent(ref);
        }
        return i->RefBind(ref, var, type);
    };

    callbacks[MAKE_UNION_CMD] = [](AstNode *root, CInter i)
    {
        string to = i->RunAst(root->GetFromLeftNodes());
        string from = i->RunAst(root->GetFromRightNodes());
        vector<string> types;

        for (size_t iters = 0; iters < root->Size(AstNode::MIDDLE); iters++)
        {
            types.push_back(i->RunAst(root->GetFromMiddleNodes(iters)));
        }

        return i->MakeUnion(to, types, from, types.empty());
    };

    callbacks[MAKE_LIST_CMD] = [](AstNode *root, CInter i)
    {
        string id = i->RunAst(root->GetFromLeftNodes());
        vector<string> type;
        for (size_t iters = 0; iters < root->Size(AstNode::RIGHT); iters++)
        {
            type.push_back(i->RunAst(root->GetFromRightNodes(iters)));
        }

        if (root->Size(AstNode::MIDDLE) > 0)
        {
            string expr = i->RunAst(root->GetFromMiddleNodes());
            string list = MakeArray(id, type, i->Table());
            return ReassignContainer(list, expr, i->Table());
        }
        else
        {
            return MakeArray(id, type, i->Table());
        }
    };

    callbacks[MAKE_MAP_CMD] = [](AstNode *root, CInter i)
    {
        string id = i->RunAst(root->GetFromLeftNodes());
        string key = i->RunAst(root->GetFromMiddleNodes());
        string val = i->RunAst(root->GetFromRightNodes());
        return MakeMap(id, key, val, i->Table());
    };

    callbacks[PUT_IN_CONTAINER_CMD] = [](AstNode *root, CInter i)
    {
        string list = i->RunAst(root->GetFromLeftNodes());
        string val = i->RunAst(root->GetFromRightNodes());
        return PutInArray(list, val, i->Table());
    };

    callbacks[PUT_IN_MAP_CMD] = [](AstNode *root, CInter i)
    {
        string map = i->RunAst(root->GetFromLeftNodes());
        string key = i->RunAst(root->GetFromMiddleNodes());
        string val = i->RunAst(root->GetFromRightNodes());
        return PutInMap(map, key, val, i->Table());
    };

    callbacks[GET_FROM_CONTAINER_CMD] = [](AstNode *root, CInter i)
    {
        string container = i->RunAst(root->GetFromLeftNodes());
        string list_index = i->RunAst(root->GetFromRightNodes());

        string data_name = GetFromContainer(container, list_index, i->Table());

        for(size_t index = 0; index < root->Size(AstNode::MIDDLE); index++) {
            list_index = i->RunAst(root->GetFromMiddleNodes(index));
            data_name = GetFromContainer(data_name, list_index, i->Table());
        }

        return data_name;
    };

    callbacks[SET_IN_CONTAINER_CMD] = [](AstNode *root, CInter i)
    {
        string container = i->RunAst(root->GetFromLeftNodes());
        string index = i->RunAst(root->GetFromMiddleNodes());
        string new_val = i->RunAst(root->GetFromRightNodes());
        return SetInContainer(container, index, new_val, i->Table());
    };

    callbacks[GET_CONTAINER_SIZE_CMD] = [](AstNode *root, CInter i)
    {
        string container = i->RunAst(root->GetFromLeftNodes());
        return GetContainerSize(container, i->Table());
    };

    auto MathOpers = [](AstNode *root, CInter i)
    {
        i->will_mutate_source = true;
        string left = i->RunAst(root->GetFromLeftNodes());
        string right = i->RunAst(root->GetFromRightNodes());

        if (root->Type() == ADDITION_CMD)
        {
            Add(left, right, i->Table());
        }
        else if (root->Type() == SUBTRACTION_CMD)
        {
            Subtract(left, right, i->Table());
        }
        else if (root->Type() == MULTIPLY_CMD)
        {
            Multiply(left, right, i->Table());
        }
        else if (root->Type() == DIVIDE_CMD)
        {
            Divide(left, right, i->Table());
        }
        else if (root->Type() == POW_CMD)
        {
            Pow(left, right, i->Table());
        }

        return left;
    };

    callbacks[ADDITION_CMD] = MathOpers;
    callbacks[SUBTRACTION_CMD] = MathOpers;
    callbacks[MULTIPLY_CMD] = MathOpers;
    callbacks[DIVIDE_CMD] = MathOpers;
    callbacks[POW_CMD] = MathOpers;

    callbacks[CAST_TYPE_CMD] = [](AstNode *root, CInter i)
    {
        string val = i->RunAst(root->GetFromLeftNodes());
        string type_to = i->RunAst(root->GetFromRightNodes());
        return i->CastVarTo(val, type_to);
    };

    auto AndOrOper = [](AstNode *root, CInter i)
    {
        string left = i->RunAst(root->GetFromLeftNodes());
        string right = i->RunAst(root->GetFromRightNodes());
        return root->Type() == AND_CMD ? And(left, right, i->Table()) : Or(left, right, i->Table());
    };

    callbacks[AND_CMD] = AndOrOper;
    callbacks[OR_CMD] = AndOrOper;

    callbacks[NOT_CMD] = [](AstNode *root, CInter i)
    {
        string val = i->RunAst(root->GetFromLeftNodes());
        return Not(val, i->Table());
    };

    auto CompareOper = [](AstNode *root, CInter i)
    {
        string left = i->RunAst(root->GetFromLeftNodes());
        string right = i->RunAst(root->GetFromRightNodes());

        if (root->Type() == LESS_CMD)
        {
            return Less(left, right, i->Table());
        }
        else if (root->Type() == LESS_EQ_CMD)
        {
            return LessEqual(left, right, i->Table());
        }
        else if (root->Type() == GREATER_CMD)
        {
            return Greater(left, right, i->Table());
        }
        else if (root->Type() == GREATER_EQ_CMD)
        {
            return GreaterEqual(left, right, i->Table());
        }
        else if (root->Type() == EQ_CMD)
        {
            return Equal(left, right, i->Table());
        }

        return EMPTY_VAR_NAME;
    };

    callbacks[LESS_CMD] = CompareOper;
    callbacks[LESS_EQ_CMD] = CompareOper;
    callbacks[GREATER_CMD] = CompareOper;
    callbacks[GREATER_EQ_CMD] = CompareOper;
    callbacks[EQ_CMD] = CompareOper;

    callbacks[PRINT_CMD] = [](AstNode *root, CInter i)
    {
        for (size_t iters = 0; iters < root->Size(AstNode::LEFT); iters++)
        {
            string print_data = i->RunAst(root->GetFromLeftNodes(iters));
            i->PrintVar(print_data, ' ');
        }
        cout << '\n';
        return EMPTY_VAR_NAME;
    };

    callbacks[CTRL_BLOCK_CMD] = [](AstNode *root, CInter i)
    {
        return i->RunAst(root->GetFromLeftNodes());
    };

    callbacks[IF_BLOCK_CMD] = [](AstNode *root, CInter i)
    {
        CircularList *jump_points = i->scope_tree[i->ScopeLevel()];
        size_t next_jump_point = jump_points->Next();
        i->cur_stack_level.push(i->scopes.Size());
        bool can_run = i->Table()->GetEntry(i->RunAst(root->GetFromLeftNodes()))->ToBool();
        i->IncreaseScopeLevel();

        if (can_run)
        {
            i->CreateScope(GEN_SCOPE);
        }
        else
        {
            i->GoTo(next_jump_point);
        }
        return EMPTY_VAR_NAME;
    };

    callbacks[ELIF_BLOCK_CMD] = [](AstNode *root, CInter i)
    {
        CircularList *jump = i->scope_tree[i->ScopeLevel() - 1];
        size_t next = jump->Next();
        bool prev_if_branch_ran = i->cur_stack_level.top() != i->scopes.Size();
        if (!prev_if_branch_ran)
        {
            bool can_run = i->Table()->GetEntry(i->RunAst(root->GetFromLeftNodes()))->ToBool();

            if (can_run)
            {
                i->CreateScope(GEN_SCOPE);
            }
            else
            {
                i->GoTo(next);
            }
        }
        else
        {
            i->GoTo(next);
        }

        return EMPTY_VAR_NAME;
    };

    callbacks[ELSE_BLOCK_CMD] = [](AstNode *root, CInter i)
    {
        CircularList *jump = i->scope_tree[i->ScopeLevel() - 1];
        size_t next = jump->Next();
        bool prev_if_branch_ran = i->cur_stack_level.top() != i->scopes.Size();
        if (!prev_if_branch_ran)
        {
            i->CreateScope(GEN_SCOPE);
        }
        else
        {
            i->GoTo(next);
        }

        return EMPTY_VAR_NAME;
    };

    callbacks[WHILE_BLOCK_CMD] = [](AstNode *root, CInter i)
    {
        CircularList *jump = i->scope_tree[i->ScopeLevel()];
        size_t next = jump->Next();
        bool can_run = i->Table()->GetEntry(i->RunAst(root->GetFromLeftNodes()))->ToBool();
        i->cur_stack_level.push(i->scopes.Size());
        i->IncreaseScopeLevel();

        if (can_run)
        {
            i->CreateScope(GEN_SCOPE);
        }
        else
        {
            i->GoTo(next);
        }

        jump->PrevInfo(true).can_jump = can_run;
        return EMPTY_VAR_NAME;
    };

    callbacks[START_BLOCK_CMD] = [](AstNode *root, CInter i)
    {
        i->CreateScope(GEN_SCOPE);
        return EMPTY_VAR_NAME;
    };

    callbacks[END_BLOCK_CMD] = [](AstNode *root, CInter i)
    {
        i->DecreaseScopeLevel();
        CircularList *jump = i->scope_tree[i->ScopeLevel()];
        JumpInfo info = jump->PrevInfo(true);
        bool is_ctrl = i->ast_trees[info.jump_point]->Type() == CTRL_BLOCK_CMD;
        bool is_while = is_ctrl && i->ast_trees[info.jump_point]->GetFromLeftNodes()->Type() == WHILE_BLOCK_CMD;

        if (is_while && info.can_jump)
        {
            i->scope_tree.MoveToLastNode(i->ScopeLevel());
            i->GoTo(jump->PrevInfo().jump_point);
        }
        else
        {
            jump->Next();
        }

        if (i->scopes.Size() > i->cur_stack_level.top())
        {
            i->DestroyScope();
        }

        i->cur_stack_level.pop();

        return EMPTY_VAR_NAME;
    };

    callbacks[END_SCOPE_CMD] = [](AstNode *root, CInter i) {
        i->DestroyScope();
        return EMPTY_VAR_NAME;
    };

    callbacks[INC_CMD] = [](AstNode *root, CInter i) {
        string var = i->RunAst(root->GetFromLeftNodes());
        Inc(var, i->Table());
        return var;
    };

    callbacks[MOD_CMD] = [](AstNode *root, CInter i) {
        string left = i->RunAst(root->GetFromLeftNodes());
        string right = i->RunAst(root->GetFromRightNodes());
        return Mod(left, right, i->Table()); 
    };

    callbacks[TRACK_TYPE_CMD] = [](AstNode *root, CInter i) {
        return i->RunAst(root->GetFromLeftNodes());
    };
}