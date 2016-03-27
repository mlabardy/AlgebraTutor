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
%token EOL	 	 	"end of line"

%token<doubleValue> DOUBLE
%token<stringValue> BINOP 
%token<stringValue> IDENTIFIER
%token<stringValue> UNOP
%token<stringValue> EQUAL

%token<stringValue> LBRACKET
%token<stringValue> RBRACKET

%type<exprValue> expression
%type<exprValue> prog

%locations

%start prog

%%

prog
   : expression prog            { $$ = $2; }
   | expression                 { $$ = $1; }
   ;

expression
	: DOUBLE 									{ $$ = driver.constant($1); }
	| UNOP LBRACKET expression RBRACKET			{ $$ = driver.unop($3, $1); }
	| expression BINOP expression				{ $$ = driver.binop($1, $3, $2); }
	| "delete"									{ driver.deleteAll(); }
	;
	

%%


void Algebra::Parser::error(const location_type & l, const std::string & err_message)
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}
