#pragma once

#include <string>
#include <memory>
#include <type_traits>
#include <vector>

using namespace std;

typedef long long int64;
typedef long double dbl128;

enum COMMANDS {
    NO_CMD,
    RAW_DATA_CMD,
    CHECK_SCOPE_CMD,
    CHECK_PARENT_SCOPE_CMD,
    OVERRIDE_SCOPE_CMD,
    BIND_CMD,
    REBIND_CMD,
    REFBIND_CMD,
    MAKE_UNION_CMD,
    MAKE_LIST_CMD,
    MAKE_MAP_CMD,
    PUT_IN_CONTAINER_CMD,
    PUT_IN_MAP_CMD,
    GET_FROM_CONTAINER_CMD,
    SET_IN_CONTAINER_CMD,
    REASSIGN_CONTAINER_CMD,
    GET_CONTAINER_SIZE_CMD,
    CLONE_TO_TEMP_CMD,
    ADDITION_CMD,
    SUBTRACTION_CMD,
    MULTIPLY_CMD,
    DIVIDE_CMD,
    POW_CMD,
    CAST_TYPE_CMD,
    AND_CMD,
    OR_CMD,
    NOT_CMD,
    LESS_CMD,
    LESS_EQ_CMD,
    GREATER_CMD,
    GREATER_EQ_CMD,
    EQ_CMD,
    GARBAGE_COLLECT_CMD,
    CREATE_SCOPE_CMD,
    DESTROY_SCOPE_CMD,
    SET_NEXT_SCOPE_CMD,
    PRINT_CMD,
    CTRL_BLOCK_CMD,
    IF_BLOCK_CMD,
    ELIF_BLOCK_CMD,
    ELSE_BLOCK_CMD,
    WHILE_BLOCK_CMD,
    START_BLOCK_CMD,
    END_BLOCK_CMD
};

enum DataType {
    INT_NODE_TYPE, 
    FLOAT_NODE_TYPE, 
    DOUBLE_NODE_TYPE, 
    CHAR_NODE_TYPE, 
    STRING_NODE_TYPE, 
    BOOL_NODE_TYPE, 
    VAR_TYPE_NODE_TYPE,
    ID_NODE_TYPE,
    NON_DATA_TYPE
};

struct Data
{
    DataType type;
    int64 i;
    float f;
    dbl128 d;
    char32_t c;
    string s;
    bool b;
};

struct AstNode {
private:
    COMMANDS type;
    Data value;
    size_t index;
    vector<AstNode*> lnode;
    vector<AstNode*> mnode;
    vector<AstNode*> rnode;
    vector<AstNode*> additional;

    void DeleteNodeList(vector<AstNode*> &node_list) {
        for(auto node : node_list) {
            if (node != nullptr) {
                delete node;
            }
        }
    }

public:

    static const int RIGHT = 1;
    static const int MIDDLE = 0;
    static const int LEFT = -1;

    void SetLeft(AstNode *node) {
        lnode.push_back(node);
    }

    void SetLeft(size_t index, AstNode *node) {
        lnode[index] = node;
    }

    void SetRight(AstNode *node) {
        rnode.push_back(node);
    }

    void SetRight(size_t index, AstNode *node) {
        rnode[index] = node;
    }

    void SetMiddle(AstNode *node) {
        mnode.push_back(node);
    }

    void SetMiddle(size_t index, AstNode *node) {
        mnode[index] = node;
    }

    void PutInAdditional(AstNode *node) {
        additional.push_back(node);
    }

    AstNode* GetAdditional(size_t index = 0){
        return additional[index];
    }

    size_t Extras() {
        return additional.size();
    }

    void NullAdditional(size_t index) {
        additional[index] = nullptr;
    }

    COMMANDS& Type() {
        return type;
    }

    Data& Value() {
        return value;
    }

    size_t Size(int which) {
        switch (which)
        {
        case -1: {
            return lnode.size();
        }
        case 0: {
            return mnode.size();
        }
        case 1: {
            return rnode.size();
        }
        
        default:
            return 0;
        }
    }

    AstNode* GetLeft(size_t index = 0) {
        return lnode[index];
    }

    AstNode* GetMiddle(size_t index = 0) {
        return mnode[index];
    }

    AstNode* GetRight(size_t index = 0) {
        return rnode[index];
    }

    ~AstNode() {
        DeleteNodeList(lnode);
        DeleteNodeList(mnode);
        DeleteNodeList(rnode);
        DeleteNodeList(additional);
    }
};

AstNode* MakeNode(COMMANDS cmd, string data, DataType d_type);

template<class T>
AstNode* MakeNode(COMMANDS cmd, T data, DataType d_type) {
    auto new_node = new AstNode();
    new_node->Value().type = d_type;
    new_node->Type() = cmd;
 
    switch(d_type) {
        case INT_NODE_TYPE: {
            new_node->Value().i = data;
            break;
        }
        case FLOAT_NODE_TYPE: {
            new_node->Value().f = data;
            break;
        }
        case DOUBLE_NODE_TYPE: {
            new_node->Value().d = data;
            break;
        }
        case CHAR_NODE_TYPE: {
            new_node->Value().c = data;
            break;
        }
        case BOOL_NODE_TYPE: {
            new_node->Value().b = data;
            break;
        }
        default: {}
    }

    return new_node;
}

AstNode* MakeNode(COMMANDS cmd);