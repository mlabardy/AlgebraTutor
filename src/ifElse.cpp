#include <iostream>
#include <sstream>

#include "ifElse.hpp"
#include "expression.hpp"
#include "block.hpp"


IfElse::IfElse(Expression * comparator, Block * expressions, Block * otherExpressions): _comparator(comparator), _expressions(expressions), _otherExpressions(otherExpressions)
{}

IfElse::IfElse(const IfElse & ie): _comparator(ie._comparator), _expressions(ie._expressions), _otherExpressions(ie._otherExpressions)
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
	if (_comparator->eval())
	{
		return _expressions->eval();
	}
	else
	{
		return _otherExpressions->eval();
	}

//	return -1;
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
