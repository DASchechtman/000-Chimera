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
        }
        else if (root->Value().type == FLOAT_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().f);
        }
        else if (root->Value().type == DOUBLE_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().d);
        }
        else if (root->Value().type == CHAR_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().c);
        }
        else if (root->Value().type == STRING_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().s);
        }
        else if (root->Value().type == BOOL_NODE_TYPE)
        {
            data_name = i->Table()->GetConstEntry(root->Value().b);
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
        auto CloneToAvoidBadDataMutation = [](string &arg_name, SymbolTable *tbl) {
            if (!tbl->Has(arg_name)) {
                cout << "Error: cannot do math oper on non-existent " << arg_name << endl;
                arg_name = EMPTY_VAR_NAME;
                return;
            }

            bool will_mutate_badly = (
                !tbl->IsTemp(arg_name)
                || tbl->GetEntry(arg_name)->GetConstStatus()
                || tbl->IsRef(arg_name)
            );

            if (will_mutate_badly) {
                arg_name = tbl->AddEntry(EMPTY_VAR_NAME, tbl->GetEntry(arg_name)->Clone());
            }

            return;
        };

        string left = i->RunAst(root->GetFromLeftNodes());
        CloneToAvoidBadDataMutation(left, i->Table());

        for (size_t iter = 1; iter < root->Size(AstNode::LEFT); iter++)
        {
            string right = i->RunAst(root->GetFromLeftNodes(iter));
            CloneToAvoidBadDataMutation(right, i->Table());

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
        cout << endl;
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
        size_t cur_instruction = i->run_time_context.top().cur_instruction;
        string func_name = i->RunAst(root->GetFromLeftNodes());
        string ret_type = i->RunAst(root->GetFromRightNodes());

        AstNode *params = nullptr;

        bool has_params = root->Size(AstNode::MIDDLE) > 0;
        size_t params_list_size = 0;
        if (has_params)
        {
            params = root->GetFromMiddleNodes().get();
            params_list_size = params->Size(AstNode::LEFT);
        }

        ChmrFunc *func = new ChmrFunc(cur_instruction + 1, ret_type, func_name);


        for (size_t index = 0; params && index < params_list_size; index++)
        {
            auto param_from_list = params->GetFromLeftNodes(index);
            bool has_name = params->GetFromLeftNodes(index)->Size(AstNode::LEFT) > 0;
            string var_name;
            string var_type = i->RunAst(param_from_list->GetFromRightNodes());

            if (has_name)
            {
                var_name = i->RunAst(param_from_list->GetFromLeftNodes());
            }
            else
            {
                var_name = "arg" + to_string(index);
            }

            bool not_enough_param_data = var_type == EMPTY_VAR_NAME || var_name == EMPTY_VAR_NAME;
            if (not_enough_param_data)
            {
                cout << "Error: couldn't get param name or type\n";
                return EMPTY_VAR_NAME;
            }

            func->AddParam(var_name, var_type);
        }

        return i->Table()->AddEntry(func_name, func);
    };

    callbacks[CALL_FUNC_CMD] = [](AstNode *root, CInter i)
    {
        string func_name = i->RunAst(root->GetFromLeftNodes());

        bool func_exists = i->Table()->Has(func_name);
        if (!func_exists)
        {
            cout << "Error: " << func_name << " does not exist\n";
            return EMPTY_VAR_NAME;
        }

        ChimeraObject *obj = i->Table()->GetEntry(func_name);

        bool is_func = obj->GetType() == FUNC_DATA_TYPE;
        if (!is_func)
        {
            cout << "Error: " << func_name << " is not a function\n";
            return EMPTY_VAR_NAME;
        }

        ChmrFunc *func = (ChmrFunc *)obj; 
        size_t num_o_passed_params = root->Size(AstNode::RIGHT);

        // multipled by two because the ParamNums will always return a list of [name, type, name, type, etc]
        // so since only arguments are being passed and not their corrisponding types, the multiplication
        // accounts for that
        bool correct_num_of_params = func->ParamNums() == num_o_passed_params * 2;
        if (!correct_num_of_params)
        {
            cout << "Error: incorrect number of parameters passed\n";
            return EMPTY_VAR_NAME;
        }

        struct param
        {
            ChimeraObject *p_obj = nullptr;
            string p_name;
            bool cant_reference = false;

            param(ChimeraObject *obj, string name) : p_obj(obj), p_name(name) {}
        };

        vector<param> func_args;

        size_t param_type_index = 1;
        for (size_t iter = 0; iter < num_o_passed_params; iter++)
        {
            string param_value = i->RunAst(root->GetFromRightNodes(iter));

            bool has_param_expression = i->Table()->Has(param_value);
            if (!has_param_expression)
            {
                cout << "Error: param " << param_value << " does not exist\n";
                return EMPTY_VAR_NAME;
            }

            ChimeraObject *expression = i->Table()->GetEntry(param_value);

            bool correct_param_type = expression->GetTypeName() == func->GetParamData(param_type_index);
            if (!correct_param_type)
            {
                cout << "Error: param " << *expression << " is a " << expression->GetTypeName() << ". Expected " << func->GetParamData(param_type_index) << endl;
                return EMPTY_VAR_NAME;
            }

            string param_name = func->GetParamData(param_type_index - 1);
            param p(expression, param_name);
            p.cant_reference = expression->GetConstStatus() || i->Table()->IsTemp(param_value);
            func_args.push_back(p);
            param_type_index += 2;
        }

        i->CreateScope("func scope");

        for (auto arg : func_args)
        {
            if (arg.cant_reference)
            {
                ChimeraObject *obj = arg.p_obj->Clone();
                obj->SetConstStatus(false);
                i->Table()->AddEntry(arg.p_name, obj);
                continue;
            }

            i->Table()->AddOrUpdateRef(arg.p_name, arg.p_obj, true);
        }

        size_t func_end_point = func->GetStartPoint();
        while (i->ast_trees[func_end_point]->Type() != FUNC_RETR_CMD)
        {
            func_end_point++;
        }

        i->run_time_context.push(Context(func->GetStartPoint(), func->ToStr(), func));

        func->SetReturnPoint(i->CurInstruction() + 1);
        i->GoTo(func->GetStartPoint(), false);
        i->RunCurInstruction(func_end_point + 1, false);

        i->run_time_context.pop();

        i->Table()->AddOrUpdateRef(func_name + "ret", func->GetRet(), true);

        return func_name + "ret";
    };

    callbacks[FUNC_RETR_CMD] = [](AstNode *root, CInter i)
    {
        if (i->run_time_context.top().func == nullptr)
        {
            cout << "Error: cannot return outside a function\n";
            return EMPTY_VAR_NAME;
        }
        string func_name = i->run_time_context.top().func->ToStr();

        bool has_ret_val = root->Size(AstNode::LEFT) > 0;
        if (has_ret_val)
        {
            string ret_name = i->RunAst(root->GetFromLeftNodes());
            if (!i->Table()->Has(ret_name))
            {
                cout << "Error: ret val doesn't exist\n";
                i->DestroyScope();
                return EMPTY_VAR_NAME;
            }

            ChimeraObject *obj = i->Table()->GetEntry(ret_name);
            ChmrFunc *func = i->run_time_context.top().func;
            func_name = func->StoreValInRet(obj) == FAIL ? EMPTY_VAR_NAME : func_name;
        }

        i->DestroyScope();
        return func_name;
    };
}