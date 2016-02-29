#ifndef VARIABLE
#define VARIABLE

#include <iostream>

#include "expression.hpp"


class Variable: public Expression
{
public:
	Variable(const std::string &, double);

	Variable(const std::string &);

	~Variable();

	double eval();

	std::string display() const;

	void set(double value);

	static void deleteAll();

	friend std::ostream & operator << (std::ostream & os, const Variable & variable);

private:
	const std::string _id;

};

#endif
