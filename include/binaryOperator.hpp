#ifndef BINARY_OPERATOR
#define BINARY_OPERATOR

#include <iostream>

#include "expression.hpp"
#include "operator.hpp"


class BinaryOperator 
{
public:
	static Expression * sum(Expression * leftExpression, Expression * rightExpression);
	static Expression * difference(Expression * leftExpression, Expression * rightExpression);
	static Expression * product(Expression * leftExpression, Expression * rightExpression);
	static Expression * quotient(Expression * leftExpression, Expression * rightExpression);

private:
	static const std::string display(Operator::Binary binaryOperator, Expression * leftExpression, Expression * rightExpression);
};

#endif
