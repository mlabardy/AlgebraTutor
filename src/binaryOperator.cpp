#include <stdio.h>

#include "binaryOperator.hpp"
#include "expression.hpp"
#include "operator.hpp"
#include "operatorFactory.hpp"
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

Expression * BinaryOperator::lessOrEqual(Expression * leftExpression, Expression * rightExpression)
{
	return new OperatorFactory (
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

Expression * BinaryOperator::greaterOrEqual(Expression * leftExpression, Expression * rightExpression)
{
	return new OperatorFactory (
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
