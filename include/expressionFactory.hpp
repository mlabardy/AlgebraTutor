#ifndef EXPRESSION_FACTORY
#define EXPRESSION_FACTORY

#include <iostream>

#include "expression.hpp"
#include "unaryOperator.hpp"


namespace ExpressionFactory
{
	// UNARY OPERATORS
	Expression * constant(double);
	Expression * variable(std::string);
	Expression * variable(std::string, double);
	Expression * affect(Expression *, Expression *);
	Expression * cosinus(Expression *);
	Expression * sinus(Expression *);
	Expression * exponantial(Expression *, Expression *);

	// BINARY OPERATORS
	Expression * sum(Expression *, Expression *);
	Expression * difference(Expression *, Expression *);
	Expression * product(Expression *, Expression *);
	Expression * quotient(Expression *, Expression *);
}

#endif
