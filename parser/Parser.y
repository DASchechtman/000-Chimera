
%{
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include "Utils/UnionStruct.hpp"
#include "../src/Ast.hpp"
#include "../src/ChmrInterpreter.hpp"
#include "Utils/IntrBridge.hpp"

using namespace std;

int lineno = 0;
ChmrInterpreter i;
string scope_type;
AstNode *root = nullptr;

void PrintLineNo();
void yyerror(const char* err);
extern int yylex();
extern FILE *yyin;
extern void yyrestart(FILE* input);
extern char* yytext;
%}

%define parse.error verbose

// variable types
%token <types> INT FLOAT DOUBLE BOOL CHAR STRING LIST MAP

// keywords
%token CAST LESS GREATER LESS_EQUAL GREATER_EQUAL EQUAL NOT_EQUAL PRINT AND OR NOT EXIT 
%token NEWLINE SEMICOLON EOPU REF ADD SUB MUL DIV POW ADD_LIST ADD_MAP SET GET POINTS_TO
<<<<<<< HEAD
%token START END IF ELSE
=======
%token START END IF ELSE WHILE SIZE
>>>>>>> @{-1}

// data values
%token <int_val> INT_VAL 
%token <dou_val> DOUBLE_VAL 
%token <str_val> STRING_VAL
%token <char_val> CHAR_VAL 
%token <bol_val> BOOL_VAL ELSE_IF
%token <flo_val> FLOAT_VAL

// whitespaces
%token MULTI_WS SINGLE_WS

// user defined names
%token <id> ID

%type <tmp_id> term expr math_expr compare_expr boolExpr unionTypes statement assign types id exprList

%token UNKNOWN

%start line

%%

<<<<<<< HEAD
start:                          START {
                                    if (scope_type.empty()) {
                                        scope_type = GEN_SCOPE;
                                    }
                                    CreateScope(scope_type, i);
                                    scope_type = "";
                                };

=======
>>>>>>> @{-1}
end:                            END {
                                    i.EatAst(MakeNode(END_BLOCK_CMD));
                                };
<<<<<<< HEAD
                                
scope:                          start newline line | start any_ws line | start newline | start any_ws;
=======
>>>>>>> @{-1}

ifHead:                         IF any_ws expr any_ws START {
                                    auto control_block = MakeNode(CTRL_BLOCK_CMD);
                                    auto if_block = MakeNode(IF_BLOCK_CMD);
                                    if_block->SetLeft($expr);
                                    control_block->SetLeft(if_block);
                                    root = nullptr;
                                    i.EatAst(control_block);
                                };

<<<<<<< HEAD
ifMod:                          IF any_ws expr any_ws {
                                    scope_type = IF_SCOPE;
                                    if (SetNextScopeRunState($expr, i) == 1) {
                                        return 1;
                                    }
                                }; 

elseif:                         ELSE_IF { 
                                            scope_type = ELIF_SCOPE;

                                            // will only be true when the previous if statement couldn't run
                                            $$ = i.NonRunnableScope();
                                            if (!i.ParentNonRunnableScope()) {
                                                i.OverrideRunnable();
                                            }
                                        };

elseMod:                        ELSE {
                                    scope_type = ELSE_SCOPE;

                                    // will only be true when the previous if statement couldn't run
                                    bool next_run_stat = i.NonRunnableScope();
                                    if (!i.ParentNonRunnableScope()) {
                                        i.OverrideRunnable();
                                    }
                                    StrWrapper expr;
                                    expr = CreateTempVar(next_run_stat, i);
                                    SetNextScopeRunState(expr, i);
=======
elseIfHead:                     ELSE_IF any_ws expr any_ws START {
                                    auto control_block = MakeNode(CTRL_BLOCK_CMD);
                                    auto if_block = MakeNode(ELIF_BLOCK_CMD);
                                    if_block->SetLeft($expr);
                                    control_block->SetLeft(if_block);
                                    root = nullptr;
                                    i.EatAst(control_block);
>>>>>>> @{-1}
                                };

elseHead:                       ELSE any_ws START{
                                    auto control_block = MakeNode(CTRL_BLOCK_CMD);
                                    auto if_block = MakeNode(ELSE_BLOCK_CMD);
                                    control_block->SetLeft(if_block);
                                    i.EatAst(control_block);
                                };

whileHead:                      WHILE any_ws expr any_ws START {
                                    auto control_block = MakeNode(CTRL_BLOCK_CMD);
                                    auto while_block = MakeNode(WHILE_BLOCK_CMD);
                                    while_block->SetLeft($expr);
                                    control_block->SetLeft(while_block);
                                    root = nullptr;
                                    i.EatAst(control_block);
                                };

ifBody:                         ifHead line;
elseIfBody:                     elseIfHead line;
elseBody:                       elseHead line;
elseIfChain:                    elseIfBody | elseIfChain elseIfBody;

whileStatement:                 whileHead line end;
ifStatement:                    ifBody end 
                                | ifBody elseIfChain end 
                                | ifBody elseIfChain elseBody end 
                                | ifBody elseBody end;

newline:                        NEWLINE {i.EatAst(root); root = nullptr;} | SEMICOLON;

term:                           INT_VAL         { 
                                       $$ = MakeNode(RAW_DATA_CMD, $1, INT_NODE_TYPE);
                                       root = $$;             
                                }
                                | DOUBLE_VAL    { 
                                        $$ = MakeNode(RAW_DATA_CMD, $1, DOUBLE_NODE_TYPE);
                                        root = $$;          
                                }
                                | FLOAT_VAL     { 
                                        $$ = MakeNode(RAW_DATA_CMD, $1, FLOAT_NODE_TYPE);
                                        root = $$;            
                                }
                                | STRING_VAL    { 
                                        $$ = MakeNode(RAW_DATA_CMD, (string)$1, STRING_NODE_TYPE);
                                        root = $$;                    
                                }
                                | CHAR_VAL      { 
                                        $$ = MakeNode(RAW_DATA_CMD, $1, CHAR_NODE_TYPE);
                                        root = $$;
                                }
                                | BOOL_VAL      { 
                                        $$ = MakeNode(RAW_DATA_CMD, $1, BOOL_NODE_TYPE);
                                        root = $$;
                                }
                                | id            { 
                                        $$ = $1;
                                        root = $$;         
                                }
                                ;

types:                          INT             { $$ = MakeNode(RAW_DATA_CMD, (string)$1, VAR_TYPE_NODE_TYPE); root = $$; }
                                | FLOAT         { $$ = MakeNode(RAW_DATA_CMD, (string)$1, VAR_TYPE_NODE_TYPE); root = $$; }
                                | DOUBLE        { $$ = MakeNode(RAW_DATA_CMD, (string)$1, VAR_TYPE_NODE_TYPE); root = $$; }
                                | BOOL          { $$ = MakeNode(RAW_DATA_CMD, (string)$1, VAR_TYPE_NODE_TYPE); root = $$; }
                                | CHAR          { $$ = MakeNode(RAW_DATA_CMD, (string)$1, VAR_TYPE_NODE_TYPE); root = $$; }
                                | STRING        { $$ = MakeNode(RAW_DATA_CMD, (string)$1, VAR_TYPE_NODE_TYPE); root = $$; }
                                ;

unionTypes:                     types[first] opt_ws '|' opt_ws types[other] {
                                   $$ = $first;
                                   $$->PutInAdditional($other);
                                   root = $$;
                                }
                                | unionTypes[prev] opt_ws '|' opt_ws types {
                                    $$ = $prev;
                                    $$->PutInAdditional($types);
                                    root = $$;
                                }
                                ;

any_ws:                         MULTI_WS | SINGLE_WS;

opt_ws:                         any_ws | %empty;

id:                             ID {
                                    $$ = MakeNode(RAW_DATA_CMD, $1, ID_NODE_TYPE);
                                    root = $$; 
                                };

assign:                         id ':' opt_ws types opt_ws '=' opt_ws expr {
                                    $$ = MakeNode(BIND_CMD);                                    
                                    $$->SetLeft($id);
                                    $$->SetMiddle($types);
                                    $$->SetRight($expr);
                                    root = $$;
                                }
                                | id ':' opt_ws UNKNOWN opt_ws '=' opt_ws expr {
                                    $$ = MakeNode(MAKE_UNION_CMD);
                                    $$->SetLeft($id);
                                    $$->SetRight($expr);
                                    root = $$;
                                }
                                | id ':' opt_ws unionTypes opt_ws '=' opt_ws expr {
                                    $$ = MakeNode(MAKE_UNION_CMD);
                                    $$->SetLeft($id);
                                    $$->SetMiddle($unionTypes);
                                    for(size_t index = 0; index < $unionTypes->Extras(); index++) {
                                        $$->SetMiddle($unionTypes->GetAdditional(index));
                                        $unionTypes->NullAdditional(index);
                                    }
                                    $$->SetRight($expr);
                                    root = $$;
                                }
                                | id opt_ws '=' opt_ws expr {
                                   $$ = MakeNode(REBIND_CMD);
                                   $$->SetLeft($id);
                                   $$->SetRight($expr);
                                   root = $$;
                                }
                                | id ':' opt_ws types '<' REF '>' opt_ws '=' opt_ws expr {
                                    $$ = MakeNode(REFBIND_CMD);
                                    $$->SetLeft($id);
                                    $$->SetMiddle($types);
                                    $$->SetRight($expr);
                                    root = $$;
                                }
                                | id ':' opt_ws LIST '<' types '>' opt_ws '=' opt_ws '[' ']' {
                                    $$ = MakeNode(MAKE_LIST_CMD);
                                    $$->SetLeft($id);
                                    $$->SetRight($types);
                                    root = $$;
                                }
                                | id ':' opt_ws MAP '<' types[key] opt_ws POINTS_TO opt_ws types[val] '>' opt_ws '=' opt_ws '{' '}' {
                                    $$ = MakeNode(MAKE_MAP_CMD);
                                    $$->SetLeft($id);
                                    $$->SetMiddle($key);
                                    $$->SetRight($val);
                                    root = $$;
                                }
                                | id ':' opt_ws LIST '<' types '>' opt_ws '=' opt_ws expr {
                                    $$ = MakeNode(MAKE_LIST_CMD);
                                    $$->SetLeft($id);
                                    $$->SetMiddle($expr);
                                    $$->SetRight($types);
                                    root = $$;

                                }
                                | id opt_ws '=' opt_ws expr '<' REF '>' {
                                    $$ = MakeNode(REFBIND_CMD);
                                    $$->SetLeft($id);
                                    $$->SetRight($expr);
                                    root = $$;
                                }
                                ;


exprList:                      opt_ws expr {
                                    $$ = $expr;
                                } 
                                | opt_newline expr {
                                    $$ = $expr;
                                }
                                | exprList[prev] any_ws expr {  
                                    $prev->PutInAdditional($expr);
                                    $$ = $prev;
                                }
                                | exprList[prev] opt_newline expr {
                                    $prev->PutInAdditional($expr);
                                    $$ = $prev;
                                }
                                ;

opt_newline:                 opt_ws NEWLINE opt_ws;
opt_ws_or_nl:                opt_ws | opt_newline;
//any_ws_or_nl:                any_ws | opt_newline;
//ws_or_nl:                    any_ws | opt_newline;

statement:                      assign
                                | PRINT opt_ws '|' exprList opt_ws_or_nl'|' { 
                                    $$ = MakeNode(PRINT_CMD);
                                    $$->SetLeft($exprList);
                                    for(size_t index = 0; index < $exprList->Extras(); index++) {
                                        $$->SetLeft($exprList->GetAdditional(index));
                                        $exprList->NullAdditional(index);
                                    }
                                    root = $$;
                                }
                                | EXIT '|' opt_ws '|'{ return 0; }
                                ;


//MATH OPERS BELOW ---------------------------------------------------------------------------------------------------------------------------------------------------
math_expr:                      '(' ADD exprList[left] opt_ws_or_nl')' {
                                    Perform($$, $left, ADDITION_CMD);
                                    root = $$;
                                }
                                | '(' SUB exprList[left] opt_ws_or_nl')' {
                                    Perform($$, $left, SUBTRACTION_CMD);
                                    root = $$;
                                }
                                | '(' MUL exprList[left] opt_ws_or_nl ')' {
                                    Perform($$, $left, MULTIPLY_CMD);
                                    root = $$;
                                }
                                | '(' DIV exprList[left] opt_ws_or_nl ')' {
                                    Perform($$, $left, DIVIDE_CMD);
                                    root = $$;
                                }
                                | '(' POW exprList[left] opt_ws_or_nl ')' {
                                    Perform($$, $left, POW_CMD);
                                    root = $$;
                                }
                                ;
//MATH OPER ABOVE ------------------------------------------------------------------------------------------------------------------------------------------------------

//COMPARE OPERS BELOW --------------------------------------------------------------------------------------------------------------------------------------------------

compare_expr:                   '(' LESS any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeNode(LESS_CMD);
                                    $$->SetLeft($first);
                                    $$->SetRight($second);
                                    root = $$;
                                }
                                | '(' GREATER any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeNode(GREATER_CMD);
                                    $$->SetLeft($first);
                                    $$->SetRight($second);
                                    root = $$;
                                }
                                | '(' LESS_EQUAL any_ws expr[first] any_ws expr[second] opt_ws ')'{
                                    $$ = MakeNode(LESS_EQ_CMD);
                                    $$->SetLeft($first);
                                    $$->SetRight($second);
                                    root = $$;
                                }
                                | '(' GREATER_EQUAL any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeNode(GREATER_EQ_CMD);
                                    $$->SetLeft($first);
                                    $$->SetRight($second);
                                    root = $$;
                                }
                                | '('EQUAL any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeNode(EQ_CMD);
                                    $$->SetLeft($first);
                                    $$->SetRight($second);
                                    root = $$;
                                }
                                | '(' NOT_EQUAL any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeNode(NOT_CMD);

                                    auto equal = MakeNode(EQ_CMD);
                                    equal->SetLeft($first);
                                    equal->SetRight($second);

                                    $$->SetLeft(equal);

                                    root = $$;
                                }
                                ;
//COMPARE OPER ABOVE ------------------------------------------------------------------------------------------------------------------------------------------------

//BOOL OPERS BELOW ---------------------------------------------------------------------------------------------------------------------------------------------------
boolExpr:                      '(' AND any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeNode(AND_CMD);
                                    $$->SetLeft($first);
                                    $$->SetRight($second);
                                    root = $$;
                                }
                                | '(' NOT any_ws expr opt_ws ')' {
                                    $$ = MakeNode(NOT_CMD);
                                    $$->SetLeft($expr);
                                    root = $$;
                                }
                                | '(' OR any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeNode(OR_CMD);
                                    $$->SetLeft($first);
                                    $$->SetRight($second);
                                    root = $$;
                                }
                                ;
//BOOL OPER ABOVE -----------------------------------------------------------------------------------------------------------------------------------------------------

expr:                           term {
                                    $$ = $term;
                                    root = $$;
                                }
                                | math_expr {
                                    $$ = $math_expr;
                                    root = $$;
                                }
                                | '(' CAST any_ws expr[val] any_ws types opt_ws_or_nl ')' {
                                    $$ = MakeNode(CAST_TYPE_CMD);
                                    $$->SetLeft($val);
                                    $$->SetRight($types);
                                    root = $$;
                                }
                                | compare_expr {
                                   $$ = $compare_expr;
                                   root = $$;
                                }
                                | boolExpr {
                                    $$ = $boolExpr;
                                    root = $$;
                                }
                                | id[list] '.' ADD_LIST '|' opt_ws expr[item] opt_ws '|' {
                                     $$ = MakeNode(PUT_IN_CONTAINER_CMD);
                                     $$->SetLeft($list);
                                     $$->SetRight($item);
                                     root = $$;
                                }
                                | id[list] '.' ADD_MAP '|' opt_ws expr[key] any_ws expr[val] opt_ws '|' {
                                    $$ = MakeNode(PUT_IN_MAP_CMD);
                                    $$->SetLeft($list);
                                    $$->SetMiddle($key);
                                    $$->SetRight($val);
                                    root = $$;
                                }
                                | id[list] '[' opt_ws expr[index] opt_ws ']' {
                                    $$ = MakeNode(GET_FROM_CONTAINER_CMD);
                                    $$->SetLeft($list);
                                    $$->SetRight($index);
                                    root = $$;
                                }
                                | id[list] '.' SET '|' opt_ws expr[index] any_ws expr[new_val] opt_ws '|' {
                                    $$ = MakeNode(SET_IN_CONTAINER_CMD);
                                    $$->SetLeft($list);
                                    $$->SetMiddle($index);
                                    $$->SetRight($new_val);
                                    root = $$;
                                }
                                | id[list] '.' SIZE '|' '|' {
                                    $$ = MakeNode(GET_CONTAINER_SIZE_CMD);
                                    $$->SetLeft($list);
                                    root = $$;
                                }
                                ;

prog:                           expr newline 
                                | expr EOPU
                                | statement newline
                                | statement EOPU
                                | newline
                                | ifStatement
                                | whileStatement
                                | EOPU { 
                                    i.EatAst(root);
                                    return 0 ;
                                }
                                | any_ws  
                                | error {  };

line:                           prog | line prog;
%%


void PrintLineNo() {
    cout << "line num: " << lineno << "\n";
    lineno++;
}

void yyerror(const char* err) {
    cout << err << '\n';
    //cout << yytext << '\n';
}

#include <vector>
using namespace std;

template<class R, class ... cparams,  class ... params>
void Test(R(*f)(cparams...), params ... p) {
    vector<string> cor_p = {typeid(cparams).name()...};
    vector<string> passed_p = {typeid(p).name()...};

    bool input = false;
    if (passed_p.size() == cor_p.size()) {
        input = true;
        for(size_t i = 0; i < passed_p.size(); i++) {
            if (passed_p[i] != cor_p[i]) {
                input = false;
                break;
            }
        }
    }

    if (!input) {
        cout << "Error: couldn't run func\n";
    }
    else {
        //(*f)(p...);
    }
}

int main(int argc, char *argv[]) {
    bool in_file_mode = false;
    FILE *file = nullptr;
    
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        
        if (file != nullptr) {
            yyin = file;
            in_file_mode = true;
        }
        else {
            cout << "Error: file doesn't exist\n";
            return 1;
        }
    }
    int x = yyparse();
    while(x != 0 && !in_file_mode) {
        // makes sure to clear the token buffer
        // so that when a parser or interpreter error
        // happens, tokens aren't trying to be read again
        yyrestart(yyin);
        
        x = yyparse();
    }

    if (file != nullptr) {
        fclose(file);
    }
    return x;
}