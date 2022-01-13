#pragma once

#include <vector>

using namespace std;
/*
    this class is used to get numbers that represent goto spots. Will give access to one jump point at a time starting from the front to the back of the list
    designed in such a way that you can keep getting the next element in the list without having to worry about going out of bounds of the list
*/

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
    bool IsEmpty();
    size_t Next();
    size_t Cur();

    JumpInfo &CurInfo();

    // the peek variable tells the function whether to actually move to the next element (the next or prev), or just look at that
    // element without actually changing the index counter
    JumpInfo &NextInfo(bool peek = false);
    JumpInfo &PrevInfo(bool peek = false);

    bool AtLastElement();
};