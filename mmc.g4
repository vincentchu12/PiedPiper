grammar mmc;

@header {
#include <stdlib.h>
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;
extern string program_name;
}

root	: 
		( functionDeclaration
		| functionDefinition
		)+
		;

declaration : typeID variableID | typeID variableID '[' INTEGER ']';
definition  : typeID assignment ;


functionDeclaration : typeID functionID '(' parameters? ')' ';' ;
functionDefinition  : typeID functionID '(' parameters? ')' 
					   '{'
					   		statementList?
					   		(RETURN expression ';')?
					   '}'
				     ;

functionCall : function '(' identifiers? ')' ;
parameters   : declaration (',' declaration)+ ;
identifiers  : expression  (',' expression)+  ;

typeID     : IDENTIFIER ;
functionID : IDENTIFIER ;
function   : IDENTIFIER ;
variableID : IDENTIFIER ;
variable   : IDENTIFIER ;

statement   : expressionStatement
			| unaryStatement
			| forStatement
			| ifStatement
			| assignmentStatement
			| declarationStatement
			| definitionStatement
			;

declarationStatement : declaration ';' ;
definitionStatement  : definition ';' ;
expressionStatement  : expression ';' ;

ifStatement	: IF '(' expression ')' '{' statementList? '}'
			(
				ELIF '(' expression ')' '{' statementList? '}'
			)*
			(
				ELSE '{' statementList? '}'
			)?
			;

forStatement : FOR '('
			 (
			 	(
			 		declaration? ';' declaration? ';' variable
			 	)
			 |
			 	(
					(definition | declaration)? ';' expression? ';' (assignment | unary)?
			 	)
			 )
			')' '{' statementList? '}'
			 ;

unaryStatement : unary ';' ;

statementList       : statement (statement)* ;
assignmentStatement : assignment ';' ;

expression locals [ TypeSpec* type = nullptr ]
	: expression LOGIC_COMP     expression # logicExpr
	| expression MATH_COMP      expression # mathExpr
	| expression MUL_DIV_MOD_OP expression # mulDivModExpr
	| expression ADD_SUB_OP     expression # addSubExpr
	| expression BIT_OP         expression # bitExpr
	| variable '[' INTEGER ']'           # arrayExpr
	| INTEGER                              # numberExpr
	| variable                           # variableExpr
	| '(' expression ')'				   # parenExpr
	| functionCall                         # funcCallExpr
	;

unary	: INC variable # preInc 
		| DEC variable # preDec
		| variable INC # postInc
		| variable DEC # postDec
		;

assignment : variable ASSIGN expression 
		   | variable '[' INTEGER ']' ASSIGN '{' identifiers '}' ;

// Operations (In Order of Precedence)
MUL_DIV_MOD_OP : MUL_OP | DIV_OP | MOD_OP ;
ADD_SUB_OP     : ADD_OP | SUB_OP          ;
BIT_OP         : AND_OP | OR_OP  | XOR_OP ;

// Comparators (In Order of Precedence)
LOGIC_COMP : L_AND    | L_OR     | L_NOT    ;
MATH_COMP  : EQ | NEQ | LT | LTE | GT | GTE ;

// Reserved Words
FOR        : 'for'    ;
IF         : 'if'     ;
ELSE       : 'else'   ;
ELIF       : 'elif'   ;
RETURN     : 'return' ;

IDENTIFIER : [_a-zA-Z][_a-zA-Z0-9]* ;
INTEGER    : [0-9]+ ;

// Assign
ASSIGN : '=' ;

// Mathematical Comparators
EQ     : '==' ;
NEQ    : '!=' ;
LT     : '<'  ;
LTE    : '<=' ;
GT     : '>'  ;
GTE    : '>=' ;

// Logical Comparators
L_AND  : '&&' ;
L_OR   : '||' ;
L_NOT  : '!'  ;

// Mathematical Operators
MUL_OP : '*' ;
DIV_OP : '/' ;
MOD_OP : '%' ;
ADD_OP : '+' ;
SUB_OP : '-' ;

// Bitwise Operators
AND_OP : '&' ;
OR_OP  : '|' ;
XOR_OP : '^' ;

// Unary Operators
INC    : '++' ;
DEC    : '--' ;

NEWLINE : '\r'? '\n' -> skip  ;		// Skip Return Return Carriage (Windows) and Newlines
WS      : [ \t]+ -> skip ; 			// Skip Spaces and Tabs

