#ifndef EXPRESSION
#define EXPRESSION

#include <iostream>


class Expression
{
public:
	Expression();

	virtual ~Expression();

	virtual double eval() = 0;

	virtual std::string display() const = 0;

	static void deleteAll();

	friend std::ostream & operator << (std::ostream & os, const Expression & expression);

};

#endif