#ifndef AFFECTATION
#define AFFECTATION

/*!
 * \file affectation.hpp
 * \brief Gestion des affectations
 * \version 1.0
 */
#include <iostream>

#include "expression.hpp"
#include "variable.hpp"

/*! 
 * \class Affectation
 * \brief Classe représentant une affectation
 *
 * Gère les affectations de variables
 */
class Affectation: public Expression
{
public:
	/*! 
	 * \brief Constructeur
	 * \param variable : la variable à affecter
	 * \param expression : l'expression à associer
	 *
	 * Constructeur de la class Affectation 
	 */
	Affectation(Variable *, Expression *);

	/*! 
	 * \brief Destructeur
	 *
	 * Destructeur de la class Affectation 
	 */
	~Affectation();

	/*!
     * \brief Evalue une affectation
     * \return Le résultat de l'affectation
     *
     * Méthode qui renvoie le résultat de l'expression algébrique
     */
	double eval();

	/*!
     * \brief Affiche une affectation
     * \return Une chaîne de charactères représentant l'affectation 
     *  
     * Affiche une expression algébrique associée à une variable
     */
	std::string display() const;

	/*!
     * \brief Affiche une affectation
     * \param os : le flux de sortie
     * \param affectation : l'affectation à afficher
     * \return Le flux contenant l'affectation
     *
     * Affiche une affectation sur le flux indiqué
     */
	friend std::ostream & operator << (std::ostream & os, const Affectation & affectation);

private:
	Variable * _variable; /*!< La variable à affecter */

	Expression * _expression; /*!< L'expression à associer à la variable */

};

#endif
