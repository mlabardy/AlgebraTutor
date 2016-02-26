#ifndef VARIABLE
#define VARIABLE

#include <iostream>

#include "expression.hpp"


class Variable 
{
public:
	static Expression * variable(std::string, double);
	static Expression * variable(std::string);
	
};

#endif
