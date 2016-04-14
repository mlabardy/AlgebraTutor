#include <stdio.h>
#include <iostream>
#include <cmath>
#include <sstream>

#include "unaryOperator.hpp"
#include "binaryOperator.hpp"
#include "expression.hpp"
#include "operator.hpp"
#include "operatorFactory.hpp"
#include "constant.hpp"

using namespace Operator;


const std::string UnaryOperator::display(Unary unaryOperator, Expression * expression)
{
	std::ostringstream stringOfValue;
	stringOfValue << name(unaryOperator) << '(' << expression->display() << ')';
	return stringOfValue.str();
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
		{},
		[=] ()
		{
			Expression * expr = BinaryOperator::product(new Constant(-1), BinaryOperator::product(expression->derivation(), sinus(expression)));
			return expr;
		},
		[=] ()
		{
			return cosinus(expression);
		},
		[=] ()
		{
			return 3;
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
		{},
		[=] ()
		{
			Expression * expr = BinaryOperator::product(expression->derivation(), cosinus(expression));
			return expr;
		},
		[=] ()
		{
			return sinus(expression);
		},
		[=] ()
		{
			return 4;
		}
	);	
}

Expression * UnaryOperator::exponantial(Expression * expression, Expression * power)
{
	return new OperatorFactory (
		[=] () 
		{ 
			std::ostringstream stringOfValue;
			stringOfValue << expression->display() <<  ' ' << name(Operator::EXP) << ' ' << power->display();
			return stringOfValue.str();
		},
		[=] () 
		{ 
			return pow(expression->eval(), power->eval()); 
		},
		[=] () 
		{},
		[=] ()
		{
			Expression * expr = BinaryOperator::product(power, exponantial(expression, BinaryOperator::difference(power, new Constant(1))));
			return expr;
		},
		[=] ()
		{
			return exponantial(expression, power);
		},
		[=] ()
		{
			return 0;
		}
	);	
}
