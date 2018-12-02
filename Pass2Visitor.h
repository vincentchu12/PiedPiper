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
    // antlrcpp::Any visitBool(mmcParser::BoolContext *ctx) override;
    antlrcpp::Any visitBoolExpr(mmcParser::BoolExprContext *ctx) override;
//    antlrcpp::Any visitDeclaration(mmcParser::DeclarationContext *ctx) override;
    antlrcpp::Any visitDefinition(mmcParser::DefinitionContext *ctx) override;
    antlrcpp::Any visitStr(mmcParser::StrContext *ctx) override;
//    antlrcpp::Any visitFunctionDeclaration(mmcParser::FunctionDeclarationContext *ctx) override;
//    antlrcpp::Any visitFunctionDefinition(mmcParser::FunctionDefinitionContext *ctx) override;
//    antlrcpp::Any visitFunctionCall(mmcParser::FunctionCallContext *ctx) override;
//    antlrcpp::Any visitParameters(mmcParser::ParametersContext *ctx) override;
//    antlrcpp::Any visitIdentifiers(mmcParser::IdentifiersContext *ctx) override;
//    antlrcpp::Any visitTypeID(mmcParser::TypeIDContext *ctx) override;
//    antlrcpp::Any visitFunctionID(mmcParser::FunctionIDContext *ctx) override;
//    antlrcpp::Any visitFunction(mmcParser::FunctionContext *ctx) override;
//    antlrcpp::Any visitVariableID(mmcParser::VariableIDContext *ctx) override;
//    antlrcpp::Any visitVariable(mmcParser::VariableContext *ctx) override;
   antlrcpp::Any visitNumber(mmcParser::NumberContext *ctx) override;
    antlrcpp::Any visitSignedNumber(mmcParser::SignedNumberContext *ctx) override;
//    antlrcpp::Any visitSign(mmcParser::SignContext *ctx) override;
//    antlrcpp::Any visitStatement(mmcParser::StatementContext *ctx) override;
//    antlrcpp::Any visitDeclarationStatement(mmcParser::DeclarationStatementContext *ctx) override;
//    antlrcpp::Any visitDefinitionStatement(mmcParser::DefinitionStatementContext *ctx) override;
//    antlrcpp::Any visitExpressionStatement(mmcParser::ExpressionStatementContext *ctx) override;
    antlrcpp::Any visitIfStatement(mmcParser::IfStatementContext *ctx) override;
   antlrcpp::Any visitForStatement(mmcParser::ForStatementContext *ctx) override;
//    antlrcpp::Any visitUnaryStatement(mmcParser::UnaryStatementContext *ctx) override;
//    antlrcpp::Any visitStatementList(mmcParser::StatementListContext *ctx) override;
//    antlrcpp::Any visitAssignmentStatement(mmcParser::AssignmentStatementContext *ctx) override;
   antlrcpp::Any visitVariableExpr(mmcParser::VariableExprContext *ctx) override;
//    antlrcpp::Any visitBitExpr(mmcParser::BitExprContext *ctx) override;
   antlrcpp::Any visitAddSubExpr(mmcParser::AddSubExprContext *ctx) override;
//    antlrcpp::Any visitArrayExpr(mmcParser::ArrayExprContext *ctx) override;
    antlrcpp::Any visitMathExpr(mmcParser::MathExprContext *ctx) override;
    antlrcpp::Any visitUnaryExpr(mmcParser::UnaryExprContext *ctx) override;
   antlrcpp::Any visitMulDivModExpr(mmcParser::MulDivModExprContext *ctx) override;
//    antlrcpp::Any visitFuncCallExpr(mmcParser::FuncCallExprContext *ctx) override;
//    antlrcpp::Any visitUnsignedNumberExpr(mmcParser::UnsignedNumberExprContext *ctx) override;
//    antlrcpp::Any visitParenExpr(mmcParser::ParenExprContext *ctx) override;
//   antlrcpp::Any visitSignedNumberExpr(mmcParser::SignedNumberExprContext *ctx) override;
    antlrcpp::Any visitPreInc(mmcParser::PreIncContext *ctx) override;
    antlrcpp::Any visitPreDec(mmcParser::PreDecContext *ctx) override;
    antlrcpp::Any visitPostInc(mmcParser::PostIncContext *ctx) override;
    antlrcpp::Any visitPostDec(mmcParser::PostDecContext *ctx) override;
   antlrcpp::Any visitAssignment(mmcParser::AssignmentContext *ctx) override;
   antlrcpp::Any visitPrintfStatement(mmcParser::PrintfStatementContext *ctx) override;


};

#endif /* PASS2VISITOR_H_ */
