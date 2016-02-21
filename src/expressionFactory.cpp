#include <iostream>
#include <cmath>
#include <sstream>

#include "expressionFactory.hpp"
#include "expression.hpp"
#include "constant.hpp"
#include "unaryOperator.hpp"
#include "binaryOperator.hpp"


namespace ExpressionFactory 
{
	Expression * constant(double value)
	{
		return Constant::constant(value);	
	}

	Expression * cosinus(Expression * expression)
	{
		return UnaryOperator::cosinus(expression);
	}

	Expression * sinus(Expression * expression)
	{
		return UnaryOperator::sinus(expression);
	}

	Expression * exponantial(Expression * expression, Expression * power)
	{
		return UnaryOperator::exponantial(expression, power);	
	}

	Expression * sum(Expression * leftExpression, Expression * rightExpression)
	{
		return BinaryOperator::sum(leftExpression, rightExpression); 
	}

	Expression * difference(Expression * leftExpression, Expression * rightExpression)
	{
		return BinaryOperator::difference(leftExpression, rightExpression);  
	}

	Expression * product(Expression * leftExpression, Expression * rightExpression)
	{
		return BinaryOperator::product(leftExpression, rightExpression);
	}

	Expression * quotient(Expression * leftExpression, Expression * rightExpression)
	{
		return BinaryOperator::quotient(leftExpression, rightExpression);
	}
}
