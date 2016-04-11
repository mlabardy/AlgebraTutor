/*!
 * \file simplification.hpp
 * \brief 
 * \version 1.0
 */

#ifndef SIMPLIFICATION
#define SIMPLIFICATION

/*!
 * \class Simplification
 * \brief Classe représentant une simplification
 *
 * Gère les simplificatiions
 */
class Simplification: public Expression
{
public:
	/*!
     * \brief Constructeur
     *
     * Constructeur de la classe Constant
     */
	Simplification(double);

	/*!
     * \brief Destructeur
     *
     * Destructeur de la classe Constant
     */
	~Simplification();

	/*!
     * \brief Evalue une constante
     * \return La constante
     *
     * Méthode qui renvoie la constante
     */
	double eval();

	/*!
	 * \brief Retourne la dérivée d'une constante
	 *
	 * Calcul la dérivée d'une constante
	 */
	double derivation();

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
	friend std::ostream & operator << (std::ostream & os, const Simplification & simplification);

}

#endif /* INCLUDE_SIMPLIFICATION_HPP_ */
