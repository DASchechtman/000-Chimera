#pragma once

#include "../SymbolTable.hpp"


const string IF_SCOPE = "if scope";
const string ELIF_SCOPE = "else if scope";
const string ELSE_SCOPE = "else scope";
const string LOOP_SCOPE = "loop scope";
const string GEN_SCOPE = "gen scope";

class Scope {
private:
protected:
    string m_type = GEN_SCOPE;
public:

    virtual ~Scope(){};

    virtual SymbolTable* GetTable() = 0;
    virtual bool IsntRunnable() = 0;
    virtual void SetRunnableState(bool is_runnable) = 0;
    virtual string GetType() = 0;
};