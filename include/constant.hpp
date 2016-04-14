#ifndef CONSTANT
#define CONSTANT

/*!
 * \file constant.hpp
 * \brief Gestion des constantes
 * \version 1.0
 */
#include <iostream>

#include "expression.hpp"


/*! 
 * \class Constant
 * \brief Classe représentant une constante
 *
 * Gère les constantes 
 */
class Constant: public Expression
{
public:
	/*!
     * \brief Constructeur
     *
     * Constructeur de la classe Constant
     */
	Constant(double);

	/*!
     * \brief Destructeur
     *
     * Destructeur de la classe Constant
     */
	~Constant();

	/*!
     * \brief Evalue une constante
     * \return La constante
     *
     * Méthode qui renvoie la constante
     */
	double eval();

	/*!
	 * \brief Retourne la valeur de la constante
	 *
	 * Retourne la valeur de la constante courante
	 */
	double value();

	/*!
	 * \brief Retourne la dérivée d'une constante
	 * \return Une nouvelle expression dérivée
	 *
	 * Calcul la dérivée d'une constante
	 */
	Expression * derivation();

	/*!
	 * \brief Retourne une expression simplifiée
	 * \return Une nouvelle expression simplifiée
	 *
	 * Simplifie une constante
	 */
	Expression * simplification();

	/*!
	 * \brief Détermine le type de l'expression
	 *
	 * Retourne le type de l'expression
	 */
	int type();

	/*!
     * \brief Affiche une constante
     * \return Une chaîne de charactères représentant la constante
     *  
     * Affiche une constante
     */
	std::string display() const;

	/*!
     * \brief Affiche une constante
     * \param os : le flux de sortie
     * \param expression : la constante à afficher
     * \return Le flux contenant la constante
     *
     * Affiche une constante sur le flux indiqué
     */
	friend std::ostream & operator << (std::ostream & os, const Constant & constant);
	
private:
	const double _value; /*!< La constante */

	Constant(const Constant &);
};

#endif
