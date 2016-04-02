#include <cstdio>
#include <iostream>

#include "conditional.hpp"
#include "expression.hpp"
#include "comparator.hpp"


Conditional::Conditional(Expression * comparator, Expression * expression, Expression * otherExpression): _comparator(comparator), _expression(expression), _otherExpression(otherExpression)
{}

Conditional::~Conditional()
{
	/*if (_comparator != nullptr)
	{
		delete _comparator;
	}
	if (_expression != nullptr)
	{
		delete _expression;
	}
	if (_otherExpression != nullptr)
	{
		delete _otherExpression;
	}*/
}

double Conditional::eval()
{
	return (_comparator->eval()) ? _expression->eval() : _otherExpression->eval();
}

std::string Conditional::display() const
{
	char buffer[100];
	snprintf(buffer, 100, "%s ? %s : %s", _comparator->display().c_str(), _expression->display().c_str(), _otherExpression->display().c_str());
	std::string str(buffer);
	return str;
}

std::ostream & operator << (std::ostream & os, const Conditional & conditional)
{
	os << conditional.display();
	return os;
}
