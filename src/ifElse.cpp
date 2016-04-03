#include <iostream>
#include <sstream>

#include "ifElse.hpp"
#include "expression.hpp"
#include "block.hpp"


IfElse::IfElse(Expression * comparator, Block * expressions, Block * otherExpressions): _comparator(comparator), _expressions(expressions), _otherExpressions(otherExpressions)
{}

IfElse::~IfElse()
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

double IfElse::eval()
{
	return -1;
}

std::string IfElse::display() const
{
	std::ostringstream stringOfValue;
	stringOfValue << "if (" <<  *_comparator << ")\n" << *_expressions << "\nelse\n" << *_otherExpressions;
	return stringOfValue.str();
}

std::ostream & operator << (std::ostream & os, const IfElse & ifElse)
{
	os << ifElse.display();
	return os;
}
