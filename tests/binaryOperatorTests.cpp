#include <iostream>

#include "../include/expressionFactory.hpp"
#include "../include/expression.hpp"


using namespace ExpressionFactory;

int main()
{

	Expression * s = sum(constant(2), 
						sum(
							sum(constant(2), constant(7)), constant(7))
					);


	std::cout << *s << " = " << s->eval() << std::endl;

	return 0;
}