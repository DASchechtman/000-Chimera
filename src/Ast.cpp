#include "Ast.hpp"

AstNode::~AstNode() {
}

void AstNode::AddToLeftNodes(AstNode *node) {
    shared_ptr<AstNode> ptr;
    ptr.reset(node);
    left_nodes.push_back(ptr);
}

void AstNode::AddToRightNodes(AstNode *node) {
    shared_ptr<AstNode> ptr;
    ptr.reset(node);
    right_nodes.push_back(ptr);
}

void AstNode::AddToMiddleNodes(AstNode *node) {
    shared_ptr<AstNode> ptr;
    ptr.reset(node);
    middle_nodes.push_back(ptr);
}

void AstNode::AddToLeftNodes(shared_ptr<AstNode> &node) {
    auto copy = Copy(node.get());
    shared_ptr<AstNode> ptr;
    ptr.reset(copy);
    left_nodes.push_back(ptr);
}

void AstNode::AddToRightNodes(shared_ptr<AstNode> &node) {
    auto copy = Copy(node.get());
    shared_ptr<AstNode> ptr;
    ptr.reset(copy);
    right_nodes.push_back(ptr);
}

void AstNode::AddToMiddleNodes(shared_ptr<AstNode> &node) {
    auto copy = Copy(node.get());
    shared_ptr<AstNode> ptr;
    ptr.reset(copy);
    middle_nodes.push_back(ptr);
}

void AstNode::SaveAsExtraNode(AstNode *node) {
    shared_ptr<AstNode> ptr;
    ptr.reset(node);
    extra_nodes.push_back(ptr);
}

void AstNode::SaveAsExtraNode(shared_ptr<AstNode> &node) {
    auto copy = Copy(node.get());
    shared_ptr<AstNode> ptr;
    ptr.reset(copy);
    extra_nodes.push_back(ptr);
}

shared_ptr<AstNode>& AstNode::GetExtraNode(size_t index){
    return extra_nodes[index];
}

size_t AstNode::Extras() {
    return extra_nodes.size();
}

void AstNode::NullExtraNode(size_t index) {
    extra_nodes.erase(extra_nodes.begin() + index);
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

shared_ptr<AstNode>& AstNode::GetFromLeftNodes(size_t index) {
    return left_nodes[index];
}

shared_ptr<AstNode>& AstNode::GetFromMiddleNodes(size_t index) {
    return middle_nodes[index];
}

shared_ptr<AstNode>& AstNode::GetFromRightNodes(size_t index) {
    return right_nodes[index];
}

void AstNode::CopyNodeList(vector<shared_ptr<AstNode>> &to, vector<shared_ptr<AstNode>> &from) {
    for (auto node : from) {
        auto copy = Copy(node.get());
        shared_ptr<AstNode> ptr;
        ptr.reset(copy);
        to.push_back(ptr);
    }
}

AstNode* AstNode::Copy(AstNode *old) {
    if (old == nullptr) {
        old = this;
    }

    AstNode *new_node = new AstNode();
    new_node->value = old->value;
    new_node->type = old->type;

    CopyNodeList(new_node->left_nodes, old->left_nodes);
    CopyNodeList(new_node->middle_nodes, old->middle_nodes);
    CopyNodeList(new_node->right_nodes, old->right_nodes);
    CopyNodeList(new_node->extra_nodes, old->extra_nodes);

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
