#ifndef UNARY_OPERATOR
#define UNARY_OPERATOR

/*!
 * \file unaryOperator.hpp
 * \brief Gestion des operateurs unaires
 * \version 1.0
 */
#include <iostream>

#include "expression.hpp"
#include "operator.hpp"

/*! 
 * \class UnaryOperator
 * \brief Classe représentant les opérateurs unaires
 *
 * Gère les opérateurs unaires
 */
class UnaryOperator
{
public:
	/*! 
	 * \brief Le cosinus de l'expression
	 * \param expression : l'opérande
	 * \return Le cosinus de l'expression
	 *
	 * Renvoie une nouvelle instance de cosinus,
	 * qui détermine le cosinus de l'expression en paramètre. 
	 */
	static Expression * cosinus(Expression *);

	/*! 
	 * \brief Le sinus de l'expression
	 * \param expression : l'opérande
	 * \return Le sinus de l'expression
	 *
	 * Renvoie une nouvelle instance de sinus,
	 * qui détermine le sinus de l'expression en paramètre. 
	 */	
	static Expression * sinus(Expression *);

	/*! 
	 * \brief Une expression exposant une autre expression
	 * \param expression : l'opérande et la puissance
	 * \return Une expression exposant une autre expression
	 *
	 * Renvoie une nouvelle instance de exponantial,
	 * qui détermine le résultat de l'expression exposant une autre expression. 
	 */
	static Expression * exponantial(Expression *, Expression *);

private:
	static const std::string display(Operator::Unary, Expression *);
	static void free(Expression * expression);

};

#endif
