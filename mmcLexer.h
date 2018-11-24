
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
    T__7 = 8, MUL_DIV_MOD_OP = 9, ADD_SUB_OP = 10, BIT_OP = 11, LOGIC_COMP = 12, 
    MATH_COMP = 13, FOR = 14, IF = 15, ELSE = 16, ELIF = 17, RETURN = 18, 
    IDENTIFIER = 19, INTEGER = 20, ASSIGN = 21, EQ = 22, NEQ = 23, LT = 24, 
    LTE = 25, GT = 26, GTE = 27, L_AND = 28, L_OR = 29, L_NOT = 30, MUL_OP = 31, 
    DIV_OP = 32, MOD_OP = 33, ADD_OP = 34, SUB_OP = 35, AND_OP = 36, OR_OP = 37, 
    XOR_OP = 38, INC = 39, DEC = 40, NEWLINE = 41, WS = 42
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

