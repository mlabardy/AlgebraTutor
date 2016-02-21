#ifndef EXPRESSION_FACTORY
#define EXPRESSION_FACTORY

#include "expression.hpp"
#include "unaryOperator.hpp"


namespace ExpressionFactory
{
	Expression * constant(double value);
	Expression * cosinus(Expression * expression);
	Expression * sinus(Expression * expression);
	Expression * exponantial(Expression * expression, Expression * power);

	Expression * sum(Expression * leftExpression, Expression * rightExpression);
	Expression * difference(Expression * leftExpression, Expression * rightExpression);
	Expression * product(Expression * leftExpression, Expression * rightExpression);
	Expression * quotient(Expression * leftExpression, Expression * rightExpression);
}

#endif
