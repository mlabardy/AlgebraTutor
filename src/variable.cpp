#include <iostream>
#include <map>

#include "variable.hpp"
#include "expression.hpp"
#include "debugger.hpp"


std::map<std::string, double> Variable::_variables;

Variable::Variable(const std::string & id, double value = 0): _id(id)
{
	if (Variable::_variables.find(_id) == Variable::_variables.end())
	{
		Variable::_variables[_id] = value;
	}
}

Variable::Variable(const std::string & id): _id(id)
{
	if (Variable::_variables.find(_id) == Variable::_variables.end())
	{
		Variable::_variables[_id] = 0;
	}
}

Variable::~Variable()
{}

double Variable::eval()
{
	return Variable::_variables[_id];
}

std::string Variable::display() const
{
	return _id;
}

void Variable::set(Expression * value)
{
	Variable::_variables[_id] = value->eval();
}

void Variable::set(double value)
{
	Variable::_variables[_id] = value;
}

void Variable::deleteAll()
{
	Variable::_variables.clear();
}

std::ostream & operator << (std::ostream & os, const Variable & variable)
{
	os << variable.display();
	return os;
}
