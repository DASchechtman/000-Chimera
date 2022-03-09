#include "FuncOpers.hpp"

string GetParamName(shared_ptr<AstNode> &root) {
    if (root->Type() != FUNC_PARAM_CMD) {
        return EMPTY_VAR_NAME;
    }

    return root->GetFromLeftNodes()->Value().s;
}

string GetParamType(shared_ptr<AstNode> &root) {
    if (root->Type() != FUNC_PARAM_CMD) {
        return EMPTY_VAR_NAME;
    }
    auto v = root->GetFromRightNodes()->Value();
    auto r = *root->GetFromRightNodes();

    return root->GetFromRightNodes()->Value().s;
}

// PUBLIC METHODS BELOW ------------------------------------------------------------------------------------------------------------------
string MakeFunc(AstNode *root, SymbolTable *tbl, string func_name, string ret_type, size_t cur_i) {
    AstNode *params = nullptr;

    if (root->Size(AstNode::MIDDLE) > 0) {
        params = root->GetFromMiddleNodes().get();
    }

    ChmrFunc *func = new ChmrFunc(cur_i + 1, ret_type, func_name);

    bool is_valid_params = params != nullptr;
    size_t param_size = 0;

    if (is_valid_params) {
        param_size = params->Size(AstNode::LEFT);
    }

    for(size_t index = 0; is_valid_params && index < param_size; index++) {
        bool has_name = params->GetFromLeftNodes(index)->Size(AstNode::LEFT) > 0;
        string var_name;
        string var_type = GetParamType(params->GetFromLeftNodes(index));

        if (has_name) {
            var_name = GetParamName(params->GetFromLeftNodes(index));
        }
        else {
            var_name = "arg" + to_string(index);
        }

        if (var_type == EMPTY_VAR_NAME || var_name == EMPTY_VAR_NAME) {
            cout << "Error: couldn't get param name or type\n";
            return EMPTY_VAR_NAME;
        }

        func->AddParam(var_name, var_type);
    }

    return tbl->AddEntry(func_name, func);
}