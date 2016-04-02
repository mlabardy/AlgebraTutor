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
int linenum = 0;
%}

%option debug
%option nodefault
%option yyclass="Algebra::Scanner"
%option noyywrap
%option c++

%%

[ \t]+ 		;

[\n]+ {
	++linenum;
	location->lines(linenum);
	return token::EOL; 
}

[0-9]+("."[0-9]*)* { 
	lval->doubleValue = atof(yytext); 
	return token::DOUBLE;
}

"(" { 
	return token::LBRACKET; 
}

")" { 
	return token::RBRACKET; 
}

"=="|"!="|"<="|">="|"<"|">" { 
	lval->stringValue = strdup(yytext); 
	return token::COMP; 
}

"+" { 
	lval->stringValue = strdup(yytext); 
	return token::ADD; 
}

"-" { 
	lval->stringValue = strdup(yytext); 
	return token::SUB; 
}

"^" {
	lval->stringValue = strdup(yytext); 
	return token::EXP; 
}

"*"|"/" { 
	lval->stringValue = strdup(yytext); 
	return token::BINOPMQ; 
}

"=" { 
	return token::EQUAL; 
}

"?" {
	return token::IM;
}

"!" {
	return token::EM;
}

":" {
	return token::OR;
}

"cos"|"sin"|"tan" { 
	lval->stringValue = strdup(yytext); 
	return token::UNOP;
}

"deleteAll" { 
	lval->stringValue = strdup(yytext); 
	return token::DEL;
}

[a-zA-Z]([a-zA-Z]|[0-9]|_)* { 
	lval->stringValue = strdup(yytext); 
	return token::IDENTIFIER; 
}

.          ;
%%


