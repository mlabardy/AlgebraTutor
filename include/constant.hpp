#ifndef CONSTANT
#define CONSTANT

#include <iostream>

#include "expression.hpp"


class Constant: public Expression
{
public:
	Constant(double);

	~Constant();

	double eval();

	std::string display() const;

	friend std::ostream & operator << (std::ostream & os, const Constant & constant);
	
private:
	const double _value;
};

#endif
