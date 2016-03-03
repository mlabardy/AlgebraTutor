#include <iostream>

#include "comparatorFactory.hpp"
#include "expression.hpp"


ComparatorFactory::ComparatorFactory(DisplayCallback displayCallback, EvalCallback evalCallback, DeleteCallback deleteCallback) : _displayCallback(displayCallback), _evalCallback(evalCallback), _deleteCallback(deleteCallback)
{}

ComparatorFactory::~ComparatorFactory()
{
	_deleteCallback();
}

double ComparatorFactory::eval()
{
	return _evalCallback();
}

std::string ComparatorFactory::display() const
{
	return _displayCallback();
}

