#include "ChmrInterpreter.hpp"

/*
* this file consists of a single function meant to initialize all the callbacks for the interpreter
* the reason this function is in a seperate file is because the callbacks consist of a lot of code
* therefore it makes the project more readable as a whole if I place this specific function in a seperate
* file of its own so I can keep ChmrInterpreter.cpp a bit more readable
*/

typedef ChmrInterpreter *CInter;

void ChmrInterpreter::GenerateCallbacks()
{
    auto Default = [](AstNode *root, CInter i)
    { return EMPTY_VAR_NAME; };
    
    for (int i = 0; i < NUM_O_CALLBACK; i++)
    {
        callbacks[i] = Default;
    }

    callbacks[RAW_DATA_CMD] = [](AstNode *root, CInter i)
    {
        string data_name;

        if (root->Value().type == INT_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().i);
            if (i->will_mutate_source)
            {
                data_name = i->CreateTmpVar(root->Value().i);
            }
        }
        else if (root->Value().type == FLOAT_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().f);
            if (i->will_mutate_source)
            {
                data_name = i->CreateTmpVar(root->Value().f);
            }
        }
        else if (root->Value().type == DOUBLE_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().d);
            if (i->will_mutate_source)
            {
                data_name = i->CreateTmpVar(root->Value().d);
            }
        }
        else if (root->Value().type == CHAR_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().c);
            if (i->will_mutate_source)
            {
                data_name = i->CreateTmpVar(root->Value().c);
            }
        }
        else if (root->Value().type == STRING_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().s);
            if (i->will_mutate_source)
            {
                data_name = i->CreateTmpVar(root->Value().s);
            }
        }
        else if (root->Value().type == BOOL_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().b);
            if (i->will_mutate_source)
            {
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
        else if (root->Value().type == MAP_NODE_TYPE)
        {
            string map = MakeMap(EMPTY_VAR_NAME, UNKNOWN_TYPE_NAME, UNKNOWN_TYPE_NAME, i->Table());
            for (size_t iter = 0; iter < root->Size(AstNode::LEFT); iter++)
            {
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
            else if (i->Table()->Has(root->Value().s) && i->Table()->GetEntry(root->Value().s)->GetGeneralType() == COLLECTION_DATA_TYPE)
            {
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

        bool is_func = (i->Table()->Has(from) && i->Table()->GetEntry(from)->GetType() == FUNC_DATA_TYPE);

        if (is_func && i->Table()->Has(to))
        {
            ChmrFunc *func = (ChmrFunc *)i->Table()->GetEntry(from);
            ChimeraObject *obj = i->Table()->GetEntry(to);
            func->SetRetDest(obj);
            return to;
        }
        else if (is_func)
        {
            cout << "Error: cannot assign ret val to " << to << " because it doesn't exist\n";
            return EMPTY_VAR_NAME;
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

        for (size_t index = 0; index < root->Size(AstNode::MIDDLE); index++)
        {
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

    callbacks[END_SCOPE_CMD] = [](AstNode *root, CInter i)
    {
        i->DestroyScope();
        return EMPTY_VAR_NAME;
    };

    callbacks[INC_CMD] = [](AstNode *root, CInter i)
    {
        string var = i->RunAst(root->GetFromLeftNodes());
        Inc(var, i->Table());
        return var;
    };

    callbacks[MOD_CMD] = [](AstNode *root, CInter i)
    {
        string left = i->RunAst(root->GetFromLeftNodes());
        string right = i->RunAst(root->GetFromRightNodes());
        return Mod(left, right, i->Table());
    };

    callbacks[TRACK_TYPE_CMD] = [](AstNode *root, CInter i)
    {
        return i->RunAst(root->GetFromLeftNodes());
    };

    callbacks[REBIND_REF_CMD] = [](AstNode *root, CInter i)
    {
        string to = i->RunAst(root->GetFromLeftNodes());
        string from = i->RunAst(root->GetFromRightNodes());
        return i->RefBind(to, from);
    };

    callbacks[MAKE_FUNC_CMD] = [](AstNode *root, CInter i)
    {
        i->cur_scope_level = SIZE_MAX;
        string func_name = i->RunAst(root->GetFromLeftNodes());
        string ret_type = i->RunAst(root->GetFromRightNodes());
        AstNode *params = nullptr;

        if (root->Size(AstNode::MIDDLE) > 0)
        {
            params = root->GetFromMiddleNodes().get();
        }

        ChmrFunc *func = new ChmrFunc(i->cur_instruction + 1, ret_type, func_name);

        bool is_valid_params = params != nullptr;

        for (size_t index = 0; is_valid_params && index < params->Size(AstNode::LEFT); index++)
        {
            string var_name = "arg" + to_string(index);
            string var_type;

            if (params->GetFromLeftNodes(index)->Size(AstNode::LEFT) > 0)
            {
                var_name = i->RunAst(params->GetFromLeftNodes(index)->GetFromLeftNodes());
            }

            var_type = i->RunAst(params->GetFromLeftNodes(index)->GetFromRightNodes());
            func->AddParam(var_name, var_type);
        }

        return i->Table()->AddEntry(func_name, func);
    };

    callbacks[CALL_FUNC_CMD] = [](AstNode *root, CInter i)
    {
        string func_name = i->RunAst(root->GetFromLeftNodes());

        if (!i->Table()->Has(func_name))
        {
            cout << "Error: " << func_name << " does not exist\n";
            return EMPTY_VAR_NAME;
        }

        ChimeraObject *obj = i->Table()->GetEntry(func_name);

        if (obj->GetType() != FUNC_DATA_TYPE)
        {
            cout << "Error: " << func_name << " is not a function\n";
            return EMPTY_VAR_NAME;
        }

        ChmrFunc *func = (ChmrFunc *)obj;
        size_t passed_params = root->Size(AstNode::RIGHT) * 2;

        if (func->ParamNums() != passed_params)
        {
            cout << "Error: incorrect number of parameters passed\n";
            return EMPTY_VAR_NAME;
        }

        struct param {
            ChimeraObject *obj;
            string name;
        };
        vector<param> params;

        size_t param_type_index = 1;
        for (size_t iter = 0; iter < passed_params / 2; iter++)
        {
            string param_name = i->RunAst(root->GetFromRightNodes(iter));

            if (!i->Table()->Has(param_name))
            {
                cout << "Error: param " << param_name << " does not exist\n";
                return EMPTY_VAR_NAME;
            }

            ChimeraObject *obj = i->Table()->GetEntry(param_name);

            if (obj->GetTypeName() != func->GetParamData(param_type_index))
            {
                cout << "Error: param " << *obj << " is a " << obj->GetTypeName() << ". Expected " << func->GetParamData(param_type_index) << '\n';
                return EMPTY_VAR_NAME;
            }

            param p;
            p.obj = obj;
            p.name = func->GetParamData(param_type_index-1);
            params.push_back(p);

            param_type_index += 2;
        }

        i->CreateScope(GEN_SCOPE);
        for(auto p : params) {
            i->Table()->AddOrUpdateRef(p.name, p.obj, true);
        }

        size_t instr = func->GetStartPoint();
        while (i->ast_trees[instr]->Type() != FUNC_RETR_CMD)
        {
            instr++;
        }

        func->SetEndPoint(i->cur_instruction+1);
        i->cur_func_running = func;
        i->GoTo(func->GetStartPoint(), false);

        i->RunCurInstruction(instr+1);

        i->Table()->AddOrUpdateRef(func_name + "ret", func->GetRet(), true);

        return func_name + "ret";
    };

    callbacks[FUNC_RETR_CMD] = [](AstNode *root, CInter i)
    {
        if (i->cur_func_running == nullptr)
        {
            cout << "Error: cannot return outside a function\n";
            return EMPTY_VAR_NAME;
        }
        string func_name = i->cur_func_running->ToStr();

        if (root->Size(AstNode::LEFT) > 0)
        {
            string ret_name = i->RunAst(root->GetFromLeftNodes());
            if (!i->Table()->Has(ret_name))
            {
                cout << "Error: ret val doesn't exist\n";
                i->DestroyScope();
                return EMPTY_VAR_NAME;
            }

            ChimeraObject *obj = i->Table()->GetEntry(ret_name);
            i->cur_func_running->StoreValInRet(obj);
        }
        i->ast_trees.push_back(MakeNode(NO_CMD));
        i->GoTo(i->cur_func_running->GetEndPoint());
        i->cur_func_running = nullptr;
        i->DestroyScope();
        return func_name;
    };
}