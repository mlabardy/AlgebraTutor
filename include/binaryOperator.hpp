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
#include "affectation.hpp"

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
	 * \fn Expression * sum(Expression * leftExpression, Expression * rightExpression)
	 * \brief La somme des expressions
	 * \param leftExpression : l'opérande de gauche
	 * \param rightExpression : l'opérande de droite
	 * \return La somme des expressions
	 *
	 * Renvoie une nouvelle instance de somme, qui effectue la somme
	 * des expressions en paramètre. 
	 */
	static Expression * sum(Expression *, Expression *);

	/*! 
	 * \fn Expression * difference(Expression * leftExpression, Expression * rightExpression)
	 * \brief La différence des expressions
	 * \param leftExpression : l'opérande de gauche
	 * \param rightExpression : l'opérande de droite
	 * \return La différence des expressions
	 *
	 * Renvoie une nouvelle instance de difference, qui effectue la différence
	 * des expressions en paramètre. 
	 */
	static Expression * difference(Expression *, Expression *);
	
	/*! 
	 * \fn Expression * product(Expression * leftExpression, Expression * rightExpression)
	 * \brief Le produit des expressions
	 * \param leftExpression : l'opérande de gauche
	 * \param rightExpression : l'opérande de droite
	 * \return Le produit des expressions
	 *
	 * Renvoie une nouvelle instance de product, qui effectue le produit
	 * des expressions en paramètre. 
	 */
	static Expression * product(Expression *, Expression *);

	/*!
	 * \fn Expression * quotient(Expression * leftExpression, Expression * rightExpression)
	 * \brief Le quotient des expressions
	 * \param leftExpression : l'opérande de gauche
	 * \param rightExpression : l'opérande de droite
	 * \return Le quotient des expressions
	 *
	 * Renvoie une nouvelle instance de quotient, qui effectue la division
	 * des expressions en paramètre. 
	 */
	static Expression * quotient(Expression *, Expression *);

	/*! 
	 * \fn Expression * lessOrEqual(Expression * leftExpression, Expression * rightExpression)
	 * \brief La comparaison des expressions avec inférieur ou égal
	 * \param leftExpression : l'opérande de gauche
	 * \param rightExpression : l'opérande de droite
	 * \return La comparaison des expressions avec inférieur ou égal
	 *
	 * Renvoie une nouvelle instance de ComparatorFactory, qui effectue la comparaison
	 * des expressions en paramètre avec l'opérateur inférieur ou égal.
	 */
	static ComparatorFactory * lessOrEqual(Expression *, Expression *);

	/*! 
	 * \fn Expression * greaterOrEqual(Expression * leftExpression, Expression * rightExpression)
	 * \brief La comparaison des expressions avec supérieur ou égal
	 * \param leftExpression : l'opérande de gauche
	 * \param rightExpression : l'opérande de droite
	 * \return La comparaison des expressions avec supérieur ou égal
	 *
	 * Renvoie une nouvelle instance de ComparatorFactory, qui effectue la comparaison
	 * des expressions en paramètre avec l'opérateur supérieur ou égal.
	 */
	static ComparatorFactory * greaterOrEqual(Expression *, Expression *);

	/*!
	 * \fn Expression * greater(Expression * leftExpression, Expression * rightExpression)
	 * \brief La comparaison des expressions avec l'opérateur supérieur
	 * \param leftExpression : l'opérande de gauche
	 * \param rightExpression : l'opérande de droite
	 * \return La comparaison des expressions avec l'opérateur supérieur
	 *
	 * Renvoie une nouvelle instance de ComparatorFactory, qui effectue la comparaison
	 * des expressions en paramètre avec l'opérateur supérieur.
	 */
	static ComparatorFactory * greater(Expression *, Expression *);

	/*!
	 * \fn Expression * less(Expression * leftExpression, Expression * rightExpression)
	 * \brief La comparaison des expressions avec l'opérateur inférieur
	 * \param leftExpression : l'opérande de gauche
	 * \param rightExpression : l'opérande de droite
	 * \return La comparaison des expressions avec l'opérateur inférieur
	 *
	 * Renvoie une nouvelle instance de ComparatorFactory, qui effectue la comparaison
	 * des expressions en paramètre avec l'opérateur inférieur.
	 */
	static ComparatorFactory * less(Expression *, Expression *);

	/*!
	 * \fn Expression * equal(Expression * leftExpression, Expression * rightExpression)
	 * \brief La comparaison des expressions avec l'opérateur égal
	 * \param leftExpression : l'opérande de gauche
	 * \param rightExpression : l'opérande de droite
	 * \return La comparaison des expressions avec l'opérateur égal
	 *
	 * Renvoie une nouvelle instance de ComparatorFactory, qui effectue la comparaison
	 * des expressions en paramètre avec l'opérateur égal.
	 */
	static ComparatorFactory * equal(Expression *, Expression *);

	/*!
	 * \fn Expression * different(Expression * leftExpression, Expression * rightExpression)
	 * \brief La comparaison des expressions avec l'opérateur 'différent de'
	 * \param leftExpression : l'opérande de gauche
	 * \param rightExpression : l'opérande de droite
	 * \return La comparaison des expressions avec l'opérateur 'différent de'
	 *
	 * Renvoie une nouvelle instance de ComparatorFactory, qui effectue la comparaison
	 * des expressions en paramètre avec l'opérateur 'différent de'.
	 */
	static ComparatorFactory * different(Expression *, Expression *);





	/*!
	 * \fn Expression * sumAffectation(Variable * variable, Expression * expression)
	 * \brief La somme des expressions
	 * \param variable : la variable à instancier
	 * \param expression : l'expression à affecter
	 * \return Une nouvelle affectation
	 *
	 * Renvoie une nouvelle instance de somme, qui effectue l'addition
	 * des expressions en paramètre.
	 */
	static Affectation * sumAffectation(Variable *, Expression *);

	/*!
	 * \fn Expression * differenceAffectation(Variable * variable, Expression * expression)
	 * \brief La différence des expressions
	 * \param variable : la variable à instancier
	 * \param expression : l'expression à affecter
	 * \return Une nouvelle affectation
	 *
	 * Renvoie une nouvelle instance de différence, qui effectue la soustraction
	 * des expressions en paramètre.
	 */
	static Affectation * differenceAffectation(Variable *, Expression *);

	/*!
	 * \fn Expression * productAffectation(Variable * variable, Expression * expression)
	 * \brief Le produit des expressions
	 * \param variable : la variable à instancier
	 * \param expression : l'expression à affecter
	 * \return Une nouvelle affectation
	 *
	 * Renvoie une nouvelle instance de produit, qui effectue la multiplication
	 * des expressions en paramètre.
	 */
	static Affectation * productAffectation(Variable *, Expression *);

	/*!
	 * \fn Expression * quotientAffectation(Variable * variable, Expression * expression)
	 * \brief Le quotient des expressions
	 * \param variable : la variable à instancier
	 * \param expression : l'expression à affecter
	 * \return Une nouvelle affectation
	 *
	 * Renvoie une nouvelle instance de quotient, qui effectue la division
	 * des expressions en paramètre.
	 */
	static Affectation * quotientAffectation(Variable *, Expression *);

private:
	/*! 
	 * \brief Affiche l'expression avec l'opérateur binaire
	 * \param binary, l'opérateur binaire
	 * \param expression : les opérandes de gauche et de droite
	 * \return La chaîne de caractères représentant l'opérateur binaire
	 *
	 * Affiche l'opérateur binaire concaténé à ses deux expressions .
	 */
	static const std::string display(Operator::Binary, Expression *, Expression *); 

	/*! 
	 * \brief Libère les expressions de gauche et de droite
	 * \param expression : les opérandes de gauche et de droite
	 *
	 * Libère récursivement les expressions en paramètre.
	 */
	static void free(Expression *, Expression *);
	
};

#endif
