/************************************************************************************
Donnees  -  description
-------------------
d・ｽbut                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <Donnees> (fichier Donnees.h) ----------------
#if ! defined ( Donnees_H )
#define Donnees_H

//--------------------------------------------------- Interfaces utilis・ｽes
#include "Maladie.h"
#include "Empreinte.h"
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R・ｽle de la classe <Donnees>
//------------------------------------------------------------------------



class Donnees
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- M・ｽthodes publiques

	//------------------------------------------------- Surcharge d'op・ｽrateurs
	Donnees & operator = (const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'op・ｽrateur = pour des objets Donnees.
	// Contrat :
	// d・ｽclar・ｽEmais non d・ｽfini pour intercepter son ・ｽventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Donnees(const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Donnees.
	// Contrat :
	// d・ｽclar・ｽEmais non d・ｽfini pour intercepter son ・ｽventuel appel.

	Donnees();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans param・ｽtre) par d・ｽfaut des objets Donnees.

	virtual ~Donnees();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Donnees.


	map<string, string> metaDonnees;

	multimap<string, Empreinte> dictionnaire;

	vector<Empreinte> ensembleEmpreinte;

	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- M・ｽthodes prot・ｽg・ｽes

	//----------------------------------------------------- Attributs prot・ｽg・ｽs
    
	
};

//-------------------------------- Autres d・ｽfinitions d・ｽpendantes de <Donnees>

#endif // Donnees_H
