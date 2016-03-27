#include "expressionFactory.hpp"
#include "expression.hpp"
#include "constant.hpp"
#include "variable.hpp"
#include "affectation.hpp"
#include "unaryOperator.hpp"
#include "binaryOperator.hpp"


namespace ExpressionFactory 
{
	Expression * constant(double value)
	{
		return new Constant(value);
	}

	Variable * variable(const std::string & id)
	{
		return new Variable(id);
	}

	Variable * variable(const std::string & id, double value)
	{
		return new Variable(id, value);
	}

	Affectation * affectation(Variable * variable, Expression * value)
	{
		return new Affectation(variable, value);	
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

	Expression * lessOrEqual(Expression * leftExpression, Expression * rightExpression)
	{
		return BinaryOperator::lessOrEqual(leftExpression, rightExpression);
	}

	Expression * greaterOrEqual(Expression * leftExpression, Expression * rightExpression)
	{
		return BinaryOperator::greaterOrEqual(leftExpression, rightExpression);
	}
}
