#ifndef OPERATOR_FACTORY
#define OPERATOR_FACTORY

/*!
 * \file operatorFactory.hpp
 * \brief Gestion des variables
 * \version 1.0
 */
#include <iostream>

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

	/*!
     * \brief Constructeur
     * \param displayCallback : la lambda qui affiche une expression contenant un opérateur
     * \param evalCallback : la lambda qui évalue une expression contenant un opérateur
     * \param deleteCallback : la lambda qui supprime une expression contenant un opérateur
     *
     * Constructeur de la classe OperatorFactory
     */
	OperatorFactory(DisplayCallback, EvalCallback, DeleteCallback);

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
     * \brief Affiche une expression contenant un opérateur
     * \return Une chaîne de charactères représentant l'expression
     *  
     * Affiche une expression algébrique composé d'au moins un opérateur
     */
	std::string display() const;

private:
	DisplayCallback _displayCallback; /*!< la lambda qui affiche une expression contenant un opérateur  */
	EvalCallback _evalCallback; /*!< la lambda qui évalue une expression contenant un opérateur  */
	DeleteCallback _deleteCallback; /* la lambda qui supprime une expression contenant un opérateur  */

};



#endif
