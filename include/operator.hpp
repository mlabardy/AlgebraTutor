#ifndef OPERATOR
#define OPERATOR

#include <iostream>


namespace Operator 
{
	typedef enum 
	{
		COS,
		SIN,
		EXP,
		TAN,
		ATAN,
		ACOS,
		ASIN
	} Unary;

	typedef enum 
	{
		ADD,
		SUB,
		DIV,
		MUL
	} Binary;
	
	const std::string name(Binary);
	const std::string name(Unary);
}

#endif
