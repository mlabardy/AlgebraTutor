/*!
 * \file for.hpp
 * \brief 
 * \version 1.0
 */

#ifndef FOR
#define FOR

#include "expression.hpp"
#include "comparatorFactory.hpp"
#include "affectation.hpp"
#include "block.hpp"


class For: public Expression
{
public:
	/*!
     * \brief Constructeur
     *
     * Constructeur de la classe For
     */
	For(Affectation *, ComparatorFactory *, Affectation *, Block *);

	/*!
     * \brief Destructeur
     *
     * Destructeur de la classe For
     */
	~For();

	/*!
     * \brief Evalue une boucle for
     * \return L'évaluation de la boucle for
     *
     * Méthode qui renvoie l'évaluation de la boucle for
     */
	double eval();

	/*!
     * \brief Affiche une boucle for
     * \return Une chaîne de charactères représentant une boucle for
     *
     * Affiche une boucle for
     */
	std::string display() const;

	/*!
     * \brief Affiche une boucle for
     * \param os : le flux de sortie
     * \param loop : la boucle for à afficher
     * \return Le flux contenant la boucle for
     *
     * Affiche une boucle for sur le flux indiqué
     */
	friend std::ostream & operator << (std::ostream & os, const For & loop);

private:
	Affectation * _start; /*!< L'initialisation de la boucle */
	ComparatorFactory * _condition; /*!< La condition de la boucle */
	Affectation * _next; /*!< La condition d'arret de la boucle */
	Block * _expressions; /*!< Un bloc d'expressions à itérer */

	/*!
     * \brief Constructeur de copie
     */
	For(const For &);

	/*!
	 * \bref Surcharge de l'opérateur =
	 */
	void operator = (const For &);
};



#endif
