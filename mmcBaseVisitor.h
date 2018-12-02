
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
    cout << "Original Function: visitRoot" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(mmcParser::DeclarationContext *ctx) override {
    cout << "Original Function: visitDeclaration" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinition(mmcParser::DefinitionContext *ctx) override {
    cout << "Original Function: visitDefinition" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclaration(mmcParser::FunctionDeclarationContext *ctx) override {
    cout << "Original Function: visitFunctionDeclaration" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDefinition(mmcParser::FunctionDefinitionContext *ctx) override {
    cout << "Original Function: visitFunctionDefinition" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCall(mmcParser::FunctionCallContext *ctx) override {
    cout << "Original Function: visitFunctionCall" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameters(mmcParser::ParametersContext *ctx) override {
    cout << "Original Function: visitParameters" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifiers(mmcParser::IdentifiersContext *ctx) override {
    cout << "Original Function: visitIdentifiers" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeID(mmcParser::TypeIDContext *ctx) override {
    cout << "Original Function: visitTypeID" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionID(mmcParser::FunctionIDContext *ctx) override {
    cout << "Original Function: visitFunctionID" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction(mmcParser::FunctionContext *ctx) override {
    cout << "Original Function: visitFunction" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableID(mmcParser::VariableIDContext *ctx) override {
    cout << "Original Function: visitVariableID" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(mmcParser::VariableContext *ctx) override {
    cout << "Original Function: visitVariable" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(mmcParser::NumberContext *ctx) override {
    cout << "Original Function: visitNumber" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStr(mmcParser::StrContext *ctx) override {
    cout << "Original Function: visitStr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignedNumber(mmcParser::SignedNumberContext *ctx) override {
    cout << "Original Function: visitSignedNumber" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSign(mmcParser::SignContext *ctx) override {
    cout << "Original Function: visitSign" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(mmcParser::StatementContext *ctx) override {
    cout << "Original Function: visitStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationStatement(mmcParser::DeclarationStatementContext *ctx) override {
    cout << "Original Function: visitDeclarationStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitionStatement(mmcParser::DefinitionStatementContext *ctx) override {
    cout << "Original Function: visitDefinitionStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStatement(mmcParser::ExpressionStatementContext *ctx) override {
    cout << "Original Function: visitExpressionStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrintfStatement(mmcParser::PrintfStatementContext *ctx) override {
    cout << "Original Function: visitPrintfStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(mmcParser::IfStatementContext *ctx) override {
    cout << "Original Function: visitIfStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStatement(mmcParser::ForStatementContext *ctx) override {
    cout << "Original Function: visitForStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryStatement(mmcParser::UnaryStatementContext *ctx) override {
    cout << "Original Function: visitUnaryStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementList(mmcParser::StatementListContext *ctx) override {
    cout << "Original Function: visitStatementList" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentStatement(mmcParser::AssignmentStatementContext *ctx) override {
    cout << "Original Function: visitAssignmentStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringExpr(mmcParser::StringExprContext *ctx) override {
    cout << "Original Function: visitStringExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableExpr(mmcParser::VariableExprContext *ctx) override {
    cout << "Original Function: visitVariableExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitExpr(mmcParser::BitExprContext *ctx) override {
    cout << "Original Function: visitBitExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryExpr(mmcParser::UnaryExprContext *ctx) override {
    cout << "Original Function: visitUnaryExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddSubExpr(mmcParser::AddSubExprContext *ctx) override {
    cout << "Original Function: visitAddSubExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayExpr(mmcParser::ArrayExprContext *ctx) override {
    cout << "Original Function: visitArrayExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulDivModExpr(mmcParser::MulDivModExprContext *ctx) override {
    cout << "Original Function: visitMulDivModExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncCallExpr(mmcParser::FuncCallExprContext *ctx) override {
    cout << "Original Function: visitFuncCallExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolExpr(mmcParser::BoolExprContext *ctx) override {
    cout << "Original Function: visitBoolExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsignedNumberExpr(mmcParser::UnsignedNumberExprContext *ctx) override {
    cout << "Original Function: visitUnsignedNumberExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenExpr(mmcParser::ParenExprContext *ctx) override {
    cout << "Original Function: visitParenExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignedNumberExpr(mmcParser::SignedNumberExprContext *ctx) override {
    cout << "Original Function: visitSignedNumberExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMathExpr(mmcParser::MathExprContext *ctx) override {
    cout << "Original Function: visitMathExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreInc(mmcParser::PreIncContext *ctx) override {
    cout << "Original Function: visitPreInc" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreDec(mmcParser::PreDecContext *ctx) override {
    cout << "Original Function: visitPreDec" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostInc(mmcParser::PostIncContext *ctx) override {
    cout << "Original Function: visitPostInc" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostDec(mmcParser::PostDecContext *ctx) override {
    cout << "Original Function: visitPostDec" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(mmcParser::AssignmentContext *ctx) override {
    cout << "Original Function: visitAssignment" << endl;
    return visitChildren(ctx);
  }


};

