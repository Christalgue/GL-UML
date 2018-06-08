/************************************************************************************
Donnees  -  description
-------------------
d・ｽE・ｽE・ｽE・ｽbut                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <Donnees> (fichier Donnees.h) ----------------
#if ! defined ( Donnees_H )
#define Donnees_H

//--------------------------------------------------- Interfaces utilis・ｽE・ｽE・ｽE・ｽes
#include "Empreinte.h"
#include <string>
#include <vector>
#include <map>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R・ｽE・ｽE・ｽE・ｽle de la classe <Donnees>
//------------------------------------------------------------------------



class Donnees
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- M・ｽE・ｽE・ｽE・ｽthodes publiques
    
	void addMetaDonnees(pair<string,string> paire);

	void addDictionnaire(pair<string,Empreinte> paire);

	void addEnsembleEmpreinte(Empreinte e);

    void clearEnsembleEmpreinte();

    map<string, string> getMetaDonnees();
	
	multimap<string, Empreinte> getDictionnaire();

    vector<Empreinte> getEnsembleEmpreinte();

	//------------------------------------------------- Surcharge d'op・ｽE・ｽE・ｽE・ｽrateurs
	Donnees & operator = (const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'op・ｽE・ｽE・ｽE・ｽrateur = pour des objets Donnees.
	// Contrat :
	// d・ｽE・ｽE・ｽE・ｽclar・ｽE・ｽE・ｽE・ｽEmais non d・ｽE・ｽE・ｽE・ｽfini pour intercepter son ・ｽE・ｽE・ｽE・ｽventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Donnees(const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Donnees.
	// Contrat :
	// d・ｽE・ｽE・ｽE・ｽclar・ｽE・ｽE・ｽE・ｽEmais non d・ｽE・ｽE・ｽE・ｽfini pour intercepter son ・ｽE・ｽE・ｽE・ｽventuel appel.

	Donnees();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans param・ｽE・ｽE・ｽE・ｽtre) par d・ｽE・ｽE・ｽE・ｽfaut des objets Donnees.

	virtual ~Donnees();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Donnees.
        

	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- M・ｽE・ｽE・ｽE・ｽthodes prot・ｽE・ｽE・ｽE・ｽg・ｽE・ｽE・ｽE・ｽes

	//----------------------------------------------------- Attributs prot・ｽE・ｽE・ｽE・ｽg・ｽE・ｽE・ｽE・ｽs
    map<string, string> metaDonnees;

	multimap<string, Empreinte> dictionnaire;

	vector<Empreinte> ensembleEmpreinte;
	
};

//-------------------------------- Autres d・ｽE・ｽE・ｽE・ｽfinitions d・ｽE・ｽE・ｽE・ｽpendantes de <Donnees>

#endif // Donnees_H
