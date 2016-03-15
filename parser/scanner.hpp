#ifndef SCANNER
#define SCANNER


#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include <iostream>

#include "parser.h"
#include "location.hh"


namespace Algebra {

class Scanner : public yyFlexLexer
{
public:
	using yyFlexLexer::yylex;
	Scanner(std::istream *in) : yyFlexLexer(in)
	{};

	~Scanner() 
	{};

	int yylex(Algebra::Parser::semantic_type * const lval, Algebra::Parser::location_type * location);
	// YY_DECL defined in mc_lexer.l
	// Method body created by flex in mc_lexer.yy.cc
};
}

#endif