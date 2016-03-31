%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {Algebra}
%define parser_class_name {Parser}
%expect 2 // on supprime les warnings concernants le signe d'un nombre

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
	#include "../include/expression.hpp"

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

%token<stringValue> LBRACKET
%token<stringValue> RBRACKET

%type<exprValue> expression
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
	: IDENTIFIER EQUAL number { driver.variable($3, $1); free($1); }
	;

expression
	: expression ADD expression			{ $$ = driver.binop($1, $3, $2); free($2); }
	| expression SUB expression			{ $$ = driver.binop($1, $3, $2); free($2); }
	| expression COMP expression		{ $$ = driver.binop($1, $3, $2); free($2); }
	| expression BINOPMQ expression		{ $$ = driver.binop($1, $3, $2); free($2); }
	| expression EXP expression			{ $$ = driver.binop($1, $3, $2); free($2); }
	| LBRACKET expression RBRACKET		{ $$ = $2; }
	| UNOP LBRACKET expression RBRACKET	{ $$ = driver.unop($3, $1); free($1); }
	| number 							{ $$ = driver.constant($1); }
	;

%%

void Algebra::Parser::error(const location_type & l, const std::string & err_message)
{
	std::cerr << "Error: " << err_message << " at " << l << "\n";
}
