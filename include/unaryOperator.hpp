#ifndef UNARY_OPERATOR
#define UNARY_OPERATOR

#include <iostream>

#include "expression.hpp"
#include "operator.hpp"


class UnaryOperator
{
public:
	static Expression * cosinus(Expression * expression);
	static Expression * sinus(Expression * expression);
	static Expression * exponantial(Expression * expression, Expression * power);

private:
	static const std::string display(Operator::Unary unaryOperator, Expression * expression);
};

#endif
