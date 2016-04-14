#include <iostream>
#include <sstream>

#include "product.hpp"
#include "expression.hpp"
#include "operator.hpp"
#include "constant.hpp"
#include "variable.hpp"

using namespace Operator;


Product::Product(Expression * leftExpression, Expression * rightExpression): _leftExpression(leftExpression), _rightExpression(rightExpression), _coefficient(1), _variable(nullptr)
{
	if (_leftExpression->type() == 1 && _rightExpression->type() == 2) // 2 * (3 * x) = 6 * x
	{
		Constant * left = (Constant*)_leftExpression;
		Variable * right = (Variable*)_rightExpression;
		_coefficient = left->eval();
		_variable = new Variable(*right);
	}
	else if (_leftExpression->type() == 1 && _rightExpression->type() == 3) // 2 * (3 * x) = 6 * x
	{
		Constant * left = (Constant*)_leftExpression;
		Product * right = (Product*)_rightExpression;

		_coefficient = left->eval() * right->_coefficient;
		_variable = new Variable(*(Variable*)(right->_variable));
	}
	else if (_leftExpression->type() == 3 && _rightExpression->type() == 3) // (2 * x) * (3 * y) = 6 * x * y
	{
		Product * left = (Product*)_leftExpression;
		Product * right = (Product*)_rightExpression;

		_coefficient = left->_coefficient * right->_coefficient;
		_variable = new Product(left->_variable, right->_variable);
/*
		if (left->_variable->display().compare(right->_variable->display()) != 0)
		{
			std::string var(left->_variable->display());
			var.append(right->_variable->display());
			_variable = new Variable(var);
		}*/
	}
}

Product::Product(const Product & product): _leftExpression(product._leftExpression), _rightExpression(product._rightExpression), _coefficient(1), _variable(nullptr)
{}

Product::~Product()
{
	delete _variable;
}

double Product::eval()
{
	return _leftExpression->eval() * _rightExpression->eval();
}

Expression * Product::derivation()
{
	return new Product(_leftExpression, _rightExpression->derivation());
}

Expression * Product::simplification()
{
	// 2 * 3 = 6
	// 2 * x = 2 * x
	// 2 * (3 * x) = 6 * x
	// (2 * x) * (3 * y) = 6 * x * y
	// (2 * x) * (3 * x) = 6 * x ^ 2

	/*if (_leftExpression->type() == 1 && _rightExpression->type() == 1) // 2 * 3 = 6
	{
		return new Constant(_coefficient);
	}
	if (_leftExpression->type() == 1 && _rightExpression->type() == 2) // 2 * x = 2 * x
	{
		return new Product(new Constant(_coefficient), _variable);
	}
	if (_leftExpression->type() == 1 && _rightExpression->type() == 3) // 2 * (3 * x) = 6 * x
	{
		return new Product(new Constant(_coefficient), _variable);
	}
	if (_leftExpression->type() == 3 && _rightExpression->type() == 3) // (2 * x) * (3 * y) = 6 * x * y
	{
		Product * left = (Product*)_leftExpression;
		Product * right = (Product*)_rightExpression;

		//return new Product(new Product(new Constant(_coefficient), left->_variable), right->_variable);
		return new Product(new Constant(_coefficient), new Product(left->_variable, right->_variable));
	}
	//return new Product(_leftExpression->simplification(), _rightExpression->simplification());
	return nullptr;*/

	return aux(_leftExpression, _rightExpression);
}

Expression * Product::aux(Expression * left, Expression * right)
{
	if (left->type() == 1 && right->type() == 1) // 2 * 3 = 6
	{
		return new Constant(_coefficient);
	}
	if (left->type() == 1 && right->type() == 2) // 2 * x = 2 * x
	{
		return new Product(new Constant(_coefficient), _variable);
	}
	if (left->type() == 1 && right->type() == 3) // 2 * (3 * x) = 6 * x
	{
		return new Product(new Constant(_coefficient), _variable);
	}
	if (left->type() == 3 && right->type() == 3) // (2 * x) * (3 * y) = 6 * x * y
	{
		Product * leftP = (Product*)left;
		Product * rightP = (Product*)right;

		return new Product(new Constant(_coefficient), new Product(leftP->_variable, rightP->_variable));
	}
	return aux(left->simplification(), right->simplification());
}

int Product::type()
{
	return 3;
}

std::string Product::display() const
{
	std::ostringstream stringOfValue;
	stringOfValue << '(' << _leftExpression->display() << ' ' << name(MUL) << ' ' << _rightExpression->display() << ')';
	return stringOfValue.str();
}

std::ostream & operator << (std::ostream & os, const Product & constant)
{
	os << constant.display();
	return os;
}



