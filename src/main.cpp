#include <iostream>

#include "expressionFactory.hpp"
#include "expression.hpp"
#include "variable.hpp"

#define M_PI 3.14

using namespace std;
using namespace ExpressionFactory;


int main()
{
	std::cout << "Les tests se font dans le dossier ./tests/" << std::endl;
	
	// auto callbacks = make_tuple(
	//     [] (int x) { std::cout << x << std::endl; },
	//     [&] () { std::cout << y << std::endl; }, // y is captured by reference
	//     [=] (int x) { std::cout << x + y << std::endl; } // y is captured by value
	//     // other lambdas here, if you want...
 	//    );

    // callbacks(2);


	return 0;
}