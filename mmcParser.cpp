
#include <stdlib.h>
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;
extern string program_name;


// Generated from mmc.g4 by ANTLR 4.7.1


#include "mmcVisitor.h"

#include "mmcParser.h"


using namespace antlrcpp;
using namespace antlr4;

mmcParser::mmcParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

mmcParser::~mmcParser() {
  delete _interpreter;
}

std::string mmcParser::getGrammarFileName() const {
  return "mmc.g4";
}

const std::vector<std::string>& mmcParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& mmcParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- RootContext ------------------------------------------------------------------

mmcParser::RootContext::RootContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mmcParser::StatementListContext* mmcParser::RootContext::statementList() {
  return getRuleContext<mmcParser::StatementListContext>(0);
}

std::vector<mmcParser::FunctionDefinitionContext *> mmcParser::RootContext::functionDefinition() {
  return getRuleContexts<mmcParser::FunctionDefinitionContext>();
}

mmcParser::FunctionDefinitionContext* mmcParser::RootContext::functionDefinition(size_t i) {
  return getRuleContext<mmcParser::FunctionDefinitionContext>(i);
}


size_t mmcParser::RootContext::getRuleIndex() const {
  return mmcParser::RuleRoot;
}

antlrcpp::Any mmcParser::RootContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitRoot(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::RootContext* mmcParser::root() {
  RootContext *_localctx = _tracker.createInstance<RootContext>(_ctx, getState());
  enterRule(_localctx, 0, mmcParser::RuleRoot);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(61); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(60);
        functionDefinition();
        setState(63); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == mmcParser::IDENTIFIER);
      break;
    }

    case 2: {
      setState(65);
      statementList();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

mmcParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t mmcParser::DeclarationContext::getRuleIndex() const {
  return mmcParser::RuleDeclaration;
}

void mmcParser::DeclarationContext::copyFrom(DeclarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayDeclarationContext ------------------------------------------------------------------

mmcParser::TypeIDContext* mmcParser::ArrayDeclarationContext::typeID() {
  return getRuleContext<mmcParser::TypeIDContext>(0);
}

mmcParser::VariableIDContext* mmcParser::ArrayDeclarationContext::variableID() {
  return getRuleContext<mmcParser::VariableIDContext>(0);
}

mmcParser::NumberContext* mmcParser::ArrayDeclarationContext::number() {
  return getRuleContext<mmcParser::NumberContext>(0);
}

mmcParser::ArrayDeclarationContext::ArrayDeclarationContext(DeclarationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::ArrayDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitArrayDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableDeclarationContext ------------------------------------------------------------------

mmcParser::TypeIDContext* mmcParser::VariableDeclarationContext::typeID() {
  return getRuleContext<mmcParser::TypeIDContext>(0);
}

mmcParser::VariableIDContext* mmcParser::VariableDeclarationContext::variableID() {
  return getRuleContext<mmcParser::VariableIDContext>(0);
}

mmcParser::VariableDeclarationContext::VariableDeclarationContext(DeclarationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}
mmcParser::DeclarationContext* mmcParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, mmcParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(77);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<mmcParser::VariableDeclarationContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(68);
      typeID();
      setState(69);
      variableID();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<mmcParser::ArrayDeclarationContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(71);
      typeID();
      setState(72);
      variableID();
      setState(73);
      match(mmcParser::T__0);
      setState(74);
      number();
      setState(75);
      match(mmcParser::T__1);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionContext ------------------------------------------------------------------

mmcParser::DefinitionContext::DefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t mmcParser::DefinitionContext::getRuleIndex() const {
  return mmcParser::RuleDefinition;
}

void mmcParser::DefinitionContext::copyFrom(DefinitionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VariableDefContext ------------------------------------------------------------------

mmcParser::TypeIDContext* mmcParser::VariableDefContext::typeID() {
  return getRuleContext<mmcParser::TypeIDContext>(0);
}

mmcParser::VariableIDContext* mmcParser::VariableDefContext::variableID() {
  return getRuleContext<mmcParser::VariableIDContext>(0);
}

tree::TerminalNode* mmcParser::VariableDefContext::ASSIGN() {
  return getToken(mmcParser::ASSIGN, 0);
}

mmcParser::ExpressionContext* mmcParser::VariableDefContext::expression() {
  return getRuleContext<mmcParser::ExpressionContext>(0);
}

mmcParser::VariableDefContext::VariableDefContext(DefinitionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::VariableDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitVariableDef(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayDefContext ------------------------------------------------------------------

mmcParser::TypeIDContext* mmcParser::ArrayDefContext::typeID() {
  return getRuleContext<mmcParser::TypeIDContext>(0);
}

mmcParser::VariableIDContext* mmcParser::ArrayDefContext::variableID() {
  return getRuleContext<mmcParser::VariableIDContext>(0);
}

mmcParser::NumberContext* mmcParser::ArrayDefContext::number() {
  return getRuleContext<mmcParser::NumberContext>(0);
}

tree::TerminalNode* mmcParser::ArrayDefContext::ASSIGN() {
  return getToken(mmcParser::ASSIGN, 0);
}

mmcParser::IdentifiersContext* mmcParser::ArrayDefContext::identifiers() {
  return getRuleContext<mmcParser::IdentifiersContext>(0);
}

mmcParser::ArrayDefContext::ArrayDefContext(DefinitionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::ArrayDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitArrayDef(this);
  else
    return visitor->visitChildren(this);
}
mmcParser::DefinitionContext* mmcParser::definition() {
  DefinitionContext *_localctx = _tracker.createInstance<DefinitionContext>(_ctx, getState());
  enterRule(_localctx, 4, mmcParser::RuleDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(94);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DefinitionContext *>(_tracker.createInstance<mmcParser::VariableDefContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(79);
      typeID();
      setState(80);
      variableID();
      setState(81);
      match(mmcParser::ASSIGN);
      setState(82);
      expression(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DefinitionContext *>(_tracker.createInstance<mmcParser::ArrayDefContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(84);
      typeID();
      setState(85);
      variableID();
      setState(86);
      match(mmcParser::T__0);
      setState(87);
      number();
      setState(88);
      match(mmcParser::T__1);
      setState(89);
      match(mmcParser::ASSIGN);
      setState(90);
      match(mmcParser::T__2);
      setState(91);
      identifiers();
      setState(92);
      match(mmcParser::T__3);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

mmcParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mmcParser::TypeIDContext* mmcParser::FunctionDefinitionContext::typeID() {
  return getRuleContext<mmcParser::TypeIDContext>(0);
}

mmcParser::FunctionIDContext* mmcParser::FunctionDefinitionContext::functionID() {
  return getRuleContext<mmcParser::FunctionIDContext>(0);
}

mmcParser::ParametersContext* mmcParser::FunctionDefinitionContext::parameters() {
  return getRuleContext<mmcParser::ParametersContext>(0);
}

mmcParser::StatementListContext* mmcParser::FunctionDefinitionContext::statementList() {
  return getRuleContext<mmcParser::StatementListContext>(0);
}

tree::TerminalNode* mmcParser::FunctionDefinitionContext::RETURN() {
  return getToken(mmcParser::RETURN, 0);
}

mmcParser::ExpressionContext* mmcParser::FunctionDefinitionContext::expression() {
  return getRuleContext<mmcParser::ExpressionContext>(0);
}


size_t mmcParser::FunctionDefinitionContext::getRuleIndex() const {
  return mmcParser::RuleFunctionDefinition;
}

antlrcpp::Any mmcParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::FunctionDefinitionContext* mmcParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 6, mmcParser::RuleFunctionDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    typeID();
    setState(97);
    functionID();
    setState(98);
    match(mmcParser::T__4);
    setState(100);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == mmcParser::IDENTIFIER) {
      setState(99);
      parameters();
    }
    setState(102);
    match(mmcParser::T__5);
    setState(103);
    match(mmcParser::T__2);
    setState(105);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << mmcParser::T__4)
      | (1ULL << mmcParser::BOOL)
      | (1ULL << mmcParser::FOR)
      | (1ULL << mmcParser::IF)
      | (1ULL << mmcParser::PRINTF)
      | (1ULL << mmcParser::IDENTIFIER)
      | (1ULL << mmcParser::INTEGER)
      | (1ULL << mmcParser::ADD_OP)
      | (1ULL << mmcParser::SUB_OP)
      | (1ULL << mmcParser::INC)
      | (1ULL << mmcParser::DEC)
      | (1ULL << mmcParser::STRING))) != 0)) {
      setState(104);
      statementList();
    }
    setState(111);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == mmcParser::RETURN) {
      setState(107);
      match(mmcParser::RETURN);
      setState(108);
      expression(0);
      setState(109);
      match(mmcParser::T__6);
    }
    setState(113);
    match(mmcParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

mmcParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mmcParser::FunctionContext* mmcParser::FunctionCallContext::function() {
  return getRuleContext<mmcParser::FunctionContext>(0);
}

mmcParser::IdentifiersContext* mmcParser::FunctionCallContext::identifiers() {
  return getRuleContext<mmcParser::IdentifiersContext>(0);
}


size_t mmcParser::FunctionCallContext::getRuleIndex() const {
  return mmcParser::RuleFunctionCall;
}

antlrcpp::Any mmcParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::FunctionCallContext* mmcParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 8, mmcParser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    function();
    setState(116);
    match(mmcParser::T__4);
    setState(118);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << mmcParser::T__4)
      | (1ULL << mmcParser::BOOL)
      | (1ULL << mmcParser::IDENTIFIER)
      | (1ULL << mmcParser::INTEGER)
      | (1ULL << mmcParser::ADD_OP)
      | (1ULL << mmcParser::SUB_OP)
      | (1ULL << mmcParser::INC)
      | (1ULL << mmcParser::DEC)
      | (1ULL << mmcParser::STRING))) != 0)) {
      setState(117);
      identifiers();
    }
    setState(120);
    match(mmcParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

mmcParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<mmcParser::DeclarationContext *> mmcParser::ParametersContext::declaration() {
  return getRuleContexts<mmcParser::DeclarationContext>();
}

mmcParser::DeclarationContext* mmcParser::ParametersContext::declaration(size_t i) {
  return getRuleContext<mmcParser::DeclarationContext>(i);
}


size_t mmcParser::ParametersContext::getRuleIndex() const {
  return mmcParser::RuleParameters;
}

antlrcpp::Any mmcParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::ParametersContext* mmcParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 10, mmcParser::RuleParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    declaration();
    setState(127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == mmcParser::T__7) {
      setState(123);
      match(mmcParser::T__7);
      setState(124);
      declaration();
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifiersContext ------------------------------------------------------------------

mmcParser::IdentifiersContext::IdentifiersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<mmcParser::ExpressionContext *> mmcParser::IdentifiersContext::expression() {
  return getRuleContexts<mmcParser::ExpressionContext>();
}

mmcParser::ExpressionContext* mmcParser::IdentifiersContext::expression(size_t i) {
  return getRuleContext<mmcParser::ExpressionContext>(i);
}


size_t mmcParser::IdentifiersContext::getRuleIndex() const {
  return mmcParser::RuleIdentifiers;
}

antlrcpp::Any mmcParser::IdentifiersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitIdentifiers(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::IdentifiersContext* mmcParser::identifiers() {
  IdentifiersContext *_localctx = _tracker.createInstance<IdentifiersContext>(_ctx, getState());
  enterRule(_localctx, 12, mmcParser::RuleIdentifiers);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    expression(0);
    setState(133); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(131);
      match(mmcParser::T__7);
      setState(132);
      expression(0);
      setState(135); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == mmcParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeIDContext ------------------------------------------------------------------

mmcParser::TypeIDContext::TypeIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mmcParser::TypeIDContext::IDENTIFIER() {
  return getToken(mmcParser::IDENTIFIER, 0);
}


size_t mmcParser::TypeIDContext::getRuleIndex() const {
  return mmcParser::RuleTypeID;
}

antlrcpp::Any mmcParser::TypeIDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitTypeID(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::TypeIDContext* mmcParser::typeID() {
  TypeIDContext *_localctx = _tracker.createInstance<TypeIDContext>(_ctx, getState());
  enterRule(_localctx, 14, mmcParser::RuleTypeID);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(mmcParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionIDContext ------------------------------------------------------------------

mmcParser::FunctionIDContext::FunctionIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mmcParser::FunctionIDContext::IDENTIFIER() {
  return getToken(mmcParser::IDENTIFIER, 0);
}


size_t mmcParser::FunctionIDContext::getRuleIndex() const {
  return mmcParser::RuleFunctionID;
}

antlrcpp::Any mmcParser::FunctionIDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitFunctionID(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::FunctionIDContext* mmcParser::functionID() {
  FunctionIDContext *_localctx = _tracker.createInstance<FunctionIDContext>(_ctx, getState());
  enterRule(_localctx, 16, mmcParser::RuleFunctionID);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(mmcParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

mmcParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mmcParser::FunctionContext::IDENTIFIER() {
  return getToken(mmcParser::IDENTIFIER, 0);
}


size_t mmcParser::FunctionContext::getRuleIndex() const {
  return mmcParser::RuleFunction;
}

antlrcpp::Any mmcParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::FunctionContext* mmcParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 18, mmcParser::RuleFunction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    match(mmcParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableIDContext ------------------------------------------------------------------

mmcParser::VariableIDContext::VariableIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mmcParser::VariableIDContext::IDENTIFIER() {
  return getToken(mmcParser::IDENTIFIER, 0);
}


size_t mmcParser::VariableIDContext::getRuleIndex() const {
  return mmcParser::RuleVariableID;
}

antlrcpp::Any mmcParser::VariableIDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitVariableID(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::VariableIDContext* mmcParser::variableID() {
  VariableIDContext *_localctx = _tracker.createInstance<VariableIDContext>(_ctx, getState());
  enterRule(_localctx, 20, mmcParser::RuleVariableID);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    match(mmcParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

mmcParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mmcParser::VariableContext::IDENTIFIER() {
  return getToken(mmcParser::IDENTIFIER, 0);
}


size_t mmcParser::VariableContext::getRuleIndex() const {
  return mmcParser::RuleVariable;
}

antlrcpp::Any mmcParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::VariableContext* mmcParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 22, mmcParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    match(mmcParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

mmcParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mmcParser::NumberContext::INTEGER() {
  return getToken(mmcParser::INTEGER, 0);
}


size_t mmcParser::NumberContext::getRuleIndex() const {
  return mmcParser::RuleNumber;
}

antlrcpp::Any mmcParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::NumberContext* mmcParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 24, mmcParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    match(mmcParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StrContext ------------------------------------------------------------------

mmcParser::StrContext::StrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mmcParser::StrContext::STRING() {
  return getToken(mmcParser::STRING, 0);
}


size_t mmcParser::StrContext::getRuleIndex() const {
  return mmcParser::RuleStr;
}

antlrcpp::Any mmcParser::StrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitStr(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::StrContext* mmcParser::str() {
  StrContext *_localctx = _tracker.createInstance<StrContext>(_ctx, getState());
  enterRule(_localctx, 26, mmcParser::RuleStr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    match(mmcParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignedNumberContext ------------------------------------------------------------------

mmcParser::SignedNumberContext::SignedNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mmcParser::SignContext* mmcParser::SignedNumberContext::sign() {
  return getRuleContext<mmcParser::SignContext>(0);
}

mmcParser::NumberContext* mmcParser::SignedNumberContext::number() {
  return getRuleContext<mmcParser::NumberContext>(0);
}


size_t mmcParser::SignedNumberContext::getRuleIndex() const {
  return mmcParser::RuleSignedNumber;
}

antlrcpp::Any mmcParser::SignedNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitSignedNumber(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::SignedNumberContext* mmcParser::signedNumber() {
  SignedNumberContext *_localctx = _tracker.createInstance<SignedNumberContext>(_ctx, getState());
  enterRule(_localctx, 28, mmcParser::RuleSignedNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    sign();
    setState(152);
    number();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignContext ------------------------------------------------------------------

mmcParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mmcParser::SignContext::ADD_OP() {
  return getToken(mmcParser::ADD_OP, 0);
}

tree::TerminalNode* mmcParser::SignContext::SUB_OP() {
  return getToken(mmcParser::SUB_OP, 0);
}


size_t mmcParser::SignContext::getRuleIndex() const {
  return mmcParser::RuleSign;
}

antlrcpp::Any mmcParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::SignContext* mmcParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 30, mmcParser::RuleSign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    _la = _input->LA(1);
    if (!(_la == mmcParser::ADD_OP

    || _la == mmcParser::SUB_OP)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

mmcParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mmcParser::ExpressionStatementContext* mmcParser::StatementContext::expressionStatement() {
  return getRuleContext<mmcParser::ExpressionStatementContext>(0);
}

mmcParser::PrintfStatementContext* mmcParser::StatementContext::printfStatement() {
  return getRuleContext<mmcParser::PrintfStatementContext>(0);
}

mmcParser::UnaryStatementContext* mmcParser::StatementContext::unaryStatement() {
  return getRuleContext<mmcParser::UnaryStatementContext>(0);
}

mmcParser::ForStatementContext* mmcParser::StatementContext::forStatement() {
  return getRuleContext<mmcParser::ForStatementContext>(0);
}

mmcParser::IfStatementContext* mmcParser::StatementContext::ifStatement() {
  return getRuleContext<mmcParser::IfStatementContext>(0);
}

mmcParser::AssignmentStatementContext* mmcParser::StatementContext::assignmentStatement() {
  return getRuleContext<mmcParser::AssignmentStatementContext>(0);
}

mmcParser::DeclarationStatementContext* mmcParser::StatementContext::declarationStatement() {
  return getRuleContext<mmcParser::DeclarationStatementContext>(0);
}

mmcParser::DefinitionStatementContext* mmcParser::StatementContext::definitionStatement() {
  return getRuleContext<mmcParser::DefinitionStatementContext>(0);
}


size_t mmcParser::StatementContext::getRuleIndex() const {
  return mmcParser::RuleStatement;
}

antlrcpp::Any mmcParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::StatementContext* mmcParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 32, mmcParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(164);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(156);
      expressionStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(157);
      printfStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(158);
      unaryStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(159);
      forStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(160);
      ifStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(161);
      assignmentStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(162);
      declarationStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(163);
      definitionStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationStatementContext ------------------------------------------------------------------

mmcParser::DeclarationStatementContext::DeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mmcParser::DeclarationContext* mmcParser::DeclarationStatementContext::declaration() {
  return getRuleContext<mmcParser::DeclarationContext>(0);
}


size_t mmcParser::DeclarationStatementContext::getRuleIndex() const {
  return mmcParser::RuleDeclarationStatement;
}

antlrcpp::Any mmcParser::DeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::DeclarationStatementContext* mmcParser::declarationStatement() {
  DeclarationStatementContext *_localctx = _tracker.createInstance<DeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, mmcParser::RuleDeclarationStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    declaration();
    setState(167);
    match(mmcParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionStatementContext ------------------------------------------------------------------

mmcParser::DefinitionStatementContext::DefinitionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mmcParser::DefinitionContext* mmcParser::DefinitionStatementContext::definition() {
  return getRuleContext<mmcParser::DefinitionContext>(0);
}


size_t mmcParser::DefinitionStatementContext::getRuleIndex() const {
  return mmcParser::RuleDefinitionStatement;
}

antlrcpp::Any mmcParser::DefinitionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitDefinitionStatement(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::DefinitionStatementContext* mmcParser::definitionStatement() {
  DefinitionStatementContext *_localctx = _tracker.createInstance<DefinitionStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, mmcParser::RuleDefinitionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    definition();
    setState(170);
    match(mmcParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

mmcParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mmcParser::ExpressionContext* mmcParser::ExpressionStatementContext::expression() {
  return getRuleContext<mmcParser::ExpressionContext>(0);
}


size_t mmcParser::ExpressionStatementContext::getRuleIndex() const {
  return mmcParser::RuleExpressionStatement;
}

antlrcpp::Any mmcParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::ExpressionStatementContext* mmcParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, mmcParser::RuleExpressionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    expression(0);
    setState(173);
    match(mmcParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintfStatementContext ------------------------------------------------------------------

mmcParser::PrintfStatementContext::PrintfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mmcParser::PrintfStatementContext::PRINTF() {
  return getToken(mmcParser::PRINTF, 0);
}

mmcParser::StrContext* mmcParser::PrintfStatementContext::str() {
  return getRuleContext<mmcParser::StrContext>(0);
}

mmcParser::IdentifiersContext* mmcParser::PrintfStatementContext::identifiers() {
  return getRuleContext<mmcParser::IdentifiersContext>(0);
}


size_t mmcParser::PrintfStatementContext::getRuleIndex() const {
  return mmcParser::RulePrintfStatement;
}

antlrcpp::Any mmcParser::PrintfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitPrintfStatement(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::PrintfStatementContext* mmcParser::printfStatement() {
  PrintfStatementContext *_localctx = _tracker.createInstance<PrintfStatementContext>(_ctx, getState());
  enterRule(_localctx, 40, mmcParser::RulePrintfStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(mmcParser::PRINTF);
    setState(176);
    match(mmcParser::T__4);
    setState(177);
    str();
    setState(180);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == mmcParser::T__7) {
      setState(178);
      match(mmcParser::T__7);
      setState(179);
      identifiers();
    }
    setState(182);
    match(mmcParser::T__5);
    setState(183);
    match(mmcParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

mmcParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mmcParser::IfStatementContext::IF() {
  return getToken(mmcParser::IF, 0);
}

std::vector<mmcParser::MathExprContext *> mmcParser::IfStatementContext::mathExpr() {
  return getRuleContexts<mmcParser::MathExprContext>();
}

mmcParser::MathExprContext* mmcParser::IfStatementContext::mathExpr(size_t i) {
  return getRuleContext<mmcParser::MathExprContext>(i);
}

std::vector<mmcParser::StatementListContext *> mmcParser::IfStatementContext::statementList() {
  return getRuleContexts<mmcParser::StatementListContext>();
}

mmcParser::StatementListContext* mmcParser::IfStatementContext::statementList(size_t i) {
  return getRuleContext<mmcParser::StatementListContext>(i);
}

std::vector<tree::TerminalNode *> mmcParser::IfStatementContext::ELIF() {
  return getTokens(mmcParser::ELIF);
}

tree::TerminalNode* mmcParser::IfStatementContext::ELIF(size_t i) {
  return getToken(mmcParser::ELIF, i);
}

tree::TerminalNode* mmcParser::IfStatementContext::ELSE() {
  return getToken(mmcParser::ELSE, 0);
}


size_t mmcParser::IfStatementContext::getRuleIndex() const {
  return mmcParser::RuleIfStatement;
}

antlrcpp::Any mmcParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::IfStatementContext* mmcParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 42, mmcParser::RuleIfStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    match(mmcParser::IF);
    setState(186);
    match(mmcParser::T__4);
    setState(187);
    mathExpr();
    setState(188);
    match(mmcParser::T__5);
    setState(189);
    match(mmcParser::T__2);
    setState(191);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << mmcParser::T__4)
      | (1ULL << mmcParser::BOOL)
      | (1ULL << mmcParser::FOR)
      | (1ULL << mmcParser::IF)
      | (1ULL << mmcParser::PRINTF)
      | (1ULL << mmcParser::IDENTIFIER)
      | (1ULL << mmcParser::INTEGER)
      | (1ULL << mmcParser::ADD_OP)
      | (1ULL << mmcParser::SUB_OP)
      | (1ULL << mmcParser::INC)
      | (1ULL << mmcParser::DEC)
      | (1ULL << mmcParser::STRING))) != 0)) {
      setState(190);
      statementList();
    }
    setState(193);
    match(mmcParser::T__3);
    setState(206);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == mmcParser::ELIF) {
      setState(194);
      match(mmcParser::ELIF);
      setState(195);
      match(mmcParser::T__4);
      setState(196);
      mathExpr();
      setState(197);
      match(mmcParser::T__5);
      setState(198);
      match(mmcParser::T__2);
      setState(200);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << mmcParser::T__4)
        | (1ULL << mmcParser::BOOL)
        | (1ULL << mmcParser::FOR)
        | (1ULL << mmcParser::IF)
        | (1ULL << mmcParser::PRINTF)
        | (1ULL << mmcParser::IDENTIFIER)
        | (1ULL << mmcParser::INTEGER)
        | (1ULL << mmcParser::ADD_OP)
        | (1ULL << mmcParser::SUB_OP)
        | (1ULL << mmcParser::INC)
        | (1ULL << mmcParser::DEC)
        | (1ULL << mmcParser::STRING))) != 0)) {
        setState(199);
        statementList();
      }
      setState(202);
      match(mmcParser::T__3);
      setState(208);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(215);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == mmcParser::ELSE) {
      setState(209);
      match(mmcParser::ELSE);
      setState(210);
      match(mmcParser::T__2);
      setState(212);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << mmcParser::T__4)
        | (1ULL << mmcParser::BOOL)
        | (1ULL << mmcParser::FOR)
        | (1ULL << mmcParser::IF)
        | (1ULL << mmcParser::PRINTF)
        | (1ULL << mmcParser::IDENTIFIER)
        | (1ULL << mmcParser::INTEGER)
        | (1ULL << mmcParser::ADD_OP)
        | (1ULL << mmcParser::SUB_OP)
        | (1ULL << mmcParser::INC)
        | (1ULL << mmcParser::DEC)
        | (1ULL << mmcParser::STRING))) != 0)) {
        setState(211);
        statementList();
      }
      setState(214);
      match(mmcParser::T__3);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

mmcParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* mmcParser::ForStatementContext::FOR() {
  return getToken(mmcParser::FOR, 0);
}

mmcParser::StatementListContext* mmcParser::ForStatementContext::statementList() {
  return getRuleContext<mmcParser::StatementListContext>(0);
}

mmcParser::VariableContext* mmcParser::ForStatementContext::variable() {
  return getRuleContext<mmcParser::VariableContext>(0);
}

mmcParser::MathExprContext* mmcParser::ForStatementContext::mathExpr() {
  return getRuleContext<mmcParser::MathExprContext>(0);
}

std::vector<mmcParser::DeclarationContext *> mmcParser::ForStatementContext::declaration() {
  return getRuleContexts<mmcParser::DeclarationContext>();
}

mmcParser::DeclarationContext* mmcParser::ForStatementContext::declaration(size_t i) {
  return getRuleContext<mmcParser::DeclarationContext>(i);
}

mmcParser::DefinitionContext* mmcParser::ForStatementContext::definition() {
  return getRuleContext<mmcParser::DefinitionContext>(0);
}

std::vector<mmcParser::AssignmentContext *> mmcParser::ForStatementContext::assignment() {
  return getRuleContexts<mmcParser::AssignmentContext>();
}

mmcParser::AssignmentContext* mmcParser::ForStatementContext::assignment(size_t i) {
  return getRuleContext<mmcParser::AssignmentContext>(i);
}

mmcParser::ExpressionContext* mmcParser::ForStatementContext::expression() {
  return getRuleContext<mmcParser::ExpressionContext>(0);
}


size_t mmcParser::ForStatementContext::getRuleIndex() const {
  return mmcParser::RuleForStatement;
}

antlrcpp::Any mmcParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::ForStatementContext* mmcParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 44, mmcParser::RuleForStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    match(mmcParser::FOR);
    setState(218);
    match(mmcParser::T__4);
    setState(240);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(220);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == mmcParser::IDENTIFIER) {
        setState(219);
        declaration();
      }
      setState(222);
      match(mmcParser::T__6);
      setState(224);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == mmcParser::IDENTIFIER) {
        setState(223);
        declaration();
      }
      setState(226);
      match(mmcParser::T__8);
      setState(227);
      variable();
      break;
    }

    case 2: {
      setState(231);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
      case 1: {
        setState(228);
        declaration();
        break;
      }

      case 2: {
        setState(229);
        definition();
        break;
      }

      case 3: {
        setState(230);
        assignment();
        break;
      }

      }
      setState(233);
      match(mmcParser::T__6);
      setState(234);
      mathExpr();
      setState(235);
      match(mmcParser::T__6);
      setState(238);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
      case 1: {
        setState(236);
        assignment();
        break;
      }

      case 2: {
        setState(237);
        expression(0);
        break;
      }

      }
      break;
    }

    }
    setState(242);
    match(mmcParser::T__5);
    setState(243);
    match(mmcParser::T__2);
    setState(245);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << mmcParser::T__4)
      | (1ULL << mmcParser::BOOL)
      | (1ULL << mmcParser::FOR)
      | (1ULL << mmcParser::IF)
      | (1ULL << mmcParser::PRINTF)
      | (1ULL << mmcParser::IDENTIFIER)
      | (1ULL << mmcParser::INTEGER)
      | (1ULL << mmcParser::ADD_OP)
      | (1ULL << mmcParser::SUB_OP)
      | (1ULL << mmcParser::INC)
      | (1ULL << mmcParser::DEC)
      | (1ULL << mmcParser::STRING))) != 0)) {
      setState(244);
      statementList();
    }
    setState(247);
    match(mmcParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryStatementContext ------------------------------------------------------------------

mmcParser::UnaryStatementContext::UnaryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mmcParser::UnaryContext* mmcParser::UnaryStatementContext::unary() {
  return getRuleContext<mmcParser::UnaryContext>(0);
}


size_t mmcParser::UnaryStatementContext::getRuleIndex() const {
  return mmcParser::RuleUnaryStatement;
}

antlrcpp::Any mmcParser::UnaryStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitUnaryStatement(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::UnaryStatementContext* mmcParser::unaryStatement() {
  UnaryStatementContext *_localctx = _tracker.createInstance<UnaryStatementContext>(_ctx, getState());
  enterRule(_localctx, 46, mmcParser::RuleUnaryStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    unary();
    setState(250);
    match(mmcParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

mmcParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<mmcParser::StatementContext *> mmcParser::StatementListContext::statement() {
  return getRuleContexts<mmcParser::StatementContext>();
}

mmcParser::StatementContext* mmcParser::StatementListContext::statement(size_t i) {
  return getRuleContext<mmcParser::StatementContext>(i);
}


size_t mmcParser::StatementListContext::getRuleIndex() const {
  return mmcParser::RuleStatementList;
}

antlrcpp::Any mmcParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::StatementListContext* mmcParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 48, mmcParser::RuleStatementList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    statement();
    setState(256);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << mmcParser::T__4)
      | (1ULL << mmcParser::BOOL)
      | (1ULL << mmcParser::FOR)
      | (1ULL << mmcParser::IF)
      | (1ULL << mmcParser::PRINTF)
      | (1ULL << mmcParser::IDENTIFIER)
      | (1ULL << mmcParser::INTEGER)
      | (1ULL << mmcParser::ADD_OP)
      | (1ULL << mmcParser::SUB_OP)
      | (1ULL << mmcParser::INC)
      | (1ULL << mmcParser::DEC)
      | (1ULL << mmcParser::STRING))) != 0)) {
      setState(253);
      statement();
      setState(258);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

mmcParser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

mmcParser::AssignmentContext* mmcParser::AssignmentStatementContext::assignment() {
  return getRuleContext<mmcParser::AssignmentContext>(0);
}


size_t mmcParser::AssignmentStatementContext::getRuleIndex() const {
  return mmcParser::RuleAssignmentStatement;
}

antlrcpp::Any mmcParser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::AssignmentStatementContext* mmcParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 50, mmcParser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    assignment();
    setState(260);
    match(mmcParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

mmcParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t mmcParser::ExpressionContext::getRuleIndex() const {
  return mmcParser::RuleExpression;
}

void mmcParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- StringExprContext ------------------------------------------------------------------

mmcParser::StrContext* mmcParser::StringExprContext::str() {
  return getRuleContext<mmcParser::StrContext>(0);
}

mmcParser::StringExprContext::StringExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::StringExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitStringExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableExprContext ------------------------------------------------------------------

mmcParser::VariableContext* mmcParser::VariableExprContext::variable() {
  return getRuleContext<mmcParser::VariableContext>(0);
}

mmcParser::VariableExprContext::VariableExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::VariableExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitVariableExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitExprContext ------------------------------------------------------------------

std::vector<mmcParser::ExpressionContext *> mmcParser::BitExprContext::expression() {
  return getRuleContexts<mmcParser::ExpressionContext>();
}

mmcParser::ExpressionContext* mmcParser::BitExprContext::expression(size_t i) {
  return getRuleContext<mmcParser::ExpressionContext>(i);
}

tree::TerminalNode* mmcParser::BitExprContext::BIT_OP() {
  return getToken(mmcParser::BIT_OP, 0);
}

mmcParser::BitExprContext::BitExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::BitExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitBitExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExprContext ------------------------------------------------------------------

mmcParser::UnaryContext* mmcParser::UnaryExprContext::unary() {
  return getRuleContext<mmcParser::UnaryContext>(0);
}

mmcParser::UnaryExprContext::UnaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubExprContext ------------------------------------------------------------------

std::vector<mmcParser::ExpressionContext *> mmcParser::AddSubExprContext::expression() {
  return getRuleContexts<mmcParser::ExpressionContext>();
}

mmcParser::ExpressionContext* mmcParser::AddSubExprContext::expression(size_t i) {
  return getRuleContext<mmcParser::ExpressionContext>(i);
}

tree::TerminalNode* mmcParser::AddSubExprContext::ADD_SUB_OP() {
  return getToken(mmcParser::ADD_SUB_OP, 0);
}

mmcParser::AddSubExprContext::AddSubExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::AddSubExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitAddSubExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayExprContext ------------------------------------------------------------------

mmcParser::VariableContext* mmcParser::ArrayExprContext::variable() {
  return getRuleContext<mmcParser::VariableContext>(0);
}

mmcParser::NumberContext* mmcParser::ArrayExprContext::number() {
  return getRuleContext<mmcParser::NumberContext>(0);
}

mmcParser::ArrayExprContext::ArrayExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::ArrayExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitArrayExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivModExprContext ------------------------------------------------------------------

std::vector<mmcParser::ExpressionContext *> mmcParser::MulDivModExprContext::expression() {
  return getRuleContexts<mmcParser::ExpressionContext>();
}

mmcParser::ExpressionContext* mmcParser::MulDivModExprContext::expression(size_t i) {
  return getRuleContext<mmcParser::ExpressionContext>(i);
}

tree::TerminalNode* mmcParser::MulDivModExprContext::MUL_DIV_MOD_OP() {
  return getToken(mmcParser::MUL_DIV_MOD_OP, 0);
}

mmcParser::MulDivModExprContext::MulDivModExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::MulDivModExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitMulDivModExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncCallExprContext ------------------------------------------------------------------

mmcParser::FunctionCallContext* mmcParser::FuncCallExprContext::functionCall() {
  return getRuleContext<mmcParser::FunctionCallContext>(0);
}

mmcParser::FuncCallExprContext::FuncCallExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::FuncCallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitFuncCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolExprContext ------------------------------------------------------------------

tree::TerminalNode* mmcParser::BoolExprContext::BOOL() {
  return getToken(mmcParser::BOOL, 0);
}

mmcParser::BoolExprContext::BoolExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::BoolExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitBoolExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnsignedNumberExprContext ------------------------------------------------------------------

mmcParser::NumberContext* mmcParser::UnsignedNumberExprContext::number() {
  return getRuleContext<mmcParser::NumberContext>(0);
}

mmcParser::UnsignedNumberExprContext::UnsignedNumberExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::UnsignedNumberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitUnsignedNumberExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

mmcParser::ExpressionContext* mmcParser::ParenExprContext::expression() {
  return getRuleContext<mmcParser::ExpressionContext>(0);
}

mmcParser::ParenExprContext::ParenExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SignedNumberExprContext ------------------------------------------------------------------

mmcParser::SignedNumberContext* mmcParser::SignedNumberExprContext::signedNumber() {
  return getRuleContext<mmcParser::SignedNumberContext>(0);
}

mmcParser::SignedNumberExprContext::SignedNumberExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::SignedNumberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitSignedNumberExpr(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::ExpressionContext* mmcParser::expression() {
   return expression(0);
}

mmcParser::ExpressionContext* mmcParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  mmcParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  mmcParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, mmcParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(279);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ArrayExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(263);
      variable();
      setState(264);
      match(mmcParser::T__0);
      setState(265);
      number();
      setState(266);
      match(mmcParser::T__1);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<BoolExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(268);
      match(mmcParser::BOOL);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<StringExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(269);
      str();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<SignedNumberExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(270);
      signedNumber();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<UnsignedNumberExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(271);
      number();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(272);
      unary();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<VariableExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(273);
      variable();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(274);
      match(mmcParser::T__4);
      setState(275);
      expression(0);
      setState(276);
      match(mmcParser::T__5);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<FuncCallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(278);
      functionCall();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(292);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(290);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivModExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(281);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(282);
          match(mmcParser::MUL_DIV_MOD_OP);
          setState(283);
          expression(13);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(284);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(285);
          match(mmcParser::ADD_SUB_OP);
          setState(286);
          expression(12);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(287);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(288);
          match(mmcParser::BIT_OP);
          setState(289);
          expression(11);
          break;
        }

        } 
      }
      setState(294);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MathExprContext ------------------------------------------------------------------

mmcParser::MathExprContext::MathExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<mmcParser::ExpressionContext *> mmcParser::MathExprContext::expression() {
  return getRuleContexts<mmcParser::ExpressionContext>();
}

mmcParser::ExpressionContext* mmcParser::MathExprContext::expression(size_t i) {
  return getRuleContext<mmcParser::ExpressionContext>(i);
}

tree::TerminalNode* mmcParser::MathExprContext::MATH_COMP() {
  return getToken(mmcParser::MATH_COMP, 0);
}


size_t mmcParser::MathExprContext::getRuleIndex() const {
  return mmcParser::RuleMathExpr;
}

antlrcpp::Any mmcParser::MathExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitMathExpr(this);
  else
    return visitor->visitChildren(this);
}

mmcParser::MathExprContext* mmcParser::mathExpr() {
  MathExprContext *_localctx = _tracker.createInstance<MathExprContext>(_ctx, getState());
  enterRule(_localctx, 54, mmcParser::RuleMathExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    expression(0);
    setState(296);
    match(mmcParser::MATH_COMP);
    setState(297);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryContext ------------------------------------------------------------------

mmcParser::UnaryContext::UnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t mmcParser::UnaryContext::getRuleIndex() const {
  return mmcParser::RuleUnary;
}

void mmcParser::UnaryContext::copyFrom(UnaryContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- PostIncContext ------------------------------------------------------------------

mmcParser::VariableContext* mmcParser::PostIncContext::variable() {
  return getRuleContext<mmcParser::VariableContext>(0);
}

tree::TerminalNode* mmcParser::PostIncContext::INC() {
  return getToken(mmcParser::INC, 0);
}

mmcParser::PostIncContext::PostIncContext(UnaryContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::PostIncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitPostInc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PreDecContext ------------------------------------------------------------------

tree::TerminalNode* mmcParser::PreDecContext::DEC() {
  return getToken(mmcParser::DEC, 0);
}

mmcParser::VariableContext* mmcParser::PreDecContext::variable() {
  return getRuleContext<mmcParser::VariableContext>(0);
}

mmcParser::PreDecContext::PreDecContext(UnaryContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::PreDecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitPreDec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostDecContext ------------------------------------------------------------------

mmcParser::VariableContext* mmcParser::PostDecContext::variable() {
  return getRuleContext<mmcParser::VariableContext>(0);
}

tree::TerminalNode* mmcParser::PostDecContext::DEC() {
  return getToken(mmcParser::DEC, 0);
}

mmcParser::PostDecContext::PostDecContext(UnaryContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::PostDecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitPostDec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PreIncContext ------------------------------------------------------------------

tree::TerminalNode* mmcParser::PreIncContext::INC() {
  return getToken(mmcParser::INC, 0);
}

mmcParser::VariableContext* mmcParser::PreIncContext::variable() {
  return getRuleContext<mmcParser::VariableContext>(0);
}

mmcParser::PreIncContext::PreIncContext(UnaryContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::PreIncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitPreInc(this);
  else
    return visitor->visitChildren(this);
}
mmcParser::UnaryContext* mmcParser::unary() {
  UnaryContext *_localctx = _tracker.createInstance<UnaryContext>(_ctx, getState());
  enterRule(_localctx, 56, mmcParser::RuleUnary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(309);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<mmcParser::PreIncContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(299);
      match(mmcParser::INC);
      setState(300);
      variable();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<mmcParser::PreDecContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(301);
      match(mmcParser::DEC);
      setState(302);
      variable();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<mmcParser::PostIncContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(303);
      variable();
      setState(304);
      match(mmcParser::INC);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<UnaryContext *>(_tracker.createInstance<mmcParser::PostDecContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(306);
      variable();
      setState(307);
      match(mmcParser::DEC);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

mmcParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t mmcParser::AssignmentContext::getRuleIndex() const {
  return mmcParser::RuleAssignment;
}

void mmcParser::AssignmentContext::copyFrom(AssignmentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VariableAssignmentContext ------------------------------------------------------------------

mmcParser::VariableContext* mmcParser::VariableAssignmentContext::variable() {
  return getRuleContext<mmcParser::VariableContext>(0);
}

tree::TerminalNode* mmcParser::VariableAssignmentContext::ASSIGN() {
  return getToken(mmcParser::ASSIGN, 0);
}

mmcParser::ExpressionContext* mmcParser::VariableAssignmentContext::expression() {
  return getRuleContext<mmcParser::ExpressionContext>(0);
}

mmcParser::VariableAssignmentContext::VariableAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::VariableAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitVariableAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayAssignmentContext ------------------------------------------------------------------

mmcParser::VariableContext* mmcParser::ArrayAssignmentContext::variable() {
  return getRuleContext<mmcParser::VariableContext>(0);
}

tree::TerminalNode* mmcParser::ArrayAssignmentContext::ASSIGN() {
  return getToken(mmcParser::ASSIGN, 0);
}

std::vector<mmcParser::ExpressionContext *> mmcParser::ArrayAssignmentContext::expression() {
  return getRuleContexts<mmcParser::ExpressionContext>();
}

mmcParser::ExpressionContext* mmcParser::ArrayAssignmentContext::expression(size_t i) {
  return getRuleContext<mmcParser::ExpressionContext>(i);
}

mmcParser::NumberContext* mmcParser::ArrayAssignmentContext::number() {
  return getRuleContext<mmcParser::NumberContext>(0);
}

mmcParser::ArrayAssignmentContext::ArrayAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }

antlrcpp::Any mmcParser::ArrayAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<mmcVisitor*>(visitor))
    return parserVisitor->visitArrayAssignment(this);
  else
    return visitor->visitChildren(this);
}
mmcParser::AssignmentContext* mmcParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 58, mmcParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(325);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<AssignmentContext *>(_tracker.createInstance<mmcParser::VariableAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(311);
      variable();
      setState(312);
      match(mmcParser::ASSIGN);
      setState(313);
      expression(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<AssignmentContext *>(_tracker.createInstance<mmcParser::ArrayAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(315);
      variable();
      setState(316);
      match(mmcParser::T__0);
      setState(319);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
      case 1: {
        setState(317);
        number();
        break;
      }

      case 2: {
        setState(318);
        expression(0);
        break;
      }

      }
      setState(321);
      match(mmcParser::T__1);
      setState(322);
      match(mmcParser::ASSIGN);
      setState(323);
      expression(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool mmcParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 26: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool mmcParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 12);
    case 1: return precpred(_ctx, 11);
    case 2: return precpred(_ctx, 10);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> mmcParser::_decisionToDFA;
atn::PredictionContextCache mmcParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN mmcParser::_atn;
std::vector<uint16_t> mmcParser::_serializedATN;

std::vector<std::string> mmcParser::_ruleNames = {
  "root", "declaration", "definition", "functionDefinition", "functionCall", 
  "parameters", "identifiers", "typeID", "functionID", "function", "variableID", 
  "variable", "number", "str", "signedNumber", "sign", "statement", "declarationStatement", 
  "definitionStatement", "expressionStatement", "printfStatement", "ifStatement", 
  "forStatement", "unaryStatement", "statementList", "assignmentStatement", 
  "expression", "mathExpr", "unary", "assignment"
};

std::vector<std::string> mmcParser::_literalNames = {
  "", "'['", "']'", "'{'", "'}'", "'('", "')'", "';'", "','", "':'", "", 
  "", "", "", "", "'for'", "'if'", "'else'", "'elif'", "'return'", "'true'", 
  "'false'", "'printf'", "", "", "'='", "'=='", "'!='", "'<'", "'<='", "'>'", 
  "'>='", "'*'", "'/'", "'%'", "'+'", "'-'", "'&'", "'|'", "'^'", "'++'", 
  "'--'"
};

std::vector<std::string> mmcParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "BOOL", "MUL_DIV_MOD_OP", "ADD_SUB_OP", 
  "BIT_OP", "MATH_COMP", "FOR", "IF", "ELSE", "ELIF", "RETURN", "TRUE", 
  "FALSE", "PRINTF", "IDENTIFIER", "INTEGER", "ASSIGN", "EQ", "NEQ", "LT", 
  "LTE", "GT", "GTE", "MUL_OP", "DIV_OP", "MOD_OP", "ADD_OP", "SUB_OP", 
  "AND_OP", "OR_OP", "XOR_OP", "INC", "DEC", "STRING", "NEWLINE", "WS"
};

dfa::Vocabulary mmcParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> mmcParser::_tokenNames;

mmcParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2e, 0x14a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x3, 0x2, 0x6, 0x2, 0x40, 0xa, 0x2, 0xd, 0x2, 0xe, 
    0x2, 0x41, 0x3, 0x2, 0x5, 0x2, 0x45, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x50, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x61, 0xa, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x67, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x6c, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0x72, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0x79, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x7, 0x7, 0x80, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x83, 0xb, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x6, 0x8, 0x88, 0xa, 0x8, 0xd, 0x8, 
    0xe, 0x8, 0x89, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x5, 0x12, 0xa7, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xb7, 
    0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0xc2, 0xa, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x5, 0x17, 0xcb, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0xcf, 0xa, 
    0x17, 0xc, 0x17, 0xe, 0x17, 0xd2, 0xb, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x5, 0x17, 0xd7, 0xa, 0x17, 0x3, 0x17, 0x5, 0x17, 0xda, 0xa, 0x17, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0xdf, 0xa, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x5, 0x18, 0xe3, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0xea, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0xf1, 0xa, 0x18, 0x5, 0x18, 
    0xf3, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0xf8, 0xa, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 
    0x3, 0x1a, 0x7, 0x1a, 0x101, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x104, 
    0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x11a, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x7, 0x1c, 0x125, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x128, 0xb, 
    0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x138, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 
    0x1f, 0x142, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x5, 0x1f, 0x148, 0xa, 0x1f, 0x3, 0x1f, 0x2, 0x3, 0x36, 0x20, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x2, 0x3, 0x3, 0x2, 0x25, 0x26, 0x2, 0x15a, 0x2, 0x44, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x6, 0x60, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x62, 0x3, 0x2, 0x2, 0x2, 0xa, 0x75, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x7c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x84, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x12, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x14, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x91, 0x3, 0x2, 0x2, 0x2, 0x18, 0x93, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x95, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x97, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x99, 0x3, 0x2, 0x2, 0x2, 0x20, 0x9c, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x24, 0xa8, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0xab, 0x3, 0x2, 0x2, 0x2, 0x28, 0xae, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0xb1, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xdb, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x32, 0xfe, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x105, 0x3, 0x2, 0x2, 0x2, 0x36, 0x119, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x129, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x137, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x147, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 0x5, 0x8, 0x5, 0x2, 
    0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x45, 0x5, 0x32, 0x1a, 0x2, 0x44, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0x47, 0x5, 0x10, 0x9, 0x2, 0x47, 0x48, 0x5, 0x16, 0xc, 
    0x2, 0x48, 0x50, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x5, 0x10, 0x9, 0x2, 
    0x4a, 0x4b, 0x5, 0x16, 0xc, 0x2, 0x4b, 0x4c, 0x7, 0x3, 0x2, 0x2, 0x4c, 
    0x4d, 0x5, 0x1a, 0xe, 0x2, 0x4d, 0x4e, 0x7, 0x4, 0x2, 0x2, 0x4e, 0x50, 
    0x3, 0x2, 0x2, 0x2, 0x4f, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x5, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x5, 0x10, 
    0x9, 0x2, 0x52, 0x53, 0x5, 0x16, 0xc, 0x2, 0x53, 0x54, 0x7, 0x1b, 0x2, 
    0x2, 0x54, 0x55, 0x5, 0x36, 0x1c, 0x2, 0x55, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x57, 0x5, 0x10, 0x9, 0x2, 0x57, 0x58, 0x5, 0x16, 0xc, 0x2, 0x58, 
    0x59, 0x7, 0x3, 0x2, 0x2, 0x59, 0x5a, 0x5, 0x1a, 0xe, 0x2, 0x5a, 0x5b, 
    0x7, 0x4, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x1b, 0x2, 0x2, 0x5c, 0x5d, 0x7, 
    0x5, 0x2, 0x2, 0x5d, 0x5e, 0x5, 0xe, 0x8, 0x2, 0x5e, 0x5f, 0x7, 0x6, 
    0x2, 0x2, 0x5f, 0x61, 0x3, 0x2, 0x2, 0x2, 0x60, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x56, 0x3, 0x2, 0x2, 0x2, 0x61, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x62, 0x63, 0x5, 0x10, 0x9, 0x2, 0x63, 0x64, 0x5, 0x12, 0xa, 0x2, 0x64, 
    0x66, 0x7, 0x7, 0x2, 0x2, 0x65, 0x67, 0x5, 0xc, 0x7, 0x2, 0x66, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x69, 0x7, 0x8, 0x2, 0x2, 0x69, 0x6b, 0x7, 0x5, 
    0x2, 0x2, 0x6a, 0x6c, 0x5, 0x32, 0x1a, 0x2, 0x6b, 0x6a, 0x3, 0x2, 0x2, 
    0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x6d, 0x6e, 0x7, 0x15, 0x2, 0x2, 0x6e, 0x6f, 0x5, 0x36, 0x1c, 0x2, 0x6f, 
    0x70, 0x7, 0x9, 0x2, 0x2, 0x70, 0x72, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6d, 
    0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 0x6, 0x2, 0x2, 0x74, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x75, 0x76, 0x5, 0x14, 0xb, 0x2, 0x76, 0x78, 0x7, 0x7, 0x2, 
    0x2, 0x77, 0x79, 0x5, 0xe, 0x8, 0x2, 0x78, 0x77, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 
    0x7b, 0x7, 0x8, 0x2, 0x2, 0x7b, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x81, 
    0x5, 0x4, 0x3, 0x2, 0x7d, 0x7e, 0x7, 0xa, 0x2, 0x2, 0x7e, 0x80, 0x5, 
    0x4, 0x3, 0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0xd, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x84, 0x87, 0x5, 0x36, 0x1c, 0x2, 0x85, 0x86, 0x7, 0xa, 0x2, 0x2, 0x86, 
    0x88, 0x5, 0x36, 0x1c, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 
    0x3, 0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0xf, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x19, 
    0x2, 0x2, 0x8c, 0x11, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x19, 0x2, 
    0x2, 0x8e, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x19, 0x2, 0x2, 
    0x90, 0x15, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x7, 0x19, 0x2, 0x2, 0x92, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0x19, 0x2, 0x2, 0x94, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x7, 0x1a, 0x2, 0x2, 0x96, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x97, 0x98, 0x7, 0x2c, 0x2, 0x2, 0x98, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x99, 0x9a, 0x5, 0x20, 0x11, 0x2, 0x9a, 0x9b, 0x5, 0x1a, 0xe, 
    0x2, 0x9b, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x9, 0x2, 0x2, 0x2, 
    0x9d, 0x21, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa7, 0x5, 0x28, 0x15, 0x2, 0x9f, 
    0xa7, 0x5, 0x2a, 0x16, 0x2, 0xa0, 0xa7, 0x5, 0x30, 0x19, 0x2, 0xa1, 
    0xa7, 0x5, 0x2e, 0x18, 0x2, 0xa2, 0xa7, 0x5, 0x2c, 0x17, 0x2, 0xa3, 
    0xa7, 0x5, 0x34, 0x1b, 0x2, 0xa4, 0xa7, 0x5, 0x24, 0x13, 0x2, 0xa5, 
    0xa7, 0x5, 0x26, 0x14, 0x2, 0xa6, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0xa6, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa1, 0x3, 
    0x2, 0x2, 0x2, 0xa6, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa3, 0x3, 0x2, 
    0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0xa7, 0x23, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x5, 0x4, 0x3, 0x2, 
    0xa9, 0xaa, 0x7, 0x9, 0x2, 0x2, 0xaa, 0x25, 0x3, 0x2, 0x2, 0x2, 0xab, 
    0xac, 0x5, 0x6, 0x4, 0x2, 0xac, 0xad, 0x7, 0x9, 0x2, 0x2, 0xad, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x5, 0x36, 0x1c, 0x2, 0xaf, 0xb0, 0x7, 
    0x9, 0x2, 0x2, 0xb0, 0x29, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x18, 
    0x2, 0x2, 0xb2, 0xb3, 0x7, 0x7, 0x2, 0x2, 0xb3, 0xb6, 0x5, 0x1c, 0xf, 
    0x2, 0xb4, 0xb5, 0x7, 0xa, 0x2, 0x2, 0xb5, 0xb7, 0x5, 0xe, 0x8, 0x2, 
    0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 
    0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0x8, 0x2, 0x2, 0xb9, 0xba, 
    0x7, 0x9, 0x2, 0x2, 0xba, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x7, 
    0x12, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x7, 0x2, 0x2, 0xbd, 0xbe, 0x5, 0x38, 
    0x1d, 0x2, 0xbe, 0xbf, 0x7, 0x8, 0x2, 0x2, 0xbf, 0xc1, 0x7, 0x5, 0x2, 
    0x2, 0xc0, 0xc2, 0x5, 0x32, 0x1a, 0x2, 0xc1, 0xc0, 0x3, 0x2, 0x2, 0x2, 
    0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 
    0xd0, 0x7, 0x6, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0x14, 0x2, 0x2, 0xc5, 0xc6, 
    0x7, 0x7, 0x2, 0x2, 0xc6, 0xc7, 0x5, 0x38, 0x1d, 0x2, 0xc7, 0xc8, 0x7, 
    0x8, 0x2, 0x2, 0xc8, 0xca, 0x7, 0x5, 0x2, 0x2, 0xc9, 0xcb, 0x5, 0x32, 
    0x1a, 0x2, 0xca, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x3, 0x2, 0x2, 
    0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x6, 0x2, 0x2, 
    0xcd, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xce, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xd2, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0xd1, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd0, 0x3, 
    0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x13, 0x2, 0x2, 0xd4, 0xd6, 0x7, 0x5, 
    0x2, 0x2, 0xd5, 0xd7, 0x5, 0x32, 0x1a, 0x2, 0xd6, 0xd5, 0x3, 0x2, 0x2, 
    0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 
    0xd8, 0xda, 0x7, 0x6, 0x2, 0x2, 0xd9, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xda, 0x3, 0x2, 0x2, 0x2, 0xda, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 
    0x7, 0x11, 0x2, 0x2, 0xdc, 0xf2, 0x7, 0x7, 0x2, 0x2, 0xdd, 0xdf, 0x5, 
    0x4, 0x3, 0x2, 0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 
    0x2, 0x2, 0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe2, 0x7, 0x9, 0x2, 
    0x2, 0xe1, 0xe3, 0x5, 0x4, 0x3, 0x2, 0xe2, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0xe2, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 
    0xe5, 0x7, 0xb, 0x2, 0x2, 0xe5, 0xf3, 0x5, 0x18, 0xd, 0x2, 0xe6, 0xea, 
    0x5, 0x4, 0x3, 0x2, 0xe7, 0xea, 0x5, 0x6, 0x4, 0x2, 0xe8, 0xea, 0x5, 
    0x3c, 0x1f, 0x2, 0xe9, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 
    0x2, 0x2, 0xe9, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x3, 0x2, 0x2, 
    0x2, 0xeb, 0xec, 0x7, 0x9, 0x2, 0x2, 0xec, 0xed, 0x5, 0x38, 0x1d, 0x2, 
    0xed, 0xf0, 0x7, 0x9, 0x2, 0x2, 0xee, 0xf1, 0x5, 0x3c, 0x1f, 0x2, 0xef, 
    0xf1, 0x5, 0x36, 0x1c, 0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xef, 
    0x3, 0x2, 0x2, 0x2, 0xf1, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0xf2, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 
    0x2, 0x2, 0xf4, 0xf5, 0x7, 0x8, 0x2, 0x2, 0xf5, 0xf7, 0x7, 0x5, 0x2, 
    0x2, 0xf6, 0xf8, 0x5, 0x32, 0x1a, 0x2, 0xf7, 0xf6, 0x3, 0x2, 0x2, 0x2, 
    0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 
    0xfa, 0x7, 0x6, 0x2, 0x2, 0xfa, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 
    0x5, 0x3a, 0x1e, 0x2, 0xfc, 0xfd, 0x7, 0x9, 0x2, 0x2, 0xfd, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0xfe, 0x102, 0x5, 0x22, 0x12, 0x2, 0xff, 0x101, 0x5, 
    0x22, 0x12, 0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 0x104, 0x3, 
    0x2, 0x2, 0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x3, 
    0x2, 0x2, 0x2, 0x103, 0x33, 0x3, 0x2, 0x2, 0x2, 0x104, 0x102, 0x3, 0x2, 
    0x2, 0x2, 0x105, 0x106, 0x5, 0x3c, 0x1f, 0x2, 0x106, 0x107, 0x7, 0x9, 
    0x2, 0x2, 0x107, 0x35, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x8, 0x1c, 
    0x1, 0x2, 0x109, 0x10a, 0x5, 0x18, 0xd, 0x2, 0x10a, 0x10b, 0x7, 0x3, 
    0x2, 0x2, 0x10b, 0x10c, 0x5, 0x1a, 0xe, 0x2, 0x10c, 0x10d, 0x7, 0x4, 
    0x2, 0x2, 0x10d, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x11a, 0x7, 0xc, 
    0x2, 0x2, 0x10f, 0x11a, 0x5, 0x1c, 0xf, 0x2, 0x110, 0x11a, 0x5, 0x1e, 
    0x10, 0x2, 0x111, 0x11a, 0x5, 0x1a, 0xe, 0x2, 0x112, 0x11a, 0x5, 0x3a, 
    0x1e, 0x2, 0x113, 0x11a, 0x5, 0x18, 0xd, 0x2, 0x114, 0x115, 0x7, 0x7, 
    0x2, 0x2, 0x115, 0x116, 0x5, 0x36, 0x1c, 0x2, 0x116, 0x117, 0x7, 0x8, 
    0x2, 0x2, 0x117, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x118, 0x11a, 0x5, 0xa, 
    0x6, 0x2, 0x119, 0x108, 0x3, 0x2, 0x2, 0x2, 0x119, 0x10e, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x119, 0x110, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x111, 0x3, 0x2, 0x2, 0x2, 0x119, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x113, 0x3, 0x2, 0x2, 0x2, 0x119, 0x114, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x126, 0x3, 0x2, 
    0x2, 0x2, 0x11b, 0x11c, 0xc, 0xe, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0xd, 
    0x2, 0x2, 0x11d, 0x125, 0x5, 0x36, 0x1c, 0xf, 0x11e, 0x11f, 0xc, 0xd, 
    0x2, 0x2, 0x11f, 0x120, 0x7, 0xe, 0x2, 0x2, 0x120, 0x125, 0x5, 0x36, 
    0x1c, 0xe, 0x121, 0x122, 0xc, 0xc, 0x2, 0x2, 0x122, 0x123, 0x7, 0xf, 
    0x2, 0x2, 0x123, 0x125, 0x5, 0x36, 0x1c, 0xd, 0x124, 0x11b, 0x3, 0x2, 
    0x2, 0x2, 0x124, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x124, 0x121, 0x3, 0x2, 
    0x2, 0x2, 0x125, 0x128, 0x3, 0x2, 0x2, 0x2, 0x126, 0x124, 0x3, 0x2, 
    0x2, 0x2, 0x126, 0x127, 0x3, 0x2, 0x2, 0x2, 0x127, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x128, 0x126, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x5, 0x36, 0x1c, 
    0x2, 0x12a, 0x12b, 0x7, 0x10, 0x2, 0x2, 0x12b, 0x12c, 0x5, 0x36, 0x1c, 
    0x2, 0x12c, 0x39, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x7, 0x2a, 0x2, 
    0x2, 0x12e, 0x138, 0x5, 0x18, 0xd, 0x2, 0x12f, 0x130, 0x7, 0x2b, 0x2, 
    0x2, 0x130, 0x138, 0x5, 0x18, 0xd, 0x2, 0x131, 0x132, 0x5, 0x18, 0xd, 
    0x2, 0x132, 0x133, 0x7, 0x2a, 0x2, 0x2, 0x133, 0x138, 0x3, 0x2, 0x2, 
    0x2, 0x134, 0x135, 0x5, 0x18, 0xd, 0x2, 0x135, 0x136, 0x7, 0x2b, 0x2, 
    0x2, 0x136, 0x138, 0x3, 0x2, 0x2, 0x2, 0x137, 0x12d, 0x3, 0x2, 0x2, 
    0x2, 0x137, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x137, 0x131, 0x3, 0x2, 0x2, 
    0x2, 0x137, 0x134, 0x3, 0x2, 0x2, 0x2, 0x138, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x139, 0x13a, 0x5, 0x18, 0xd, 0x2, 0x13a, 0x13b, 0x7, 0x1b, 0x2, 0x2, 
    0x13b, 0x13c, 0x5, 0x36, 0x1c, 0x2, 0x13c, 0x148, 0x3, 0x2, 0x2, 0x2, 
    0x13d, 0x13e, 0x5, 0x18, 0xd, 0x2, 0x13e, 0x141, 0x7, 0x3, 0x2, 0x2, 
    0x13f, 0x142, 0x5, 0x1a, 0xe, 0x2, 0x140, 0x142, 0x5, 0x36, 0x1c, 0x2, 
    0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x141, 0x140, 0x3, 0x2, 0x2, 0x2, 
    0x142, 0x143, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x7, 0x4, 0x2, 0x2, 
    0x144, 0x145, 0x7, 0x1b, 0x2, 0x2, 0x145, 0x146, 0x5, 0x36, 0x1c, 0x2, 
    0x146, 0x148, 0x3, 0x2, 0x2, 0x2, 0x147, 0x139, 0x3, 0x2, 0x2, 0x2, 
    0x147, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x148, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x20, 
    0x41, 0x44, 0x4f, 0x60, 0x66, 0x6b, 0x71, 0x78, 0x81, 0x89, 0xa6, 0xb6, 
    0xc1, 0xca, 0xd0, 0xd6, 0xd9, 0xde, 0xe2, 0xe9, 0xf0, 0xf2, 0xf7, 0x102, 
    0x119, 0x124, 0x126, 0x137, 0x141, 0x147, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

mmcParser::Initializer mmcParser::_init;
