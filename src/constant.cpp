#include <iostream>
#include <sstream>

#include "constant.hpp"
#include "expression.hpp"


Expression * Constant::constant(double value)
{
	return new Expression (
		[=] () 
		{ 
			std::ostringstream stringOfValue;
			stringOfValue << value;
			return stringOfValue.str(); 
		},
		[=] () 
		{ 
			return value; 
		},
		[=] () {},
		[=] ()
		{
			return "constant";
		}
	);	
}

