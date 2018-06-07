/************************************************************************************
Donnees  -  description
-------------------
d�E�but                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <Donnees> (fichier Donnees.h) ----------------
#if ! defined ( Donnees_H )
#define Donnees_H

//--------------------------------------------------- Interfaces utilis�E�es
#include "Empreinte.h"
#include <string>
#include <vector>
#include <map>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�E�le de la classe <Donnees>
//------------------------------------------------------------------------



class Donnees
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- M�E�thodes publiques
    
        map<string, string> getMetaDonnees();

        multimap<string, Empreinte> getDictionnaire();

        vector<Empreinte> getEnsembleEmpreinte();

	//------------------------------------------------- Surcharge d'op�E�rateurs
	Donnees & operator = (const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'op�E�rateur = pour des objets Donnees.
	// Contrat :
	// d�E�clar�E�Emais non d�E�fini pour intercepter son �E�ventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Donnees(const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Donnees.
	// Contrat :
	// d�E�clar�E�Emais non d�E�fini pour intercepter son �E�ventuel appel.

	Donnees();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans param�E�tre) par d�E�faut des objets Donnees.

	virtual ~Donnees();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Donnees.
        

	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- M�E�thodes prot�E�g�E�es

	//----------------------------------------------------- Attributs prot�E�g�E�s
        map<string, string> metaDonnees;

	multimap<string, Empreinte> dictionnaire;

	vector<Empreinte> ensembleEmpreinte;
	
};

//-------------------------------- Autres d�E�finitions d�E�pendantes de <Donnees>

#endif // Donnees_H
