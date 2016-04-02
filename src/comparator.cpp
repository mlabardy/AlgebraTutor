#include <stdio.h>

#include "comparator.hpp"
#include "expression.hpp"
#include "operator.hpp"
#include "comparatorFactory.hpp"

using namespace Operator;


const std::string Comparator::display(Binary binaryOperator, Expression * leftExpression, Expression * rightExpression)
{
	// std::ostringstream stringOfValue;
	// stringOfValue << '(' << leftExpression->display() << ' ' << name(binaryOperator) << ' ' << rightExpression->display() << ')';
	// return stringOfValue.str();

	char buffer[100];
	snprintf(buffer, 100, "(%s %s %s)", leftExpression->display().c_str(), name(binaryOperator).c_str(), rightExpression->display().c_str());
	std::string str(buffer);
	return str;
}

void Comparator::free(Expression * leftExpression, Expression * rightExpression)
{
	if (leftExpression != nullptr)
	{
		delete leftExpression;
		leftExpression = nullptr;
	}

	if (rightExpression != nullptr)
	{
		delete rightExpression;
		rightExpression = nullptr;
	}
}

Comparator * Comparator::lessOrEqual(Expression * leftExpression, Expression * rightExpression)
{
	return new ComparatorFactory (
		[=] ()
		{
			return Comparator::display(LOE, leftExpression, rightExpression);
		},
		[=] ()
		{
			return (leftExpression->eval() <= rightExpression->eval()) ? 1.0 : 0.0;
		},
		[=] ()
		{
			// BinaryOperator::free(leftExpression, rightExpression);
		}
	);
}

Comparator * Comparator::greaterOrEqual(Expression * leftExpression, Expression * rightExpression)
{
	return new ComparatorFactory (
		[=] ()
		{
			return BinaryOperator::display(GOE, leftExpression, rightExpression);
		},
		[=] ()
		{
			return (leftExpression->eval() >= rightExpression->eval()) ? 1.0 : 0.0;
		},
		[=] ()
		{
			// BinaryOperator::free(leftExpression, rightExpression);
		}
	);
}
