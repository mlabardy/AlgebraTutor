#include "expressionFactory.hpp"
#include "expression.hpp"
#include "constant.hpp"
#include "variable.hpp"
#include "affectation.hpp"
#include "unaryOperator.hpp"
#include "binaryOperator.hpp"
#include "conditional.hpp"
#include "comparatorFactory.hpp"


namespace ExpressionFactory 
{
	Expression * constant(double value)
	{
		return new Constant(value);
	}

	Variable * variable(const std::string & id, double value)
	{
		return new Variable(id, value);
	}

	Variable * variable(const std::string & id)
	{
		return new Variable(id);
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

	ComparatorFactory * lessOrEqual(Expression * leftExpression, Expression * rightExpression)
	{
		return BinaryOperator::lessOrEqual(leftExpression, rightExpression);
	}

	ComparatorFactory * greaterOrEqual(Expression * leftExpression, Expression * rightExpression)
	{
		return BinaryOperator::greaterOrEqual(leftExpression, rightExpression);
	}

	ComparatorFactory * greaterThan(Expression * leftExpression, Expression * rightExpression)
	{
		return BinaryOperator::greater(leftExpression, rightExpression);
	}

	ComparatorFactory * lessThan(Expression * leftExpression, Expression * rightExpression)
	{
		return BinaryOperator::less(leftExpression, rightExpression);
	}

	ComparatorFactory * equal(Expression * leftExpression, Expression * rightExpression)
	{
		return BinaryOperator::equal(leftExpression, rightExpression);
	}

	ComparatorFactory * different(Expression * leftExpression, Expression * rightExpression)
	{
		return BinaryOperator::different(leftExpression, rightExpression);
	}

	Expression * ternary(Expression * comparator, Expression * expression, Expression * otherExpression)
	{
		return new Conditional(comparator, expression, otherExpression);
	}

	Affectation * sumAffectation(Variable * variable, Expression * expression)
	{
		return BinaryOperator::sumAffectation(variable, expression);
	}

	Affectation * differenceAffectation(Variable * variable, Expression * expression)
	{
		return BinaryOperator::differenceAffectation(variable, expression);
	}

	Affectation * productAffectation(Variable * variable, Expression * expression)
	{
		return BinaryOperator::productAffectation(variable, expression);
	}

	Affectation * quotientAffectation(Variable * variable, Expression * expression)
	{
		return BinaryOperator::quotientAffectation(variable, expression);
	}
}
