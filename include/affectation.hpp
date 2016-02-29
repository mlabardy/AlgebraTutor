#ifndef AFFECTATION
#define AFFECTATION

#include <iostream>

#include "expression.hpp"
#include "variable.hpp"


class Affectation: public Expression
{
public:
	Affectation(Variable *, Expression *);

	~Affectation();

	double eval();

	std::string display() const;

	friend std::ostream & operator << (std::ostream & os, const Affectation & affectation);

private:
	Variable * _variable;

	Expression * _expression;

};

#endif
