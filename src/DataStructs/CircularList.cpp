#include "CircularList.hpp"

void CircularList::Add(size_t data) {
    JumpInfo ji;
    ji.jump_point = data;
    m_list.push_back(ji);
}

bool CircularList::IsEmpty() {
    return m_list.empty();
}

size_t CircularList::Cur() {
    return m_list[m_cur_index%m_list.size()].jump_point;
}

size_t CircularList::Next() {
    m_cur_index++;
    return Cur();
}

JumpInfo& CircularList::CurInfo() {
    return m_list[m_cur_index%m_list.size()];
}

JumpInfo& CircularList::NextInfo(bool peek) {
    if (!peek) {
        m_cur_index++;
        return CurInfo();
    }
    return m_list[(m_cur_index+1)%m_list.size()];
}

JumpInfo& CircularList::PrevInfo(bool peek) {
    if (!peek) {
        m_cur_index--;
        return CurInfo();
    }
    return m_list[(m_cur_index-1)%m_list.size()];
}

bool CircularList::AtLastElement() {
    return (m_cur_index % m_list.size()) == m_list.size()-1;
}