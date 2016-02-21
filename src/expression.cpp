#include <iostream>

#include "expression.hpp"
#include "expressionFactory.hpp"


Expression::Expression(DisplayCallback displayCallback, EvalCallback evalCallback) : _displayCallback(displayCallback), _evalCallback(evalCallback) 
{}

Expression::~Expression() 
{}

double Expression::eval() 
{
	return _evalCallback();
}

std::string Expression::display() const
{
	return _displayCallback();
}

std::ostream & operator << (std::ostream & os, const Expression & expression) 
{
	os << expression.display();
	return os;
}
