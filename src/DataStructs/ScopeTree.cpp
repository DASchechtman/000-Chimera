#include "ScopeTree.hpp"

ScopeTree::ScopeTree() {}

ScopeTree::~ScopeTree() {
    Clear();
}

void ScopeTree::MoveToLevel(size_t level) {
    while(level != cur_block->m_depth) {
        if (level > cur_block->m_depth) {
            if (cur_block->m_children.empty()) {
                break;
            }
            size_t size = cur_block->m_children.size();
            cur_block = cur_block->m_children[cur_block->m_cur_child % size];
        }
        else {
            if (!cur_block->m_parent) {
                break;
            }
            cur_block = cur_block->m_parent;
        }
    }
}

void ScopeTree::MoveToNextNode(size_t index) {
    cur_block->m_parent->m_cur_child++;
    size_t cur_index = cur_block->m_parent->m_cur_child;
    size_t size = cur_block->m_parent->m_children.size();
    cur_block = cur_block->m_parent->m_children[cur_index % size];
}

void ScopeTree::AvoidCircularRefsBugs(shared_ptr<ScopeBlock> child) {
    for (shared_ptr<ScopeBlock> c : child->m_children) {
        AvoidCircularRefsBugs(c);
    }
    child->m_parent = nullptr;
}

void ScopeTree::CreateNewBlock(bool is_if_link) {
    size++;
    if (!cur_block) {
        root = make_shared<ScopeBlock>(ScopeBlock());
        cur_block = root;

        // makes sure the root of a tree is never an if-statement
        if(!is_if_link) {
            return;
        }
    }

    shared_ptr<ScopeBlock> new_block = make_shared<ScopeBlock>(ScopeBlock());

    new_block->m_depth = cur_block->m_depth + 1;
    new_block->m_parent = cur_block;
    new_block->m_is_if_link = is_if_link;
    cur_block->m_children.push_back(new_block);
    cur_block = new_block;
}

void ScopeTree::AddJpToBlock(size_t jump_point) {
    cur_block->m_jump_points.Add(jump_point);
}

void ScopeTree::CloseBlock() {
    if (cur_block->m_parent) {
        cur_block = cur_block->m_parent;
    }
}

void ScopeTree::MoveToLastNode(size_t level) {
    if (level >= 1) {
        if (cur_block && level != cur_block->m_depth) {
            MoveToLevel(level);
        }

        cur_block->m_parent->m_cur_child -= 2;
        MoveToNextNode(level);
    }
}

void ScopeTree::Clear() {
    if (root) {
        AvoidCircularRefsBugs(root);
        cur_block.reset();
        root.reset();
    }
}

size_t ScopeTree::Size() {
    return size;
}

CircularList* ScopeTree::operator[](size_t index) {
    
    MoveToLevel(index);

    if(cur_block->m_jump_points.IsEmpty()) {
        index++;
        MoveToLevel(index);
    }

    CircularList *cur_jps = &cur_block->m_jump_points;
    if (cur_block->m_jump_points.AtLastElement() && cur_block->m_parent) {
        MoveToNextNode(index);
        if (cur_block->m_is_if_link) {
            CircularList *prev_jps = cur_jps;
            cur_jps = &cur_block->m_jump_points;
            prev_jps->Next();
        }
    }

    return cur_jps;
}