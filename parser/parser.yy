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
   
   #include "driver.hpp"

   #undef yylex
   #define yylex scanner.yylex
}

%define parse.assert

%union
{
	char * stringValue;
	double doubleValue;
}


%token END    0   "end of file"
%token EOL			"end of line"
%token<doubleValue> DOUBLE
%token<stringValue> OP 
%token<stringValue> IDENTIFIER


%type<doubleValue> expression 
%type<doubleValue> prog

%locations

%start prog

%%

prog
   : expression prog             { $$=$2; }
   | expression                  { $$=$1; }
   ;

expression
	: DOUBLE 				         { driver.get($1); $$=$1; }
	| expression OP expression 	{ driver.operation($1, $3, $2); $$=$1+$3;}
	;

%%


void 
Algebra::Parser::error(const location_type & l, const std::string & err_message)
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}
