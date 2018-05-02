/************************************************************************************
MALADIE  -  description
-------------------
début                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <Maladie> (fichier Maladie.h) ----------------
#if ! defined ( MALADIE_H )
#define MALADIE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Maladie>
//------------------------------------------------------------------------

class Maladie
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	string getNom();

	//------------------------------------------------- Surcharge d'opérateurs
	Maladie & operator = (const Maladie & unMaladie) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'opérateur = pour des objets Maladie.
	// Contrat :
	// déclaré mais non défini pour intersepter son éventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Maladie(const Maladie & unMaladie) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Maladie.
	// Contrat :
	// déclaré mais non défini pour intersepter son éventuel appel.

	Maladie(string nomMaladie);

	Maladie();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans paramètre) par défaut des objets Maladie.



	virtual ~Maladie();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Maladie.

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

	string nom;

};

//-------------------------------- Autres définitions dépendantes de <Maladie>

#endif // MALADIE_H