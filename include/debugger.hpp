#ifndef DEBUGGER
#define DEBUGGER

/*!
 * \file debugger.hpp
 * \brief Gestion du mode debug
 * \version 1.0
 */

/*! 
 * \class Debugger
 * \brief Classe représentant le mode debug
 *
 * Gère le mode debug 
 */
class Debugger
{
public:
	/*! 
	 * \brief Détermine l'activation du mode debug
	 * \param boolean : un booléen activant ou désactivant le mode debug
	 *
	 * Active ou désactive le mode debug selon le paramètre
	 */
	void set(bool);

	/*! 
	 * \brief Affiche une chaîne de caractères sur le flux de sortie spécifié
	 * \param os : le flux de sortie
	 * \param message : le message à afficher
	 *
	 * Affiche le message sur le flux de sortie spécifié lorsque le mode debug est activé 
	 */
	void debug(std::ostream &, const std::string &);

	/*! 
	 * \brief Affiche une chaîne de caractères sur le flux d'erreur
	 * \param message : le message à afficher
	 *
	 * Affiche le message sur la sortie d'erreur lorsque le mode debug est activé 
	 */
	void debug(const std::string &);

	/*! 
	 * \brief Retourne une unique instance de Debugger
	 * \return debugger : la référence vers le debugger
	 */
	static Debugger & instance();

private:
	bool _activate; /*!< Determine l'activation du mode debug */
 
	static Debugger d; /*!< Une instance de Debugger */

	/*!
	 * Constructeur
	 */
	Debugger();

	/*!
	 * Destructeur
	 */
	~Debugger();
	
	// to avoid the copy of the singleton
	
	/*!
	 * \bref Constructeur de copie
	 */
	Debugger(const Debugger &);

	/*!
	 * \bref Surcharge de l'opérateur =
	 */
	void operator = (const Debugger &);
	
};

#endif