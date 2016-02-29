#ifndef UNARY_OPERATOR
#define UNARY_OPERATOR

#include <iostream>

#include "expression.hpp"
#include "operator.hpp"


class UnaryOperator
{
public:
	static Expression * cosinus(Expression *);
	static Expression * sinus(Expression *);
	static Expression * exponantial(Expression *, Expression *);

private:
	static const std::string display(Operator::Unary, Expression *);
	static void free(Expression * expression);
};

#endif
