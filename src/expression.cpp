#include <iostream>
#include <set>
#include <typeinfo>

#include "expression.hpp"
#include "debugger.hpp"


std::set<Expression *> _pool;

Expression::Expression()
{
	_pool.insert(this);
}

Expression::~Expression()
{}

void Expression::deleteAll()
{
	std::set<Expression *>::iterator it = _pool.begin();

	while (it != _pool.end()) 
	{
		Expression * tmp = *it;
    	delete tmp;
        it = _pool.erase(it);
	}

	_pool.clear();
}

std::ostream & operator << (std::ostream & os, const Expression & expression) 
{
	os << expression.display();
	return os;
}
