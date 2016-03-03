#ifndef COMPARATOR
#define COMPARATOR

/*!
 * \file comparator.hpp
 * \brief Gestion des comparateurs binaires
 * \version 1.0
 */
#include <iostream>

#include "expression.hpp"
#include "operator.hpp"

/*!
 * \class Comparator
 * \brief Classe représentant les opérateurs binaires
 *
 * Gère les opérateurs binaires
 */
class Comparator: public Expression
{
public:
	/*!
	 * \brief La comparaison des expressions avec inférieur ou égal
	 * \param expression : les opérandes de gauche et de droite
	 * \return La comparaison des expressions avec inférieur ou égal
	 *
	 * Renvoie une nouvelle instance de lessOrEqual, qui effectue la comparaison
	 * des expressions en paramètre avec l'opératuer inférieur ou égal.
	 */
	static Comparator * lessOrEqual(Expression *, Expression *);

	/*!
	 * \brief La comparaison des expressions avec supérieur ou égal
	 * \param expression : les opérandes de gauche et de droite
	 * \return La comparaison des expressions avec supérieur ou égal
	 *
	 * Renvoie une nouvelle instance de lessOrEqual, qui effectue la comparaison
	 * des expressions en paramètre avec l'opératuer supérieur ou égal.
	 */
	static Comparator * greaterOrEqual(Expression *, Expression *);

private:
	/*!
	 * \brief Affiche l'expression avec l'opérateur binaire
	 * \param binary, l'opérateur binaire
	 * \param expression : les opérandes de gauche et de droite
	 * \return La chaîne de caractères représentant l'opérateur binaire
	 *
	 * Affiche l'opérateur binaire concaténé à ses deux expressions
	 */
	static const std::string display(Operator::Binary, Expression *, Expression *);

	/*!
	 * \brief Libère les expressions de gauche et de droite
	 * \param expression : les opérandes de gauche et de droite
	 *
	 * Libère récursivement les expressions en paramètre
	 */
	static void free(Expression *, Expression *);

};

#endif
