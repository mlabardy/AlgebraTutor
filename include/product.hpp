/*!
 * \file product.hpp
 * \brief 
 * \version 1.0
 */

#ifndef PRODUCT
#define PRODUCT

#include <iostream>

#include "expression.hpp"
#include "variable.hpp"


/*!
 * \class Product
 * \brief Classe représentant un produit
 *
 * Gère les produits
 */
class Product: public Expression
{
public:
	/*!
     * \brief Constructeur
     *
     * Constructeur de la classe Product
     */
	Product(Expression *, Expression *);

	/*!
     * \brief Destructeur
     *
     * Destructeur de la classe Product
     */
	~Product();

	/*!
     * \brief Evalue un produit
     * \return Le produit
     *
     * Méthode qui renvoie un produit
     */
	double eval();

	/*!
	 * \brief Retourne la dérivée d'un produit
	 * \return Une nouvelle expression dérivée
	 *
	 * Calcul la dérivée d'un produit
	 */
	Expression * derivation();

	/*!
	 * \brief Retourne une expression simplifiée
	 * \return Une nouvelle expression simplifiée
	 *
	 * Simplifie un produit
	 */
	Expression * simplification();

	/*!
	 * \brief Détermine le type de l'expression
	 *
	 * Retourne le type de l'expression
	 */
	int type();

	/*!
     * \brief Affiche un produit
     * \return Une chaîne de charactères représentant le produit
     *
     * Affiche un produit
     */
	std::string display() const;

	/*!
     * \brief Affiche une constante
     * \param os : le flux de sortie
     * \param produit : le produit à afficher
     * \return Le flux contenant la constante
     *
     * Affiche une constante sur le flux indiqué
     */
	friend std::ostream & operator << (std::ostream & os, const Product & product);

private:
	Expression * _leftExpression;
	Expression * _rightExpression;

	double _coefficient; /*!< Le coefficient */
	Expression * _variable; /*!< La variable */

	Product(const Product &);
	Expression * aux(Expression *, Expression *);
};



#endif /* INCLUDE_PRODUCT_HPP_ */
