%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {Algebra}
%define parser_class_name {Parser}

%code requires{
   namespace Algebra {
      class Driver;
      class Scanner;
   }
   class Expression;
   class Block;
   class Affectation;

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { Scanner & scanner }
%parse-param { Driver & driver }

%locations
%start prog

%code{
	#include <iostream>
	#include <cstdlib>
	#include <fstream>
	#include <math.h>
	#include <list>
   
	#include "driver.hpp"
	#include "../include/variable.hpp"
	#include "../include/affectation.hpp"
	#include "../include/expression.hpp"
	#include "../include/comparatorFactory.hpp"
	#include "../include/block.hpp"
	#include "../include/ifElse.hpp"

	#undef yylex
	#define yylex scanner.yylex
	
	Block * block = nullptr;
	
}

%define parse.assert

%union
{
	char * stringValue;
	double doubleValue;
	Expression * exprValue;
	Affectation * affValue;
	Block * blockValue;
}

%token END     0   	"end of file"
%token EOL

%token<doubleValue> DOUBLE
%token<stringValue> IDENTIFIER
%token<stringValue> UNOP
%token<stringValue> OA
%token<stringValue> COMMA
%token<stringValue> DEL
%token<stringValue> IM
%token<stringValue> OR
%token<stringValue> EM
%token<stringValue> IF THEN ELSE SEMICOLON LOOP

%token<stringValue> LBRACKET
%token<stringValue> RBRACKET

%token<stringValue> LBRACE
%token<stringValue> RBRACE

%type<exprValue> expression conditional ternary affectation
%type<doubleValue> number
%type<blockValue> braces block

%left<stringValue> COMP
%left<stringValue> ADD SUB
%left<stringValue> BINOPMQ
%left MINUS PLUS

%right<stringValue> EXP

%%

prog
	: prog EOL line				{ ; }
	| line 						{ ; }
	| EOL						{ ; }
   	;

line
	: affectation 	{ ; }
	| ifElse 		{ ; }
	| loop			{ ; }
	;
	
number
	: SUB DOUBLE %prec MINUS 	{ $$ = -$2; free($1); }
	| ADD DOUBLE %prec PLUS 	{ $$ = $2; free($1); }
	| DOUBLE 					{ $$ = $1; }
	;	
	
affectation
	: IDENTIFIER OA expression 	{ 
		$$ = driver.affectation($3, $1, $2);
		free($2);
		free($1);
	}
	| IDENTIFIER OA ternary 	{ 
		$$ = driver.affectation($3, $1, $2);
		free($2);
		free($1);
	}
	;	
	
ternary
	: LBRACKET conditional RBRACKET IM expression OR expression { 
		$$ = driver.ternary($2, $5, $7);
	}
	;

conditional
	: expression COMP expression		{ $$ = driver.comp($1, $3, $2); free($2); }
	| EM LBRACKET conditional RBRACKET 	{
		ComparatorFactory * tmp = (ComparatorFactory *)$3;
		tmp->isNegation();
		$$ = tmp; 
	} 
	| LBRACKET conditional RBRACKET 	{ $$ = $2; }
	| "0" 								{ $$ = driver.constant(0); }
	| "1" 								{ $$ = driver.constant(1); }
	;
	
block
	:  block EOL affectation { 
		if (block == nullptr)
		{
			block = new Block();
		}
		block->add((Affectation*)$3); 
		$$ = new Block(*block);
	}
	| affectation {
		if (block == nullptr)
		{
			block = new Block();
		}
		block->add((Affectation*)$1);
		$$ = new Block(*block);
	}	
	;
	
ifElse
	: IF conditional THEN braces ELSE braces 				{ driver.ifElse($2, $4, $6); }
	| IF conditional THEN EOL braces EOL ELSE EOL braces 	{ driver.ifElse($2, $5, $9); }
	| IF conditional EOL braces EOL ELSE EOL braces 		{ driver.ifElse($2, $4, $8); }
	| IF conditional braces ELSE braces 					{ driver.ifElse($2, $3, $5); }
	;
	
braces
	: LBRACE block RBRACE 			{ $$ = driver.block($2); block = nullptr; }
	| LBRACE EOL block EOL RBRACE 	{ $$ = driver.block($3); block = nullptr; }
	;
	
loop
	: LOOP LBRACKET affectation SEMICOLON conditional SEMICOLON affectation RBRACKET braces {
		driver.forLoop((Affectation *)$3, (ComparatorFactory*)$5, (Affectation *)$7, $9);
	}
	;
	
expression
	: expression ADD expression			{ $$ = driver.binop($1, $3, $2); free($2); }
	| expression SUB expression			{ $$ = driver.binop($1, $3, $2); free($2); }
	| expression BINOPMQ expression		{ $$ = driver.binop($1, $3, $2); free($2); }
	| expression EXP expression			{ $$ = driver.binop($1, $3, $2); free($2); }
	| LBRACKET expression RBRACKET		{ $$ = $2; }
	| UNOP LBRACKET expression RBRACKET	{ $$ = driver.unop($3, $1); free($1); }
	| number 							{ $$ = driver.constant($1); }
	| IDENTIFIER 						{ $$ = driver.variable($1); free($1); }
	;

%%

void Algebra::Parser::error(const location_type & l, const std::string & err_message)
{
	std::cerr << "Error: " << err_message << " at line " << l << "\n";
}
