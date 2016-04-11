#include <stdio.h>

#include "binaryOperator.hpp"
#include "expression.hpp"
#include "operator.hpp"
#include "operatorFactory.hpp"
#include "comparatorFactory.hpp"
#include "variable.hpp"
#include "affectation.hpp"
#include "debugger.hpp"
#include "unaryOperator.hpp"
#include "constant.hpp"

using namespace Operator;


const std::string BinaryOperator::display(Binary binaryOperator, Expression * leftExpression, Expression * rightExpression)
{ 
	// std::ostringstream stringOfValue;
	// stringOfValue << '(' << leftExpression->display() << ' ' << name(binaryOperator) << ' ' << rightExpression->display() << ')';
	// return stringOfValue.str();

	char buffer[100];
	snprintf(buffer, 100, "(%s %s %s)", leftExpression->display().c_str(), name(binaryOperator).c_str(), rightExpression->display().c_str());
	std::string str(buffer);
	return str;
}

void BinaryOperator::free(Expression * leftExpression, Expression * rightExpression) 
{
	if (leftExpression != nullptr)
	{
		delete leftExpression;
		leftExpression = nullptr;
	}

	if (rightExpression != nullptr)
	{
		delete rightExpression;
		rightExpression = nullptr;
	}
}

Expression * BinaryOperator::sum(Expression * leftExpression, Expression * rightExpression)
{
	return new OperatorFactory (
		[=] () 
		{ 
			return BinaryOperator::display(ADD, leftExpression, rightExpression);
		},
		[=] () 
		{ 
			return leftExpression->eval() + rightExpression->eval(); 
		},
		[=] () 
		{},
		[=] ()
		{
			return sum(leftExpression->derivation(), rightExpression->derivation());
		},
		[=] ()
		{
			return nullptr;
		}
	); 
}

Expression * BinaryOperator::difference(Expression * leftExpression, Expression * rightExpression)
{
	return new OperatorFactory (
		[=] () 
		{ 
			return BinaryOperator::display(SUB, leftExpression, rightExpression);
		},
		[=] () 
		{ 
			return leftExpression->eval() - rightExpression->eval(); 
		},
		[=] () 
		{ 
			// BinaryOperator::free(leftExpression, rightExpression);
		},
		[=] ()
		{
			return difference(leftExpression->derivation(), rightExpression->derivation());
		},
		[=] ()
		{
			return nullptr;
		}
	);  
}

Expression * BinaryOperator::product(Expression * leftExpression, Expression * rightExpression)
{
	return new OperatorFactory (
		[=] () 
		{ 
			return BinaryOperator::display(MUL, leftExpression, rightExpression); 
		},
		[=] () 
		{ 
			return leftExpression->eval() * rightExpression->eval(); 
		},
		[=] () 
		{ 
			// BinaryOperator::free(leftExpression, rightExpression);
		},
		[=] ()
		{
			//return sum(product(leftExpression->derivation(), rightExpression), product(rightExpression->derivation(), leftExpression->derivation()));
			return product(leftExpression, rightExpression->derivation());
		},
		[=] ()
		{
			return nullptr;
		}
	);
}

Expression * BinaryOperator::quotient(Expression * leftExpression, Expression * rightExpression)
{
	return new OperatorFactory (
		[=] () 
		{ 
			return BinaryOperator::display(DIV, leftExpression, rightExpression);
		},
		[=] () 
		{ 
			return leftExpression->eval() / rightExpression->eval(); 
		},
		[=] () 
		{ 
			// BinaryOperator::free(leftExpression, rightExpression);
		},
		[=] ()
		{
			Expression * a = product(leftExpression->derivation(), rightExpression);
			Expression * b = product(rightExpression->derivation(), leftExpression);

			Expression * numerator = difference(a, b);
			Expression * denominator = UnaryOperator::exponantial(rightExpression, new Constant(2));

			return quotient(numerator, denominator);

		},
		[=] ()
		{
			return nullptr;
		}
	);
}

ComparatorFactory * BinaryOperator::lessOrEqual(Expression * leftExpression, Expression * rightExpression)
{
	return new ComparatorFactory (
		[=] () 
		{ 
			return BinaryOperator::display(LOE, leftExpression, rightExpression);
		},
		[=] () 
		{ 
			return (leftExpression->eval() <= rightExpression->eval()) ? 1.0 : 0.0; 
		},
		[=] () 
		{ 
			// BinaryOperator::free(leftExpression, rightExpression);
		},
		[=] ()
		{
			return lessOrEqual(leftExpression, rightExpression);
		},
		[=] ()
		{
			return nullptr;
		}
	);
}

ComparatorFactory * BinaryOperator::greaterOrEqual(Expression * leftExpression, Expression * rightExpression)
{
	return new ComparatorFactory (
		[=] () 
		{ 
			return BinaryOperator::display(GOE, leftExpression, rightExpression);
		},
		[=] () 
		{ 
			return (leftExpression->eval() >= rightExpression->eval()) ? 1.0 : 0.0; 
		},
		[=] () 
		{ 
			// BinaryOperator::free(leftExpression, rightExpression);
		},
		[=] ()
		{
			return greaterOrEqual(leftExpression, rightExpression);
		},
		[=] ()
		{
			return nullptr;
		}
	);
}

ComparatorFactory * BinaryOperator::greater(Expression * leftExpression, Expression * rightExpression)
{
	return new ComparatorFactory (
		[=] ()
		{
			return BinaryOperator::display(GT, leftExpression, rightExpression);
		},
		[=] ()
		{
			return (leftExpression->eval() > rightExpression->eval()) ? 1.0 : 0.0;
		},
		[=] ()
		{
			// BinaryOperator::free(leftExpression, rightExpression);
		},
		[=] ()
		{
			return greater(leftExpression, rightExpression);
		},
		[=] ()
		{
			return nullptr;
		}
	);
}

ComparatorFactory * BinaryOperator::less(Expression * leftExpression, Expression * rightExpression)
{
	return new ComparatorFactory (
		[=] ()
		{
			return BinaryOperator::display(LT, leftExpression, rightExpression);
		},
		[=] ()
		{
			return (leftExpression->eval() < rightExpression->eval()) ? 1.0 : 0.0;
		},
		[=] ()
		{
			// BinaryOperator::free(leftExpression, rightExpression);
		},
		[=] ()
		{
			return less(leftExpression, rightExpression);
		},
		[=] ()
		{
			return nullptr;
		}
	);
}

ComparatorFactory * BinaryOperator::equal(Expression * leftExpression, Expression * rightExpression)
{
	return new ComparatorFactory (
		[=] ()
		{
			return BinaryOperator::display(EQ, leftExpression, rightExpression);
		},
		[=] ()
		{
			return (leftExpression->eval() == rightExpression->eval()) ? 1.0 : 0.0;
		},
		[=] ()
		{
			// BinaryOperator::free(leftExpression, rightExpression);
		},
		[=] ()
		{
			return equal(leftExpression, rightExpression);
		},
		[=] ()
		{
			return nullptr;
		}
	);
}

ComparatorFactory * BinaryOperator::different(Expression * leftExpression, Expression * rightExpression)
{
	return new ComparatorFactory (
		[=] ()
		{
			return BinaryOperator::display(DIF, leftExpression, rightExpression);
		},
		[=] ()
		{
			return (leftExpression->eval() != rightExpression->eval()) ? 1.0 : 0.0;
		},
		[=] ()
		{
			// BinaryOperator::free(leftExpression, rightExpression);
		},
		[=] ()
		{
			return different(leftExpression, rightExpression);
		},
		[=] ()
		{
			return nullptr;
		}
	);
}

Affectation * BinaryOperator::sumAffectation(Variable * variable, Expression * expression)
{
	return new Affectation(variable, sum(variable, expression));
}

Affectation * BinaryOperator::differenceAffectation(Variable * variable, Expression * expression)
{
	return new Affectation(variable, difference(variable, expression));
}

Affectation * BinaryOperator::productAffectation(Variable * variable, Expression * expression)
{
	return new Affectation(variable, product(variable, expression));
}

Affectation * BinaryOperator::quotientAffectation(Variable * variable, Expression * expression)
{
	return new Affectation(variable, quotient(variable, expression));
}
