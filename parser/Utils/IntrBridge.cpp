#include "IntrBridge.hpp"
#include <functional>
#include <iostream>

using namespace std;

void Perform(AstNode *&root, AstNode *node, COMMANDS type)
{
    root = MakeNode(type);
    root->SetLeft(node);

    if(node->Extras() == 0) {
        if (type == ADDITION_CMD || type == SUBTRACTION_CMD) {
            node->PutInAdditional(MakeNode(RAW_DATA_CMD, 0, INT_NODE_TYPE));
        }
        else {
            node->PutInAdditional(MakeNode(RAW_DATA_CMD, 1, INT_NODE_TYPE));
        }
    }

    if (node->Extras() < 2)
    {
        root->SetRight(node->GetAdditional());
    }
    else if (node->Extras() == 2)
    {
        auto oper = MakeNode(type);
        oper->SetLeft(node->GetAdditional());
        oper->SetRight(node->GetAdditional(1));
        root->SetRight(oper);
    }
    else
    {
        auto oper = MakeNode(type);
        auto oper_ptr = oper;
        size_t index = 0;
        for (; index < node->Extras() - 2; index++)
        {
            auto tmp = MakeNode(type);
            oper->SetLeft(node->GetAdditional(index));
            oper->SetRight(tmp);
            oper = tmp;
            node->NullAdditional(index);
        }

        oper->SetLeft(node->GetAdditional(index));
        oper->SetRight(node->GetAdditional(index + 1));
        root->SetRight(oper_ptr);
    }

    for(size_t i = 0; i < node->Extras(); i++) {
        node->NullAdditional(i);
    }
}