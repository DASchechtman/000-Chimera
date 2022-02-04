
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

// variable types
%token <types> INT 
%token <types> FLOAT 
%token <types> DOUBLE 
%token <types> BOOL 
%token <types> CHAR 
%token <types> STRING 
%token <types> LIST 
%token <types> MAP

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
%token GET 
%token POINTS_TO
%token START 
%token END 
%token IF 
%token ELSE 
%token WHILE 
%token SIZE 
%token REPEAT 
%token WITH
%token MULTI_WS 
%token SINGLE_WS
%token INC
%token MOD

%token <int_val> INT_VAL 
%token <dou_val> DOUBLE_VAL 
%token <str_val> STRING_VAL
%token <char_val> CHAR_VAL 
%token <bol_val> BOOL_VAL ELSE_IF
%token <flo_val> FLOAT_VAL
%token <id> ID

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

%token UNKNOWN

%start line

%%

start:                          START { i.EatAst(MakeStartAst()); };

end:                            END { i.EatAst(MakeEndScopeAst()); };

ifHead:                         IF any_ws expr any_ws START {
                                    root = nullptr;
                                    i.EatAst(MakeIfDeclAst($expr));
                                };

elseIfHead:                     ELSE_IF any_ws expr any_ws START {
                                    root = nullptr;
                                    i.EatAst(MakeElifDeclAst($expr));
                                };

elseHead:                       ELSE any_ws START{
                                    i.EatAst(MakeElseDeclAst());
                                };

whileHead:                      WHILE any_ws expr any_ws START {
                                    root = nullptr;
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
                                    
                                    root = nullptr;
                                    $$ = $id->Copy();
                                };

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

newline:                        NEWLINE {i.EatAst(root); root = nullptr;} | SEMICOLON;

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
                                    root = $$;
                                }
                                | keyValPairs[kp] any_ws {
                                    $$ = new AstNode();
                                    $$->SaveAsExtraNode($kp->GetExtraNode());
                                    $$->SaveAsExtraNode($kp->GetExtraNode(1));
                                    $kp->NullExtraNode(0);
                                    $kp->NullExtraNode(1);
                                    delete $kp;
                                    root = $$;
                                }
                                | keyVals[prev] keyValPairs[kp] NEWLINE opt_ws {
                                    $prev->SaveAsExtraNode($kp->GetExtraNode());
                                    $prev->SaveAsExtraNode($kp->GetExtraNode(1));
                                    $kp->NullExtraNode(0);
                                    $kp->NullExtraNode(1);
                                    delete $kp;
                                    $$ = $prev;
                                    root = $$;
                                }
                                | keyVals[prev] keyValPairs[kp] any_ws {
                                    $prev->SaveAsExtraNode($kp->GetExtraNode());
                                    $prev->SaveAsExtraNode($kp->GetExtraNode(1));
                                    $kp->NullExtraNode(0);
                                    $kp->NullExtraNode(1);
                                    delete $kp;
                                    $$ = $prev;
                                    root = $$;
                                }
                                ; 

term:                           INT_VAL         { 
                                       $$ = MakeTermNode($1, INT_NODE_TYPE);
                                       root = $$;             
                                }
                                | DOUBLE_VAL    { 
                                        $$ = MakeTermNode($1, DOUBLE_NODE_TYPE);
                                        root = $$;          
                                }
                                | FLOAT_VAL     { 
                                        $$ = MakeTermNode($1, FLOAT_NODE_TYPE);
                                        root = $$;            
                                }
                                | STRING_VAL    { 
                                        $$ = MakeTermNode((string)$1, STRING_NODE_TYPE);
                                        root = $$;                    
                                }
                                | CHAR_VAL      { 
                                        $$ = MakeTermNode($1, CHAR_NODE_TYPE);
                                        root = $$;
                                }
                                | BOOL_VAL      { 
                                        $$ = MakeTermNode($1, BOOL_NODE_TYPE);
                                        root = $$;
                                }
                                | id            { 
                                        $$ = $1;
                                        root = $$;         
                                }
                                | '[' opt_ws_or_nl terms  opt_ws_or_nl ']' {
                                    $$ = MakeArrayTermAst($terms);
                                    root = $$;
                                }
                                | '[' ']' {
                                    $$ = MakeTermNode(0, ARRAY_NODE_TYPE);
                                    root = $$;
                                }
                                | '{' opt_ws_or_nl keyVals '}' {
                                    $$ = MakeMapTermAst($keyVals);
                                    root = $$;
                                }
                                | '{' '}' {
                                    $$ = MakeTermNode(0, MAP_NODE_TYPE);
                                    root = $$;
                                }
                                ;

types:                          INT             { $$ = MakeDataTypeNode((string)$1); root = $$; }
                                | FLOAT         { $$ = MakeDataTypeNode((string)$1); root = $$; }
                                | DOUBLE        { $$ = MakeDataTypeNode((string)$1); root = $$; }
                                | BOOL          { $$ = MakeDataTypeNode((string)$1); root = $$; }
                                | CHAR          { $$ = MakeDataTypeNode((string)$1); root = $$; }
                                | STRING        { $$ = MakeDataTypeNode((string)$1); root = $$; }
                                | LIST {
                                    $$ = MakeDataTypeNode((string)$LIST);
                                    root = $$;
                                }
                                | MAP {
                                    $$ = MakeDataTypeNode((string)$MAP);
                                    root = $$;
                                }
                                ;

unionTypes:                     types[first] opt_ws '|' opt_ws types[other] {
                                   $$ = $first;
                                   $$->SaveAsExtraNode($other);
                                   root = $$;
                                }
                                | unionTypes[prev] opt_ws '|' opt_ws types {
                                    $$ = $prev;
                                    $$->SaveAsExtraNode($types);
                                    root = $$;
                                }
                                ;

any_ws:                         MULTI_WS | SINGLE_WS;

opt_ws:                         any_ws | %empty;

id:                             ID {
                                    $$ = MakeTermNode($1, ID_NODE_TYPE);
                                    root = $$; 
                                };

assign:                         id ':' opt_ws types opt_ws '=' opt_ws expr {
                                    $$ = MakeAssignAst($id, $types, $expr);
                                    root = $$;
                                }
                                | id ':' opt_ws UNKNOWN opt_ws '=' opt_ws expr {
                                    $$ = MakeUnionAst($id, $expr);
                                    root = $$;
                                }
                                | id ':' opt_ws unionTypes opt_ws '=' opt_ws expr {
                                    $$ = MakeUnionAst($id, $unionTypes, $expr);
                                    root = $$;
                                }
                                | id opt_ws '=' opt_ws expr {
                                   $$ = MakeReassignAst($id, $expr);
                                   root = $$;
                                }
                                | id ':' opt_ws types '<' REF '>' opt_ws '=' opt_ws expr {
                                    $$ = MakeRefAst($id, $types, $expr);
                                    root = $$;
                                }
                                | id opt_ws '=' opt_ws expr '<' REF '>' {
                                    $$ = MakeRebindRefAst($id, $expr);
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
                                    root = $$;
                                }
                                | EXIT '|' opt_ws '|'{ return 0; }
                                ;


//MATH OPERS BELOW ---------------------------------------------------------------------------------------------------------------------------------------------------
math_expr:                      '(' ADD exprList[left] ')' {
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
                                | '(' INC any_ws expr  opt_ws_or_nl ')' {
                                    $$ = MakeIncAst($expr);
                                    root = $$;
                                }
                                | '(' MOD any_ws expr[left] any_ws expr[right] opt_ws_or_nl ')' {
                                    $$ = MakeModAst($left, $right);
                                    root = $$;
                                }
                                ;
//MATH OPER ABOVE ------------------------------------------------------------------------------------------------------------------------------------------------------

//COMPARE OPERS BELOW --------------------------------------------------------------------------------------------------------------------------------------------------

compare_expr:                   '(' LESS any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeLessCompAst($first, $second);
                                    root = $$;
                                }
                                | '(' GREATER any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeGreaterCompAst($first, $second);
                                    root = $$;
                                }
                                | '(' LESS_EQUAL any_ws expr[first] any_ws expr[second] opt_ws ')'{
                                    $$ = MakeLessEqualCompAst($first, $second);
                                    root = $$;
                                }
                                | '(' GREATER_EQUAL any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeGreaterEqualCompAst($first, $second);
                                    root = $$;
                                }
                                | '('EQUAL any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeEqualCompAst($first, $second);
                                    root = $$;
                                }
                                | '(' NOT_EQUAL any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeNotEqualCompAst($first, $second);
                                    root = $$;
                                }
                                ;
//COMPARE OPER ABOVE ------------------------------------------------------------------------------------------------------------------------------------------------

//BOOL OPERS BELOW ---------------------------------------------------------------------------------------------------------------------------------------------------
boolExpr:                      '(' AND any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeAndAst($first, $second);
                                    root = $$;
                                }
                                | '(' NOT any_ws expr opt_ws ')' {
                                    $$ = MakeNotAst($expr);
                                    root = $$;
                                }
                                | '(' OR any_ws expr[first] any_ws expr[second] opt_ws ')' {
                                    $$ = MakeOrAst($first, $second);
                                    root = $$;
                                }
                                ;
//BOOL OPER ABOVE -----------------------------------------------------------------------------------------------------------------------------------------------------

indexAccessor:                  id '[' opt_ws expr opt_ws ']' {
                                    $$ = MakeGetFromCollectionAst($id, $expr);
                                    root = $$;
                                } 
                                | indexAccessor[pre] '[' opt_ws expr opt_ws ']' {
                                    $pre->AddToMiddleNodes($expr);
                                    $$ = $pre;
                                    root = $$;
                                }
                                
                                ;

expr:                           term {
                                    $$ = $term;
                                    root = $$;
                                }
                                | math_expr {
                                    $$ = $math_expr;
                                    root = $$;
                                }
                                | '(' CAST any_ws expr[val] any_ws types opt_ws_or_nl ')' {
                                    $$ = MakeCastAst($val, $types);
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
                                | expr[list] '.' ADD_LIST '|' opt_ws expr[item] opt_ws '|' {
                                     $$ = MakeAddToListAst($list, $item);
                                     root = $$;
                                }
                                | expr[list] '.' ADD_MAP '|' opt_ws expr[key] any_ws expr[val] opt_ws '|' {
                                    $$ = MakeAddToMapAst($list, $key, $val);
                                    root = $$;
                                }
                                | indexAccessor {
                                    $$ = $indexAccessor;
                                    root = $$;
                                }
                                | expr[list] '.' SET '|' opt_ws expr[index] any_ws expr[new_val] opt_ws '|' {
                                    $$ = MakeSetInCollectionAst($list, $index, $new_val);
                                    root = $$;
                                }
                                | expr[list] '.' SIZE {
                                    $$ = MakeCollectionSizeAst($list);
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
                                | forloopStatement
                                | start line end
                                | EOPU { 
                                    i.EatAst(root);
                                    return 0 ;
                                }
                                | any_ws  
                                | error { return 0; };

line:                           prog | line prog;
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