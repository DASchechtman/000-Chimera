#include "Context.hpp"

bool Context::NewScopeEntered() {
    bool stack_is_empty = scope_branches_entered.size() == 0 || scopes.Size() == 0;
    if (stack_is_empty) { return false; }


    return scope_branches_entered.top() != scopes.Size();
}

bool Context::ScopeWasExecuted() {
    bool stack_is_empty = scope_branches_entered.size() == 0 || scopes.Size() == 0;
    if (stack_is_empty) { return false; }

    return scopes.Size() > scope_branches_entered.top();
}