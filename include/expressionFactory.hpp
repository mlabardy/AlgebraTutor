#ifndef EXPRESSION_FACTORY
#define EXPRESSION_FACTORY

/*!
 * \file expressionFactory.hpp
 * \brief Gestion de la création d'expressions
 * \version 1.0
 */
#include <iostream>

#include "expression.hpp"
#include "variable.hpp" 
#include "affectation.hpp"


/*! 
 * \namespace ExpressionFactory
 * 
 * Espace de nommage regroupant tous les types d'expressions
 */
namespace ExpressionFactory
{
	// UNARY OPERATORS
	/*!
	 * \fn Expression * constant(double value)
     * \brief Crée une constante
     * \param value : la valeur de la constante
     * \return Une expression
     *
     * Fonction qui crée une nouvelle constante
     */
	Expression * constant(double);

	/*!
	 * \fn Variable * variable(const std::string & id)
     * \brief Crée une variable initialisée à 0
     * \param id : l'identifiant de la variable
     * \return Une variable
     *
     * Fonction qui crée une nouvelle variable si elle n'existe pas encore dans le programme.
     * Sinon l'identifiant est réinitialisé à 0
     */
	Variable * variable(const std::string &);
	
	/*!
	 * \fn Variable * variable(const std::string & id, double value)
     * \brief Crée une variable
     * \param id : l'identifiant de la variable
     * \param value : la valeur de la variable
     * \return Une expression
     *
     * Fonction qui crée une nouvelle variable si elle n'existe pas encore dans le programme.
     * Sinon l'identifiant est réinitialisé par la valeur renseignée
     */	
	Variable * variable(const std::string &, double);
	
	/*!
	 * \fn Affectation * affectation(Variable * variable, Expression * expression)
     * \brief Crée une affectation
     * \param variable : la variable à affecter
     * \param expression : l'expression à assigner
     * \return Une expression
     *
     * Fonction qui crée une nouvelle affectation
     */
	Affectation * affectation(Variable *, Expression *);

	/*!
	 * \fn Expression * cosinus(Expression * expression)
     * \brief Crée un cosinus
     * \param expression : l'expression
     * \return Une expression
     *
     * Fonction qui crée un nouveau cosinus
     */
	Expression * cosinus(Expression *);

	/*!
	 * \fn Expression * sinus(Expression * expression)
     * \brief Crée un sinus
     * \param expression : l'expression
     * \return Une expression
     *
     * Fonction qui crée un nouveau sinus
     */
	Expression * sinus(Expression *);

	/*!
	 * \fn Expression * exponantial(Expression * expression, Expression * power)
     * \brief Crée une exponentiation
     * \param expression : l'expression
     * \param power : l'exposant
     * \return Une expression
     *
     * Fonction qui crée une nouvelle exponentiation
     */
	Expression * exponantial(Expression *, Expression *);

	// BINARY OPERATORS

	/*!
	 * \fn Expression * sum(Expression * leftExpression, Expression * rightExpression)
     * \brief Crée une somme
     * \param leftExpression : l'opérande de gauche
     * \param rightExpression : l'operande de droite
     * \return Une expression
     *
     * Fonction qui crée une nouvelle somme
     */
	Expression * sum(Expression *, Expression *);

	/*!
	 * \fn Expression * difference(Expression * leftExpression, Expression * rightExpression)
     * \brief Crée une différence
     * \param leftExpression : l'opérande de gauche
     * \param rightExpression : l'operande de droite
     * \return Une expression
     *
     * Fonction qui crée une nouvelle différence
     */
	Expression * difference(Expression *, Expression *);

	/*!
	 * \fn Expression * product(Expression * leftExpression, Expression * rightExpression)
     * \brief Crée un produit
     * \param leftExpression : l'opérande de gauche
     * \param rightExpression : l'operande de droite
     * \return Une expression
     *
     * Fonction qui crée une nouveau produit
     */
	Expression * product(Expression *, Expression *);

	/*!
	 * \fn Expression * quotient(Expression * leftExpression, Expression * rightExpression)
     * \brief Crée un quotient
     * \param leftExpression : l'opérande de gauche
     * \param rightExpression : l'operande de droite
     * \return Une expression
     *
     * Fonction qui crée une nouveau quotient
     */
	Expression * quotient(Expression *, Expression *);

	/*!
	 * \fn Expression * lessOrEqual(Expression * leftExpression, Expression * rightExpression)
     * \brief Crée une comparaison inférieur ou égal
     * \param leftExpression : l'opérande de gauche
     * \param rightExpression : l'operande de droite
     * \return Une expression
     *
     * Fonction qui crée une nouvelle comparaison inférieur ou égal
     */
	Expression * lessOrEqual(Expression *, Expression *);

	/*!
	 * \fn Expression * greaterOrEqual(Expression * leftExpression, Expression * rightExpression)
     * \brief Crée une comparaison supérieur ou égal
     * \param leftExpression : l'opérande de gauche
     * \param rightExpression : l'operande de droite
     * \return Une expression
     *
     * Fonction qui crée une nouvelle comparaison supérieur ou égal
     */
	Expression * greaterOrEqual(Expression *, Expression *);

	/*!
	 * \fn Expression * conditional(Expression * comparator, Expression * expression, Expression * otherExpression)
     * \brief Crée une ternaire
     * \param comparator : le test à éffectuer
     * \param expression : le résultat si le test renvoi true
     * \param otherExpression : le résultat si le test renvoi false
     * \return Une expression
     *
     * Fonction qui crée une nouvelle ternaire
     */
	Expression * ternary(Expression *, Expression *, Expression *);
}

#endif
