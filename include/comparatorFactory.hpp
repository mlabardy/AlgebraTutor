#ifndef COMPARATOR_FACTORY
#define COMPARATOR_FACTORY

/*!
 * \file comparatorFactory.hpp
 * \brief Gestion des comparateurs
 * \version 1.0
 */
#include <iostream>

#include "expression.hpp"


/*!
 * \class ComparatorFactory
 * \brief Classe représentant une expression composées de comparateurs
 *
 * Gère les expressions composées de comparateurs
 */
class ComparatorFactory: public Expression
{
public:
	typedef std::function<std::string(void)> DisplayCallback;
	typedef std::function<double(void)> EvalCallback;
	typedef std::function<void(void)> DeleteCallback;

	/*!
     * \brief Constructeur
     * \param displayCallback : la lambda qui affiche une expression contenant un comparateur
     * \param evalCallback : la lambda qui évalue une expression contenant un comparateur
     * \param deleteCallback : la lambda qui supprime une expression contenant un comparateur
     *
     * Constructeur de la classe ComparatorFactory
     */
	ComparatorFactory(DisplayCallback, EvalCallback, DeleteCallback);

	/*!
     * \brief Destructeur
     *
     * Destructeur de la classe ComparatorFactory
     */
	~ComparatorFactory();

	/*!
     * \brief Indique que la valeur de l'expression doit être inversée
     *
     * Méthode qui négationne une comparaison
     */
	void isNegation();

	/*!
     * \brief Evalue une expression contenant un comparateur
     * \return Le résultat de l'expression
     *
     * Méthode qui renvoie le résultat de l'expression
     */
	double eval();

	/*!
     * \brief Affiche une expression contenant un comparateur
     * \return Une chaîne de charactères représentant l'expression
     *
     * Affiche une expression algébrique composé d'au moins un comparateur
     */
	std::string display() const;

private:
	bool _isNegation;
	DisplayCallback _displayCallback; /*!< la lambda qui affiche une expression contenant un comparateur  */
	EvalCallback _evalCallback; /*!< la lambda qui évalue une expression contenant un comparateur  */
	DeleteCallback _deleteCallback; /* la lambda qui supprime une expression contenant un comparateur  */

};



#endif