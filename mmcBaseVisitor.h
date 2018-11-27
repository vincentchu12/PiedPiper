
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
    cout << "Original function visitRoot " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(mmcParser::DeclarationContext *ctx) override {
    cout << "Original function visitDeclaration " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinition(mmcParser::DefinitionContext *ctx) override {
    cout << "Original function visitDefinition " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclaration(mmcParser::FunctionDeclarationContext *ctx) override {
    cout << "Original function visitFunctionDeclaration " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDefinition(mmcParser::FunctionDefinitionContext *ctx) override {
    cout << "Original function visitFunctionDefinition " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCall(mmcParser::FunctionCallContext *ctx) override {
    cout << "Original function visitFunctionCall " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameters(mmcParser::ParametersContext *ctx) override {
    cout << "Original function visitParameters " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifiers(mmcParser::IdentifiersContext *ctx) override {
    cout << "Original function visitIdentifiers " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeID(mmcParser::TypeIDContext *ctx) override {
    cout << "Original function visitTypeID " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionID(mmcParser::FunctionIDContext *ctx) override {
    cout << "Original function visitFunctionID " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction(mmcParser::FunctionContext *ctx) override {
    cout << "Original function visitFunction " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableID(mmcParser::VariableIDContext *ctx) override {
    cout << "Original function visitVariableID " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(mmcParser::VariableContext *ctx) override {
    cout << "Original function visitVariable " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(mmcParser::NumberContext *ctx) override {
    cout << "Original function visitNumber " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignedNumber(mmcParser::SignedNumberContext *ctx) override {
    cout << "Original function visitSignedNumber " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSign(mmcParser::SignContext *ctx) override {
    cout << "Original function visitSign " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(mmcParser::StatementContext *ctx) override {
    cout << "Original function visitStatement " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationStatement(mmcParser::DeclarationStatementContext *ctx) override {
    cout << "Original function visitDeclarationStatement " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitionStatement(mmcParser::DefinitionStatementContext *ctx) override {
    cout << "Original function visitDefinitionStatement " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStatement(mmcParser::ExpressionStatementContext *ctx) override {
    cout << "Original function visitExpressionStatement " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(mmcParser::IfStatementContext *ctx) override {
    cout << "Original function visitIfStatement " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStatement(mmcParser::ForStatementContext *ctx) override {
    cout << "Original function visitForStatement " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryStatement(mmcParser::UnaryStatementContext *ctx) override {
    cout << "Original function visitUnaryStatement " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementList(mmcParser::StatementListContext *ctx) override {
    cout << "Original function visitStatementList " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentStatement(mmcParser::AssignmentStatementContext *ctx) override {
    cout << "Original function visitAssignmentStatement " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableExpr(mmcParser::VariableExprContext *ctx) override {
    cout << "Original function visitVariableExpr " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitExpr(mmcParser::BitExprContext *ctx) override {
    cout << "Original function visitBitExpr " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddSubExpr(mmcParser::AddSubExprContext *ctx) override {
    cout << "Original function visitAddSubExpr " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayExpr(mmcParser::ArrayExprContext *ctx) override {
    cout << "Original function visitArrayExpr " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMathExpr(mmcParser::MathExprContext *ctx) override {
    cout << "Original function visitMathExpr " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicExpr(mmcParser::LogicExprContext *ctx) override {
    cout << "Original function visitLogicExpr " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulDivModExpr(mmcParser::MulDivModExprContext *ctx) override {
    cout << "Original function visitMulDivModExpr " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncCallExpr(mmcParser::FuncCallExprContext *ctx) override {
    cout << "Original function visitFuncCallExpr " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolExpr(mmcParser::BoolExprContext *ctx) override {
    cout << "Original function visitBoolExpr " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsignedNumberExpr(mmcParser::UnsignedNumberExprContext *ctx) override {
    cout << "Original function visitUnsignedNumberExpr " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenExpr(mmcParser::ParenExprContext *ctx) override {
    cout << "Original function visitParenExpr " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignedNumberExpr(mmcParser::SignedNumberExprContext *ctx) override {
    cout << "Original function visitSignedNumberExpr " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreInc(mmcParser::PreIncContext *ctx) override {
    cout << "Original function visitPreInc " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreDec(mmcParser::PreDecContext *ctx) override {
    cout << "Original function visitPreDec " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostInc(mmcParser::PostIncContext *ctx) override {
    cout << "Original function visitPostInc " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostDec(mmcParser::PostDecContext *ctx) override {
    cout << "Original function visitPostDec " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(mmcParser::AssignmentContext *ctx) override {
    cout << "Original function visitAssignment " << ctx->getText() << endl << endl;
    return visitChildren(ctx);
  }


};

