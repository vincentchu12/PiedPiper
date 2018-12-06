
#include <stdlib.h>
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;
extern string program_name;


// Generated from mmc.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  mmcParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, BOOL = 10, MUL_DIV_MOD_OP = 11, ADD_SUB_OP = 12, 
    BIT_OP = 13, MATH_COMP = 14, FOR = 15, IF = 16, ELSE = 17, ELIF = 18, 
    RETURN = 19, TRUE = 20, FALSE = 21, PRINTF = 22, IDENTIFIER = 23, INTEGER = 24, 
    ASSIGN = 25, EQ = 26, NEQ = 27, LT = 28, LTE = 29, GT = 30, GTE = 31, 
    MUL_OP = 32, DIV_OP = 33, MOD_OP = 34, ADD_OP = 35, SUB_OP = 36, AND_OP = 37, 
    OR_OP = 38, XOR_OP = 39, INC = 40, DEC = 41, STRING = 42, NEWLINE = 43, 
    WS = 44
  };

  enum {
    RuleRoot = 0, RuleDeclaration = 1, RuleDefinition = 2, RuleFunctionDefinition = 3, 
    RuleFunctionCall = 4, RuleParameters = 5, RuleIdentifiers = 6, RuleTypeID = 7, 
    RuleFunctionID = 8, RuleFunction = 9, RuleVariableID = 10, RuleVariable = 11, 
    RuleNumber = 12, RuleStr = 13, RuleSignedNumber = 14, RuleSign = 15, 
    RuleStatement = 16, RuleDeclarationStatement = 17, RuleDefinitionStatement = 18, 
    RuleExpressionStatement = 19, RulePrintfStatement = 20, RuleIfStatement = 21, 
    RuleForStatement = 22, RuleUnaryStatement = 23, RuleStatementList = 24, 
    RuleAssignmentStatement = 25, RuleExpression = 26, RuleMathExpr = 27, 
    RuleUnary = 28, RuleAssignment = 29
  };

  mmcParser(antlr4::TokenStream *input);
  ~mmcParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class RootContext;
  class DeclarationContext;
  class DefinitionContext;
  class FunctionDefinitionContext;
  class FunctionCallContext;
  class ParametersContext;
  class IdentifiersContext;
  class TypeIDContext;
  class FunctionIDContext;
  class FunctionContext;
  class VariableIDContext;
  class VariableContext;
  class NumberContext;
  class StrContext;
  class SignedNumberContext;
  class SignContext;
  class StatementContext;
  class DeclarationStatementContext;
  class DefinitionStatementContext;
  class ExpressionStatementContext;
  class PrintfStatementContext;
  class IfStatementContext;
  class ForStatementContext;
  class UnaryStatementContext;
  class StatementListContext;
  class AssignmentStatementContext;
  class ExpressionContext;
  class MathExprContext;
  class UnaryContext;
  class AssignmentContext; 

  class  RootContext : public antlr4::ParserRuleContext {
  public:
    RootContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementListContext *statementList();
    std::vector<FunctionDefinitionContext *> functionDefinition();
    FunctionDefinitionContext* functionDefinition(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RootContext* root();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DeclarationContext() : antlr4::ParserRuleContext() { }
    void copyFrom(DeclarationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ArrayDeclarationContext : public DeclarationContext {
  public:
    ArrayDeclarationContext(DeclarationContext *ctx);

    TypeIDContext *typeID();
    VariableIDContext *variableID();
    NumberContext *number();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VariableDeclarationContext : public DeclarationContext {
  public:
    VariableDeclarationContext(DeclarationContext *ctx);

    TypeIDContext *typeID();
    VariableIDContext *variableID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DeclarationContext* declaration();

  class  DefinitionContext : public antlr4::ParserRuleContext {
  public:
    DefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DefinitionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(DefinitionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VariableDefContext : public DefinitionContext {
  public:
    VariableDefContext(DefinitionContext *ctx);

    TypeIDContext *typeID();
    VariableIDContext *variableID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayDefContext : public DefinitionContext {
  public:
    ArrayDefContext(DefinitionContext *ctx);

    TypeIDContext *typeID();
    VariableIDContext *variableID();
    NumberContext *number();
    antlr4::tree::TerminalNode *ASSIGN();
    IdentifiersContext *identifiers();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DefinitionContext* definition();

  class  FunctionDefinitionContext : public antlr4::ParserRuleContext {
  public:
    FunctionDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeIDContext *typeID();
    FunctionIDContext *functionID();
    ParametersContext *parameters();
    StatementListContext *statementList();
    antlr4::tree::TerminalNode *RETURN();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDefinitionContext* functionDefinition();

  class  FunctionCallContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionContext *function();
    IdentifiersContext *identifiers();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionCallContext* functionCall();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametersContext* parameters();

  class  IdentifiersContext : public antlr4::ParserRuleContext {
  public:
    IdentifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifiersContext* identifiers();

  class  TypeIDContext : public antlr4::ParserRuleContext {
  public:
    TypeIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeIDContext* typeID();

  class  FunctionIDContext : public antlr4::ParserRuleContext {
  public:
    FunctionIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionIDContext* functionID();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();

  class  VariableIDContext : public antlr4::ParserRuleContext {
  public:
    TypeSpec* type = nullptr;
    VariableIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableIDContext* variableID();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    TypeSpec* type = nullptr;
    int size = 0;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    TypeSpec* type = nullptr;
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  StrContext : public antlr4::ParserRuleContext {
  public:
    TypeSpec* type = nullptr;
    StrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StrContext* str();

  class  SignedNumberContext : public antlr4::ParserRuleContext {
  public:
    TypeSpec* type = nullptr;
    SignedNumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SignContext *sign();
    NumberContext *number();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SignedNumberContext* signedNumber();

  class  SignContext : public antlr4::ParserRuleContext {
  public:
    SignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD_OP();
    antlr4::tree::TerminalNode *SUB_OP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SignContext* sign();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionStatementContext *expressionStatement();
    PrintfStatementContext *printfStatement();
    UnaryStatementContext *unaryStatement();
    ForStatementContext *forStatement();
    IfStatementContext *ifStatement();
    AssignmentStatementContext *assignmentStatement();
    DeclarationStatementContext *declarationStatement();
    DefinitionStatementContext *definitionStatement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  DeclarationStatementContext : public antlr4::ParserRuleContext {
  public:
    DeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationContext *declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationStatementContext* declarationStatement();

  class  DefinitionStatementContext : public antlr4::ParserRuleContext {
  public:
    DefinitionStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DefinitionContext *definition();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefinitionStatementContext* definitionStatement();

  class  ExpressionStatementContext : public antlr4::ParserRuleContext {
  public:
    ExpressionStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionStatementContext* expressionStatement();

  class  PrintfStatementContext : public antlr4::ParserRuleContext {
  public:
    PrintfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRINTF();
    StrContext *str();
    IdentifiersContext *identifiers();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrintfStatementContext* printfStatement();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<MathExprContext *> mathExpr();
    MathExprContext* mathExpr(size_t i);
    std::vector<StatementListContext *> statementList();
    StatementListContext* statementList(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ELIF();
    antlr4::tree::TerminalNode* ELIF(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStatementContext* ifStatement();

  class  ForStatementContext : public antlr4::ParserRuleContext {
  public:
    ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    StatementListContext *statementList();
    VariableContext *variable();
    MathExprContext *mathExpr();
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);
    DefinitionContext *definition();
    std::vector<AssignmentContext *> assignment();
    AssignmentContext* assignment(size_t i);
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStatementContext* forStatement();

  class  UnaryStatementContext : public antlr4::ParserRuleContext {
  public:
    UnaryStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryContext *unary();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryStatementContext* unaryStatement();

  class  StatementListContext : public antlr4::ParserRuleContext {
  public:
    StatementListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementListContext* statementList();

  class  AssignmentStatementContext : public antlr4::ParserRuleContext {
  public:
    AssignmentStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignmentContext *assignment();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentStatementContext* assignmentStatement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    TypeSpec* type = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StringExprContext : public ExpressionContext {
  public:
    StringExprContext(ExpressionContext *ctx);

    StrContext *str();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VariableExprContext : public ExpressionContext {
  public:
    VariableExprContext(ExpressionContext *ctx);

    VariableContext *variable();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitExprContext : public ExpressionContext {
  public:
    BitExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *BIT_OP();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryExprContext : public ExpressionContext {
  public:
    UnaryExprContext(ExpressionContext *ctx);

    UnaryContext *unary();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddSubExprContext : public ExpressionContext {
  public:
    AddSubExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *ADD_SUB_OP();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayExprContext : public ExpressionContext {
  public:
    ArrayExprContext(ExpressionContext *ctx);

    VariableContext *variable();
    NumberContext *number();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulDivModExprContext : public ExpressionContext {
  public:
    MulDivModExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *MUL_DIV_MOD_OP();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FuncCallExprContext : public ExpressionContext {
  public:
    FuncCallExprContext(ExpressionContext *ctx);

    FunctionCallContext *functionCall();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BoolExprContext : public ExpressionContext {
  public:
    BoolExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *BOOL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnsignedNumberExprContext : public ExpressionContext {
  public:
    UnsignedNumberExprContext(ExpressionContext *ctx);

    NumberContext *number();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenExprContext : public ExpressionContext {
  public:
    ParenExprContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SignedNumberExprContext : public ExpressionContext {
  public:
    SignedNumberExprContext(ExpressionContext *ctx);

    SignedNumberContext *signedNumber();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  MathExprContext : public antlr4::ParserRuleContext {
  public:
    TypeSpec* type = nullptr;
    MathExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *MATH_COMP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MathExprContext* mathExpr();

  class  UnaryContext : public antlr4::ParserRuleContext {
  public:
    TypeSpec* type = nullptr;
    UnaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnaryContext() : antlr4::ParserRuleContext() { }
    void copyFrom(UnaryContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PostIncContext : public UnaryContext {
  public:
    PostIncContext(UnaryContext *ctx);

    VariableContext *variable();
    antlr4::tree::TerminalNode *INC();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PreDecContext : public UnaryContext {
  public:
    PreDecContext(UnaryContext *ctx);

    antlr4::tree::TerminalNode *DEC();
    VariableContext *variable();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PostDecContext : public UnaryContext {
  public:
    PostDecContext(UnaryContext *ctx);

    VariableContext *variable();
    antlr4::tree::TerminalNode *DEC();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PreIncContext : public UnaryContext {
  public:
    PreIncContext(UnaryContext *ctx);

    antlr4::tree::TerminalNode *INC();
    VariableContext *variable();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  UnaryContext* unary();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AssignmentContext() : antlr4::ParserRuleContext() { }
    void copyFrom(AssignmentContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VariableAssignmentContext : public AssignmentContext {
  public:
    VariableAssignmentContext(AssignmentContext *ctx);

    VariableContext *variable();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayAssignmentContext : public AssignmentContext {
  public:
    ArrayAssignmentContext(AssignmentContext *ctx);

    VariableContext *variable();
    antlr4::tree::TerminalNode *ASSIGN();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    NumberContext *number();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AssignmentContext* assignment();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

