/*!
 * \file for.cpp
 * \brief 
 * \version 1.0
 */
#include <sstream>

#include "for.hpp"
#include "expression.hpp"
#include "affectation.hpp"
#include "comparatorFactory.hpp"
#include "variable.hpp"
#include "block.hpp"


For::For(Affectation * start, ComparatorFactory * condition, Affectation * end, Block * expressions): _start(start), _condition(condition), _next(end), _expressions(expressions)
{}

For::For(const For & loop): _start(loop._start), _condition(loop._condition), _next(loop._next), _expressions(loop._expressions)
{}

For::~For()
{}

double For::eval()
{
	// remet les valeurs précédente avant première itération
	new Affectation(*_start);
	_expressions->rollback();

	while ((int)_condition->eval() != 0)
	{
		_expressions->execute();
		new Affectation(*_next);
	}
	return -1;
}

Expression * For::derivation()
{
	return nullptr;
}


Expression * For::simplification()
{
	return nullptr;
}

std::string For::display() const
{
	std::ostringstream stringOfValue;
	stringOfValue << "for (" <<  *_start << " ; " << *_condition << " ; " << *_next << ")\n" << *_expressions;
	return stringOfValue.str();
}

std::ostream & operator << (std::ostream & os, const For & loop)
{
	os << loop.display();
	return os;
}
