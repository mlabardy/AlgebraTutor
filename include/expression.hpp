#ifndef EXPRESSION
#define EXPRESSION

#include <iostream>


class Expression 
{
public:
	typedef std::function<std::string(void)> DisplayCallback;
	typedef std::function<double(void)> EvalCallback;
	typedef std::function<void(void)> DeleteCallback;
	typedef std::function<std::string(void)> TypeCallback;

	Expression(DisplayCallback, EvalCallback, DeleteCallback, TypeCallback);

	~Expression();

	double eval();

	std::string type();

	std::string display() const;

	friend std::ostream & operator << (std::ostream & os, const Expression & expression);

private:
	DisplayCallback _displayCallback;
	EvalCallback _evalCallback;
	DeleteCallback _deleteCallback;
	TypeCallback _typeCallback;
	
};

#endif