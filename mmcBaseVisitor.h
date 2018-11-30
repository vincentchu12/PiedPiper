
#include <stdlib.h>
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;
extern string program_name;


// Generated from mmc.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "mmcVisitor.h"


/**
 * This class provides an empty implementation of mmcVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  mmcBaseVisitor : public mmcVisitor {
public:

  virtual antlrcpp::Any visitRoot(mmcParser::RootContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(mmcParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinition(mmcParser::DefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclaration(mmcParser::FunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDefinition(mmcParser::FunctionDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCall(mmcParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameters(mmcParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifiers(mmcParser::IdentifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeID(mmcParser::TypeIDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionID(mmcParser::FunctionIDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction(mmcParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableID(mmcParser::VariableIDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(mmcParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(mmcParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStr(mmcParser::StrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignedNumber(mmcParser::SignedNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSign(mmcParser::SignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(mmcParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationStatement(mmcParser::DeclarationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitionStatement(mmcParser::DefinitionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStatement(mmcParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrintfStatement(mmcParser::PrintfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(mmcParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStatement(mmcParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryStatement(mmcParser::UnaryStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementList(mmcParser::StatementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentStatement(mmcParser::AssignmentStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddSubExpr(mmcParser::AddSubExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayExpr(mmcParser::ArrayExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulDivModExpr(mmcParser::MulDivModExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncCallExpr(mmcParser::FuncCallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenExpr(mmcParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringExpr(mmcParser::StringExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableExpr(mmcParser::VariableExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitExpr(mmcParser::BitExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryExpr(mmcParser::UnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMathExpr(mmcParser::MathExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicExpr(mmcParser::LogicExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolExpr(mmcParser::BoolExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsignedNumberExpr(mmcParser::UnsignedNumberExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignedNumberExpr(mmcParser::SignedNumberExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreInc(mmcParser::PreIncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreDec(mmcParser::PreDecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostInc(mmcParser::PostIncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostDec(mmcParser::PostDecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(mmcParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }


};

