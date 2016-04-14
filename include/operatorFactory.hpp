#ifndef OPERATOR_FACTORY
#define OPERATOR_FACTORY

/*!
 * \file operatorFactory.hpp
 * \brief Gestion des variables
 * \version 1.0
 */
#include <iostream>
#include <functional>

#include "expression.hpp"


/*! 
 * \class OperatorFactory
 * \brief Classe représentant une expression composées d'opérateurs 
 *
 * Gère les expression composées d'opérateurs 
 */
class OperatorFactory: public Expression
{
public:
	typedef std::function<std::string(void)> DisplayCallback;
	typedef std::function<double(void)> EvalCallback;
	typedef std::function<void(void)> DeleteCallback;
	typedef std::function<Expression *(void)> DerivationCallback;
	typedef std::function<Expression *(void)> SimplificationCallback;
	typedef std::function<int(void)> TypeCallback;

	/*!
     * \brief Constructeur
     * \param displayCallback : la lambda qui affiche une expression contenant un opérateur
     * \param evalCallback : la lambda qui évalue une expression contenant un opérateur
     * \param deleteCallback : la lambda qui supprime une expression contenant un opérateur
     *
     * Constructeur de la classe OperatorFactory
     */
	OperatorFactory(DisplayCallback, EvalCallback, DeleteCallback, DerivationCallback, SimplificationCallback, TypeCallback);

	/*!
     * \brief Destructeur
     *
     * Destructeur de la classe OperatorFactory
     */
	~OperatorFactory();

	/*!
     * \brief Evalue une expression contenant un opérateur
     * \return Le résultat de l'expression
     *
     * Méthode qui renvoie le résultat de l'expression
     */
	double eval();

	/*!
	 * \brief Retourne la dérivée d'une expression
	 * \return Une nouvelle expression dérivée
	 *
	 * Calcul la dérivée d'une expression
	 */
	Expression * derivation();

	/*!
     * \brief Simplifie une expression
     * \return L'espression simplifiée
     *
     * Simplifie une expression
     */
	Expression * simplification();

	/*!
	 * \brief Détermine le type de l'expression
	 *
	 * Retourne le type de l'expression
	 */
	int type();

	/*!
     * \brief Affiche une expression contenant un opérateur
     * \return Une chaîne de charactères représentant l'expression
     *  
     * Affiche une expression algébrique composé d'au moins un opérateur
     */
	std::string display() const;

private:
	DisplayCallback _displayCallback; /*!< la lambda qui affiche une expression contenant un opérateur  */
	EvalCallback _evalCallback; /*!< la lambda qui évalue une expression contenant un opérateur  */
	DeleteCallback _deleteCallback; /*!< la lambda qui supprime une expression contenant un opérateur  */
	DerivationCallback _derivationCallback; /*!< la lambda qui dérive une expression  */
	SimplificationCallback _simplificationCallback; /*!< la lambda qui simplifie une expression  */
	TypeCallback _typeCallback; /*!< la lambda qui retourne le type d'une expression  */
};



#endif
