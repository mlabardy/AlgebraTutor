%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {Algebra}
%define parser_class_name {Parser}
%expect 8 // on supprime les warnings concernants le signe d'un nombre

%code requires{
   namespace Algebra {
      class Driver;
      class Scanner;
   }
   class Expression;

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
   
	#include "driver.hpp"
	#include "../include/variable.hpp"
	#include "../include/expression.hpp"
	#include "../include/comparatorFactory.hpp"

	#undef yylex
	#define yylex scanner.yylex
}

%define parse.assert

%union
{
	char * stringValue;
	double doubleValue;
	Expression * exprValue;
}

%token END     0   	"end of file"
%token EOL

%token<doubleValue> DOUBLE
%token<stringValue> IDENTIFIER
%token<stringValue> UNOP
%token<stringValue> EQUAL
%token<stringValue> COMMA
%token<stringValue> DEL
%token<stringValue> IM
%token<stringValue> OR
%token<stringValue> EM

%token<stringValue> LBRACKET
%token<stringValue> RBRACKET

%type<exprValue> expression
%type<exprValue> conditional
%type<exprValue> ternary
%type<doubleValue> number

%left<stringValue> COMP
%left<stringValue> ADD SUB
%left<stringValue> BINOPMQ
%left MINUS PLUS


%right<stringValue> EXP

%%

prog
	: prog line		{ ; }
	| line 			{ ; }
   	;

line
	: EOL			{ ; }
	| expression 	{ ; }
	| affectations 	{ ; }
	| DEL 			{ free($1); }
	| IDENTIFIER 	{ printf("new exercise\n"); free($1); }
	;

number
	: SUB DOUBLE %prec MINUS 	{ $$ = -$2; free($1); }
	| ADD DOUBLE %prec PLUS 	{ $$ = $2; free($1); }
	| DOUBLE 					{ $$ = $1; }
	;
	
affectations
	: affectation COMMA affectations  	{ ; }
	| affectation						{ ; }
	;

affectation
	: IDENTIFIER EQUAL expression 	{ 
		Variable * val = driver.variable(0, $1); 
		val->set($3);
		free($1); 
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

ternary
	: LBRACKET conditional RBRACKET IM expression OR expression { 
		$$ = driver.ternary($2, $5, $7);
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
	| ternary 							{ ; }
	;

%%

void Algebra::Parser::error(const location_type & l, const std::string & err_message)
{
	std::cerr << "Error: " << err_message << " at " << l << "\n";
}
