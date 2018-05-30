/************************************************************************************
Donnees  -  description
-------------------
début                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <Donnees> (fichier Donnees.h) ----------------
#if ! defined ( Donnees_H )
#define Donnees_H

//--------------------------------------------------- Interfaces utilisées
#include "Maladie.h"

#include <string>
#include <vector>
#include <map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Donnees>
//------------------------------------------------------------------------



class Donnees
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- Méthodes publiques



	//------------------------------------------------- Surcharge d'opérateurs
	Donnees & operator = (const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'opérateur = pour des objets Donnees.
	// Contrat :
	// déclaré mais non défini pour intercepter son éventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Donnees(const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Donnees.
	// Contrat :
	// déclaré mais non défini pour intercepter son éventuel appel.

	Donnees();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans paramètre) par défaut des objets Donnees.

	virtual ~Donnees();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Donnees.



	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Méthodes protégées


	//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Donnees>

#endif // Donnees_H
