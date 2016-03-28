#include <stdio.h>
#include <iostream>
#include <cmath>
// #include <sstream>

#include "unaryOperator.hpp"
#include "expression.hpp"
#include "operator.hpp"
#include "operatorFactory.hpp"

using namespace Operator;


const std::string UnaryOperator::display(Unary unaryOperator, Expression * expression)
{
	// std::ostringstream stringOfValue;
	// stringOfValue << name(unaryOperator) << '(' << expression->display() << ')';
	// return stringOfValue.str(); 

	char buffer[100];
	snprintf(buffer, 100, "%s(%s)", name(unaryOperator).c_str(), expression->display().c_str());
	std::string str(buffer);
	return str;
}

void UnaryOperator::free(Expression * expression) 
{
	if (expression != nullptr)
	{
		delete expression;
		expression = nullptr;
	}
}

Expression * UnaryOperator::cosinus(Expression * expression)
{
	return new OperatorFactory (
		[=] () 
		{ 
			return UnaryOperator::display(COS, expression);
		},
		[=] () 
		{ 
			return cos(expression->eval()); 
		},
		[=] () 
		{ 
			// UnaryOperator::free(expression);
		}
	);	
}

Expression * UnaryOperator::sinus(Expression * expression)
{
	return new OperatorFactory (
		[=] () 
		{ 
			return UnaryOperator::display(SIN, expression); 
		},
		[=] () 
		{ 
			return sin(expression->eval()); 
		},
		[=] () 
		{ 
			// UnaryOperator::free(expression);
		}
	);	
}

Expression * UnaryOperator::exponantial(Expression * expression, Expression * power)
{
	return new OperatorFactory (
		[=] () 
		{ 
			// std::ostringstream stringOfValue;
			// stringOfValue << expression->display() <<  ' ' << name(Operator::EXP) << ' ' << power->display();
			// return stringOfValue.str(); 
			char buffer[100];
			snprintf(buffer, 100, "(%s %s %s)", expression->display().c_str(), name(Operator::EXP).c_str(), power->display().c_str());
			std::string str(buffer);
			return str;
		},
		[=] () 
		{ 
			return pow(expression->eval(), power->eval()); 
		},
		[=] () 
		{ 
			// UnaryOperator::free(expression);
			// UnaryOperator::free(power);
		}
	);	
}
