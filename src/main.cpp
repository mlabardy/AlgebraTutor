#include <iostream>

#include "expressionFactory.hpp"
#include "expression.hpp"

#define M_PI 3.14

using namespace ExpressionFactory;

int main()
{
	double val = 1.0472;
	double x = 2;
	double y = 3;

	Expression * s = sum(constant(1.0),
					product(constant(2.0),
					sinus(constant(M_PI/6.0))
					));


	Expression * var = variable("y", 3.0);
	Expression * var1 = variable("y");

	std::cout << *var << " = "<< var->eval() << std::endl;
	std::cout << *var1 << " = "<< var1->eval() << std::endl;
	
	Expression * b = affect(s, s);

	std::cout << *b << " = " << b->eval() << std::endl;


	delete var;
	delete var1;

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