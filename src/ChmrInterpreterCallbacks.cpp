#include "ChmrInterpreter.hpp"
#include <sstream>

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
            data_name = i->ProgramMem().GetConstsData(root->Value().i);
        }
        else if (root->Value().type == FLOAT_NODE_TYPE)
        {
            data_name = i->ProgramMem().GetConstsData(root->Value().f);
        }
        else if (root->Value().type == DOUBLE_NODE_TYPE)
        {
            data_name = i->ProgramMem().GetConstsData(root->Value().d);
        }
        else if (root->Value().type == CHAR_NODE_TYPE)
        {
            data_name = i->ProgramMem().GetConstsData(root->Value().c);
        }
        else if (root->Value().type == STRING_NODE_TYPE)
        {
            data_name = i->ProgramMem().GetConstsData(root->Value().s);
        }
        else if (root->Value().type == BOOL_NODE_TYPE)
        {
            data_name = i->ProgramMem().GetConstsData(root->Value().b);
        }
        else if (root->Value().type == ARRAY_NODE_TYPE)
        {
            string arr = MakeArray(EMPTY_VAR_NAME, UNKNOWN_TYPE_NAME, i->ProgramMem());
            for (size_t iter = 0; iter < root->Size(AstNode::LEFT); iter++)
            {
                PutInArray(arr, i->RunAst(root->GetFromLeftNodes(iter)), i->ProgramMem());
            }
            data_name = arr;
        }
        else if (root->Value().type == MAP_NODE_TYPE)
        {
            string map = MakeMap(EMPTY_VAR_NAME, UNKNOWN_TYPE_NAME, UNKNOWN_TYPE_NAME, i->ProgramMem());
            for (size_t iter = 0; iter < root->Size(AstNode::LEFT); iter++)
            {
                string key = i->RunAst(root->GetFromLeftNodes(iter));
                string val = i->RunAst(root->GetFromRightNodes(iter));
                PutInMap(map, key, val, i->ProgramMem());
            }
            data_name = map;
        }
        else if (root->Value().type == VAR_TYPE_NODE_TYPE || root->Value().type == ID_NODE_TYPE)
        {
            data_name = root->Value().s;
        }

        return data_name;
    };

    callbacks[BIND_CMD] = [](AstNode *root, CInter i)
    {
        string to = i->RunAst(root->GetFromLeftNodes());
        string from = i->RunAst(root->GetFromRightNodes());
        string type = "undefined";

        ChimeraObject *obj = i->ProgramMem().GetData(ORIGINAL, from);
        bool is_func = (obj != nullptr && obj->GetType() == FUNC_DATA_TYPE);

        if (root->Size(AstNode::MIDDLE) == 0 && obj != nullptr) {
            type = obj->GetTypeName();
        }
        else if (root->Size(AstNode::MIDDLE) == 0 && obj == nullptr) {
            cout << "Error: cannot infer type from data" << endl;
            return EMPTY_VAR_NAME;
        }
        else {
            type = i->RunAst(root->GetFromMiddleNodes());
        }

        ChimeraObject *dest = i->ProgramMem().GetData(ORIGINAL, to);
        if (is_func && dest != nullptr)
        {
            ChmrFunc *func = (ChmrFunc *)obj;
            func->SetRetDest(dest);
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
            string list = MakeArray(id, type, i->ProgramMem());
            return ReassignContainer(list, expr, i->ProgramMem());
        }
        else
        {
            return MakeArray(id, type, i->ProgramMem());
        }
    };

    callbacks[MAKE_MAP_CMD] = [](AstNode *root, CInter i)
    {
        string id = i->RunAst(root->GetFromLeftNodes());
        string key = i->RunAst(root->GetFromMiddleNodes());
        string val = i->RunAst(root->GetFromRightNodes());
        return MakeMap(id, key, val, i->ProgramMem());
    };

    callbacks[PUT_IN_CONTAINER_CMD] = [](AstNode *root, CInter i)
    {
        string list = i->RunAst(root->GetFromLeftNodes());
        string val = i->RunAst(root->GetFromRightNodes());
        return PutInArray(list, val, i->ProgramMem());
    };

    callbacks[PUT_IN_MAP_CMD] = [](AstNode *root, CInter i)
    {
        string map = i->RunAst(root->GetFromLeftNodes());
        string key = i->RunAst(root->GetFromMiddleNodes());
        string val = i->RunAst(root->GetFromRightNodes());
        return PutInMap(map, key, val, i->ProgramMem());
    };

    callbacks[GET_FROM_CONTAINER_CMD] = [](AstNode *root, CInter i)
    {
        string container = i->RunAst(root->GetFromLeftNodes());
        string list_index = i->RunAst(root->GetFromRightNodes());

        string data_name = GetChar(container, list_index, i->ProgramMem());

        if (data_name.empty()) {
            data_name = GetFromContainer(container, list_index, i->ProgramMem());
            if (data_name.empty()) {
                cout << "Error: cannot get from non-string or container type" << endl;
            }
        }


        return data_name;
    };

    callbacks[SET_IN_CONTAINER_CMD] = [](AstNode *root, CInter i)
    {
        string container = i->RunAst(root->GetFromLeftNodes());
        string index = i->RunAst(root->GetFromMiddleNodes());
        string new_val = i->RunAst(root->GetFromRightNodes());
        return SetInContainer(container, index, new_val, i->ProgramMem());
    };

    callbacks[GET_CONTAINER_SIZE_CMD] = [](AstNode *root, CInter i)
    {
        string container = i->RunAst(root->GetFromLeftNodes());
        string data = GetStrLen(container, i->ProgramMem());
        if (data.empty()) {
            data = GetContainerSize(container, i->ProgramMem());
            if (data.empty()) {
                cout << "Error: cannot get size of non-string or non-container type" << endl;
            }
        }
        return data;
    };

    auto MathOpers = [](AstNode *root, CInter i)
    {
        

        string left = i->RunAst(root->GetFromLeftNodes());
        
        if (!i->ProgramMem().IsTemp(left) || i->ProgramMem().IsConst(left)) {
            i->ProgramMem().GetData(CLONED, left);
        }

        for (size_t iter = 1; iter < root->Size(AstNode::LEFT); iter++)
        {
            string right = i->RunAst(root->GetFromLeftNodes(iter));
            i->ProgramMem().GetData(ORIGINAL, right);

            if (root->Type() == ADDITION_CMD)
            {
                Add(left, right, i->ProgramMem());
            }
            else if (root->Type() == SUBTRACTION_CMD)
            {
                Subtract(left, right, i->ProgramMem());
            }
            else if (root->Type() == MULTIPLY_CMD)
            {
                Multiply(left, right, i->ProgramMem());
            }
            else if (root->Type() == DIVIDE_CMD)
            {
                Divide(left, right, i->ProgramMem());
            }
            else if (root->Type() == POW_CMD)
            {
                Pow(left, right, i->ProgramMem());
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
        return root->Type() == AND_CMD ? And(left, right, i->ProgramMem()) : Or(left, right, i->ProgramMem());
    };

    callbacks[AND_CMD] = AndOrOper;
    callbacks[OR_CMD] = AndOrOper;

    callbacks[NOT_CMD] = [](AstNode *root, CInter i)
    {
        string val = i->RunAst(root->GetFromLeftNodes());
        return Not(val, i->ProgramMem());
    };

    auto CompareOper = [](AstNode *root, CInter i)
    {
        string left = i->RunAst(root->GetFromLeftNodes());
        string right = i->RunAst(root->GetFromRightNodes());

        if (root->Type() == LESS_CMD)
        {
            return Less(left, right, i->ProgramMem());
        }
        else if (root->Type() == LESS_EQ_CMD)
        {
            return LessEqual(left, right, i->ProgramMem());
        }
        else if (root->Type() == GREATER_CMD)
        {
            return Greater(left, right, i->ProgramMem());
        }
        else if (root->Type() == GREATER_EQ_CMD)
        {
            return GreaterEqual(left, right, i->ProgramMem());
        }
        else if (root->Type() == EQ_CMD)
        {
            return Equal(left, right, i->ProgramMem());
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
        string val = i->RunAst(root->GetFromLeftNodes());
        CircularList *jump_points = i->CurScopeTree()[i->ScopeLevel()];
        size_t next_jump_point = jump_points->Next();
        i->ScopesRan().push(i->CurScopes().Size());
        bool can_run = i->ProgramMem().HasData(val) && i->ProgramMem().GetData(ORIGINAL, val)->ToBool();
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
        CircularList *jump = i->CurScopeTree()[i->ScopeLevel() - 1];
        size_t next = jump->Next();
        bool prev_if_branch_ran = i->run_time_context.top().NewScopeEntered();
        if (!prev_if_branch_ran)
        {
            string val = i->RunAst(root->GetFromLeftNodes());
            bool can_run = i->ProgramMem().GetData(ORIGINAL, val)->ToBool();

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
        CircularList *jump = i->CurScopeTree()[i->ScopeLevel() - 1];
        size_t next = jump->Next();
        bool prev_if_branch_ran = i->run_time_context.top().NewScopeEntered();
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
        CircularList *jump = i->CurScopeTree()[i->ScopeLevel()];
        size_t next = jump->Next();
        string var_id = i->RunAst(root->GetFromLeftNodes());
        bool can_run = i->ProgramMem().HasData(var_id) && i->ProgramMem().GetData(ORIGINAL, var_id)->ToBool();
        i->ScopesRan().push(i->CurScopes().Size());
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
        CircularList *jump = i->CurScopeTree()[i->ScopeLevel()];
        JumpInfo info = jump->PrevInfo(true);
        bool is_ctrl = i->ast_trees[info.jump_point]->Type() == CTRL_BLOCK_CMD;
        bool is_while = is_ctrl && i->ast_trees[info.jump_point]->GetFromLeftNodes()->Type() == WHILE_BLOCK_CMD;

        if (is_while && info.can_jump)
        {
            i->CurScopeTree().MoveToLastNode(i->ScopeLevel());
            i->GoTo(jump->PrevInfo().jump_point);
        }
        else
        {
            jump->Next();
        }

        bool scope_was_created = i->CurScopes().Size() > i->ScopesRan().top();
        while (scope_was_created)
        {
            i->DestroyScope();
            scope_was_created = i->CurScopes().Size() > i->ScopesRan().top();
        }

        if (i->ScopesRan().size() > 1) {
            i->ScopesRan().pop();
        }

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
        Inc(var, i->ProgramMem());
        return var;
    };

    callbacks[MOD_CMD] = [](AstNode *root, CInter i)
    {
        string left = i->RunAst(root->GetFromLeftNodes());
        string right = i->RunAst(root->GetFromRightNodes());
        return Mod(left, right, i->ProgramMem());
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
        i->CurScopeLevel() = SIZE_MAX;
        size_t cur_instruction = i->run_time_context.top().cur_instruction;
        string func_name = i->RunAst(root->GetFromLeftNodes());
        string ret_type = i->RunAst(root->GetFromRightNodes());
        COMMANDS func_type = root->GetFromLeftNodes(1)->Type();

        AstNode *params = nullptr;

        bool has_params = root->Size(AstNode::MIDDLE) > 0;
        size_t params_list_size = 0;
        if (has_params)
        {
            params = root->GetFromMiddleNodes().get();
            params_list_size = params->Size(AstNode::LEFT);
        }

        
        i->ProgramMem().CreateFunc(func_name, cur_instruction + 1, ret_type, func_type);
        ChmrFunc *func = (ChmrFunc *)i->ProgramMem().GetData(ORIGINAL, func_name);

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

        func->create_scope_mem = &i->ProgramMem();

        return func_name;
    };

    callbacks[CALL_FUNC_CMD] = [](AstNode *root, CInter i)
    {
        string func_name = i->RunAst(root->GetFromLeftNodes());

        bool func_exists = i->ProgramMem().HasData(func_name);
        if (!func_exists)
        {
            cout << "Error: " << func_name << " does not exist\n";
            return EMPTY_VAR_NAME;
        }

        ChimeraObject *obj = i->ProgramMem().GetData(ORIGINAL, func_name);

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
        // accounts for the lacking type info
        bool correct_num_of_params = func->ParamNums() == num_o_passed_params * 2;
        if (!correct_num_of_params)
        {
            cout << "Error: incorrect number of parameters passed\n";
            cout << "Expected: " << func->ParamNums()/2 << " Given: " << num_o_passed_params << "\n";
            return EMPTY_VAR_NAME;
        }

        vector<ChimeraObject*> func_args_objs;
        vector<string> func_args_names;
        vector<bool> can_ref_args;

        size_t param_type_index = 1;
        for (size_t iter = 0; iter < num_o_passed_params; iter++)
        {
            string param_value = i->RunAst(root->GetFromRightNodes(iter));

            bool has_param_expression = i->ProgramMem().HasData(param_value);
            if (!has_param_expression)
            {
                cout << "Error: param " << param_value << " does not exist\n";
                return EMPTY_VAR_NAME;
            }

            ChimeraObject *expression = i->ProgramMem().GetData(ORIGINAL, param_value);

            bool correct_param_type = expression->GetTypeName() == func->GetParamData(param_type_index);
            if (!correct_param_type)
            {
                cout << "Error: param " << *expression << " is a " << expression->GetTypeName() << ". Expected " << func->GetParamData(param_type_index) << endl;
                return EMPTY_VAR_NAME;
            }

            string param_name = func->GetParamData(param_type_index - 1);
            func_args_names.push_back(param_value);
            func_args_names.push_back(param_name);

            param_type_index += 2;
        }
        
        Memory &old = i->ProgramMem();
        i->run_time_context.push(Context(func->GetStartPoint(), func->ToStr(), func));

        if (!func->GetEndPoint()) {
            size_t index = func->GetStartPoint();
            while (i->ast_trees[index]->Type() != FUNC_END_CMD) {
                index++;
            }
            func->SetFuncEndPoint(index);
        }
        
        i->ProgramMem().LinkOtherMemory(func->create_scope_mem);
        func->CopyParamsToNewContext(func_args_names, i->ProgramMem(), old);
        i->RunCurInstruction(func->GetEndPoint(), false);

        i->run_time_context.pop();

        string ret_name = func_name + "ret";
        i->ProgramMem().CreateData(ret_name, func->GetRet()->GetType());
        i->ProgramMem().InitData(func->GetRet(), ret_name);

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
        ChmrFunc *func = i->run_time_context.top().func;

        bool has_ret_val = root->Size(AstNode::LEFT) > 0;
        if (has_ret_val)
        {
            string ret_name = i->RunAst(root->GetFromLeftNodes());
            if (!i->ProgramMem().HasData(ret_name))
            {
                cout << "Error: ret val doesn't exist\n";
                i->DestroyScope();
                return EMPTY_VAR_NAME;
            }

            ChimeraObject *obj = i->ProgramMem().GetData(ORIGINAL, ret_name);
            func_name = func->StoreValInRet(obj) == FAIL ? EMPTY_VAR_NAME : func_name;
        }

        i->GoTo(func->GetEndPoint());
        return func_name;
    };

    callbacks[REMOVE_FROM_CONTAINER_CMD] = [](AstNode *root, CInter i) {
        string container = i->RunAst(root->GetFromLeftNodes());
        string item = i->RunAst(root->GetFromRightNodes());
        return RemoveFromContainer(container, item, i->ProgramMem());
    };

    callbacks[QUERY_CONTAINER_CMD] = [](AstNode *root, CInter i) {
        string container = i->RunAst(root->GetFromLeftNodes());
        string item = i->RunAst(root->GetFromRightNodes());
        return QueryContainer(container, item, i->ProgramMem());
    };
    
    callbacks[GET_TYPE_CMD] = [](AstNode *root, CInter i) {
        string var = i->RunAst(root->GetFromLeftNodes());
        if (!i->ProgramMem().HasData(var)) {
            cout << "Error: cannot get type of non-existent data" << endl;
            return EMPTY_VAR_NAME;
        }
        string type_name = i->ProgramMem().GetData(ORIGINAL, var)->GetTypeName();
        return i->ProgramMem().GetConstsData(type_name);
    };

    callbacks[INPUT_USER_DATA_CMD] = [](AstNode *root, CInter i) {
        string input_msg = i->RunAst(root->GetFromLeftNodes());
        string input_results;
        if (i->ProgramMem().HasData(input_msg)) {
            cout << *i->ProgramMem().GetData(ORIGINAL, input_msg);
        }
        else {
            cout << "no input message: ";
        }
        cout << flush;

        getline(cin, input_results);
        auto IsNum = [](string &str) {
            bool is_num = true;
            bool dot_found = false;
            for(size_t i = 0; i < str.length(); i++) {
                char c = str[i];
                bool last_char = i == str.length()-1;
                bool is_digit = c >= '0' && c <= '9';

                if (c == '.' && !dot_found && !last_char) {
                    dot_found = true;
                    continue;
                }

                if (!is_digit && last_char && str[i-1] != '.') {
                    continue;
                }

                if (!is_digit) {
                    is_num = false;
                    break;
                }
            }
            return is_num;
        };

        string empty = EMPTY_VAR_NAME;
        if (IsNum(input_results)) {
            switch(input_results.back()) {
                case 'i': {
                    auto data = stoll(input_results);
                    string var_name = i->ProgramMem().CreateData(empty, INT_DATA_TYPE);
                    i->ProgramMem().InitData(data, var_name);
                    return var_name;
                }
                case 'f': {
                    auto data = stof(input_results);
                    string var_name = i->ProgramMem().CreateData(empty, FLOAT_DATA_TYPE);
                    i->ProgramMem().InitData(data, var_name);
                    return var_name;
                }
                default: {
                    char c = input_results.back();
                    if (c == 'd' || (c >= '0' && c <= '9')) {
                        auto data = (chmr_dbl)stod(input_results);
                        string var_name = i->ProgramMem().CreateData(empty, DOUBLE_DATA_TYPE);
                        i->ProgramMem().InitData(data, var_name);
                        return var_name;
                    }
                }
            }
        }

        string var_name = i->ProgramMem().CreateData(empty, STRING_DATA_TYPE);
        i->ProgramMem().InitData(input_results, var_name);
        return var_name;
    };
}