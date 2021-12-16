#pragma once

#include "CircularList.hpp"
#include <vector>
#include <memory>
#include <stack>

using namespace std;

struct ScopeBlock {
    CircularList jump_points;
    vector<shared_ptr<ScopeBlock>> children;
    shared_ptr<ScopeBlock> parent;
    size_t depth = 0;
    size_t cur_child = 0; 
    bool is_if_link = false;
    bool is_else_link = false;

    ScopeBlock() {};

    ScopeBlock(ScopeBlock *&old) {
        jump_points = old->jump_points;

        for(auto item : old->children) {
            children.push_back(make_shared<ScopeBlock>(*item));
        }

        parent = make_shared<ScopeBlock>(*old->parent);
    } 
};

class ScopeTree {
private:
    shared_ptr<ScopeBlock> root;
    shared_ptr<ScopeBlock> cur_block;

    void MoveToLevel(size_t level);
    void MoveToNextNode(size_t index);
    void RemoveParent(shared_ptr<ScopeBlock> child);

protected:
public:

    ScopeTree();
    ~ScopeTree();
    void CreateNewBlock(bool is_if_link = false);
    void AddJpToBlock(size_t jump_point);
    void CloseBlock();
    void MoveToLastNode(size_t level);
    void Clear();

    CircularList* operator[] (size_t index);
};