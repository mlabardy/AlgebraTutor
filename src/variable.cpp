#include <iostream>

#include "variable.hpp"
#include "expression.hpp"


Expression * Variable::variable(std::string id, double value) 
{
	return new Expression (
		[=] () 
		{ 
			return id; 
		},
		[=] () 
		{ 
			return value; 
		},
		[=] () {},
		[=] ()
		{
			return "variable";
		}
	);
}

Expression * Variable::variable(std::string id) 
{
	return new Expression (
		[=] () 
		{
			return id; 
		},
		[=] () 
		{ 
			return 0; 
		},
		[=] () {},
		[=] ()
		{
			return "variable";
		}
	);
}
