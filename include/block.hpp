#ifndef BLOCK
#define BLOCK

/*!
 * \file block.hpp
 * \brief Gestion d'un bloc
 * \version 1.0
 */
#include <list>

#include "expression.hpp"

/*!
 * \class Bloc
 * \brief Classe représentant une conditionelle
 *
 * Gère les ternaires
 */
class Block: public Expression
{
public:
	/*!
     * \brief Constructeur
     *
     * Constructeur de la classe Block
     */
	Block();

	/*!
     * \brief Destructeur
     *
     * Destructeur de la classe Block
     */
	~Block();

	/*!
     * \brief Evalue un bloc
     * \return Le résultat d'un bloc
     *
     * Méthode qui renvoie le résultat de la dernière expression
     */
	double eval();

	/*!
     * \brief Ajoute une expression au bloc
     *
     * Méthode qui rajoute une expression à la fin du bloc
     */
	void add(Expression *);

	/*!
     * \brief Affiche un bloc
     * \return Une chaîne de charactères représentant un bloc
     *
     * Renvoie un bloc sous forme de chaîne de caractères
     */
	std::string display() const;

	/*!
     * \brief Affiche un bloc
     * \param os : le flux de sortie
     * \param block : le bloc à afficher
     * \return Le flux contenant la constante
     *
     * Affiche un bloc sur le flux indiqué
     */
	friend std::ostream & operator << (std::ostream & os, const Block & block);

private:
	std::list<Expression *> _expressions; /*!< Une liste d'expressions */
};


#endif
