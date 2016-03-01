#include <stdio.h>
#include <iostream>
// #include <sstream>

#include "constant.hpp"
#include "expression.hpp"
#include "debugger.hpp"


Constant::Constant(double value): _value(value)
{}

Constant::~Constant()
{}

double Constant::eval()
{
	return _value;
}

std::string Constant::display() const
{
	// std::ostringstream stringOfValue;
	// stringOfValue << _value;
	// return stringOfValue.str(); 
	char buffer[100];
	snprintf(buffer, 100, "%f", _value);
	std::string str(buffer);
	return str;
}

std::ostream & operator << (std::ostream & os, const Constant & constant)
{
	os << constant.display();
	return os;
}
