
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
    cout << "Original Function\tvisitRoot" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclaration(mmcParser::VariableDeclarationContext *ctx) override {
    cout << "Original Function\tvisitVariableDeclaration" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayDeclaration(mmcParser::ArrayDeclarationContext *ctx) override {
    cout << "Original Function\tvisitArrayDeclaration" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDef(mmcParser::VariableDefContext *ctx) override {
    cout << "Original Function\tvisitVariableDef" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayDef(mmcParser::ArrayDefContext *ctx) override {
    cout << "Original Function\tvisitArrayDef" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclaration(mmcParser::FunctionDeclarationContext *ctx) override {
    cout << "Original Function\tvisitFunctionDeclaration" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDefinition(mmcParser::FunctionDefinitionContext *ctx) override {
    cout << "Original Function\tvisitFunctionDefinition" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCall(mmcParser::FunctionCallContext *ctx) override {
    cout << "Original Function\tvisitFunctionCall" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameters(mmcParser::ParametersContext *ctx) override {
    cout << "Original Function\tvisitParameters" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifiers(mmcParser::IdentifiersContext *ctx) override {
    cout << "Original Function\tvisitIdentifiers" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeID(mmcParser::TypeIDContext *ctx) override {
    cout << "Original Function\tvisitTypeID" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionID(mmcParser::FunctionIDContext *ctx) override {
    cout << "Original Function\tvisitFunctionID" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction(mmcParser::FunctionContext *ctx) override {
    cout << "Original Function\tvisitFunction" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableID(mmcParser::VariableIDContext *ctx) override {
    cout << "Original Function\tvisitVariableID" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(mmcParser::VariableContext *ctx) override {
    cout << "Original Function\tvisitVariable" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(mmcParser::NumberContext *ctx) override {
    cout << "Original Function\tvisitNumber" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStr(mmcParser::StrContext *ctx) override {
    cout << "Original Function\tvisitStr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignedNumber(mmcParser::SignedNumberContext *ctx) override {
    cout << "Original Function\tvisitSignedNumber" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSign(mmcParser::SignContext *ctx) override {
    cout << "Original Function\tvisitSign" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(mmcParser::StatementContext *ctx) override {
    cout << "Original Function\tvisitStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationStatement(mmcParser::DeclarationStatementContext *ctx) override {
    cout << "Original Function\tvisitDeclarationStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitionStatement(mmcParser::DefinitionStatementContext *ctx) override {
    cout << "Original Function\tvisitDefinitionStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStatement(mmcParser::ExpressionStatementContext *ctx) override {
    cout << "Original Function\tvisitExpressionStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrintfStatement(mmcParser::PrintfStatementContext *ctx) override {
    cout << "Original Function\tvisitPrintfStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(mmcParser::IfStatementContext *ctx) override {
    cout << "Original Function\tvisitIfStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStatement(mmcParser::ForStatementContext *ctx) override {
    cout << "Original Function\tvisitForStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryStatement(mmcParser::UnaryStatementContext *ctx) override {
    cout << "Original Function\tvisitUnaryStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementList(mmcParser::StatementListContext *ctx) override {
    cout << "Original Function\tvisitStatementList" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentStatement(mmcParser::AssignmentStatementContext *ctx) override {
    cout << "Original Function\tvisitAssignmentStatement" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringExpr(mmcParser::StringExprContext *ctx) override {
    cout << "Original Function\tvisitStringExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableExpr(mmcParser::VariableExprContext *ctx) override {
    cout << "Original Function\tvisitVariableExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitExpr(mmcParser::BitExprContext *ctx) override {
    cout << "Original Function\tvisitBitExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryExpr(mmcParser::UnaryExprContext *ctx) override {
    cout << "Original Function\tvisitUnaryExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddSubExpr(mmcParser::AddSubExprContext *ctx) override {
    cout << "Original Function\tvisitAddSubExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayExpr(mmcParser::ArrayExprContext *ctx) override {
    cout << "Original Function\tvisitArrayExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulDivModExpr(mmcParser::MulDivModExprContext *ctx) override {
    cout << "Original Function\tvisitMulDivModExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncCallExpr(mmcParser::FuncCallExprContext *ctx) override {
    cout << "Original Function\tvisitFuncCallExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolExpr(mmcParser::BoolExprContext *ctx) override {
    cout << "Original Function\tvisitBoolExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsignedNumberExpr(mmcParser::UnsignedNumberExprContext *ctx) override {
    cout << "Original Function\tvisitUnsignedNumberExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenExpr(mmcParser::ParenExprContext *ctx) override {
    cout << "Original Function\tvisitParenExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignedNumberExpr(mmcParser::SignedNumberExprContext *ctx) override {
    cout << "Original Function\tvisitSignedNumberExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMathExpr(mmcParser::MathExprContext *ctx) override {
    cout << "Original Function\tvisitMathExpr" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreInc(mmcParser::PreIncContext *ctx) override {
    cout << "Original Function\tvisitPreInc" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreDec(mmcParser::PreDecContext *ctx) override {
    cout << "Original Function\tvisitPreDec" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostInc(mmcParser::PostIncContext *ctx) override {
    cout << "Original Function\tvisitPostInc" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostDec(mmcParser::PostDecContext *ctx) override {
    cout << "Original Function\tvisitPostDec" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableAssignment(mmcParser::VariableAssignmentContext *ctx) override {
    cout << "Original Function\tvisitVariableAssignment" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayAssignment(mmcParser::ArrayAssignmentContext *ctx) override {
    cout << "Original Function\tvisitArrayAssignment" << endl;
    return visitChildren(ctx);
  }


};

