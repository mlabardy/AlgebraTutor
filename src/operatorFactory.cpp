#include "operatorFactory.hpp"
#include "expression.hpp"


OperatorFactory::OperatorFactory(DisplayCallback displayCallback, EvalCallback evalCallback, DeleteCallback deleteCallback, DerivationCallback derivationCallback, SimplificationCallback simplificationCallback, TypeCallback typeCallback) : _displayCallback(displayCallback), _evalCallback(evalCallback), _deleteCallback(deleteCallback), _derivationCallback(derivationCallback), _simplificationCallback(simplificationCallback), _typeCallback(typeCallback)
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

Expression * OperatorFactory::derivation()
{
	return _derivationCallback();
}

Expression * OperatorFactory::simplification()
{
	return _simplificationCallback();
}

int OperatorFactory::type()
{
	return _typeCallback();
}
