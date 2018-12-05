
#include <stdlib.h>
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;
extern string program_name;


// Generated from mmc.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "mmcParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by mmcParser.
 */
class  mmcVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by mmcParser.
   */
    virtual antlrcpp::Any visitRoot(mmcParser::RootContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclaration(mmcParser::VariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitArrayDeclaration(mmcParser::ArrayDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVariableDef(mmcParser::VariableDefContext *context) = 0;

    virtual antlrcpp::Any visitArrayDef(mmcParser::ArrayDefContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclaration(mmcParser::FunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDefinition(mmcParser::FunctionDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCall(mmcParser::FunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitParameters(mmcParser::ParametersContext *context) = 0;

    virtual antlrcpp::Any visitIdentifiers(mmcParser::IdentifiersContext *context) = 0;

    virtual antlrcpp::Any visitTypeID(mmcParser::TypeIDContext *context) = 0;

    virtual antlrcpp::Any visitFunctionID(mmcParser::FunctionIDContext *context) = 0;

    virtual antlrcpp::Any visitFunction(mmcParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitVariableID(mmcParser::VariableIDContext *context) = 0;

    virtual antlrcpp::Any visitVariable(mmcParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitNumber(mmcParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitStr(mmcParser::StrContext *context) = 0;

    virtual antlrcpp::Any visitSignedNumber(mmcParser::SignedNumberContext *context) = 0;

    virtual antlrcpp::Any visitSign(mmcParser::SignContext *context) = 0;

    virtual antlrcpp::Any visitStatement(mmcParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationStatement(mmcParser::DeclarationStatementContext *context) = 0;

    virtual antlrcpp::Any visitDefinitionStatement(mmcParser::DefinitionStatementContext *context) = 0;

    virtual antlrcpp::Any visitExpressionStatement(mmcParser::ExpressionStatementContext *context) = 0;

    virtual antlrcpp::Any visitPrintfStatement(mmcParser::PrintfStatementContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(mmcParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitForStatement(mmcParser::ForStatementContext *context) = 0;

    virtual antlrcpp::Any visitUnaryStatement(mmcParser::UnaryStatementContext *context) = 0;

    virtual antlrcpp::Any visitStatementList(mmcParser::StatementListContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentStatement(mmcParser::AssignmentStatementContext *context) = 0;

    virtual antlrcpp::Any visitStringExpr(mmcParser::StringExprContext *context) = 0;

    virtual antlrcpp::Any visitVariableExpr(mmcParser::VariableExprContext *context) = 0;

    virtual antlrcpp::Any visitBitExpr(mmcParser::BitExprContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExpr(mmcParser::UnaryExprContext *context) = 0;

    virtual antlrcpp::Any visitAddSubExpr(mmcParser::AddSubExprContext *context) = 0;

    virtual antlrcpp::Any visitArrayExpr(mmcParser::ArrayExprContext *context) = 0;

    virtual antlrcpp::Any visitMulDivModExpr(mmcParser::MulDivModExprContext *context) = 0;

    virtual antlrcpp::Any visitFuncCallExpr(mmcParser::FuncCallExprContext *context) = 0;

    virtual antlrcpp::Any visitBoolExpr(mmcParser::BoolExprContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedNumberExpr(mmcParser::UnsignedNumberExprContext *context) = 0;

    virtual antlrcpp::Any visitParenExpr(mmcParser::ParenExprContext *context) = 0;

    virtual antlrcpp::Any visitSignedNumberExpr(mmcParser::SignedNumberExprContext *context) = 0;

    virtual antlrcpp::Any visitMathExpr(mmcParser::MathExprContext *context) = 0;

    virtual antlrcpp::Any visitPreInc(mmcParser::PreIncContext *context) = 0;

    virtual antlrcpp::Any visitPreDec(mmcParser::PreDecContext *context) = 0;

    virtual antlrcpp::Any visitPostInc(mmcParser::PostIncContext *context) = 0;

    virtual antlrcpp::Any visitPostDec(mmcParser::PostDecContext *context) = 0;

    virtual antlrcpp::Any visitVariableAssignment(mmcParser::VariableAssignmentContext *context) = 0;

    virtual antlrcpp::Any visitArrayAssignment(mmcParser::ArrayAssignmentContext *context) = 0;


};

