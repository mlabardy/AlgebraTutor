#ifndef OPERATOR_FACTORY
#define OPERATOR_FACTORY

#include <iostream>

#include "expression.hpp"


class OperatorFactory: public Expression
{
public:
	typedef std::function<std::string(void)> DisplayCallback;
	typedef std::function<double(void)> EvalCallback;
	typedef std::function<void(void)> DeleteCallback;

	OperatorFactory(DisplayCallback, EvalCallback, DeleteCallback);

	~OperatorFactory();

	double eval();

	std::string display() const;

private:
	DisplayCallback _displayCallback;
	EvalCallback _evalCallback;
	DeleteCallback _deleteCallback;

};



#endif
