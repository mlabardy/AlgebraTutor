#ifndef VARIABLE
#define VARIABLE

/*!
 * \file variable.hpp
 * \brief Gestion des variables
 * \version 1.0
 */
#include <iostream>
#include <map>
#include "expression.hpp"


/*! 
 * \class Variable
 * \brief Classe représentant une variable
 *
 * Gère les variables 
 */
class Variable: public Expression
{
public:
	/*!
     * \brief Constructeur
     * \param string : l'identifiant de la variable
     * \param value : la valeur de la variable
     *
     * Constructeur de la classe Variable
     */
	Variable(const std::string &, double);

	/*!
     * \brief Constructeur
     * \param string : l'identifiant de la variable
     *
     * Constructeur de la classe Variable
     */
	Variable(const std::string &);

	/*!
     * \brief Destructeur
     *
     * Destructeur de la classe Variable
     */
	~Variable();

	/*!
     * \brief Evalue une variable
     * \return Le résultat de l'expression dans la variable
     *
     * Méthode qui renvoie résultat de l'expression dans la variable
     */
	double eval();

	/*!
     * \brief Affiche une constante
     * \return Une chaîne de charactères représentant la constante
     *  
     * Affiche une constante
     */
	std::string display() const;

	/*!
     * \brief Modifie la valeur d'une variable
     * \param value : la nouvelle valeur à assigner
     *
     * Modifie la valeur de la variable avec la nouvelle valeur 
     * spécifiée en paramètre
     */
	void set(double value);

	/*!
     * \brief Modifie la valeur d'une variable
     * \param value : la nouvelle expression à assigner
     *
     * Modifie la valeur de la variable avec la nouvelle expression
     * spécifiée en paramètre
     */
	void set(Expression * value);

	/*!
	 * \brief Ré-insère la valeur précedente dans la variable
	 *
	 * Remet la valeur de la variable à l'instant précedent
	 */
	void rollback();

	/*!
	 * \brief Retourne l'identifiant
	 *
	 * Retourne l'identifiant de la variable courante
	 */
	std::string id();

	/*!
	 * \brief Retourne la dérivée d'une variable
	 * \return Une nouvelle expression dérivée
	 *
	 * Calcul la dérivée d'une variable
	 */
	Expression * derivation();

	/*!
	 * \brief Retourne une expression simplifiée
	 * \return Une nouvelle expression simplifiée
	 *
	 * Simplifie une variable
	 */
	Expression * simplification();

	/*!
	 * \brief Détermine le type de l'expression
	 *
	 * Retourne le type de l'expression
	 */
	int type();

	/*!
     * \brief Supprime les variables
     *
     * Supprime toutes les variables precedement crées
     */
	static void deleteAll();

	/*!
     * \brief Affiche une variable
     * \param os : le flux de sortie
     * \param variable : la variable à afficher
     * \return Le flux contenant la variable
     *
     * Affiche une variable sur le flux indiqué
     */
	friend std::ostream & operator << (std::ostream & os, const Variable & variable);

private:
	const std::string _id; /*!< L'identifiant de la variable */
	double _previousValue; /*!< Stock la valeur précédente */
	static std::map<std::string, double> _variables; /*!< L'ensemble des variables du programme */
};

#endif
