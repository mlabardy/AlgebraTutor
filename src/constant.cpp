#include <stdio.h>
#include <iostream>
#include <sstream>

#include "constant.hpp"
#include "expression.hpp"
#include "debugger.hpp"


Constant::Constant(double value): _value(value)
{}

Constant::Constant(const Constant & constant): _value(constant._value)
{}

Constant::~Constant()
{}

double Constant::eval()
{
	return _value;
}

Expression * Constant::derivation()
{
	return new Constant(0);
}

Expression * Constant::simplification()
{
	return this;
}

std::string Constant::display() const
{
	std::ostringstream stringOfValue;
	stringOfValue << _value;
	return stringOfValue.str();
}

std::ostream & operator << (std::ostream & os, const Constant & constant)
{
	os << constant.display();
	return os;
}
