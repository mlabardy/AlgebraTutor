#include <stdio.h>

#include "binaryOperator.hpp"
#include "expression.hpp"
#include "operator.hpp"
#include "operatorFactory.hpp"
#include "comparatorFactory.hpp"
#include "variable.hpp"
#include "affectation.hpp"
#include "debugger.hpp"

using namespace Operator;


const std::string BinaryOperator::display(Binary binaryOperator, Expression * leftExpression, Expression * rightExpression)
{ 
	// std::ostringstream stringOfValue;
	// stringOfValue << '(' << leftExpression->display() << ' ' << name(binaryOperator) << ' ' << rightExpression->display() << ')';
	// return stringOfValue.str();

	char buffer[100];
	snprintf(buffer, 100, "(%s %s %s)", leftExpression->display().c_str(), name(binaryOperator).c_str(), rightExpression->display().c_str());
	std::string str(buffer);
	return str;
}

void BinaryOperator::free(Expression * leftExpression, Expression * rightExpression) 
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

Expression * BinaryOperator::sum(Expression * leftExpression, Expression * rightExpression)
{
	return new OperatorFactory (
		[=] () 
		{ 
			return BinaryOperator::display(ADD, leftExpression, rightExpression);
		},
		[=] () 
		{ 
			return leftExpression->eval() + rightExpression->eval(); 
		},
		[=] () 
		{ 
			// BinaryOperator::free(leftExpression, rightExpression);
		}
	); 
}

Expression * BinaryOperator::difference(Expression * leftExpression, Expression * rightExpression)
{
	return new OperatorFactory (
		[=] () 
		{ 
			return BinaryOperator::display(SUB, leftExpression, rightExpression);
		},
		[=] () 
		{ 
			return leftExpression->eval() - rightExpression->eval(); 
		},
		[=] () 
		{ 
			// BinaryOperator::free(leftExpression, rightExpression);
		}
	);  
}

Expression * BinaryOperator::product(Expression * leftExpression, Expression * rightExpression)
{
	return new OperatorFactory (
		[=] () 
		{ 
			return BinaryOperator::display(MUL, leftExpression, rightExpression); 
		},
		[=] () 
		{ 
			return leftExpression->eval() * rightExpression->eval(); 
		},
		[=] () 
		{ 
			// BinaryOperator::free(leftExpression, rightExpression);
		}
	);
}

Expression * BinaryOperator::quotient(Expression * leftExpression, Expression * rightExpression)
{
	return new OperatorFactory (
		[=] () 
		{ 
			return BinaryOperator::display(DIV, leftExpression, rightExpression);
		},
		[=] () 
		{ 
			return leftExpression->eval() / rightExpression->eval(); 
		},
		[=] () 
		{ 
			// BinaryOperator::free(leftExpression, rightExpression);
		}
	);
}

ComparatorFactory * BinaryOperator::lessOrEqual(Expression * leftExpression, Expression * rightExpression)
{
	return new ComparatorFactory (
		[=] () 
		{ 
			return BinaryOperator::display(LOE, leftExpression, rightExpression);
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

ComparatorFactory * BinaryOperator::greaterOrEqual(Expression * leftExpression, Expression * rightExpression)
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

ComparatorFactory * BinaryOperator::greater(Expression * leftExpression, Expression * rightExpression)
{
	return new ComparatorFactory (
		[=] ()
		{
			return BinaryOperator::display(GT, leftExpression, rightExpression);
		},
		[=] ()
		{
			return (leftExpression->eval() > rightExpression->eval()) ? 1.0 : 0.0;
		},
		[=] ()
		{
			// BinaryOperator::free(leftExpression, rightExpression);
		}
	);
}

ComparatorFactory * BinaryOperator::less(Expression * leftExpression, Expression * rightExpression)
{
	return new ComparatorFactory (
		[=] ()
		{
			return BinaryOperator::display(LT, leftExpression, rightExpression);
		},
		[=] ()
		{
			return (leftExpression->eval() < rightExpression->eval()) ? 1.0 : 0.0;
		},
		[=] ()
		{
			// BinaryOperator::free(leftExpression, rightExpression);
		}
	);
}

ComparatorFactory * BinaryOperator::equal(Expression * leftExpression, Expression * rightExpression)
{
	return new ComparatorFactory (
		[=] ()
		{
			return BinaryOperator::display(EQ, leftExpression, rightExpression);
		},
		[=] ()
		{
			return (leftExpression->eval() == rightExpression->eval()) ? 1.0 : 0.0;
		},
		[=] ()
		{
			// BinaryOperator::free(leftExpression, rightExpression);
		}
	);
}

ComparatorFactory * BinaryOperator::different(Expression * leftExpression, Expression * rightExpression)
{
	return new ComparatorFactory (
		[=] ()
		{
			return BinaryOperator::display(DIF, leftExpression, rightExpression);
		},
		[=] ()
		{
			return (leftExpression->eval() != rightExpression->eval()) ? 1.0 : 0.0;
		},
		[=] ()
		{
			// BinaryOperator::free(leftExpression, rightExpression);
		}
	);
}

Affectation * BinaryOperator::sumAffectation(Variable * variable, Expression * expression)
{
	return new Affectation(variable, sum(variable, expression));
}

Affectation * BinaryOperator::differenceAffectation(Variable * variable, Expression * expression)
{
	return new Affectation(variable, difference(variable, expression));
}

Affectation * BinaryOperator::productAffectation(Variable * variable, Expression * expression)
{
	return new Affectation(variable, product(variable, expression));
}

Affectation * BinaryOperator::quotientAffectation(Variable * variable, Expression * expression)
{
	return new Affectation(variable, quotient(variable, expression));
}
