/*
this is a header full of wrapper functions that wrap the public method of the interpreter class.
I did this because bison/yacc mix code and parser syntax into one thing, so I was trying to extract as
much code into it's own cpp file as possible so that I can keep things more flexible
*/
#pragma once

#include <string>
#include <vector>
#include "../../src/ChmrInterpreter.hpp"
#include "StrWrapper.hpp"

using namespace std;

void Perform(AstNode *&root, AstNode *node, COMMANDS type);

AstNode* MakeStartAst();
AstNode* MakeEndScopeAst();
AstNode* MakeEndCtrlScopeAst();
AstNode* MakeIfDeclAst                          (AstNode *expr);
AstNode* MakeElifDeclAst                        (AstNode *expr);
AstNode* MakeElseDeclAst();
AstNode* MakeWhileDeclAst                       (AstNode *expr);
AstNode* MakeAssignAst                          (AstNode* id, AstNode* types, AstNode *expr);
AstNode* MakeUnionAst                           (AstNode *id, AstNode* types, AstNode *expr);
AstNode* MakeUnionAst                           (AstNode *id, AstNode *expr);
AstNode* MakeReassignAst                        (AstNode *id, AstNode *expr);
AstNode* MakeRefAst                             (AstNode *id, AstNode *types, AstNode *expr);
AstNode* MakeArrayBindAst                       (AstNode *id, AstNode *types);
AstNode* MakeArrayTermAst                       (AstNode *data);
AstNode* MakeMapTermAst                         (AstNode *data);
AstNode* MakeMapBindAst                         (AstNode* id, AstNode *key_type, AstNode *val_type);
AstNode* MakeArrayBindAst                       (AstNode *id, AstNode *types, AstNode *expr);
AstNode* MakeRebindRefAst                       (AstNode *id, AstNode *expr);
AstNode* MakePrintAst                           (AstNode *exprs);
AstNode* MakeLessCompAst                        (AstNode *left, AstNode *right);
AstNode* MakeGreaterCompAst                     (AstNode *left, AstNode *right);
AstNode* MakeLessEqualCompAst                   (AstNode *left, AstNode *right);
AstNode* MakeGreaterEqualCompAst                (AstNode *left, AstNode *right);
AstNode* MakeEqualCompAst                       (AstNode *left, AstNode *right);
AstNode* MakeNotEqualCompAst                    (AstNode *left, AstNode *right);
AstNode* MakeAndAst                             (AstNode *left, AstNode *right);
AstNode* MakeNotAst                             (AstNode *left);
AstNode* MakeOrAst                              (AstNode *left, AstNode *right);
AstNode* MakeCastAst                            (AstNode *expr, AstNode *type);
AstNode* MakeAddToListAst                       (AstNode *id, AstNode *expr);
AstNode* MakeAddToMapAst                        (AstNode *id, AstNode *key, AstNode *expr);
AstNode* MakeGetFromCollectionAst               (AstNode *id, AstNode *expr);
AstNode* MakeSetInCollectionAst                 (AstNode *id, AstNode *index, AstNode *val);
AstNode* MakeCollectionSizeAst                  (AstNode *id);
AstNode* MakeAddAst                             (AstNode *node);
AstNode* MakeIncAst                             (AstNode *node);
AstNode* MakeModAst                             (AstNode *left, AstNode *right);
AstNode* MakeFuncAst                            (AstNode *name, AstNode *params, AstNode *ret_type);
AstNode* MakeFuncParamAst                       (AstNode *name, AstNode *type);

AstNode* MakeTermNode                           (string data, DataType type);
AstNode* MakeDataTypeNode                       (string type);
AstNode* MakeIDNode                             (string id);

template<class T>
AstNode* MakeTermNode(T data, DataType type) {
    return MakeNode(RAW_DATA_CMD, data, type);
}
