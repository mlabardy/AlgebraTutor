#ifndef BINARY_OPERATOR
#define BINARY_OPERATOR

/*!
 * \file binaryOperator.hpp
 * \brief Gestion des operateurs binaires
 * \version 1.0
 */
#include <iostream>

#include "expression.hpp"
#include "operator.hpp"
#include "comparatorFactory.hpp"

/*! 
 * \class BinaryOperator
 * \brief Classe représentant les opérateurs binaires
 *
 * Gère les opérateurs binaires
 */
class BinaryOperator 
{
public:
	/*! 
	 * \brief La somme des expressions
	 * \param expression : les opérandes de gauche et de droite
	 * \return La somme des expressions
	 *
	 * Renvoie une nouvelle instance de somme, qui effectue la somme
	 * des expressions en paramètre. 
	 */
	static Expression * sum(Expression *, Expression *);

	/*! 
	 * \brief La différence des expressions
	 * \param expression : les opérandes de gauche et de droite
	 * \return La différence des expressions
	 *
	 * Renvoie une nouvelle instance de difference, qui effectue la différence
	 * des expressions en paramètre. 
	 */
	static Expression * difference(Expression *, Expression *);
	
	/*! 
	 * \brief Le produit des expressions
	 * \param expression : les opérandes de gauche et de droite
	 * \return Le produit des expressions
	 *
	 * Renvoie une nouvelle instance de product, qui effectue le produit
	 * des expressions en paramètre. 
	 */
	static Expression * product(Expression *, Expression *);

	/*! 
	 * \brief Le quotient des expressions
	 * \param expression : les opérandes de gauche et de droite
	 * \return Le quotient des expressions
	 *
	 * Renvoie une nouvelle instance de quotient, qui effectue la division
	 * des expressions en paramètre. 
	 */
	static Expression * quotient(Expression *, Expression *);

	/*! 
	 * \brief La comparaison des expressions avec inférieur ou égal
	 * \param expression : les opérandes de gauche et de droite
	 * \return La comparaison des expressions avec inférieur ou égal
	 *
	 * Renvoie une nouvelle instance de lessOrEqual, qui effectue la comparaison
	 * des expressions en paramètre avec l'opératuer inférieur ou égal. 
	 */
	static ComparatorFactory * lessOrEqual(Expression *, Expression *);

	/*! 
	 * \brief La comparaison des expressions avec supérieur ou égal
	 * \param expression : les opérandes de gauche et de droite
	 * \return La comparaison des expressions avec supérieur ou égal
	 *
	 * Renvoie une nouvelle instance de lessOrEqual, qui effectue la comparaison
	 * des expressions en paramètre avec l'opératuer supérieur ou égal. 
	 */
	static ComparatorFactory * greaterOrEqual(Expression *, Expression *);

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
