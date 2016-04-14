#ifndef CONDITIONAL
#define CONDITIONAL

/*!
 * \file conditional.hpp
 * \brief Gestion des conditions
 * \version 1.0
 */
#include <iostream>

#include "expression.hpp"
//#include "comparator.hpp"


/*!
 * \class Conditional
 * \brief Classe représentant une conditionelle
 *
 * Gère les ternaires
 */
class Conditional: public Expression
{
public:
	/*!
     * \brief Constructeur
     *
     * Constructeur de la classe Conditional
     */
	Conditional(Expression *, Expression *, Expression *);

	/*!
     * \brief Destructeur
     *
     * Destructeur de la classe Conditional
     */
	~Conditional();

	/*!
     * \brief Evalue une ternaire
     * \return Le résultat de la ternaire
     *
     * Méthode qui renvoie le résultat de la ternaire
     */
	double eval();

	/*!
     * \brief Affiche une ternaire
     * \return Une chaîne de charactères représentant la ternaire
     *
     * Renvoie une ternaire sous forme de chaîne de caractères
     */
	std::string display() const;

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
     * \brief Affiche une ternaire
     * \param os : le flux de sortie
     * \param conditional : la ternaire à afficher
     * \return Le flux contenant la constante
     *
     * Affiche une ternaire sur le flux indiqué
     */
	friend std::ostream & operator << (std::ostream & os, const Conditional & conditional);

private:
	Expression * _comparator; /*!< L'expression à évaluer */
	Expression * _expression; /*!< Une expression à retourner */
	Expression * _otherExpression; /*!< Une autre expression à retourner */

	/*!
     * \brief Constructeur de copie
     */
	Conditional(const Conditional &);

	/*!
	 * \bref Surcharge de l'opérateur =
	 */
	void operator = (const Conditional &);
};

#endif
