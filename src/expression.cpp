#include <iostream>

#include "expression.hpp"
#include "expressionFactory.hpp"


Expression::Expression()
{}

Expression::Expression(DisplayCallback displayCallback, EvalCallback evalCallback, DeleteCallback deleteCallback, TypeCallback typeCallback) : _displayCallback(displayCallback), _evalCallback(evalCallback), _deleteCallback(deleteCallback), _typeCallback(typeCallback) 
{}

Expression::~Expression() 
{
	_deleteCallback();
}

double Expression::eval() 
{
	return _evalCallback();
}

std::string Expression::display() const
{
	return _displayCallback();
}

std::string Expression::type() 
{
	return _typeCallback();
}

std::ostream & operator << (std::ostream & os, const Expression & expression) 
{
	os << expression.display();
	return os;
}
