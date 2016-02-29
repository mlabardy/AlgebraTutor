#ifndef EXPRESSION_FACTORY
#define EXPRESSION_FACTORY

#include <iostream>

#include "expression.hpp"
#include "variable.hpp" 
#include "affectation.hpp"


namespace ExpressionFactory
{
	// UNARY OPERATORS
	Expression * constant(double);
	Variable * variable(const std::string &);
	Variable * variable(const std::string &, double);
	Affectation * affectation(Variable *, Expression *);
	Expression * cosinus(Expression *);
	Expression * sinus(Expression *);
	Expression * exponantial(Expression *, Expression *);

	// BINARY OPERATORS
	Expression * sum(Expression *, Expression *);
	Expression * difference(Expression *, Expression *);
	Expression * product(Expression *, Expression *);
	Expression * quotient(Expression *, Expression *);

	Expression * lessOrEqual(Expression *, Expression *);
	Expression * greaterOrEqual(Expression *, Expression *);
}

#endif
