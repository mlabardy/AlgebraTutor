#include <iostream>

#include "operatorFactory.hpp"
#include "expression.hpp"


OperatorFactory::OperatorFactory(DisplayCallback displayCallback, EvalCallback evalCallback, DeleteCallback deleteCallback) : _displayCallback(displayCallback), _evalCallback(evalCallback), _deleteCallback(deleteCallback)
{}

OperatorFactory::~OperatorFactory() 
{
	_deleteCallback();
}

double OperatorFactory::eval() 
{
	return _evalCallback();
}

std::string OperatorFactory::display() const
{
	return _displayCallback();
}
