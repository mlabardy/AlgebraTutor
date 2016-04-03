#ifndef IFELSE
#define IFELSE

/*!
 * \file ifElse.hpp
 * \brief Gestion des if else
 * \version 1.0
 */
#include "expression.hpp"
#include "block.hpp"


class IfElse: public Expression
{
public:
	/*!
     * \brief Constructeur
     *
     * Constructeur de la classe IfElse
     */
	IfElse(Expression *, Block *, Block *);

	/*!
     * \brief Destructeur
     *
     * Destructeur de la classe IfElse
     */
	~IfElse();

	/*!
     * \brief Evalue une clause if else
     * \return L'évaluation de la clause if else
     *
     * Méthode qui renvoie l'évaluation de la clause if else
     */
	double eval();

	/*!
     * \brief Affiche un if else
     * \return Une chaîne de charactères représentant un if else
     *
     * Affiche une clause if else
     */
	std::string display() const;

	/*!
     * \brief Affiche une clause if else
     * \param os : le flux de sortie
     * \param expression : la clause if else à afficher
     * \return Le flux contenant le if else
     *
     * Affiche une clause if else sur le flux indiqué
     */
	friend std::ostream & operator << (std::ostream & os, const IfElse & ifElse);

private:
	Expression * _comparator; /*!< L'expression à évaluer */
	Block * _expressions; /*!< Un bloc d'expressions à retourner */
	Block * _otherExpressions; /*!< Un autre bloc d'expressions à retourner */
};

#endif
