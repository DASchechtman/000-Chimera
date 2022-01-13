#include "Ast.hpp"

AstNode::~AstNode() {
    DeleteNodeList(left_nodes);
    DeleteNodeList(middle_nodes);
    DeleteNodeList(right_nodes);
    DeleteNodeList(extra_nodes);
}

void AstNode::DeleteNodeList(vector<AstNode*> &node_list) {
    for(AstNode *node : node_list) {
        if (node != nullptr) {
            delete node;
        }
    }
}

void AstNode::AddToLeftNodes(AstNode *node) {
    left_nodes.push_back(node);
}

void AstNode::AddToLeftNodes(size_t index, AstNode *node) {
    left_nodes[index] = node;
} 

void AstNode::AddToRightNodes(AstNode *node) {
    right_nodes.push_back(node);
}

void AstNode::AddToRightNodes(size_t index, AstNode *node) {
    right_nodes[index] = node;
}

void AstNode::AddToMiddleNodes(AstNode *node) {
    middle_nodes.push_back(node);
}

void AstNode::AddToMiddleNodes(size_t index, AstNode *node) {
    middle_nodes[index] = node;
}

void AstNode::SaveAsExtraNode(AstNode *node) {
    extra_nodes.push_back(node);
}

AstNode* AstNode::GetExtraNode(size_t index){
    return extra_nodes[index];
}

size_t AstNode::Extras() {
    return extra_nodes.size();
}

void AstNode::NullExtraNode(size_t index) {
    extra_nodes[index] = nullptr;
}

COMMANDS& AstNode::Type() {
    return type;
}

Data& AstNode::Value() {
    return value;
}

size_t AstNode::Size(int which) {
    switch (which)
    {
    case -1: {
        return left_nodes.size();
    }
    case 0: {
        return middle_nodes.size();
    }
    case 1: {
        return right_nodes.size();
    }
    
    default:
        return 0;
    }
}

AstNode* AstNode::GetFromLeftNodes(size_t index) {
    return left_nodes[index];
}

AstNode* AstNode::GetFromMiddleNodes(size_t index) {
    return middle_nodes[index];
}

AstNode* AstNode::GetFromRightNodes(size_t index) {
    return right_nodes[index];
}

void AstNode::CopyNodeList(vector<AstNode*> &to, vector<AstNode*> &from) {
    for (AstNode *node : from) {
        to.push_back(node->Copy());
    }
}

AstNode* AstNode::Copy() {
    AstNode *new_node = new AstNode();
    new_node->Value() = value;
    new_node->Type() = type;
    CopyNodeList(new_node->left_nodes, left_nodes);
    CopyNodeList(new_node->right_nodes, right_nodes);
    CopyNodeList(new_node->middle_nodes, middle_nodes);
    CopyNodeList(new_node->extra_nodes, extra_nodes);
    return new_node;
}

AstNode* MakeNode(COMMANDS cmd) {
    AstNode *new_node = new AstNode();
    new_node->Type() = cmd;
    new_node->Value().i = 0;
    new_node->Value().type = NON_DATA_TYPE;
    return new_node;
}

AstNode* MakeNode(COMMANDS cmd, string data, DataType d_type) {
    AstNode *new_node = new AstNode();
    new_node->Value().type = d_type;
    new_node->Value().s = data;
    new_node->Type() = cmd;
    return new_node;
}
