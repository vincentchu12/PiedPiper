
#include <stdlib.h>
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;



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
    cout << "Visiting visitRoot" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(mmcParser::DeclarationContext *ctx) override {
    cout << "Visiting visitDeclaration" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinition(mmcParser::DefinitionContext *ctx) override {
    cout << "Visiting visitDefinition" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclaration(mmcParser::FunctionDeclarationContext *ctx) override {
    cout << "Visiting visitFunctionDeclaration" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDefinition(mmcParser::FunctionDefinitionContext *ctx) override {
    cout << "Visiting visitFunctionDefinition" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCall(mmcParser::FunctionCallContext *ctx) override {
    cout << "Visiting visitFunctionCall" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameters(mmcParser::ParametersContext *ctx) override {
    cout << "Visiting visitParameters" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifiers(mmcParser::IdentifiersContext *ctx) override {
    cout << "Visiting visitIdentifiers" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeID(mmcParser::TypeIDContext *ctx) override {
    cout << "Visiting visitTypeID" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(mmcParser::VariableContext *ctx) override {
    cout << "Visiting visitVariable" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(mmcParser::StatementContext *ctx) override {
    cout << "Visiting visitStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationStatement(mmcParser::DeclarationStatementContext *ctx) override {
    cout << "Visiting visitDeclarationStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitionStatement(mmcParser::DefinitionStatementContext *ctx) override {
    cout << "Visiting visitDefinitionStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStatement(mmcParser::ExpressionStatementContext *ctx) override {
    cout << "Visiting visitExpressionStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(mmcParser::IfStatementContext *ctx) override {
    cout << "Visiting visitIfStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStatement(mmcParser::ForStatementContext *ctx) override {
    cout << "Visiting visitForStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryStatement(mmcParser::UnaryStatementContext *ctx) override {
    cout << "Visiting visitUnaryStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementList(mmcParser::StatementListContext *ctx) override {
    cout << "Visiting visitStatementList" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentStatement(mmcParser::AssignmentStatementContext *ctx) override {
    cout << "Visiting visitAssignmentStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableExpr(mmcParser::VariableExprContext *ctx) override {
    cout << "Visiting visitVariableExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitExpr(mmcParser::BitExprContext *ctx) override {
    cout << "Visiting visitBitExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddSubExpr(mmcParser::AddSubExprContext *ctx) override {
    cout << "Visiting visitAddSubExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayExpr(mmcParser::ArrayExprContext *ctx) override {
    cout << "Visiting visitArrayExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMathExpr(mmcParser::MathExprContext *ctx) override {
    cout << "Visiting visitMathExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberExpr(mmcParser::NumberExprContext *ctx) override {
    cout << "Visiting visitNumberExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicExpr(mmcParser::LogicExprContext *ctx) override {
    cout << "Visiting visitLogicExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulDivModExpr(mmcParser::MulDivModExprContext *ctx) override {
    cout << "Visiting visitMulDivModExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncCallExpr(mmcParser::FuncCallExprContext *ctx) override {
    cout << "Visiting visitFuncCallExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenExpr(mmcParser::ParenExprContext *ctx) override {
    cout << "Visiting visitParenExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreInc(mmcParser::PreIncContext *ctx) override {
    cout << "Visiting visitPreInc" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreDec(mmcParser::PreDecContext *ctx) override {
    cout << "Visiting visitPreDec" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostInc(mmcParser::PostIncContext *ctx) override {
    cout << "Visiting visitPostInc" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostDec(mmcParser::PostDecContext *ctx) override {
    cout << "Visiting visitPostDec" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(mmcParser::AssignmentContext *ctx) override {
    cout << "Visiting visitAssignment" << endl;
    return visitChildren(ctx);
  }


};

