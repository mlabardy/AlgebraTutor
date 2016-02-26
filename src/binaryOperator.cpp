#include <sstream>

#include "binaryOperator.hpp"
#include "expression.hpp"
#include "operator.hpp"

using namespace Operator;


const std::string BinaryOperator::display(Binary binaryOperator, Expression * leftExpression, Expression * rightExpression)
{
	std::ostringstream stringOfValue;
	stringOfValue << '(' << leftExpression->display() << ' ' << name(binaryOperator) << ' ' << rightExpression->display() << ')';
	return stringOfValue.str();
}

void BinaryOperator::free(Expression * leftExpression, Expression * rightExpression) 
{
	if (leftExpression != NULL)
		delete leftExpression;
	if (rightExpression != NULL)
		delete rightExpression;
}

Expression * BinaryOperator::sum(Expression * leftExpression, Expression * rightExpression)
{
	return new Expression (
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
			BinaryOperator::free(leftExpression, rightExpression);
		},
		[=] ()
		{
			return "binary";
		}
	); 
}

Expression * BinaryOperator::difference(Expression * leftExpression, Expression * rightExpression)
{
	return new Expression (
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
			BinaryOperator::free(leftExpression, rightExpression);
		},
		[=] ()
		{
			return "binary";
		}
	);  
}

Expression * BinaryOperator::product(Expression * leftExpression, Expression * rightExpression)
{
	return new Expression (
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
			BinaryOperator::free(leftExpression, rightExpression);
		},
		[=] ()
		{
			return "binary";
		}
	);
}

Expression * BinaryOperator::quotient(Expression * leftExpression, Expression * rightExpression)
{
	return new Expression (
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
			BinaryOperator::free(leftExpression, rightExpression);
		},
		[=] ()
		{
			return "binary";
		}
	);
}


