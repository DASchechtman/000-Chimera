#include "IntrBridge.hpp"
#include <functional>
#include <iostream>

using namespace std;

void Perform(AstNode *&root, AstNode *node, COMMANDS type)
{
    root = MakeNode(type);
    root->AddToLeftNodes(node);

    if(node->Extras() == 0) {
        if (type == ADDITION_CMD || type == SUBTRACTION_CMD) {
            node->SaveAsExtraNode(MakeNode(RAW_DATA_CMD, 0, INT_NODE_TYPE));
        }
        else {
            node->SaveAsExtraNode(MakeNode(RAW_DATA_CMD, 1, INT_NODE_TYPE));
        }
    }

    if (node->Extras() < 2)
    {
        root->AddToRightNodes(node->GetExtraNode());
    }
    else if (node->Extras() == 2)
    {
        AstNode *oper = MakeNode(type);
        oper->AddToLeftNodes(node->GetExtraNode());
        oper->AddToRightNodes(node->GetExtraNode(1));
        root->AddToRightNodes(oper);
    }
    else
    {
        AstNode *oper = MakeNode(type);
        AstNode *oper_ptr = oper;
        size_t index = 0;
        for (; index < node->Extras() - 2; index++)
        {
            AstNode *tmp = MakeNode(type);
            oper->AddToLeftNodes(node->GetExtraNode(index));
            oper->AddToRightNodes(tmp);
            oper = tmp;
            node->NullExtraNode(index);
        }

        oper->AddToLeftNodes(node->GetExtraNode(index));
        oper->AddToRightNodes(node->GetExtraNode(index + 1));
        root->AddToRightNodes(oper_ptr);
    }

    for(size_t i = 0; i < node->Extras(); i++) {
        node->NullExtraNode(i);
    }
}

AstNode* MakeStartAst() {
    return MakeNode(START_BLOCK_CMD);
}

AstNode* MakeEndScopeAst() {
    return MakeNode(END_SCOPE_CMD);
}

AstNode* MakeEndCtrlScopeAst() {
    return MakeNode(END_BLOCK_CMD);
}

AstNode* MakeIfDeclAst(AstNode *expr) {
    AstNode *control_block = MakeNode(CTRL_BLOCK_CMD);
    AstNode *if_block = MakeNode(IF_BLOCK_CMD);

    if_block->AddToLeftNodes(expr);
    control_block->AddToLeftNodes(if_block);

    return control_block;
}

AstNode* MakeElifDeclAst(AstNode *expr) {
    AstNode *control_block = MakeNode(CTRL_BLOCK_CMD);
    AstNode *elif_block = MakeNode(ELIF_BLOCK_CMD);

    elif_block->AddToLeftNodes(expr);
    control_block->AddToLeftNodes(elif_block);

    return control_block;
}

AstNode* MakeElseDeclAst() {
    AstNode *control_block = MakeNode(CTRL_BLOCK_CMD);
    AstNode *else_block = MakeNode(ELSE_BLOCK_CMD);

    control_block->AddToLeftNodes(else_block);

    return control_block;
}

AstNode* MakeWhileDeclAst(AstNode *expr) {
    AstNode *control_block = MakeNode(CTRL_BLOCK_CMD);
    AstNode *while_block = MakeNode(WHILE_BLOCK_CMD);

    while_block->AddToLeftNodes(expr);
    control_block->AddToLeftNodes(while_block);

    return control_block;
}

AstNode* MakeAssignAst(AstNode *id, AstNode *types, AstNode* expr) {
    AstNode *bind_cmd = MakeNode(BIND_CMD);
    bind_cmd->AddToLeftNodes(id);
    bind_cmd->AddToMiddleNodes(types);
    bind_cmd->AddToRightNodes(expr);

    return bind_cmd;
}

AstNode* MakeUnionAst(AstNode *id, AstNode *types, AstNode *expr) {
    AstNode *make_union_ast = MakeNode(MAKE_UNION_CMD);

    make_union_ast->AddToLeftNodes(id);
    make_union_ast->AddToMiddleNodes(types);

    for(size_t i = 0; i < types->Extras(); i++) {
        make_union_ast->AddToMiddleNodes(types->GetExtraNode(i));
        types->NullExtraNode(i);
    }

    make_union_ast->AddToRightNodes(expr);

    return make_union_ast;
}

AstNode* MakeUnionAst(AstNode *id, AstNode *expr) {
    AstNode *make_union_ast = MakeNode(MAKE_UNION_CMD);
    make_union_ast->AddToLeftNodes(id);
    make_union_ast->AddToRightNodes(expr);

    return make_union_ast;
}

AstNode* MakeReassignAst(AstNode *id, AstNode *expr) {
    AstNode *rebind_ast = MakeNode(REBIND_CMD);

    rebind_ast->AddToLeftNodes(id);
    rebind_ast->AddToRightNodes(expr);

    return rebind_ast;
}

AstNode* MakeRefAst(AstNode *id, AstNode *types, AstNode *expr) {
    AstNode *ref_ast = MakeNode(REFBIND_CMD);

    ref_ast->AddToLeftNodes(id);
    ref_ast->AddToMiddleNodes(types);
    ref_ast->AddToRightNodes(expr);

    return ref_ast;
}

AstNode* MakeArrayBindAst(AstNode *id, AstNode *types) {
    AstNode *array_bind_ast = MakeNode(MAKE_LIST_CMD);

    array_bind_ast->AddToLeftNodes(id);
    array_bind_ast->AddToRightNodes(types);

    for(size_t i = 0; i < types->Extras(); i++) {
        array_bind_ast->AddToRightNodes(types->GetExtraNode(i));
        types->NullExtraNode(i);
    }

    return array_bind_ast;
}

AstNode* MakeArrayTermAst(AstNode *data) {
    AstNode *arr = MakeTermNode(0, ARRAY_NODE_TYPE);
    arr->AddToLeftNodes(data);
    for(size_t i = 0; i < data->Extras(); i++) {
        arr->AddToLeftNodes(data->GetExtraNode(i));
        data->NullExtraNode(i);
    }
    return arr;
}

AstNode* MakeMapTermAst(AstNode *data) {
    AstNode *map = MakeTermNode(0, MAP_NODE_TYPE);

    for(size_t i = 0; i < data->Extras(); i += 2) {
        map->AddToLeftNodes(data->GetExtraNode(i));
        map->AddToRightNodes(data->GetExtraNode(i+1));
        data->NullExtraNode(i);
        data->NullExtraNode(i+1);
    }

    delete data;

    return map;
}

AstNode* MakeMapBindAst(AstNode* id, AstNode *key_type, AstNode *val_type) {
    AstNode *make_map_ast = MakeNode(MAKE_MAP_CMD);

    make_map_ast->AddToLeftNodes(id);
    make_map_ast->AddToMiddleNodes(key_type);
    make_map_ast->AddToRightNodes(val_type);

    return make_map_ast;
}

AstNode* MakeArrayBindAst(AstNode *id, AstNode *types, AstNode *expr) {
    AstNode *make_array_ast = MakeNode(MAKE_LIST_CMD);

    make_array_ast->AddToLeftNodes(id);
    make_array_ast->AddToMiddleNodes(expr);
    make_array_ast->AddToRightNodes(types);

    for(size_t i = 0; i < types->Extras(); i++) {
        make_array_ast->AddToRightNodes(types->GetExtraNode(i));
        types->NullExtraNode(i);
    }

    return make_array_ast;
}

AstNode* MakeRebindRefAst(AstNode *id, AstNode *expr) {
    AstNode *rebind_ref_ast = MakeNode(REBIND_REF_CMD);
    
    rebind_ref_ast->AddToLeftNodes(id);
    rebind_ref_ast->AddToRightNodes(expr);

    return rebind_ref_ast;
}

AstNode* MakePrintAst(AstNode *exprs) {
    AstNode *print_ast = MakeNode(PRINT_CMD);

    print_ast->AddToLeftNodes(exprs);

    for(size_t i = 0; i < exprs->Extras(); i++) {
        print_ast->AddToLeftNodes(exprs->GetExtraNode(i));
        exprs->NullExtraNode(i);
    }

    return print_ast;
}

AstNode* MakeLessCompAst(AstNode *left, AstNode *right) {
    AstNode *comp = MakeNode(LESS_CMD);

    comp->AddToLeftNodes(left);
    comp->AddToRightNodes(right);

    return comp;
}
AstNode* MakeGreaterCompAst(AstNode *left, AstNode *right) {
    AstNode *comp = MakeNode(GREATER_CMD);

    comp->AddToLeftNodes(left);
    comp->AddToRightNodes(right);

    return comp;
}

AstNode* MakeLessEqualCompAst(AstNode *left, AstNode *right) {
    AstNode *comp = MakeNode(LESS_EQ_CMD);

    comp->AddToLeftNodes(left);
    comp->AddToRightNodes(right);

    return comp;
}

AstNode* MakeGreaterEqualCompAst(AstNode *left, AstNode *right) {
    AstNode *comp = MakeNode(GREATER_EQ_CMD);

    comp->AddToLeftNodes(left);
    comp->AddToRightNodes(right);

    return comp;
}

AstNode* MakeEqualCompAst(AstNode *left, AstNode *right) {
    AstNode *comp = MakeNode(EQ_CMD);

    comp->AddToLeftNodes(left);
    comp->AddToRightNodes(right);

    return comp;
}

AstNode* MakeNotEqualCompAst(AstNode *left, AstNode *right) {
    AstNode *comp = MakeNode(NOT_CMD);
    AstNode *equal = MakeEqualCompAst(left, right);

    comp->AddToLeftNodes(equal);

    return comp;
}

AstNode* MakeAndAst(AstNode *left, AstNode *right) {
    AstNode *bool_op = MakeNode(AND_CMD);

    bool_op->AddToLeftNodes(left);
    bool_op->AddToRightNodes(right);

    return bool_op;
}

AstNode* MakeNotAst(AstNode *left) {
    AstNode *bool_op = MakeNode(NOT_CMD);

    bool_op->AddToLeftNodes(left);

    return bool_op;
}

AstNode* MakeOrAst(AstNode *left, AstNode *right) {
    AstNode *bool_op = MakeNode(OR_CMD);

    bool_op->AddToLeftNodes(left);
    bool_op->AddToRightNodes(right);

    return bool_op;
}

AstNode* MakeCastAst(AstNode *expr, AstNode *type) {
    AstNode *cast_ast = MakeNode(CAST_TYPE_CMD);

    cast_ast->AddToLeftNodes(expr);
    cast_ast->AddToRightNodes(type);

    return cast_ast;
}

AstNode* MakeAddToListAst(AstNode *id, AstNode *expr) {
    AstNode *add_to_array_ast = MakeNode(PUT_IN_CONTAINER_CMD);

    add_to_array_ast->AddToLeftNodes(id);
    add_to_array_ast->AddToRightNodes(expr);

    return add_to_array_ast;
}

AstNode* MakeAddToMapAst(AstNode *id, AstNode *key, AstNode *expr) {
    AstNode *add_to_map_ast = MakeNode(PUT_IN_MAP_CMD);

    add_to_map_ast->AddToLeftNodes(id);
    add_to_map_ast->AddToMiddleNodes(key);
    add_to_map_ast->AddToRightNodes(expr);

    return add_to_map_ast;
}

AstNode* MakeGetFromCollectionAst(AstNode *id, AstNode *expr) {
    AstNode *get_from_container_ast = MakeNode(GET_FROM_CONTAINER_CMD);

    get_from_container_ast->AddToLeftNodes(id);
    get_from_container_ast->AddToRightNodes(expr);

    return get_from_container_ast;
}

AstNode* MakeSetInCollectionAst(AstNode *id, AstNode *index, AstNode *val) {
    AstNode *set_in_container_ast = MakeNode(SET_IN_CONTAINER_CMD);

    set_in_container_ast->AddToLeftNodes(id);
    set_in_container_ast->AddToMiddleNodes(index);
    set_in_container_ast->AddToRightNodes(val);

    return set_in_container_ast;
}

AstNode* MakeCollectionSizeAst(AstNode *id) {
    AstNode *container_size_ast = MakeNode(GET_CONTAINER_SIZE_CMD);

    container_size_ast->AddToLeftNodes(id);

    return container_size_ast;
}

AstNode* MakeAddAst(AstNode *node) {
    AstNode *add_ast = nullptr;
    Perform(add_ast, node, ADDITION_CMD);
    return add_ast;
}

AstNode* MakeIncAst(AstNode *node) {
    AstNode* inc = MakeNode(INC_CMD);
    inc->AddToLeftNodes(node);
    return inc;
}

AstNode* MakeModAst(AstNode *left, AstNode *right) {
    AstNode *mod = MakeNode(MOD_CMD);
    mod->AddToLeftNodes(left);
    mod->AddToRightNodes(right);
    return mod;
}

AstNode* MakeFuncAst(AstNode *name, AstNode *params, AstNode *ret_type) {
    AstNode *func_call = new AstNode();
    func_call->AddToLeftNodes(name);
    func_call->AddToMiddleNodes(params);
    func_call->AddToRightNodes(ret_type);
    return func_call;
}

AstNode* MakeFuncParamAst(AstNode *name, AstNode *type) {
    AstNode *param = new AstNode();
    if (name != nullptr) {
        param->AddToLeftNodes(name);
    }
    param->AddToRightNodes(type);
    return param;
}

AstNode* MakeTermNode(string data, DataType type) {
    return MakeNode(RAW_DATA_CMD, data, type);
}

AstNode* MakeDataTypeNode(string type) {
    AstNode *track = MakeNode(TRACK_TYPE_CMD);
    AstNode *type_node = MakeNode(RAW_DATA_CMD, type, VAR_TYPE_NODE_TYPE);
    track->AddToLeftNodes(type_node);
    return track;
}

AstNode* MakeIDNode(string id) {
    return MakeNode(RAW_DATA_CMD, id, ID_NODE_TYPE);
}