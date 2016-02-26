#include <iostream>
#include <string>
#include <sstream>

#include "affect.hpp"
#include "expression.hpp"


Expression * Affect::affect(Expression * variable, Expression * value)
{
	return new Expression (
		[=] () 
		{ 
			if (variable->type().compare("variable") == 0)
				return variable->display(); 
			std::ostringstream stringOfValue;
			stringOfValue << "";
			return stringOfValue.str(); 
		},
		[=] () 
		{ 
			if (variable->type().compare("variable") == 0)
				return value->eval(); 
			return 0.0; 
		},
		[=] () 
		{
			if (variable != NULL)
				delete variable;
			if (value != NULL)
				delete value;
		},
		[=] ()
		{
			return "affect";
		}
	);
}
