#ifndef EXPRESSION
#define EXPRESSION

/*!
 * \file expression.hpp
 * \brief Gestion d'expressions
 * \version 1.0
 */
#include <iostream>

/*! 
 * \class Expression
 * \brief Classe représentant une expression
 *
 * Gère tous les types d'expressions algébriques 
 */
class Expression
{
public:
	/*!
     * \brief Constructeur
     *
     * Constructeur de la classe Expression
     */
	Expression();

	/*!
     * \brief Destructeur
     *
     * Destructeur de la classe Expression
     */
	virtual ~Expression();

	/*!
     * \brief Evalue une expression
     * \return Le résultat de l'expression algébrique
     *
     * Méthode qui renvoie le résultat de l'expression algébrique
     */
	virtual double eval() = 0;

	/*!
     * \brief Affiche une expression
     * \return Une chaîne de charactères représentant l'espression
     *  
     * Affiche une expression algébrique
     */
	virtual std::string display() const = 0;

	/*!
     * \brief Simplifie une expression
     * \return L'espression simplifiée
     *
     * Simplifie une expression
     */
	virtual Expression * simplification() = 0;

	/*!
     * \brief Dérive une expression
     * \return Une expression dérivée
     *
     * Dérive une expression
     */
	virtual Expression * derivation() = 0;

	/*!
     * \brief Supprime toutes les expressions
     *
     * Supprime itérativement toutes les expressions de l'arbre
     */
	static void deleteAll();

	/*!
     * \brief Affiche une expresssion
     * \param os : le flux de sortie
     * \param expression : l'espression à afficher
     * \return Le flux contenant l'espression
     *
     * Affiche une expression sur le flux indiqué
     */
	friend std::ostream & operator << (std::ostream & os, const Expression & expression);

};

#endif
