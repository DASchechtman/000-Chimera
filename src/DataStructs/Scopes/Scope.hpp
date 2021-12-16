#pragma once

#include "../SymbolTable.hpp"

/*
    base class for any type of scope the interpreter needs to run a program
    a scope is a combination of a unique symbol table and other code to modify how that symbol table
    relates to other symbol tables on the scope stack. For instance an if scope is able to tell how many else-if/else blocks
    follow an if block, and gives those block scopes access to the same symbol table and parent scope as the if block
*/

// used this because when it comes time to implement repeating scopes like loops and functions
// it'll be easier to store what type of scope should be created, because all the input into the interpreter is a
// string. Therefore the best way to remember an instruction is to store that string input
const string IF_SCOPE = "if scope";
const string ELIF_SCOPE = "else if scope";
const string ELSE_SCOPE = "else scope";
const string WHILE_LOOP_SCOPE = "loop scope";
const string GEN_SCOPE = "gen scope";

class Scope {
private:
protected:
    string m_type = GEN_SCOPE;
public:

    virtual ~Scope(){};

    virtual SymbolTable* GetTable() = 0;

    // returns true if the current scope can't be run (like an if-statement with a false run condition)
    virtual bool IsntRunnable() = 0;
    virtual bool ParentIsntRunnable() = 0;

    // the next scope to be pushed on the stack will be passed a bool value
    // so it can compute if it can run or not
    virtual void SetRunnableState(bool is_runnable) = 0;
    virtual string GetType() = 0;

    /* this is to allow scopes to report how many different scopes share resources
    for example, and if/else-if/else-if/else chain all share the same symbol table
    so this will return 4, indicating that all these scopes share the same resources/parent scope*/
    virtual size_t NumOfScopeMembers() = 0;
};