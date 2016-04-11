#include <iostream>
#include <sstream>

#include "ifElse.hpp"
#include "expression.hpp"
#include "block.hpp"


IfElse::IfElse(Expression * comparator, Block * expressions, Block * otherExpressions): _comparator(comparator), _expressions(expressions), _otherExpressions(otherExpressions)
{
	_expressions->rollback();
	_otherExpressions->rollback();
}

IfElse::IfElse(const IfElse & ie): _comparator(ie._comparator), _expressions(ie._expressions), _otherExpressions(ie._otherExpressions)
{
	_expressions->rollback();
	_otherExpressions->rollback();
}

IfElse::~IfElse()
{}

double IfElse::eval()
{
	if (_comparator->eval())
	{
		_expressions->execute();
	}
	else
	{
		_otherExpressions->execute();
	}
	return -1;
}

Expression * IfElse::derivation()
{
	return nullptr;
}


Expression * IfElse::simplification()
{
	return nullptr;
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
