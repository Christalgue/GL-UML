/************************************************************************************
Donnees  -  description
-------------------
d�but                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <Donnees> (fichier Donnees.h) ----------------
#if ! defined ( Donnees_H )
#define Donnees_H

//--------------------------------------------------- Interfaces utilis�es
#include "Maladie.h"
#include "Empreinte.h"
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Donnees>
//------------------------------------------------------------------------



class Donnees
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- M�thodes publiques

	//------------------------------------------------- Surcharge d'op�rateurs
	Donnees & operator = (const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'op�rateur = pour des objets Donnees.
	// Contrat :
	// d�clar�Emais non d�fini pour intercepter son �ventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Donnees(const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Donnees.
	// Contrat :
	// d�clar�Emais non d�fini pour intercepter son �ventuel appel.

	Donnees();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans param�tre) par d�faut des objets Donnees.

	virtual ~Donnees();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Donnees.


	map<string, string> metaDonnees;

	multimap<string, Empreinte> dictionnaire;

	vector<Empreinte> ensembleEmpreinte;

	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
    
	
};

//-------------------------------- Autres d�finitions d�pendantes de <Donnees>

#endif // Donnees_H
