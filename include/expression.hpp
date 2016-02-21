#ifndef EXPRESSION
#define EXPRESSION

#include <iostream>


class Expression 
{
public:
	typedef std::function<std::string(void)> DisplayCallback;
	typedef std::function<double(void)> EvalCallback;

	Expression(DisplayCallback displayCallback, EvalCallback evalCallback);

	virtual ~Expression();

	double eval();

	std::string display() const;

	friend std::ostream & operator << (std::ostream & os, const Expression & expression);

private:
	DisplayCallback _displayCallback;
	EvalCallback _evalCallback;
	
};

#endif