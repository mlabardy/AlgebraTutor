#ifndef OPERATOR
#define OPERATOR

/*!
 * \file operator.hpp
 * \brief Gestion des operateurs
 * \version 1.0
 */
#include <iostream>

/*! 
 * \namespace Operator
 * 
 * Espace de nommage regroupant les opérateurs
 */
namespace Operator 
{
	/*! 
	 * \enum Unary
	 * 
	 * Regroupe tous les opérateurs unaires
	 */
	typedef enum 
	{
		COS, /*!< L'opérateur cosinus */
		SIN, /*!< L'opérateur sinus */
		EXP, /*!< L'opérateur exposant */
		TAN, /*!< L'opérateur tangente */
		ATAN, /*!< L'opérateur arctangente */
		ACOS, /*!< L'opérateur arcosinus */
		ASIN /*!< L'opérateur arcsinus */
	} Unary;

	/*! 
	 * \enum Binary
	 * 
	 * Regroupe tous les opérateurs binaires
	 */
	typedef enum 
	{
		ADD, /*!< L'opérateur somme */
		SUB, /*!< L'opérateur soustraction */
		DIV, /*!< L'opérateur division */
		MUL, /*!< L'opérateur multiplication */
		LOE, /*!< L'opérateur inférieur ou égal */
		GOE, /*!< L'opérateur supérieur ou égal */
		LT, /*!< L'opérateur strictement inférieur */
		GT, /*!< L'opérateur strictement supérieur */
		EQ, /*!< L'opérateur égalité */
		DIF /*!< L'opérateur différence */
	} Binary;
	
	/*!
     * \brief Affiche le symbole de l'opérateur binaire
     * \param binary : l'opérateur binaire
     * \return Le symbole de l'opérateur en chaîne de caractères
     *
     * Affiche le symbole de l'opérateur binaire
     */
	const std::string name(Binary);

	/*!
     * \brief Affiche le symbole de l'opérateur unaire
     * \param unaire : l'opérateur unaire
     * \return Le symbole de l'opérateur en chaîne de caractères
     *
     * Affiche le symbole de l'opérateur unaire
     */
	const std::string name(Unary);
}

#endif
