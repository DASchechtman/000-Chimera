
%code requires {
#include "Utils/UnionStruct.hpp"
}

%{
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include "../src/Ast.hpp"
#include "../src/ChmrInterpreter.hpp"
#include "Utils/IntrBridge.hpp"

using namespace std;

int lineno = 0;
ChmrInterpreter i;
string scope_type;
AstNode *root = nullptr;
AstNode *loop_id = nullptr;
bool for_loop_made = false;

void PrintLineNo();
void yyerror(const char* err);
extern int yylex();
extern FILE *yyin;
extern void yyrestart(FILE* input);
extern char* yytext;
%}

%define parse.error verbose

%union {
    YYSTYPEs *data;
    AstNode *tmp_id;
}

// variable types
%token <data> INT 
%token <data> FLOAT 
%token <data> DOUBLE 
%token <data> BOOL 
%token <data> CHAR 
%token <data> STRING 
%token <data> LIST 
%token <data> MAP

// keywords
%token CAST 
%token LESS 
%token GREATER 
%token LESS_EQUAL 
%token GREATER_EQUAL 
%token EQUAL 
%token NOT_EQUAL 
%token PRINT 
%token AND 
%token OR 
%token NOT 
%token EXIT 
%token NEWLINE 
%token SEMICOLON 
%token EOPU 
%token REF 
%token ADD 
%token SUB 
%token MUL 
%token DIV 
%token POW 
%token ADD_LIST 
%token ADD_MAP 
%token SET 
%token POINTS_TO
%token START 
%token END 
%token IF 
%token ELSE 
%token WHILE 
%token SIZE 
%token REPEAT 
%token WITH
%token INC
%token MOD
%token GET
%token SURO

%token <data> INT_VAL 
%token <data> DOUBLE_VAL 
%token <data> STRING_VAL
%token <data> CHAR_VAL 
%token <data> BOOL_VAL ELSE_IF
%token <data> FLOAT_VAL
%token <data> ID

%type <tmp_id> term
%type <tmp_id> terms
%type <tmp_id> keyVals
%type <tmp_id> keyValPairs
%type <tmp_id> expr 
%type <tmp_id> math_expr 
%type <tmp_id> compare_expr 
%type <tmp_id> boolExpr 
%type <tmp_id> unionTypes 
%type <tmp_id> statement 
%type <tmp_id> assign 
%type <tmp_id> types 
%type <tmp_id> id
%type <tmp_id> indexAccessor 
%type <tmp_id> exprList 
%type <tmp_id> forloopHead
%type <tmp_id> functionHead
%type <tmp_id> paramList
%type <tmp_id> functionDeclStatement
%type <tmp_id> functionCall

%token UNKNOWN

%start line

%left MULTI_WS SINGLE_WS

%%

start:                          START { i.EatAst(MakeStartAst()); };

end:                            END { i.EatAst(MakeEndScopeAst()); };

ifHead:                         IF any_ws expr any_ws START {
                                    i.EatAst(MakeIfDeclAst($expr));
                                };

elseIfHead:                     ELSE_IF any_ws expr any_ws START {
                                    i.EatAst(MakeElifDeclAst($expr));
                                };

elseHead:                       ELSE any_ws START{
                                    i.EatAst(MakeElseDeclAst());
                                };

whileHead:                      WHILE any_ws expr any_ws START {
                                    i.EatAst(MakeWhileDeclAst($expr));
                                };

forloopHead:                    REPEAT any_ws expr any_ws WITH any_ws id any_ws START {
                                    i.EatAst(MakeNode(START_BLOCK_CMD));

                                    auto type = MakeDataTypeNode("int");
                                    auto val = MakeTermNode(0, INT_NODE_TYPE);
                                    auto make = MakeAssignAst($id, type, val);
                                    i.EatAst(make);

                                    auto less = MakeLessCompAst($id->Copy(), $expr);
                                    auto while_ast = MakeWhileDeclAst(less);
                                    i.EatAst(while_ast);   
                                    $$ = $id->Copy();
                                };

paramList:                      id ':' opt_ws types {
                                    auto param = new AstNode();
                                    param->AddToLeftNodes($id);
                                    param->AddToRightNodes($types);
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    $$ = list;

                                }
                                | types {
                                    auto param = new AstNode();
                                    param->AddToRightNodes($types);
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    $$ = list;
                                }
                                | paramList[list] any_ws id ':' opt_ws types {
                                    auto param = new AstNode();
                                    param->AddToLeftNodes($id);
                                    param->AddToRightNodes($types);
                                    $list->AddToLeftNodes(param);
                                    $$ = $list;
                                }
                                | paramList[list] any_ws types {
                                    auto param = new AstNode();
                                    param->AddToRightNodes($types);
                                    $list->AddToLeftNodes(param);
                                    $$ = $list;
                                }
                                ;

functionHead:                   SURO any_ws id opt_ws '|' '|' ':' opt_ws types any_ws START {
                                    $$ = MakeNode(MAKE_FUNC_CMD);
                                    $$->AddToLeftNodes($id);
                                    $$->AddToRightNodes($types);
                                    i.EatAst($$);
                                }
                                | SURO any_ws id opt_ws '|' paramList opt_ws '|' ':' opt_ws types any_ws START {
                                    $$ = MakeNode(MAKE_FUNC_CMD);
                                    $$->AddToLeftNodes($id);
                                    $$->AddToMiddleNodes($paramList);
                                    $$->AddToRightNodes($types);
                                    i.EatAst($$);
                                    $$ = nullptr;
                                }
                                ;

functionCall:                   id opt_ws '|' '|' {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    func_call->AddToLeftNodes($id);
                                    $$ = func_call;
                                }
                                | id opt_ws '|' exprList opt_ws_or_nl '|' {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    auto list = $exprList;
                                    auto id = $id;
                                    func_call->AddToLeftNodes($id);
                                    auto end = $exprList->Extras();
                                    for(size_t iter = 0; iter < end; iter++) {
                                        func_call->AddToRightNodes($exprList->GetExtraNode(iter));
                                    }
                                    $$ = func_call;
                                }
                                ;

ifBody:                         ifHead line;
elseIfBody:                     elseIfHead line;
elseBody:                       elseHead line;
elseIfChain:                    elseIfBody | elseIfChain elseIfBody;

whileStatement:                 whileHead line END {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                };

forloopStatement:               forloopHead line END {
                                    i.EatAst(MakeIncAst($forloopHead));
                                    i.EatAst(MakeEndCtrlScopeAst());
                                    i.EatAst(MakeEndScopeAst());  
                                };

ifStatement:                    ifBody END {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }    
                                | ifBody elseIfChain END {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                } 
                                | ifBody elseIfChain elseBody END {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
                                | ifBody elseBody END {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                };

functionDeclStatement:          functionHead line END {
                                    $$ = MakeNode(FUNC_RETR_CMD);
                                }
                                ;

newline:                        NEWLINE | SEMICOLON;

terms:                          term { $$ = $1; } 
                                | terms[list] any_ws term { $list->SaveAsExtraNode($term); $$ = $list; }
                                | terms[list] opt_newline term {$list->SaveAsExtraNode($term); $$ = $list; }
                                ;

keyValPairs:                    '|' opt_ws term[key] opt_ws POINTS_TO opt_ws term[val] opt_ws '|' {
                                    $$ = new AstNode();
                                    $$->SaveAsExtraNode($key);
                                    $$->SaveAsExtraNode($val);
                                }
                                ;

keyVals:                        keyValPairs[kp] NEWLINE opt_ws {
                                    $$ = new AstNode();
                                    $$->SaveAsExtraNode($kp->GetExtraNode());
                                    $$->SaveAsExtraNode($kp->GetExtraNode(1));
                                    $kp->NullExtraNode(0);
                                    $kp->NullExtraNode(1);
                                    delete $kp;
                                }
                                | keyValPairs[kp] any_ws {
                                    $$ = new AstNode();
                                    $$->SaveAsExtraNode($kp->GetExtraNode());
                                    $$->SaveAsExtraNode($kp->GetExtraNode(1));
                                    $kp->NullExtraNode(0);
                                    $kp->NullExtraNode(1);
                                    delete $kp;
                                }
                                | keyVals[prev] keyValPairs[kp] NEWLINE opt_ws {
                                    $prev->SaveAsExtraNode($kp->GetExtraNode());
                                    $prev->SaveAsExtraNode($kp->GetExtraNode(1));
                                    $kp->NullExtraNode(0);
                                    $kp->NullExtraNode(1);
                                    delete $kp;
                                    $$ = $prev;
                                }
                                | keyVals[prev] keyValPairs[kp] any_ws {
                                    $prev->SaveAsExtraNode($kp->GetExtraNode());
                                    $prev->SaveAsExtraNode($kp->GetExtraNode(1));
                                    $kp->NullExtraNode(0);
                                    $kp->NullExtraNode(1);
                                    delete $kp;
                                    $$ = $prev;
                                }
                                ; 

term:                           INT_VAL         { 
                                       $$ = MakeTermNode($1->int_val, INT_NODE_TYPE);            
                                }
                                | DOUBLE_VAL    { 
                                        $$ = MakeTermNode($1->dou_val, DOUBLE_NODE_TYPE);          
                                }
                                | FLOAT_VAL     { 
                                        $$ = MakeTermNode($1->flo_val, FLOAT_NODE_TYPE);            
                                }
                                | STRING_VAL    { 
                                        $$ = MakeTermNode((string)$1->str_val, STRING_NODE_TYPE);                   
                                }
                                | CHAR_VAL      { 
                                        $$ = MakeTermNode($1->char_val, CHAR_NODE_TYPE);
                                }
                                | BOOL_VAL      { 
                                        $$ = MakeTermNode($1->bol_val, BOOL_NODE_TYPE);
                                }
                                | id            { 
                                        $$ = $1;       
                                }
                                | '[' opt_ws_or_nl terms  opt_ws_or_nl ']' {
                                    $$ = MakeArrayTermAst($terms);
                                }
                                | '[' ']' {
                                    $$ = MakeTermNode(0, ARRAY_NODE_TYPE);
                                }
                                | '{' opt_ws_or_nl keyVals '}' {
                                    $$ = MakeMapTermAst($keyVals);
                                }
                                | '{' '}' {
                                    $$ = MakeTermNode(0, MAP_NODE_TYPE);
                                }
                                ;

types:                          INT             { $$ = MakeDataTypeNode((string)$1->types); }
                                | FLOAT         { $$ = MakeDataTypeNode((string)$1->types); }
                                | DOUBLE        { $$ = MakeDataTypeNode((string)$1->types); }
                                | BOOL          { $$ = MakeDataTypeNode((string)$1->types); }
                                | CHAR          { $$ = MakeDataTypeNode((string)$1->types); }
                                | STRING        { $$ = MakeDataTypeNode((string)$1->types); }
                                | LIST {
                                    $$ = MakeDataTypeNode((string)$LIST->types);
                                }
                                | MAP {
                                    $$ = MakeDataTypeNode((string)$MAP->types);
                                }
                                ;

unionTypes:                     types[first] opt_ws '|' opt_ws types[other] {
                                   $$ = $first;
                                   $$->SaveAsExtraNode($other);
                                }
                                | unionTypes[prev] opt_ws '|' opt_ws types {
                                    $$ = $prev;
                                    $$->SaveAsExtraNode($types);
                                }
                                ;

any_ws:                         MULTI_WS | SINGLE_WS;

opt_ws:                         any_ws | %empty;

id:                             ID {
                                    $$ = MakeTermNode((string)$1->id, ID_NODE_TYPE);
                                };

assign:                         '(' '=' opt_ws id opt_ws ':' opt_ws types any_ws expr opt_ws ')' {
                                    $$ = MakeAssignAst($id, $types, $expr);
                                }
                                | '(' '=' opt_ws id opt_ws ':' opt_ws UNKNOWN any_ws expr opt_ws ')' {
                                    $$ = MakeUnionAst($id, $expr);
                                }
                                | '(' '=' opt_ws id opt_ws ':' opt_ws '[' unionTypes ']' any_ws expr opt_ws ')' {
                                    $$ = MakeUnionAst($id, $unionTypes, $expr);
                                }
                                | '(' '=' opt_ws id any_ws expr opt_ws ')' {
                                   $$ = MakeReassignAst($id, $expr);
                                }
                                | '(' '=' opt_ws id opt_ws ':' opt_ws types opt_ws '<' REF '>' any_ws expr opt_ws ')' {
                                    $$ = MakeRefAst($id, $types, $expr);
                                }
                                | '(' '=' opt_ws id any_ws expr opt_ws '<' REF '>' opt_ws ')' {
                                    $$ = MakeRebindRefAst($id, $expr);
                                }
                                ;


exprList:                      opt_ws expr {
                                    $$ = new AstNode();
                                    $$->SaveAsExtraNode($expr);
                                } 
                                | opt_newline expr {
                                    $$ = new AstNode();
                                    $$->SaveAsExtraNode($expr);
                                }
                                | exprList[prev] any_ws expr {  
                                    $prev->SaveAsExtraNode($expr);
                                    $$ = $prev;
                                }
                                | exprList[prev] opt_newline expr {
                                    $prev->SaveAsExtraNode($expr);
                                    $$ = $prev;
                                }
                                ;

opt_newline:                 opt_ws NEWLINE opt_ws;
opt_ws_or_nl:                opt_ws | opt_newline;

statement:                      assign
                                | PRINT opt_ws '|' exprList opt_ws_or_nl'|' { 
                                    $$ = MakePrintAst($exprList);
                                }
                                | EXIT '|' opt_ws '|'{ Destroy(); return 0; $$ = nullptr; }
                                ;


//MATH OPERS BELOW ---------------------------------------------------------------------------------------------------------------------------------------------------
math_expr:                      '(' ADD exprList[left] ')' {
                                    Perform($$, $left, ADDITION_CMD);
                                }
                                | '(' SUB exprList[left] opt_ws_or_nl')' {
                                    Perform($$, $left, SUBTRACTION_CMD);
                                }
                                | '(' MUL exprList[left] opt_ws_or_nl ')' {
                                    Perform($$, $left, MULTIPLY_CMD);
                                }
                                | '(' DIV exprList[left] opt_ws_or_nl ')' {
                                    Perform($$, $left, DIVIDE_CMD);
                                }
                                | '(' POW exprList[left] opt_ws_or_nl ')' {
                                    Perform($$, $left, POW_CMD);
                                }
                                | '(' INC any_ws expr  opt_ws_or_nl ')' {
                                    $$ = MakeIncAst($expr);
                                }
                                | '(' MOD any_ws expr[left] any_ws expr[right] opt_ws_or_nl ')' {
                                    $$ = MakeModAst($left, $right);
                                }
                                ;
//MATH OPER ABOVE ------------------------------------------------------------------------------------------------------------------------------------------------------

//COMPARE OPERS BELOW --------------------------------------------------------------------------------------------------------------------------------------------------

compare_expr:                   '(' LESS any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeLessCompAst($first, $second);
                                }
                                | '(' GREATER any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeGreaterCompAst($first, $second);
                                }
                                | '(' LESS_EQUAL any_ws expr[first] any_ws expr[second] opt_ws ')'{
                                    $$ = MakeLessEqualCompAst($first, $second);
                                }
                                | '(' GREATER_EQUAL any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeGreaterEqualCompAst($first, $second);
                                }
                                | '('EQUAL any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeEqualCompAst($first, $second);
                                }
                                | '(' NOT_EQUAL any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeNotEqualCompAst($first, $second);
                                }
                                ;
//COMPARE OPER ABOVE ------------------------------------------------------------------------------------------------------------------------------------------------

//BOOL OPERS BELOW ---------------------------------------------------------------------------------------------------------------------------------------------------
boolExpr:                      '(' AND any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeAndAst($first, $second);
                                }
                                | '(' NOT any_ws expr opt_ws ')' {
                                    $$ = MakeNotAst($expr);
                                }
                                | '(' OR any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeOrAst($first, $second);
                                }
                                ;
//BOOL OPER ABOVE -----------------------------------------------------------------------------------------------------------------------------------------------------

indexAccessor:                  '(' GET any_ws id any_ws expr ')' {
                                    $$ = MakeGetFromCollectionAst($id, $expr);
                                } 
                                
                                ;

expr:                           term {
                                    $$ = $term;
                                }
                                | math_expr {
                                    $$ = $math_expr;
                                }
                                | '(' CAST any_ws expr[val] any_ws types opt_ws_or_nl ')' {
                                    $$ = MakeCastAst($val, $types);
                                }
                                | compare_expr {
                                   $$ = $compare_expr;
                                }
                                | boolExpr {
                                    $$ = $boolExpr;
                                }
                                | expr[list] '.' ADD_LIST '|' opt_ws expr[item] opt_ws '|' {
                                     $$ = MakeAddToListAst($list, $item);
                                }
                                | expr[list] '.' ADD_MAP '|' opt_ws expr[key] any_ws expr[val] opt_ws '|' {
                                    $$ = MakeAddToMapAst($list, $key, $val);
                                }
                                | indexAccessor {
                                    $$ = $indexAccessor;
                                }
                                | expr[list] '.' SET '|' opt_ws expr[index] any_ws expr[new_val] opt_ws '|' {
                                    $$ = MakeSetInCollectionAst($list, $index, $new_val);
                                }
                                | expr[list] '.' SIZE {
                                    $$ = MakeCollectionSizeAst($list);
                                }
                                | functionDeclStatement {
                                    $$ = $functionDeclStatement;
                                }
                                ;

prog:                           expr { i.EatAst($expr); $expr = nullptr; }
                                | statement { i.EatAst($statement); $statement = nullptr; }
                                | ifStatement
                                | whileStatement
                                | forloopStatement
                                | functionCall { i.EatAst($functionCall); $functionCall = nullptr; }
                                | start line end
                                | any_ws
                                | newline
                                | EOPU {
                                    Destroy();
                                    return 0;
                                }
                                | error { return 0; };

line:                            prog | line prog;
%%


void PrintLineNo() {
    cout << "line num: " << lineno << "\n";
    lineno++;
}

void yyerror(const char* err) {
    cout << err << '\n';
}

#include <vector>
using namespace std;

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