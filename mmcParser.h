
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
    T__7 = 8, MUL_DIV_MOD_OP = 9, ADD_SUB_OP = 10, BIT_OP = 11, LOGIC_COMP = 12, 
    MATH_COMP = 13, FOR = 14, IF = 15, ELSE = 16, ELIF = 17, RETURN = 18, 
    IDENTIFIER = 19, INTEGER = 20, ASSIGN = 21, EQ = 22, NEQ = 23, LT = 24, 
    LTE = 25, GT = 26, GTE = 27, L_AND = 28, L_OR = 29, L_NOT = 30, MUL_OP = 31, 
    DIV_OP = 32, MOD_OP = 33, ADD_OP = 34, SUB_OP = 35, AND_OP = 36, OR_OP = 37, 
    XOR_OP = 38, INC = 39, DEC = 40, NEWLINE = 41, WS = 42
  };

  enum {
    RuleRoot = 0, RuleDeclaration = 1, RuleDefinition = 2, RuleFunctionDeclaration = 3, 
    RuleFunctionDefinition = 4, RuleFunctionCall = 5, RuleParameters = 6, 
    RuleIdentifiers = 7, RuleTypeID = 8, RuleFunctionID = 9, RuleFunction = 10, 
    RuleVariableID = 11, RuleVariable = 12, RuleStatement = 13, RuleDeclarationStatement = 14, 
    RuleDefinitionStatement = 15, RuleExpressionStatement = 16, RuleIfStatement = 17, 
    RuleForStatement = 18, RuleUnaryStatement = 19, RuleStatementList = 20, 
    RuleAssignmentStatement = 21, RuleExpression = 22, RuleUnary = 23, RuleAssignment = 24
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
  class FunctionDeclarationContext;
  class FunctionDefinitionContext;
  class FunctionCallContext;
  class ParametersContext;
  class IdentifiersContext;
  class TypeIDContext;
  class FunctionIDContext;
  class FunctionContext;
  class VariableIDContext;
  class VariableContext;
  class StatementContext;
  class DeclarationStatementContext;
  class DefinitionStatementContext;
  class ExpressionStatementContext;
  class IfStatementContext;
  class ForStatementContext;
  class UnaryStatementContext;
  class StatementListContext;
  class AssignmentStatementContext;
  class ExpressionContext;
  class UnaryContext;
  class AssignmentContext; 

  class  RootContext : public antlr4::ParserRuleContext {
  public:
    RootContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FunctionDeclarationContext *> functionDeclaration();
    FunctionDeclarationContext* functionDeclaration(size_t i);
    std::vector<FunctionDefinitionContext *> functionDefinition();
    FunctionDefinitionContext* functionDefinition(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RootContext* root();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeIDContext *typeID();
    VariableIDContext *variableID();
    antlr4::tree::TerminalNode *INTEGER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  DefinitionContext : public antlr4::ParserRuleContext {
  public:
    DefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeIDContext *typeID();
    AssignmentContext *assignment();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefinitionContext* definition();

  class  FunctionDeclarationContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeIDContext *typeID();
    FunctionIDContext *functionID();
    ParametersContext *parameters();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDeclarationContext* functionDeclaration();

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
    VariableIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableIDContext* variableID();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionStatementContext *expressionStatement();
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

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
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
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);
    DefinitionContext *definition();
    ExpressionContext *expression();
    AssignmentContext *assignment();
    UnaryContext *unary();

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
    antlr4::tree::TerminalNode *INTEGER();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MathExprContext : public ExpressionContext {
  public:
    MathExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *MATH_COMP();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberExprContext : public ExpressionContext {
  public:
    NumberExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *INTEGER();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicExprContext : public ExpressionContext {
  public:
    LogicExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *LOGIC_COMP();
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

  class  ParenExprContext : public ExpressionContext {
  public:
    ParenExprContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  UnaryContext : public antlr4::ParserRuleContext {
  public:
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
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *INTEGER();
    IdentifiersContext *identifiers();

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

