#include <iostream>
#include <cmath>
#include <sstream>

#include "unaryOperator.hpp"
#include "expression.hpp"
#include "operator.hpp"

using namespace Operator;


const std::string UnaryOperator::display(Unary unaryOperator, Expression * expression)
{
	std::ostringstream stringOfValue;
	stringOfValue << name(unaryOperator) << '(' << expression->display() << ')';
	return stringOfValue.str(); 
}

Expression * UnaryOperator::cosinus(Expression * expression)
{
	return new Expression (
		[=] () 
		{ 
			return UnaryOperator::display(COS, expression);
		},
		[=] () 
		{ 
			return cos(expression->eval()); 
		}
	);	
}

Expression * UnaryOperator::sinus(Expression * expression)
{
	return new Expression (
		[=] () 
		{ 
			return UnaryOperator::display(SIN, expression); 
		},
		[=] () 
		{ 
			return sin(expression->eval()); 
		}
	);	
}

Expression * UnaryOperator::exponantial(Expression * expression, Expression * power)
{
	return new Expression (
		[=] () 
		{ 
			std::ostringstream stringOfValue;
			stringOfValue << expression->display() <<  ' ' << name(Operator::EXP) << ' ' << power->display();
			return stringOfValue.str(); 
		},
		[=] () 
		{ 
			return pow(expression->eval(), power->eval()); 
		}
	);	
}
