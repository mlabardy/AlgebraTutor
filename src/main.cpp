#include <iostream>

#include "expressionFactory.hpp"
#include "expression.hpp"


int main()
{
	double val = 1.0472;
	double x = 2;
	double y = 3;


	Expression * ux = ExpressionFactory::constant(x);
	Expression * uy = ExpressionFactory::constant(y);


	Expression * cons = ExpressionFactory::constant(val);
	Expression * cosi = ExpressionFactory::cosinus(cons);
	Expression * sinu = ExpressionFactory::sinus(cons);
	Expression * expo = ExpressionFactory::exponantial(ux, uy);


	std::cout << *cons << " = " << cons->eval() << std::endl;
	std::cout << *cosi << " = " << cosi->eval() << std::endl;
	std::cout << *sinu << " = " << sinu->eval() << std::endl;
	std::cout << *expo << " = " << expo->eval() << std::endl;


	// std::cout << *s << std::endl;
	// std::cout << *e << std::endl;


	// auto callbacks = make_tuple(
	//     [] (int x) { std::cout << x << std::endl; },
	//     [&] () { std::cout << y << std::endl; }, // y is captured by reference
	//     [=] (int x) { std::cout << x + y << std::endl; } // y is captured by value
	//     // other lambdas here, if you want...
 	//    );

    // callbacks(2);


	return 0;
}