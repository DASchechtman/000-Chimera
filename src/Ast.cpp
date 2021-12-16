#include "Ast.hpp"

AstNode* MakeNode(COMMANDS cmd) {
    auto new_node = new AstNode();
    new_node->Type() = cmd;
    new_node->Value().i = 0;
    new_node->Value().type = NON_DATA_TYPE;
    return new_node;
}

AstNode* MakeNode(COMMANDS cmd, string data, DataType d_type) {
    auto new_node = new AstNode();
    new_node->Value().type = d_type;
    new_node->Value().s = data;
    new_node->Type() = cmd;
    return new_node;
}
