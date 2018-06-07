/************************************************************************************
Donnees  -  description
-------------------
d・ｽE・ｽbut                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <Donnees> (fichier Donnees.h) ----------------
#if ! defined ( Donnees_H )
#define Donnees_H

//--------------------------------------------------- Interfaces utilis・ｽE・ｽes
#include "Empreinte.h"
#include <string>
#include <vector>
#include <map>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R・ｽE・ｽle de la classe <Donnees>
//------------------------------------------------------------------------



class Donnees
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- M・ｽE・ｽthodes publiques

	//------------------------------------------------- Surcharge d'op・ｽE・ｽrateurs
	Donnees & operator = (const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'op・ｽE・ｽrateur = pour des objets Donnees.
	// Contrat :
	// d・ｽE・ｽclar・ｽE・ｽEmais non d・ｽE・ｽfini pour intercepter son ・ｽE・ｽventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Donnees(const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Donnees.
	// Contrat :
	// d・ｽE・ｽclar・ｽE・ｽEmais non d・ｽE・ｽfini pour intercepter son ・ｽE・ｽventuel appel.

	Donnees();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans param・ｽE・ｽtre) par d・ｽE・ｽfaut des objets Donnees.

	virtual ~Donnees();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Donnees.
        

	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- M・ｽE・ｽthodes prot・ｽE・ｽg・ｽE・ｽes

	//----------------------------------------------------- Attributs prot・ｽE・ｽg・ｽE・ｽs
        map<string, string> metaDonnees;

	multimap<string, Empreinte> dictionnaire;

	vector<Empreinte> ensembleEmpreinte;
	
};

//-------------------------------- Autres d・ｽE・ｽfinitions d・ｽE・ｽpendantes de <Donnees>

#endif // Donnees_H
