#ifndef BINARY_OPERATOR
#define BINARY_OPERATOR

#include <iostream>

#include "expression.hpp"
#include "operator.hpp"


class BinaryOperator 
{
public:
	static Expression * sum(Expression *, Expression *);
	static Expression * difference(Expression *, Expression *);
	static Expression * product(Expression *, Expression *);
	static Expression * quotient(Expression *, Expression *);

private:
	static const std::string display(Operator::Binary, Expression *, Expression *);
	static void free(Expression *, Expression *);
};

#endif
