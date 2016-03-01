#include <iostream>
#include <map>

#include "variable.hpp"
#include "expression.hpp"
#include "debugger.hpp"


std::map<std::string, double> _variables;

Variable::Variable(const std::string & id, double value = 0): _id(id)
{
	if (_variables.find(_id) == _variables.end())
	{
		_variables[_id] = value;
	}
}

Variable::Variable(const std::string & id): _id(id)
{
	if (_variables.find(_id) == _variables.end())
	{
		_variables[_id] = 0;
	}
}

Variable::~Variable()
{}

double Variable::eval()
{
	return _variables[_id];
}

std::string Variable::display() const
{
	return _id;
}

void Variable::set(double value)
{
	_variables[_id] = value;
}

void Variable::deleteAll()
{
	_variables.clear();
}

std::ostream & operator << (std::ostream & os, const Variable & variable)
{
	os << variable.display();
	return os;
}
