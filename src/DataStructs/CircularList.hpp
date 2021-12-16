#pragma once

#include <vector>

using namespace std;

struct JumpInfo {
    size_t jump_point;
    size_t depth;
    bool can_jump = true;
};

class CircularList {
private:
    vector<JumpInfo> m_list;
    size_t m_cur_index = 0;

public:

    void Add(size_t data);
    size_t Next();
    size_t Cur();

    JumpInfo &CurInfo();
    JumpInfo &NextInfo(bool peek = false);
    JumpInfo &PrevInfo(bool peek = false);

    bool IsLastElement();
};