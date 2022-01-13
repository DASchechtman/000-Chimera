#include "ChmrInterpreter.hpp"
#include "Types/Number/Number.hpp"
#include "Types/Text/Text.hpp"
#include <iostream>
#include <math.h>

using namespace std;

// PRIVATE METHODS BELOW ---------------------------------------------------------------------------

ChmrInterpreter::~ChmrInterpreter() {
    for(AstNode *node : ast_trees) {
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
    string p = Table()->GetParent(to);

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
    case LIST_DATA_TYPE: {
        var_id = Table()->AddEntry(EMPTY_VAR_NAME, obj->Clone());
        Table()->SetParent(var_id, from);
        break;
    }
    case MAP_DATA_TYPE: {
        var_id = Table()->AddEntry(EMPTY_VAR_NAME, obj->Clone());
        Table()->SetParent(var_id, from);
        break;
    }
    default:
    {
        cout << "Error: cannot create var of type " << type << "\n";
    }
    }

    return var_id;
}

SymbolTable* ChmrInterpreter::Table() {
    return scopes.GetTable();
}

void ChmrInterpreter::GoTo(size_t jump_point) {
    for (size_t i = 0; i < jump_points.size(); i++) {
        if (jump_points[i].jump_point == jump_point) {
            cur_jump_point = i;
            break;
        }
    }
    cur_instruction = jump_point - 1;
}

size_t ChmrInterpreter::ScopeLevel() {
    return cur_scope_level;
}

void ChmrInterpreter::IncreaseScopeLevel() {
    cur_scope_level++;
}

void ChmrInterpreter::DecreaseScopeLevel() {
    cur_scope_level--;
}

void ChmrInterpreter::ProcessCtrlStructure(AstNode *node) {
    if (node->Type() == CTRL_BLOCK_CMD) {
        bool is_start = (
            node->GetFromLeftNodes()->Type() == IF_BLOCK_CMD 
            || node->GetFromLeftNodes()->Type() == WHILE_BLOCK_CMD
        );
        cur_scope_level = is_start ? cur_scope_level+1 : cur_scope_level;

        JumpInfo ji;
        ji.jump_point = ast_trees.size()-1;
        ji.depth = cur_scope_level;
        
        jump_points.push_back(ji);
    }
    else if (node->Type() == END_BLOCK_CMD) {
        JumpInfo ji;
        ji.jump_point = ast_trees.size()-1;
        ji.depth = cur_scope_level;

        jump_points.push_back(ji);
        cur_scope_level = ji.depth-1;;
    }
}

void ChmrInterpreter::ConvertJumpPointsToScopeTree() {
    for(JumpInfo point : jump_points) {
        AstNode *point_type = ast_trees[point.jump_point];
        
        if (point_type->Type() == CTRL_BLOCK_CMD) {
            if (
                point_type->GetFromLeftNodes()->Type() == IF_BLOCK_CMD
                || point_type->GetFromLeftNodes()->Type() == WHILE_BLOCK_CMD
            ) {
                bool is_if_stmt_outside_other_scopes = (
                    point_type->GetFromLeftNodes()->Type() == IF_BLOCK_CMD 
                    && scope_tree.Size() == 0
                );
                
                scope_tree.CreateNewBlock(is_if_stmt_outside_other_scopes);
                scope_tree.AddJpToBlock(point.jump_point);
            }
            else if (
                point_type->GetFromLeftNodes()->Type() == ELIF_BLOCK_CMD
                || point_type->GetFromLeftNodes()->Type() == ELSE_BLOCK_CMD
            ) {
                scope_tree.AddJpToBlock(point.jump_point);
                scope_tree.CloseBlock();
                scope_tree.CreateNewBlock(true);
                scope_tree.AddJpToBlock(point.jump_point);
            }
        }
        else if (point_type->Type() == END_BLOCK_CMD) {
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
        if (!Table()->GetParent(to).empty()) {
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
    if (!Table()->Has(to))
    {
        cout << "Error: couldn't clone var\n";
        return EMPTY_VAR_NAME;
    }
    else
    {
        ChimeraObject *obj = Table()->GetEntry(to);
        if (obj->GetGeneralType() == COLLECTION_DATA_TYPE) {
            return ReassignContainer(to, from, Table());
        }
        return MakeBind(to, from, Table()->GetEntry(to)->GetTypeName());
    }
}

string ChmrInterpreter::RefBind(string ref_id, string var_id, string ref_type) {

    // makes sure that the variable being bound to a ref
    // is valid
    if (!Table()->Has(var_id)) {
        cout << "Error: cannot bind a reference to a nonexistent var\n";
        return EMPTY_VAR_NAME;
    }
    else if(!Table()->CameFromVar(var_id)) {
        cout << "Error: cannot bind ref to a temp value\n";
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj = Table()->GetEntry(Table()->GetParent(var_id));

    // makes sure that the reference id is valid in cases
    // that a reference is being rebound
    if(ref_type.empty() && Table()->Has(ref_id)) {
        ref_type = Table()->GetEntry(ref_id)->GetTypeName();
    }
    else if (ref_type.empty() && !Table()->Has(ref_id)) {
        cout << "Error: can't rebind a nonexistent ref\n";
        return EMPTY_VAR_NAME;
    }

    // makes sure that the right time of variable is being bound
    // to the same type of reference
    if (obj->GetTypeName() != ref_type) {
        cout << "Error: cannot reference type '" << obj->GetTypeName() << "' as " << ref_type << "-ref\n";
        return EMPTY_VAR_NAME;
    }
    else if (obj->GetGeneralType() == UNION_DATA_TYPE) {
        cout << "Error: cannot make a reference to dynamic types 'unions'\n";
        return EMPTY_VAR_NAME;
    }

    return Table()->AddOrUpdateRef(ref_id, obj);
}

string ChmrInterpreter::MakeUnion(string var_id, vector<string> types, string var_id_2, bool unknown) {
    
    if (!Table()->Has(var_id_2)) {
        cout << "Error: cannot make a union type, var " << var_id_2 << " doesn't exist\n";
        return EMPTY_VAR_NAME;
    }

    vector<string> type_list = types;

    if (unknown) {
        type_list = {
            INT_TYPE_NAME, 
            FLOAT_TYPE_NAME, 
            DOUBLE_TYPE_NAME, 
            CHAR_TYPE_NAME, 
            BOOL_TYPE_NAME, 
            STRING_TYPE_NAME
        };
    }

    ChimeraObject *from = Table()->GetEntry(var_id_2);
    ChimeraObject *to = new ChimeraUnion(type_list, from);

    if (to->GetType() == UNDEFINED_DATA_TYPE) {
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

    return Table()->AddEntry("", var);
}

void ChmrInterpreter::GarbageCollect()
{
    Table()->FreeTempItems();
}

void ChmrInterpreter::CreateScope(string type) {
    scopes.CreateScope(type);
}

void ChmrInterpreter::DestroyScope() {
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

void ChmrInterpreter::EatAst(AstNode *root) {
    if (root == nullptr) {
        return;
    }

    ast_trees.push_back(root);

    ProcessCtrlStructure(root);

    if (cur_scope_level == 0) {
        if (jump_points.size() > 0) {
            ConvertJumpPointsToScopeTree();
        }

        while(cur_instruction < ast_trees.size()) {
            RunAst(ast_trees[cur_instruction]);
            cur_instruction++;
            GarbageCollect();
        }

        if (jump_points.size() > 0) {
            jump_points.clear();
            scope_tree.Clear();
        }
    }
}

string ChmrInterpreter::RunAst(AstNode *root) {

    switch(root->Type()) {
        case PRINT_CMD: {
            for(size_t i = 0; i < root->Size(AstNode::LEFT); i++) {
                string print_data = RunAst(root->GetFromLeftNodes(i));
                PrintVar(print_data, ' ');
            }
            cout << '\n';
            break;
        }
        case BIND_CMD: {
            string to = RunAst(root->GetFromLeftNodes());
            string from = RunAst(root->GetFromRightNodes());
            string type = RunAst(root->GetFromMiddleNodes());
            return Bind(to, from, type);
        }
        case MAKE_UNION_CMD: {
            string to = RunAst(root->GetFromLeftNodes());
            string from = RunAst(root->GetFromRightNodes());
            vector<string> types;

            for(size_t i = 0; i < root->Size(AstNode::MIDDLE); i++) {
                types.push_back(RunAst(root->GetFromMiddleNodes(i)));
            }

            return MakeUnion(to, types, from, types.empty());
        }
        case REBIND_CMD: {
            string to = RunAst(root->GetFromLeftNodes());
            string from = RunAst(root->GetFromRightNodes());

            bool exists = Table()->Has(to);
            bool is_child = Table()->CameFromVar(to);

            if(exists && is_child) {
                to = Table()->GetParent(to);
            }

            return Rebind(to, from);
        }
        case REFBIND_CMD: {
            string ref = RunAst(root->GetFromLeftNodes());
            string var = RunAst(root->GetFromRightNodes());
            string type = "";
            if (root->Size(AstNode::MIDDLE) > 0) {
                type = RunAst(root->GetFromMiddleNodes());
            }
            else {
                ref = Table()->GetParent(ref);
            }
            return RefBind(ref, var, type);
        }
        case MAKE_LIST_CMD: {
            string id = RunAst(root->GetFromLeftNodes());
            vector<string> type;
            for(size_t i = 0; i < root->Size(AstNode::RIGHT); i++) {
                type.push_back(RunAst(root->GetFromRightNodes(i)));
            }

            if (root->Size(AstNode::MIDDLE) > 0) {
                string expr = RunAst(root->GetFromMiddleNodes());
                string list = MakeArray(id, type, Table());
                return ReassignContainer(list, expr, Table());
            }
            else {
                return MakeArray(id, type, Table());
            }
        }
        case MAKE_MAP_CMD: {
            string id = RunAst(root->GetFromLeftNodes());
            string key = RunAst(root->GetFromMiddleNodes());
            string val = RunAst(root->GetFromRightNodes());
            return MakeMap(id, key, val, Table());
        }
        case ADDITION_CMD:
        case SUBTRACTION_CMD:
        case MULTIPLY_CMD:
        case DIVIDE_CMD:
        case POW_CMD: {
            string left = RunAst(root->GetFromLeftNodes());
            string right = RunAst(root->GetFromRightNodes());
    
            if (root->Type() == ADDITION_CMD) {
                Add(left, right, Table());
            }
            else if (root->Type() == SUBTRACTION_CMD) {
                Subtract(left, right, Table());
            }
            else if (root->Type() == MULTIPLY_CMD) {
                Multiply(left, right, Table());
            }
            else if (root->Type() == DIVIDE_CMD) {
                Divide(left, right, Table());
            }
            else if (root->Type() == POW_CMD) {
                Pow(left, right, Table());
            }
            
            return left;
        }
        case LESS_CMD:
        case LESS_EQ_CMD:
        case GREATER_CMD:
        case GREATER_EQ_CMD:
        case EQ_CMD: {
            string left = RunAst(root->GetFromLeftNodes());
            string right = RunAst(root->GetFromRightNodes());

            if (root->Type() == LESS_CMD) {
                return Less(left, right, Table());
            }
            else if (root->Type() == LESS_EQ_CMD) {
                return LessEqual(left, right, Table());
            }
            else if (root->Type() == GREATER_CMD) {
                return Greater(left, right, Table());
            }
            else if (root->Type() == GREATER_EQ_CMD) {
                return GreaterEqual(left, right, Table());
            }
            else if (root->Type() == EQ_CMD) {
                return Equal(left, right, Table());
            }

            break;
        }
        case AND_CMD:
        case OR_CMD:{
            string left = RunAst(root->GetFromLeftNodes());
            string right = RunAst(root->GetFromRightNodes());
            return root->Type() == AND_CMD ? And(left, right, Table()) : Or(left, right, Table());
        }
        case NOT_CMD: {
            string val = RunAst(root->GetFromLeftNodes());
            return Not(val, Table());
        }
        case CAST_TYPE_CMD: {
            string val = RunAst(root->GetFromLeftNodes());
            string type_to = RunAst(root->GetFromRightNodes());
            return CastVarTo(val, type_to);
        }
        case PUT_IN_CONTAINER_CMD: {
            string list = Table()->GetParent(RunAst(root->GetFromLeftNodes()));
            string val = RunAst(root->GetFromRightNodes());
            return PutInArray(list, val, Table());
        }
        case PUT_IN_MAP_CMD: {
            string map = Table()->GetParent(RunAst(root->GetFromLeftNodes()));
            string key = RunAst(root->GetFromMiddleNodes());
            string val = RunAst(root->GetFromRightNodes());
            return PutInMap(map, key, val, Table());
        }
        case GET_FROM_CONTAINER_CMD: {
            string container = RunAst(root->GetFromLeftNodes());
            string index = RunAst(root->GetFromRightNodes());
            return GetFromContainer(container, index, Table());
        }
        case SET_IN_CONTAINER_CMD: {
            string container = Table()->GetParent(RunAst(root->GetFromLeftNodes()));
            string index = RunAst(root->GetFromMiddleNodes());
            string new_val = RunAst(root->GetFromRightNodes());
            return SetInContainer(container, index, new_val, Table());
        }
        case GET_CONTAINER_SIZE_CMD: {
            string container = RunAst(root->GetFromLeftNodes());
            return GetContainerSize(container, Table());
        }
        case RAW_DATA_CMD: {
            string data_name;

            if (root->Value().type == INT_NODE_TYPE) {
                return CreateTmpVar(root->Value().i);
            }
            else if (root->Value().type == FLOAT_NODE_TYPE) {
                return CreateTmpVar(root->Value().f);
            }
            else if (root->Value().type == DOUBLE_NODE_TYPE) {
                return CreateTmpVar(root->Value().d);
            }
            else if (root->Value().type == CHAR_NODE_TYPE) {
                return CreateTmpVar(root->Value().c);
            }
            else if (root->Value().type == STRING_NODE_TYPE) {
                return CreateTmpVar(root->Value().s);
            }
            else if (root->Value().type == BOOL_NODE_TYPE) {
                return CreateTmpVar(root->Value().b);
            }
            else if (root->Value().type == ARRAY_NODE_TYPE) {
                string arr;
                if (root->Size(AstNode::LEFT) > 0) {
                    string var_name = RunAst(root->GetFromLeftNodes());
                    
                    arr = MakeArray(EMPTY_VAR_NAME, UNKNOWN_TYPE_NAME, Table());

                    for(size_t i = 0; i < root->Size(AstNode::LEFT); i++) {
                        if (i == 0) {
                            PutInArray(arr, var_name, Table());
                            continue;
                        }
                        PutInArray(arr, RunAst(root->GetFromLeftNodes(i)), Table());
                    }
                }

                arr = arr.empty() ? MakeArray(EMPTY_VAR_NAME, UNKNOWN_TYPE_NAME, Table()) : arr;
                return arr;
            }
            else if (root->Value().type == VAR_TYPE_NODE_TYPE) {
                return root->Value().s;
            } else if (root->Value().type == ID_NODE_TYPE) {
                if (!Table()->Has(root->Value().s)) {
                    return root->Value().s;
                }
                return CloneVarToTempVar(root->Value().s);;
            }
                
            break;
        }
        case CTRL_BLOCK_CMD: {
            RunAst(root->GetFromLeftNodes());
            break;
        }
        case IF_BLOCK_CMD: {
            CircularList *jump_points = scope_tree[ScopeLevel()];
            size_t next_jump_point = jump_points->Next();
            cur_stack_level.push(scopes.Size());
            bool can_run = Table()->GetEntry(RunAst(root->GetFromLeftNodes()))->ToBool();
            IncreaseScopeLevel();
        
            if (can_run) {
                CreateScope(GEN_SCOPE);
            }
            else {
                GoTo(next_jump_point);
            }
            
            break;
        }
        case ELIF_BLOCK_CMD: {
            CircularList *jump = scope_tree[ScopeLevel()-1];
            size_t next = jump->Next();
            bool prev_if_branch_ran = cur_stack_level.top() != scopes.Size();
            if (!prev_if_branch_ran) {
                bool can_run = Table()->GetEntry(RunAst(root->GetFromLeftNodes()))->ToBool();

                if (can_run) {
                    CreateScope(GEN_SCOPE);
                }
                else {
                    GoTo(next);
                }
            }
            else {
                GoTo(next);
            }
            break;
        }
        case ELSE_BLOCK_CMD: {
            CircularList *jump = scope_tree[ScopeLevel()-1];
            size_t next = jump->Next();
            bool prev_if_branch_ran = cur_stack_level.top() != scopes.Size();
            if (!prev_if_branch_ran) {
                CreateScope(GEN_SCOPE);
            }
            else {
                GoTo(next);
            }
            break;
        }
        case WHILE_BLOCK_CMD: {
            CircularList *jump = scope_tree[ScopeLevel()];
            size_t next = jump->Next();
            bool can_run = Table()->GetEntry(RunAst(root->GetFromLeftNodes()))->ToBool();
            cur_stack_level.push(scopes.Size());
            IncreaseScopeLevel();

            if (can_run) {
                CreateScope(GEN_SCOPE);
            }
            else {
                GoTo(next);
            }

            jump->PrevInfo(true).can_jump = can_run;

            break;
        }
        case START_BLOCK_CMD: {
            CreateScope(GEN_SCOPE);
            break;
        }
        case END_BLOCK_CMD: {
            DecreaseScopeLevel();
            CircularList *jump = scope_tree[ScopeLevel()];
            JumpInfo info = jump->PrevInfo(true);
            bool is_ctrl = ast_trees[info.jump_point]->Type() == CTRL_BLOCK_CMD;
            bool is_while = is_ctrl && ast_trees[info.jump_point]->GetFromLeftNodes()->Type() == WHILE_BLOCK_CMD;

            if(is_while && info.can_jump) {
                scope_tree.MoveToLastNode(ScopeLevel());
                GoTo(jump->PrevInfo().jump_point);
            }
            else {
                jump->Next();
            }


            if (scopes.Size() > cur_stack_level.top()) {
                DestroyScope();
            }

            cur_stack_level.pop();

            break;
        }
        case END_SCOPE_CMD: {
            DestroyScope();
            break;
        }
        default: {
            cout << "Error: command not recognized\n";
        }
    }

    return EMPTY_VAR_NAME;
}

// PUBLIC METHODS ABOVE -----------------------------------------------------------------------------