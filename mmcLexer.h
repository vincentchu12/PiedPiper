
#include <stdlib.h>
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;
extern string program_name;


// Generated from mmc.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  mmcLexer : public antlr4::Lexer {
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

  mmcLexer(antlr4::CharStream *input);
  ~mmcLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

