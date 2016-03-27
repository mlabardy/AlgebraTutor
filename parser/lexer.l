%{
/* C++ string header, for string ops below */
#include <iostream>
#include <string>

/* Implementation of yyFlexScanner */ 
#include "scanner.hpp"
#undef  YY_DECL
#define YY_DECL int Algebra::Scanner::yylex(Algebra::Parser::semantic_type * const lval, Algebra::Parser::location_type * location)

/* typedef to make the returns for the tokens shorter */
typedef Algebra::Parser::token token;

/* define to keep from re-typing the same code over and over */
#define STOKEN( x ) ( new std::string( x ) )

/* define yyterminate as this instead of NULL */
#define yyterminate() return( token::END )

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

/* update location on matching */
#define YY_USER_ACTION location->step(); location->columns(yyleng);

%}

%option debug
%option nodefault
%option yyclass="Algebra::Scanner"
%option noyywrap
%option c++

%%
%{  // Code executed at the beginning of yylex
	//yylval = lval;
%}

[ \t\r]+ 		;

\n 				{ printf("%s\n", "end of line"); }

[0-9]+"."[0-9]* { lval->doubleValue = atof(yytext); return token::DOUBLE; }

"(" 		 	{ lval->stringValue = strdup(yytext); return token::LBRACKET; }

")" 		 	{ lval->stringValue = strdup(yytext); return token::RBRACKET; }

"cos"|"sin"|"tan"	{ lval->stringValue = strdup(yytext); return token::UNOP; }

"+"|"-"|"*"|"/" 	{ lval->stringValue = strdup(yytext); return token::BINOP; }

"="				 	{ lval->stringValue = strdup(yytext); return token::EQUAL; }

[a-zA-Z]+		{ lval->stringValue = strdup(yytext); return token::IDENTIFIER; }

.           ;
%%


