/************************************************************************************
EMPREINTE  -  description
-------------------
début                : 10/01/2018
copyright            : (C) 2018 par 
e-mail               : 
*************************************************************************************/

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( EMPREINTE_H )
#define EMPREINTE_H

//--------------------------------------------------- Interfaces utilisées
#include "Maladie.h"
#include "Donnees.h"

#include <string>
#include <vector>
#include <map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Empreinte>
//------------------------------------------------------------------------

class Empreinte
{
	//----------------------------------------------------------------- PUBLIC

public:
	

	//----------------------------------------------------- Méthodes publiques

	int getID();

	Maladie* getMaladie();

	//------------------------------------------------- Surcharge d'opérateurs
	Empreinte & operator = (const Empreinte & unEmpreinte) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'opérateur = pour des objets Empreinte.
	// Contrat :
	// déclaré mais non défini pour intercepter son éventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Empreinte(const Empreinte & unEmpreinte) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Empreinte.
	// Contrat :
	// déclaré mais non défini pour intercepter son éventuel appel.

	Empreinte(int id, Maladie * maMaladie, vector<string> mesValeurs);

	Empreinte();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans paramètre) par défaut des objets Empreinte.

	virtual ~Empreinte();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Empreinte.

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

	int ID;
	Maladie *maMaladie;
	vector<string> valeurs;	
};

//-------------------------------- Autres définitions dépendantes de <Empreinte>

#endif // EMPREINTE_H