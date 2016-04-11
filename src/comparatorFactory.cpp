#include <iostream>

#include "comparatorFactory.hpp"
#include "expression.hpp"


ComparatorFactory::ComparatorFactory(DisplayCallback displayCallback, EvalCallback evalCallback, DeleteCallback deleteCallback, DerivationCallback derivationCallback, SimplificationCallback simplificationCallback) : _isNegation(false), _displayCallback(displayCallback), _evalCallback(evalCallback), _deleteCallback(deleteCallback), _derivationCallback(derivationCallback), _simplificationCallback(simplificationCallback)
{}

ComparatorFactory::~ComparatorFactory()
{
	_deleteCallback();
}

void ComparatorFactory::isNegation()
{
	_isNegation = true;
}

double ComparatorFactory::eval()
{
	if (_isNegation)
	{
		return ((int)_evalCallback() + 1) % 2;
	}
	return _evalCallback();
}

std::string ComparatorFactory::display() const
{
	if (_isNegation)
	{
		return std::string("!").append(_displayCallback());
	}
	return _displayCallback();
}

Expression * ComparatorFactory::derivation()
{
	return _derivationCallback();
}

Expression * ComparatorFactory::simplification()
{
	return _simplificationCallback();
}
