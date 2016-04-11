#include <iostream>
#include <map>

#include "variable.hpp"
#include "expression.hpp"
#include "debugger.hpp"
#include "constant.hpp"


std::map<std::string, double> Variable::_variables;

Variable::Variable(const std::string & id, double value = 0): _id(id), _previousValue(0)
{
	if (Variable::_variables.find(_id) == Variable::_variables.end())
	{
		Variable::_variables[_id] = value;
	}
}

Variable::Variable(const std::string & id): _id(id), _previousValue(0)
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
	_previousValue = Variable::_variables[_id];
	Variable::_variables[_id] = value->eval();
}

void Variable::set(double value)
{
	_previousValue = Variable::_variables[_id];
	Variable::_variables[_id] = value;
}

void Variable::rollback()
{
	Variable::_variables[_id] = _previousValue;
}

Expression * Variable::derivation()
{
	//std::string newId(_id);
	//newId.append("'");
	return new Variable(_id, Variable::_variables[_id]);
}

Expression * Variable::simplification()
{
	return nullptr;
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
