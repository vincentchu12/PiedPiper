
#include <stdlib.h>
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;
extern string program_name;


// Generated from mmc.g4 by ANTLR 4.7.1


#include "mmcLexer.h"


using namespace antlr4;


mmcLexer::mmcLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

mmcLexer::~mmcLexer() {
  delete _interpreter;
}

std::string mmcLexer::getGrammarFileName() const {
  return "mmc.g4";
}

const std::vector<std::string>& mmcLexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& mmcLexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& mmcLexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& mmcLexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& mmcLexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> mmcLexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& mmcLexer::getATN() const {
  return _atn;
}




// Static vars and initialization.
std::vector<dfa::DFA> mmcLexer::_decisionToDFA;
atn::PredictionContextCache mmcLexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN mmcLexer::_atn;
std::vector<uint16_t> mmcLexer::_serializedATN;

std::vector<std::string> mmcLexer::_ruleNames = {
  u8"T__0", u8"T__1", u8"T__2", u8"T__3", u8"T__4", u8"T__5", u8"T__6", 
  u8"T__7", u8"T__8", u8"BOOL", u8"MUL_DIV_MOD_OP", u8"ADD_SUB_OP", u8"BIT_OP", 
  u8"MATH_COMP", u8"FOR", u8"IF", u8"ELSE", u8"ELIF", u8"RETURN", u8"TRUE", 
  u8"FALSE", u8"PRINTF", u8"IDENTIFIER", u8"INTEGER", u8"ASSIGN", u8"EQ", 
  u8"NEQ", u8"LT", u8"LTE", u8"GT", u8"GTE", u8"MUL_OP", u8"DIV_OP", u8"MOD_OP", 
  u8"ADD_OP", u8"SUB_OP", u8"AND_OP", u8"OR_OP", u8"XOR_OP", u8"INC", u8"DEC", 
  u8"STRING", u8"NEWLINE", u8"WS"
};

std::vector<std::string> mmcLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> mmcLexer::_modeNames = {
  u8"DEFAULT_MODE"
};

std::vector<std::string> mmcLexer::_literalNames = {
  "", u8"'['", u8"']'", u8"'{'", u8"'}'", u8"'('", u8"')'", u8"';'", u8"','", 
  u8"':'", "", "", "", "", "", u8"'for'", u8"'if'", u8"'else'", u8"'elif'", 
  u8"'return'", u8"'true'", u8"'false'", u8"'printf'", "", "", u8"'='", 
  u8"'=='", u8"'!='", u8"'<'", u8"'<='", u8"'>'", u8"'>='", u8"'*'", u8"'/'", 
  u8"'%'", u8"'+'", u8"'-'", u8"'&'", u8"'|'", u8"'^'", u8"'++'", u8"'--'"
};

std::vector<std::string> mmcLexer::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", u8"BOOL", u8"MUL_DIV_MOD_OP", 
  u8"ADD_SUB_OP", u8"BIT_OP", u8"MATH_COMP", u8"FOR", u8"IF", u8"ELSE", 
  u8"ELIF", u8"RETURN", u8"TRUE", u8"FALSE", u8"PRINTF", u8"IDENTIFIER", 
  u8"INTEGER", u8"ASSIGN", u8"EQ", u8"NEQ", u8"LT", u8"LTE", u8"GT", u8"GTE", 
  u8"MUL_OP", u8"DIV_OP", u8"MOD_OP", u8"ADD_OP", u8"SUB_OP", u8"AND_OP", 
  u8"OR_OP", u8"XOR_OP", u8"INC", u8"DEC", u8"STRING", u8"NEWLINE", u8"WS"
};

dfa::Vocabulary mmcLexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> mmcLexer::_tokenNames;

mmcLexer::Initializer::Initializer() {
  // This code could be in a static initializer lambda, but VS doesn't allow access to private class members from there.
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
    0x2, 0x2e, 0xfc, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 
    0x4, 0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
    0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 
    0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 
    0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 
    0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 
    0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 
    0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 
    0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 
    0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 
    0x22, 0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 
    0x9, 0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 
    0x28, 0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 
    0x4, 0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x70, 0xa, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x75, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0x79, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x7e, 0xa, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0x86, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 
    0x18, 0x7, 0x18, 0xb4, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0xb7, 0xb, 0x18, 
    0x3, 0x19, 0x6, 0x19, 0xba, 0xa, 0x19, 0xd, 0x19, 0xe, 0x19, 0xbb, 0x3, 
    0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
    0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0xe8, 0xa, 0x2b, 0xc, 0x2b, 0xe, 
    0x2b, 0xeb, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x5, 0x2c, 0xf0, 
    0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x6, 
    0x2d, 0xf7, 0xa, 0x2d, 0xd, 0x2d, 0xe, 0x2d, 0xf8, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0xe9, 0x2, 0x2e, 0x3, 0x3, 0x5, 0x4, 0x7, 0x5, 0x9, 0x6, 0xb, 0x7, 
    0xd, 0x8, 0xf, 0x9, 0x11, 0xa, 0x13, 0xb, 0x15, 0xc, 0x17, 0xd, 0x19, 
    0xe, 0x1b, 0xf, 0x1d, 0x10, 0x1f, 0x11, 0x21, 0x12, 0x23, 0x13, 0x25, 
    0x14, 0x27, 0x15, 0x29, 0x16, 0x2b, 0x17, 0x2d, 0x18, 0x2f, 0x19, 0x31, 
    0x1a, 0x33, 0x1b, 0x35, 0x1c, 0x37, 0x1d, 0x39, 0x1e, 0x3b, 0x1f, 0x3d, 
    0x20, 0x3f, 0x21, 0x41, 0x22, 0x43, 0x23, 0x45, 0x24, 0x47, 0x25, 0x49, 
    0x26, 0x4b, 0x27, 0x4d, 0x28, 0x4f, 0x29, 0x51, 0x2a, 0x53, 0x2b, 0x55, 
    0x2c, 0x57, 0x2d, 0x59, 0x2e, 0x3, 0x2, 0x6, 0x5, 0x2, 0x43, 0x5c, 0x61, 
    0x61, 0x63, 0x7c, 0x6, 0x2, 0x32, 0x3b, 0x43, 0x5c, 0x61, 0x61, 0x63, 
    0x7c, 0x3, 0x2, 0x32, 0x3b, 0x4, 0x2, 0xb, 0xb, 0x22, 0x22, 0x2, 0x10b, 
    0x2, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0xd, 0x3, 0x2, 0x2, 0x2, 0x2, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x11, 0x3, 0x2, 0x2, 0x2, 0x2, 0x13, 0x3, 0x2, 0x2, 0x2, 0x2, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x17, 0x3, 0x2, 0x2, 0x2, 0x2, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x2, 0x21, 0x3, 0x2, 0x2, 0x2, 0x2, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x25, 0x3, 0x2, 0x2, 0x2, 0x2, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x2, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x37, 0x3, 0x2, 0x2, 0x2, 0x2, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x2, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x41, 0x3, 0x2, 0x2, 0x2, 0x2, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x45, 0x3, 0x2, 0x2, 0x2, 0x2, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x49, 0x3, 0x2, 0x2, 0x2, 0x2, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x2, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x53, 0x3, 0x2, 0x2, 0x2, 0x2, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x57, 0x3, 0x2, 0x2, 0x2, 0x2, 0x59, 0x3, 0x2, 0x2, 0x2, 0x3, 0x5b, 
    0x3, 0x2, 0x2, 0x2, 0x5, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x7, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x9, 0x61, 0x3, 0x2, 0x2, 0x2, 0xb, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0xd, 0x65, 0x3, 0x2, 0x2, 0x2, 0xf, 0x67, 0x3, 0x2, 0x2, 0x2, 0x11, 
    0x69, 0x3, 0x2, 0x2, 0x2, 0x13, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x15, 0x6f, 
    0x3, 0x2, 0x2, 0x2, 0x17, 0x74, 0x3, 0x2, 0x2, 0x2, 0x19, 0x78, 0x3, 
    0x2, 0x2, 0x2, 0x1b, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0x1f, 0x87, 0x3, 0x2, 0x2, 0x2, 0x21, 0x8b, 0x3, 0x2, 0x2, 
    0x2, 0x23, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x25, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x27, 0x98, 0x3, 0x2, 0x2, 0x2, 0x29, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0xa4, 0x3, 0x2, 0x2, 0x2, 0x2d, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x2f, 0xb1, 
    0x3, 0x2, 0x2, 0x2, 0x31, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x33, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0x35, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x37, 0xc2, 0x3, 0x2, 
    0x2, 0x2, 0x39, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x3b, 0xc7, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0xca, 0x3, 0x2, 0x2, 0x2, 0x3f, 0xcc, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x43, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0xd3, 0x3, 0x2, 0x2, 0x2, 0x47, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x49, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0x4b, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x4d, 0xdb, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x51, 0xdf, 0x3, 0x2, 
    0x2, 0x2, 0x53, 0xe2, 0x3, 0x2, 0x2, 0x2, 0x55, 0xe5, 0x3, 0x2, 0x2, 
    0x2, 0x57, 0xef, 0x3, 0x2, 0x2, 0x2, 0x59, 0xf6, 0x3, 0x2, 0x2, 0x2, 
    0x5b, 0x5c, 0x7, 0x5d, 0x2, 0x2, 0x5c, 0x4, 0x3, 0x2, 0x2, 0x2, 0x5d, 
    0x5e, 0x7, 0x5f, 0x2, 0x2, 0x5e, 0x6, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 
    0x7, 0x7d, 0x2, 0x2, 0x60, 0x8, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x7, 
    0x7f, 0x2, 0x2, 0x62, 0xa, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0x2a, 
    0x2, 0x2, 0x64, 0xc, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x7, 0x2b, 0x2, 
    0x2, 0x66, 0xe, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x3d, 0x2, 0x2, 
    0x68, 0x10, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x2e, 0x2, 0x2, 0x6a, 
    0x12, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x3c, 0x2, 0x2, 0x6c, 0x14, 
    0x3, 0x2, 0x2, 0x2, 0x6d, 0x70, 0x5, 0x29, 0x15, 0x2, 0x6e, 0x70, 0x5, 
    0x2b, 0x16, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6e, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x16, 0x3, 0x2, 0x2, 0x2, 0x71, 0x75, 0x5, 0x41, 0x21, 
    0x2, 0x72, 0x75, 0x5, 0x43, 0x22, 0x2, 0x73, 0x75, 0x5, 0x45, 0x23, 
    0x2, 0x74, 0x71, 0x3, 0x2, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x18, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x79, 0x5, 0x47, 0x24, 0x2, 0x77, 0x79, 0x5, 0x49, 0x25, 0x2, 0x78, 
    0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0x1a, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x7e, 0x5, 0x4b, 0x26, 0x2, 0x7b, 0x7e, 0x5, 
    0x4d, 0x27, 0x2, 0x7c, 0x7e, 0x5, 0x4f, 0x28, 0x2, 0x7d, 0x7a, 0x3, 
    0x2, 0x2, 0x2, 0x7d, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7c, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x86, 0x5, 0x35, 0x1b, 
    0x2, 0x80, 0x86, 0x5, 0x37, 0x1c, 0x2, 0x81, 0x86, 0x5, 0x39, 0x1d, 
    0x2, 0x82, 0x86, 0x5, 0x3b, 0x1e, 0x2, 0x83, 0x86, 0x5, 0x3d, 0x1f, 
    0x2, 0x84, 0x86, 0x5, 0x3f, 0x20, 0x2, 0x85, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x85, 0x80, 0x3, 0x2, 0x2, 0x2, 0x85, 0x81, 0x3, 0x2, 0x2, 0x2, 0x85, 
    0x82, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x84, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x7, 
    0x68, 0x2, 0x2, 0x88, 0x89, 0x7, 0x71, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x74, 
    0x2, 0x2, 0x8a, 0x20, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x6b, 0x2, 
    0x2, 0x8c, 0x8d, 0x7, 0x68, 0x2, 0x2, 0x8d, 0x22, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x8f, 0x7, 0x67, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x6e, 0x2, 0x2, 0x90, 
    0x91, 0x7, 0x75, 0x2, 0x2, 0x91, 0x92, 0x7, 0x67, 0x2, 0x2, 0x92, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0x67, 0x2, 0x2, 0x94, 0x95, 0x7, 
    0x6e, 0x2, 0x2, 0x95, 0x96, 0x7, 0x6b, 0x2, 0x2, 0x96, 0x97, 0x7, 0x68, 
    0x2, 0x2, 0x97, 0x26, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x7, 0x74, 0x2, 
    0x2, 0x99, 0x9a, 0x7, 0x67, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x76, 0x2, 0x2, 
    0x9b, 0x9c, 0x7, 0x77, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x74, 0x2, 0x2, 0x9d, 
    0x9e, 0x7, 0x70, 0x2, 0x2, 0x9e, 0x28, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 
    0x7, 0x76, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x74, 0x2, 0x2, 0xa1, 0xa2, 0x7, 
    0x77, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x67, 0x2, 0x2, 0xa3, 0x2a, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xa5, 0x7, 0x68, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x63, 0x2, 
    0x2, 0xa6, 0xa7, 0x7, 0x6e, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x75, 0x2, 0x2, 
    0xa8, 0xa9, 0x7, 0x67, 0x2, 0x2, 0xa9, 0x2c, 0x3, 0x2, 0x2, 0x2, 0xaa, 
    0xab, 0x7, 0x72, 0x2, 0x2, 0xab, 0xac, 0x7, 0x74, 0x2, 0x2, 0xac, 0xad, 
    0x7, 0x6b, 0x2, 0x2, 0xad, 0xae, 0x7, 0x70, 0x2, 0x2, 0xae, 0xaf, 0x7, 
    0x76, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x68, 0x2, 0x2, 0xb0, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0xb1, 0xb5, 0x9, 0x2, 0x2, 0x2, 0xb2, 0xb4, 0x9, 0x3, 0x2, 
    0x2, 0xb3, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb7, 0x3, 0x2, 0x2, 0x2, 
    0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb6, 
    0x30, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xba, 
    0x9, 0x4, 0x2, 0x2, 0xb9, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 
    0x2, 0x2, 0x2, 0xbb, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0x32, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x7, 0x3f, 0x2, 
    0x2, 0xbe, 0x34, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x3f, 0x2, 0x2, 
    0xc0, 0xc1, 0x7, 0x3f, 0x2, 0x2, 0xc1, 0x36, 0x3, 0x2, 0x2, 0x2, 0xc2, 
    0xc3, 0x7, 0x23, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x3f, 0x2, 0x2, 0xc4, 0x38, 
    0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0x3e, 0x2, 0x2, 0xc6, 0x3a, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x3e, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x3f, 
    0x2, 0x2, 0xc9, 0x3c, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x40, 0x2, 
    0x2, 0xcb, 0x3e, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x40, 0x2, 0x2, 
    0xcd, 0xce, 0x7, 0x3f, 0x2, 0x2, 0xce, 0x40, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xd0, 0x7, 0x2c, 0x2, 0x2, 0xd0, 0x42, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 
    0x7, 0x31, 0x2, 0x2, 0xd2, 0x44, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 
    0x27, 0x2, 0x2, 0xd4, 0x46, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0x2d, 
    0x2, 0x2, 0xd6, 0x48, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x2f, 0x2, 
    0x2, 0xd8, 0x4a, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x7, 0x28, 0x2, 0x2, 
    0xda, 0x4c, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x7e, 0x2, 0x2, 0xdc, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x60, 0x2, 0x2, 0xde, 0x50, 
    0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x2d, 0x2, 0x2, 0xe0, 0xe1, 0x7, 
    0x2d, 0x2, 0x2, 0xe1, 0x52, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x2f, 
    0x2, 0x2, 0xe3, 0xe4, 0x7, 0x2f, 0x2, 0x2, 0xe4, 0x54, 0x3, 0x2, 0x2, 
    0x2, 0xe5, 0xe9, 0x7, 0x24, 0x2, 0x2, 0xe6, 0xe8, 0xb, 0x2, 0x2, 0x2, 
    0xe7, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe9, 
    0xea, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xea, 0xec, 
    0x3, 0x2, 0x2, 0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 
    0x24, 0x2, 0x2, 0xed, 0x56, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf0, 0x7, 0xf, 
    0x2, 0x2, 0xef, 0xee, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 
    0x2, 0xf0, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x7, 0xc, 0x2, 0x2, 
    0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x8, 0x2c, 0x2, 0x2, 0xf4, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf7, 0x9, 0x5, 0x2, 0x2, 0xf6, 0xf5, 
    0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf6, 0x3, 
    0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 0x2, 
    0x2, 0x2, 0xfa, 0xfb, 0x8, 0x2d, 0x2, 0x2, 0xfb, 0x5a, 0x3, 0x2, 0x2, 
    0x2, 0xd, 0x2, 0x6f, 0x74, 0x78, 0x7d, 0x85, 0xb5, 0xbb, 0xe9, 0xef, 
    0xf8, 0x3, 0x8, 0x2, 0x2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

mmcLexer::Initializer mmcLexer::_init;
