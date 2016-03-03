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
     * spécifié en paramètre
     */
	void set(double value);

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
	static std::map<std::string, double> _variables; /*!< L'ensemble des variables du programme */
};

#endif
