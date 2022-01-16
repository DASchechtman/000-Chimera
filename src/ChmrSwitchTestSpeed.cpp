#include "ChmrInterpreter.hpp"

string ChmrInterpreter::TestSwitchSpeed(AstNode *root) {
    switch (root->Type())
    {
    case PRINT_CMD:
    {
        for (size_t i = 0; i < root->Size(AstNode::LEFT); i++)
        {
            string print_data = RunAst(root->GetFromLeftNodes(i));
            PrintVar(print_data, ' ');
        }
        cout << '\n';
        break;
    }
    case BIND_CMD:
    {
        string to = RunAst(root->GetFromLeftNodes());
        string from = RunAst(root->GetFromRightNodes());
        string type = RunAst(root->GetFromMiddleNodes());
        return Bind(to, from, type);
    }
    case MAKE_UNION_CMD:
    {
        string to = RunAst(root->GetFromLeftNodes());
        string from = RunAst(root->GetFromRightNodes());
        vector<string> types;

        for (size_t i = 0; i < root->Size(AstNode::MIDDLE); i++)
        {
            types.push_back(RunAst(root->GetFromMiddleNodes(i)));
        }

        return MakeUnion(to, types, from, types.empty());
    }
    case REBIND_CMD:
    {
        string to = RunAst(root->GetFromLeftNodes());
        string from = RunAst(root->GetFromRightNodes());

        bool exists = Table()->Has(to);
        bool is_child = Table()->CameFromVar(to);

        if (exists && is_child)
        {
            to = Table()->GetParent(to);
        }

        return Rebind(to, from);
    }
    case REFBIND_CMD:
    {
        string ref = RunAst(root->GetFromLeftNodes());
        string var = RunAst(root->GetFromRightNodes());
        string type = "";
        if (root->Size(AstNode::MIDDLE) > 0)
        {
            type = RunAst(root->GetFromMiddleNodes());
        }
        else
        {
            ref = Table()->GetParent(ref);
        }
        return RefBind(ref, var, type);
    }
    case MAKE_LIST_CMD:
    {
        string id = RunAst(root->GetFromLeftNodes());
        vector<string> type;
        for (size_t i = 0; i < root->Size(AstNode::RIGHT); i++)
        {
            type.push_back(RunAst(root->GetFromRightNodes(i)));
        }

        if (root->Size(AstNode::MIDDLE) > 0)
        {
            string expr = RunAst(root->GetFromMiddleNodes());
            string list = MakeArray(id, type, Table());
            return ReassignContainer(list, expr, Table());
        }
        else
        {
            return MakeArray(id, type, Table());
        }
    }
    case MAKE_MAP_CMD:
    {
        string id = RunAst(root->GetFromLeftNodes());
        string key = RunAst(root->GetFromMiddleNodes());
        string val = RunAst(root->GetFromRightNodes());
        return MakeMap(id, key, val, Table());
    }
    case ADDITION_CMD:
    case SUBTRACTION_CMD:
    case MULTIPLY_CMD:
    case DIVIDE_CMD:
    case POW_CMD:
    {
        string left = RunAst(root->GetFromLeftNodes());
        string right = RunAst(root->GetFromRightNodes());

        if (root->Type() == ADDITION_CMD)
        {
            Add(left, right, Table());
        }
        else if (root->Type() == SUBTRACTION_CMD)
        {
            Subtract(left, right, Table());
        }
        else if (root->Type() == MULTIPLY_CMD)
        {
            Multiply(left, right, Table());
        }
        else if (root->Type() == DIVIDE_CMD)
        {
            Divide(left, right, Table());
        }
        else if (root->Type() == POW_CMD)
        {
            Pow(left, right, Table());
        }

        return left;
    }
    case LESS_CMD:
    case LESS_EQ_CMD:
    case GREATER_CMD:
    case GREATER_EQ_CMD:
    case EQ_CMD:
    {
        string left = RunAst(root->GetFromLeftNodes());
        string right = RunAst(root->GetFromRightNodes());

        if (root->Type() == LESS_CMD)
        {
            return Less(left, right, Table());
        }
        else if (root->Type() == LESS_EQ_CMD)
        {
            return LessEqual(left, right, Table());
        }
        else if (root->Type() == GREATER_CMD)
        {
            return Greater(left, right, Table());
        }
        else if (root->Type() == GREATER_EQ_CMD)
        {
            return GreaterEqual(left, right, Table());
        }
        else if (root->Type() == EQ_CMD)
        {
            return Equal(left, right, Table());
        }

        break;
    }
    case AND_CMD:
    case OR_CMD:
    {
        string left = RunAst(root->GetFromLeftNodes());
        string right = RunAst(root->GetFromRightNodes());
        return root->Type() == AND_CMD ? And(left, right, Table()) : Or(left, right, Table());
    }
    case NOT_CMD:
    {
        string val = RunAst(root->GetFromLeftNodes());
        return Not(val, Table());
    }
    case CAST_TYPE_CMD:
    {
        string val = RunAst(root->GetFromLeftNodes());
        string type_to = RunAst(root->GetFromRightNodes());
        return CastVarTo(val, type_to);
    }
    case PUT_IN_CONTAINER_CMD:
    {
        string list = Table()->GetParent(RunAst(root->GetFromLeftNodes()));
        string val = RunAst(root->GetFromRightNodes());
        return PutInArray(list, val, Table());
    }
    case PUT_IN_MAP_CMD:
    {
        string map = Table()->GetParent(RunAst(root->GetFromLeftNodes()));
        string key = RunAst(root->GetFromMiddleNodes());
        string val = RunAst(root->GetFromRightNodes());
        return PutInMap(map, key, val, Table());
    }
    case GET_FROM_CONTAINER_CMD:
    {
        string container = RunAst(root->GetFromLeftNodes());
        string index = RunAst(root->GetFromRightNodes());
        return GetFromContainer(container, index, Table());
    }
    case SET_IN_CONTAINER_CMD:
    {
        string container = Table()->GetParent(RunAst(root->GetFromLeftNodes()));
        string index = RunAst(root->GetFromMiddleNodes());
        string new_val = RunAst(root->GetFromRightNodes());
        return SetInContainer(container, index, new_val, Table());
    }
    case GET_CONTAINER_SIZE_CMD:
    {
        string container = RunAst(root->GetFromLeftNodes());
        return GetContainerSize(container, Table());
    }
    case RAW_DATA_CMD:
    {
        string data_name;

        if (root->Value().type == INT_NODE_TYPE)
        {
            return CreateTmpVar(root->Value().i);
        }
        else if (root->Value().type == FLOAT_NODE_TYPE)
        {
            return CreateTmpVar(root->Value().f);
        }
        else if (root->Value().type == DOUBLE_NODE_TYPE)
        {
            return CreateTmpVar(root->Value().d);
        }
        else if (root->Value().type == CHAR_NODE_TYPE)
        {
            return CreateTmpVar(root->Value().c);
        }
        else if (root->Value().type == STRING_NODE_TYPE)
        {
            return CreateTmpVar(root->Value().s);
        }
        else if (root->Value().type == BOOL_NODE_TYPE)
        {
            return CreateTmpVar(root->Value().b);
        }
        else if (root->Value().type == ARRAY_NODE_TYPE)
        {
            string arr;
            if (root->Size(AstNode::LEFT) > 0)
            {
                string var_name = RunAst(root->GetFromLeftNodes());

                arr = MakeArray(EMPTY_VAR_NAME, UNKNOWN_TYPE_NAME, Table());

                for (size_t i = 0; i < root->Size(AstNode::LEFT); i++)
                {
                    if (i == 0)
                    {
                        PutInArray(arr, var_name, Table());
                        continue;
                    }
                    PutInArray(arr, RunAst(root->GetFromLeftNodes(i)), Table());
                }
            }

            arr = arr.empty() ? MakeArray(EMPTY_VAR_NAME, UNKNOWN_TYPE_NAME, Table()) : arr;
            return arr;
        }
        else if (root->Value().type == VAR_TYPE_NODE_TYPE)
        {
            return root->Value().s;
        }
        else if (root->Value().type == ID_NODE_TYPE)
        {
            if (!Table()->Has(root->Value().s))
            {
                return root->Value().s;
            }
            return CloneVarToTempVar(root->Value().s);
            ;
        }

        break;
    }
    case CTRL_BLOCK_CMD:
    {
        RunAst(root->GetFromLeftNodes());
        break;
    }
    case IF_BLOCK_CMD:
    {
        CircularList *jump_points = scope_tree[ScopeLevel()];
        size_t next_jump_point = jump_points->Next();
        cur_stack_level.push(scopes.Size());
        bool can_run = Table()->GetEntry(RunAst(root->GetFromLeftNodes()))->ToBool();
        IncreaseScopeLevel();

        if (can_run)
        {
            CreateScope(GEN_SCOPE);
        }
        else
        {
            GoTo(next_jump_point);
        }

        break;
    }
    case ELIF_BLOCK_CMD:
    {
        CircularList *jump = scope_tree[ScopeLevel() - 1];
        size_t next = jump->Next();
        bool prev_if_branch_ran = cur_stack_level.top() != scopes.Size();
        if (!prev_if_branch_ran)
        {
            bool can_run = Table()->GetEntry(RunAst(root->GetFromLeftNodes()))->ToBool();

            if (can_run)
            {
                CreateScope(GEN_SCOPE);
            }
            else
            {
                GoTo(next);
            }
        }
        else
        {
            GoTo(next);
        }
        break;
    }
    case ELSE_BLOCK_CMD:
    {
        CircularList *jump = scope_tree[ScopeLevel() - 1];
        size_t next = jump->Next();
        bool prev_if_branch_ran = cur_stack_level.top() != scopes.Size();
        if (!prev_if_branch_ran)
        {
            CreateScope(GEN_SCOPE);
        }
        else
        {
            GoTo(next);
        }
        break;
    }
    case WHILE_BLOCK_CMD:
    {
        CircularList *jump = scope_tree[ScopeLevel()];
        size_t next = jump->Next();
        bool can_run = Table()->GetEntry(RunAst(root->GetFromLeftNodes()))->ToBool();
        cur_stack_level.push(scopes.Size());
        IncreaseScopeLevel();

        if (can_run)
        {
            CreateScope(GEN_SCOPE);
        }
        else
        {
            GoTo(next);
        }

        jump->PrevInfo(true).can_jump = can_run;

        break;
    }
    case START_BLOCK_CMD:
    {
        CreateScope(GEN_SCOPE);
        break;
    }
    case END_BLOCK_CMD:
    {
        DecreaseScopeLevel();
        CircularList *jump = scope_tree[ScopeLevel()];
        JumpInfo info = jump->PrevInfo(true);
        bool is_ctrl = ast_trees[info.jump_point]->Type() == CTRL_BLOCK_CMD;
        bool is_while = is_ctrl && ast_trees[info.jump_point]->GetFromLeftNodes()->Type() == WHILE_BLOCK_CMD;

        if (is_while && info.can_jump)
        {
            scope_tree.MoveToLastNode(ScopeLevel());
            GoTo(jump->PrevInfo().jump_point);
        }
        else
        {
            jump->Next();
        }

        if (scopes.Size() > cur_stack_level.top())
        {
            DestroyScope();
        }

        cur_stack_level.pop();

        break;
    }
    case END_SCOPE_CMD:
    {
        DestroyScope();
        break;
    }
    default:
    {
        return callbacks[root->Type()](root, this);
    }
    }

    return EMPTY_VAR_NAME;
}