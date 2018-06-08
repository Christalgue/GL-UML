/************************************************************************************
Donnees  -  description
-------------------
d�E�E�E�E�E�E�E�but                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <Donnees> (fichier Donnees.h) ----------------
#if ! defined ( Donnees_H )
#define Donnees_H

//--------------------------------------------------- Interfaces utilis�E�E�E�E�E�E�E�es
#include "Empreinte.h"
#include <string>
#include <vector>
#include <map>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�E�E�E�E�E�E�E�le de la classe <Donnees>
//------------------------------------------------------------------------



class Donnees
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- M�E�E�E�E�E�E�E�thodes publiques
    
	void addMetaDonnees(pair<string,string> paire);

	void addDictionnaire(pair<string,Empreinte> paire);

	void addEnsembleEmpreinte(Empreinte e);
    
    void clearMetaDonnees();

    void clearDictionnaire();
    
    void clearEnsembleEmpreinte();

    map<string, string> getMetaDonnees();
	
	multimap<string, Empreinte> getDictionnaire();

    vector<Empreinte> getEnsembleEmpreinte();

	//------------------------------------------------- Surcharge d'op�E�E�E�E�E�E�E�rateurs
	Donnees & operator = (const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'op�E�E�E�E�E�E�E�rateur = pour des objets Donnees.
	// Contrat :
	// d�E�E�E�E�E�E�E�clar�E�E�E�E�E�E�E�Emais non d�E�E�E�E�E�E�E�fini pour intercepter son �E�E�E�E�E�E�E�ventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Donnees(const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Donnees.
	// Contrat :
	// d�E�E�E�E�E�E�E�clar�E�E�E�E�E�E�E�Emais non d�E�E�E�E�E�E�E�fini pour intercepter son �E�E�E�E�E�E�E�ventuel appel.

	Donnees();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans param�E�E�E�E�E�E�E�tre) par d�E�E�E�E�E�E�E�faut des objets Donnees.

	virtual ~Donnees();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Donnees.
        

	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- M�E�E�E�E�E�E�E�thodes prot�E�E�E�E�E�E�E�g�E�E�E�E�E�E�E�es

	//----------------------------------------------------- Attributs prot�E�E�E�E�E�E�E�g�E�E�E�E�E�E�E�s
    map<string, string> metaDonnees;

	multimap<string, Empreinte> dictionnaire;

	vector<Empreinte> ensembleEmpreinte;
	
};

//-------------------------------- Autres d�E�E�E�E�E�E�E�finitions d�E�E�E�E�E�E�E�pendantes de <Donnees>

#endif // Donnees_H
