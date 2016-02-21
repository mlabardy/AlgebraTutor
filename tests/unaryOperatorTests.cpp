#include <iostream>

#include "../include/expressionFactory.hpp"
#include "../include/expression.hpp"


using namespace ExpressionFactory;

int main()
{
	double val = 1.0472;
	double x = 2;
	double y = 3;


	Expression * ux = constant(x);
	Expression * uy = constant(y);


	Expression * cons = constant(val);
	Expression * cosi = cosinus(cons);
	Expression * sinu = sinus(cons);
	Expression * expo = exponantial(ux, uy);


	std::cout << *cons << " = " << cons->eval() << std::endl;
	std::cout << *cosi << " = " << cosi->eval() << std::endl;
	std::cout << *sinu << " = " << sinu->eval() << std::endl;
	std::cout << *expo << " = " << expo->eval() << std::endl;

	return 0;
}