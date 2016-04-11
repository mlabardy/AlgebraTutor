#include "operatorFactory.hpp"
#include "expression.hpp"


OperatorFactory::OperatorFactory(DisplayCallback displayCallback, EvalCallback evalCallback, DeleteCallback deleteCallback, DerivationCallback derivationCallback, SimplificationCallback simplificationCallback) : _displayCallback(displayCallback), _evalCallback(evalCallback), _deleteCallback(deleteCallback), _derivationCallback(derivationCallback), _simplificationCallback(simplificationCallback)
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
