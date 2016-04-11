/*!
 * \file affectation.cpp
 * \brief Gère les affectations de variables.
 * \version 0.1
 *
 * Module gérant l'affectation d'une expression à une variable.
 *
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

#include "affectation.hpp"
#include "expression.hpp"
#include "variable.hpp"
#include "debugger.hpp"


Affectation::Affectation(Variable * variable, Expression * expression): _variable(variable), _expression(expression)
{
	_variable->set(_expression->eval());
}

Affectation::Affectation(const Affectation & affectation): _variable(affectation._variable), _expression(affectation._expression)
{
	_variable->set(_expression->eval());
}

Affectation::~Affectation()
{}

void Affectation::rollback()
{
	_variable->rollback();
}

double Affectation::eval()
{
	return _variable->eval();
}

Expression * Affectation::derivation()
{
	return new Affectation((Variable*)_variable->derivation(), _expression->derivation());
}

Expression * Affectation::simplification()
{
	return nullptr;
}

std::string Affectation::display() const 
{
	std::ostringstream stringOfValue;
	stringOfValue << '(' <<  *_variable << " <- " << *_expression << ')';
	return stringOfValue.str();
}

std::ostream & operator << (std::ostream & os, const Affectation & affectation)
{
	os << affectation.display();
	return os;
}
