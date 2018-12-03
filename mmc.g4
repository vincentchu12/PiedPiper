grammar mmc;

@header {
#include <stdlib.h>
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;
extern string program_name;
}

root	: (statementList)
		;

declaration
	: typeID variableID					   # variableDecl
	| typeID variableID '[' INTEGER ']'	   # arrayDecl
	;
	
definition  
	: typeID variableID ASSIGN expression    					   # variableDef
	| typeID variableID '[' INTEGER ']' ASSIGN '{' identifiers '}' # arrayDef
	;


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

typeID       : IDENTIFIER ;
functionID   : IDENTIFIER ;
function     : IDENTIFIER ;
variableID   : IDENTIFIER ;
variable     : IDENTIFIER ;
number       locals [ TypeSpec* type = nullptr ] : INTEGER    ;
str          locals [ TypeSpec* type = nullptr ] : STRING     ;
signedNumber locals [ TypeSpec* type = nullptr ] : sign number;
sign         : ADD_OP | SUB_OP ;

statement   : expressionStatement
			| printfStatement
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

printfStatement : PRINTF '(' str (',' identifiers)? ')' ';';

ifStatement	: IF '(' mathExpr ')' '{' statementList? '}'
			(
				ELIF '(' mathExpr ')' '{' statementList? '}'
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
					(declaration | definition | assignment) ';' mathExpr ';' (assignment | unary)
			 	)
			 )
			')' '{' statementList? '}'
			 ;

unaryStatement : unary ';' ;

statementList       : statement (statement)* ;
assignmentStatement : assignment ';' ;
	
expression locals [ TypeSpec* type = nullptr ]
	: expression MUL_DIV_MOD_OP expression # mulDivModExpr
	| expression ADD_SUB_OP     expression # addSubExpr
	| expression BIT_OP         expression # bitExpr
	| variable '[' number ']'              # arrayExpr
	| BOOL                                 # boolExpr
	| str    							   # stringExpr
	| signedNumber                         # signedNumberExpr
	| number                               # unsignedNumberExpr
	| unary                                # unaryExpr
	| variable                             # variableExpr
	| '(' expression ')'				   # parenExpr
	| functionCall                         # funcCallExpr
	;

mathExpr locals [ TypeSpec* type = nullptr ]
	: expression MATH_COMP      expression
	;

unary locals [ TypeSpec* type = nullptr ]
		: INC variable # preInc 
		| DEC variable # preDec
		| variable INC # postInc
		| variable DEC # postDec
		;

assignment : variable ASSIGN expression 						 # variableAssignment
		   | variable '[' INTEGER ']' ASSIGN '{' identifiers '}' # arrayAssignment
		   ;

BOOL : TRUE | FALSE ;
// Operations (In Order of Precedence)
MUL_DIV_MOD_OP : MUL_OP | DIV_OP | MOD_OP ;
ADD_SUB_OP     : ADD_OP | SUB_OP          ;
BIT_OP         : AND_OP | OR_OP  | XOR_OP ;

// Comparators (In Order of Precedence)
MATH_COMP  : EQ | NEQ | LT | LTE | GT | GTE ;

// Reserved Words
FOR        : 'for'    ;
IF         : 'if'     ;
ELSE       : 'else'   ;
ELIF       : 'elif'   ;
RETURN     : 'return' ;
TRUE       : 'true'   ;
FALSE      : 'false'  ;
PRINTF     : 'printf' ;

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

STRING  : '"' .*? '"' ;
NEWLINE : '\r'? '\n' -> skip  ;		// Skip Return Return Carriage (Windows) and Newlines
WS      : [ \t]+ -> skip ; 			// Skip Spaces and Tabs

