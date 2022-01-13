#pragma once

#include "CircularList.hpp"
#include <vector>
#include <memory>
#include <stack>

using namespace std;

/*
    the purpose of this class is to organize jump point values in such a way that will take the concept of scope into account of
    where the jump point is. for example 
    
    if <expr> start
        if <expr> start
        end
    else-if <expr> start
        if <expr>
        end
    end

    this data structure will prevent for the next jump point of the first nested if to point to the start of the second nested if.
    will only allow for the jump point of the next jump point from "if <expr> start" to be the line where "end" is within the same scope
*/

struct ScopeBlock {
    CircularList m_jump_points;

    // nodes to other part of tree
    vector<shared_ptr<ScopeBlock>> m_children;
    shared_ptr<ScopeBlock> m_parent;

    // way to tell where in the tree the program is
    // note: since code is read top to node starts from first to last child
    // depth just helps figure out which child to get relative to the root
    size_t m_depth = 0;
    size_t m_cur_child = 0; 

    // used to determine if the node represents an else-if/else block
    bool m_is_if_link = false;

    ScopeBlock() {};

    ScopeBlock(ScopeBlock *&old) {
        m_jump_points = old->m_jump_points;

        for(shared_ptr<ScopeBlock> item : old->m_children) {
            m_children.push_back(make_shared<ScopeBlock>(*item));
        }

        m_parent = make_shared<ScopeBlock>(*old->m_parent);
        m_cur_child = old->m_cur_child;
    } 
};

class ScopeTree {
private:
    shared_ptr<ScopeBlock> root;
    shared_ptr<ScopeBlock> cur_block;
    size_t size = 0;

    void MoveToLevel(size_t level);
    void MoveToNextNode(size_t index);

    // prevents double reference issues that would prevent shared_ptr from automatically freeing memory
    void AvoidCircularRefsBugs(shared_ptr<ScopeBlock> child);

protected:
public:

    ScopeTree();
    ~ScopeTree();
    void CreateNewBlock(bool is_if_link = false);
    void AddJpToBlock(size_t jump_point);
    void CloseBlock();
    void MoveToLastNode(size_t level);
    void Clear();
    size_t Size();

    CircularList* operator[] (size_t index);
};