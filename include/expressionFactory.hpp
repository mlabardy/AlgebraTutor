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
     * \brief Crée une constante
     * \param value : la valeur de la constante
     * \return Une expression
     *
     * Fonction qui crée une nouvelle constante
     */
	Expression * constant(double);

	/*!
     * \brief Crée une variable
     * \param value : la valeur de la variable
     * \return Une expression
     *
     * Fonction qui crée une nouvelle variable
     */
	Variable * variable(const std::string &);
	
	/*!
     * \brief Crée une variable
     * \param id : l'identifiant de la variable
     * \param value : la valeur de la variable
     * \return Une expression
     *
     * Fonction qui crée une nouvelle variable
     */	
	Variable * variable(const std::string &, double);
	
	/*!
     * \brief Crée une affectation
     * \param variable : la variable à affecter
     * \param expression : l'expression à assigner
     * \return Une expression
     *
     * Fonction qui crée une nouvelle affectation
     */
	Affectation * affectation(Variable *, Expression *);

	/*!
     * \brief Crée un cosinus
     * \param expression : l'expression
     * \return Une expression
     *
     * Fonction qui crée un nouveau cosinus
     */
	Expression * cosinus(Expression *);

	/*!
     * \brief Crée un sinus
     * \param expression : l'expression
     * \return Une expression
     *
     * Fonction qui crée un nouveau sinus
     */
	Expression * sinus(Expression *);

	/*!
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
     * \brief Crée une somme
     * \param expression : l'opérande de gauche et de droite
     * \return Une expression
     *
     * Fonction qui crée une nouvelle somme
     */
	Expression * sum(Expression *, Expression *);

	/*!
     * \brief Crée une différence
     * \param expression : l'opérande de gauche et de droite
     * \return Une expression
     *
     * Fonction qui crée une nouvelle différence
     */
	Expression * difference(Expression *, Expression *);

	/*!
     * \brief Crée un produit
     * \param expression : l'opérande de gauche et de droite
     * \return Une expression
     *
     * Fonction qui crée une nouveau produit
     */
	Expression * product(Expression *, Expression *);

	/*!
     * \brief Crée un quotient
     * \param expression : l'opérande de gauche et de droite
     * \return Une expression
     *
     * Fonction qui crée une nouveau quotient
     */
	Expression * quotient(Expression *, Expression *);

	/*!
     * \brief Crée une comparaison inférieur ou égal
     * \param expression : l'opérande de gauche et de droite
     * \return Une expression
     *
     * Fonction qui crée une nouvelle comparaison inférieur ou égal
     */
	Expression * lessOrEqual(Expression *, Expression *);

	/*!
     * \brief Crée une comparaison supérieur ou égal
     * \param expression : l'opérande de gauche et de droite
     * \return Une expression
     *
     * Fonction qui crée une nouvelle comparaison supérieur ou égal
     */
	Expression * greaterOrEqual(Expression *, Expression *);
}

#endif
