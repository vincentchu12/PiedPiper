#ifndef PASS1VISITOR_H_
#define PASS1VISITOR_H_

#include <iostream>
#include <string>

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "mmcBaseVisitor.h"
#include "antlr4-runtime.h"
#include "mmcVisitor.h"

using namespace wci;
using namespace wci::intermediate;

class Pass1Visitor : public mmcBaseVisitor
{
private:
    SymTabStack *symtab_stack;
    SymTabEntry *program_id;
    vector<SymTabEntry *> variable_id_list;
    ofstream j_file;

public:
    Pass1Visitor();
    virtual ~Pass1Visitor();

    ostream& get_assembly_file();

    bool lookupVariable(mmcParser::VariableContext *ctx, SymTabEntry ** var_id);
    bool determineType(mmcParser::TypeIDContext *ctx, TypeSpec ** type, string * type_indicator);

    antlrcpp::Any visitRoot(mmcParser::RootContext *ctx) override;
    antlrcpp::Any visitFunctionDefinition(mmcParser::FunctionDefinitionContext *ctx) override;
    antlrcpp::Any visitFunctionID(mmcParser::FunctionIDContext *ctx) override;
    antlrcpp::Any visitVariableID(mmcParser::VariableIDContext *ctx) override;
    antlrcpp::Any visitVariable(mmcParser::VariableContext *ctx) override;
    antlrcpp::Any visitBitIndexExpr(mmcParser::BitIndexExprContext *ctx) override;
    antlrcpp::Any visitStr(mmcParser::StrContext *ctx) override;
    antlrcpp::Any visitStringExpr(mmcParser::StringExprContext *ctx) override;
    antlrcpp::Any visitNumber(mmcParser::NumberContext *ctx) override;
    antlrcpp::Any visitSignedNumber(mmcParser::SignedNumberContext *ctx) override;
    antlrcpp::Any visitUnaryExpr(mmcParser::UnaryExprContext *ctx) override;
    antlrcpp::Any visitBoolExpr(mmcParser::BoolExprContext *ctx) override;
    antlrcpp::Any visitVariableExpr(mmcParser::VariableExprContext *ctx) override;
    antlrcpp::Any visitBitExpr(mmcParser::BitExprContext *ctx) override;
    antlrcpp::Any visitAddSubExpr(mmcParser::AddSubExprContext *ctx) override;
    antlrcpp::Any visitArrayExpr(mmcParser::ArrayExprContext *ctx) override;
    antlrcpp::Any visitMathExpr(mmcParser::MathExprContext *ctx) override;
    antlrcpp::Any visitMulDivModExpr(mmcParser::MulDivModExprContext *ctx) override;
    antlrcpp::Any visitFuncCallExpr(mmcParser::FuncCallExprContext *ctx) override;
    antlrcpp::Any visitUnsignedNumberExpr(mmcParser::UnsignedNumberExprContext *ctx) override;  
    antlrcpp::Any visitParenExpr(mmcParser::ParenExprContext *ctx) override;
    antlrcpp::Any visitSignedNumberExpr(mmcParser::SignedNumberExprContext *ctx) override;
    antlrcpp::Any visitPreInc(mmcParser::PreIncContext *ctx) override;
    antlrcpp::Any visitPreDec(mmcParser::PreDecContext *ctx) override;
    antlrcpp::Any visitPostInc(mmcParser::PostIncContext *ctx) override;
    antlrcpp::Any visitPostDec(mmcParser::PostDecContext *ctx) override;
    antlrcpp::Any visitVariableDeclaration(mmcParser::VariableDeclarationContext *ctx) override;
    antlrcpp::Any visitArrayDeclaration(mmcParser::ArrayDeclarationContext *ctx) override;
    antlrcpp::Any visitVariableDef(mmcParser::VariableDefContext *ctx) override;
    antlrcpp::Any visitArrayDef(mmcParser::ArrayDefContext *ctx) override;
};

#endif /* PASS1VISITOR_H_ */
