#include <cstdio>
#include <iostream>

#include "conditional.hpp"
#include "expression.hpp"


Conditional::Conditional(Expression * comparator, Expression * expression, Expression * otherExpression): _comparator(comparator), _expression(expression), _otherExpression(otherExpression)
{}

Conditional::Conditional(const Conditional & conditional): _comparator(conditional._comparator), _expression(conditional._expression), _otherExpression(conditional._otherExpression)
{}

Conditional::~Conditional()
{}

double Conditional::eval()
{
	return (_comparator->eval()) ? _expression->eval() : _otherExpression->eval();
}

Expression * Conditional::derivation()
{
	return nullptr;
}

Expression * Conditional::simplification()
{
	return nullptr;
}

int Conditional::type()
{
	return 0;
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
