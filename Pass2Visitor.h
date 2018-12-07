#ifndef PASS2VISITOR_H_
#define PASS2VISITOR_H_

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

class Pass2Visitor : public mmcBaseVisitor
{
private:
	ostream& j_file;

public:
	Pass2Visitor(ostream& j_file);
    virtual ~Pass2Visitor();

    antlrcpp::Any visitRoot(mmcParser::RootContext *ctx) override;
    antlrcpp::Any visitBoolExpr(mmcParser::BoolExprContext *ctx) override;
    antlrcpp::Any visitStr(mmcParser::StrContext *ctx) override;
    antlrcpp::Any visitFunctionDefinition(mmcParser::FunctionDefinitionContext *ctx) override;
    antlrcpp::Any visitFunctionCall(mmcParser::FunctionCallContext *ctx) override;
    antlrcpp::Any visitNumber(mmcParser::NumberContext *ctx) override;
    antlrcpp::Any visitSignedNumber(mmcParser::SignedNumberContext *ctx) override;
    antlrcpp::Any visitBitIndexAssignment(mmcParser::BitIndexAssignmentContext *ctx) override;
    antlrcpp::Any visitBitIndexExpr(mmcParser::BitIndexExprContext *ctx) override;
    antlrcpp::Any visitIfStatement(mmcParser::IfStatementContext *ctx) override;
    antlrcpp::Any visitForStatement(mmcParser::ForStatementContext *ctx) override;
    antlrcpp::Any visitVariableExpr(mmcParser::VariableExprContext *ctx) override;
    antlrcpp::Any visitAddSubExpr(mmcParser::AddSubExprContext *ctx) override;
    antlrcpp::Any visitMathExpr(mmcParser::MathExprContext *ctx) override;
    antlrcpp::Any visitUnaryExpr(mmcParser::UnaryExprContext *ctx) override;
    antlrcpp::Any visitMulDivModExpr(mmcParser::MulDivModExprContext *ctx) override;
    antlrcpp::Any visitPreInc(mmcParser::PreIncContext *ctx) override;
    antlrcpp::Any visitPreDec(mmcParser::PreDecContext *ctx) override;
    antlrcpp::Any visitPostInc(mmcParser::PostIncContext *ctx) override;
    antlrcpp::Any visitPostDec(mmcParser::PostDecContext *ctx) override;
    antlrcpp::Any visitPrintfStatement(mmcParser::PrintfStatementContext *ctx) override;
    antlrcpp::Any visitArrayDeclaration(mmcParser::ArrayDeclarationContext *ctx) override;
    antlrcpp::Any visitVariableDef(mmcParser::VariableDefContext *ctx) override;
    antlrcpp::Any visitArrayDef(mmcParser::ArrayDefContext *ctx) override;
    antlrcpp::Any visitVariableAssignment(mmcParser::VariableAssignmentContext *ctx) override;
    antlrcpp::Any visitArrayAssignment(mmcParser::ArrayAssignmentContext *ctx) override;

};

#endif /* PASS2VISITOR_H_ */
