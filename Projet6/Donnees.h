/************************************************************************************
DONNEES  -  description
-------------------
début                : 10/01/2018
copyright            : (C) 2018 par COCQUIO-LESBRENE Clementine
                                    FERY Simon
                                    GIBERT Christophe
                                    SIMONIN Joseph
e-mail               : clementine.coquio--lebresne@insa-lyon.fr
                       simon.fery@insa-lyon.fr
                       christophe.gibert@insa-lyon.fr
                       joseph.simonin@insa-lyon.fr
*************************************************************************************/

//---------- Interface de la classe <Donnees> (fichier Donnees.h) ----------------
#if ! defined ( Donnees_H )
#define Donnees_H

//--------------------------------------------------- Interfaces utilisées
#include "Empreinte.h"
#include <string>
#include <vector>
#include <map>

//------------------------------------------------------------------------
// Rôle de la classe <Donnees>
// Cette classe contient les structures de données pour les métadonnées, le
// dictionnaire de maladies et l'ensemble des empreintes que l'on veut analyser.
// Elle contient aussi des méthodes pour y accèder, ajouter des éléments ou 
// vider les structures.
//------------------------------------------------------------------------

class Donnees
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- Méthodes publiques
    
	void addMetaDonnees(pair<string,string> paire);

	void addDictionnaire(pair<string,Empreinte> paire);

	void addEnsembleEmpreinte(Empreinte e);
    
    void clearMetaDonnees();

    void clearDictionnaire();
    
    void clearEnsembleEmpreinte();

    map<string, string> getMetaDonnees();
	
	multimap<string, Empreinte> getDictionnaire();

    vector<Empreinte> getEnsembleEmpreinte();

	//------------------------------------------------- Surcharge d'opérateurs
	Donnees & operator = (const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'opérateur = pour des objets Donnees.
	// Contrat :
	// Déclaré mais non défini pour intercepter son éventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Donnees(const Donnees & unDonnees) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Donnees.
	// Contrat :
	// Déclaré mais non défini pour intercepter son éventuel appel.

	Donnees();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans paramètre) par défaut des objets Donnees.

	virtual ~Donnees();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Donnees.
        
protected:
    
	//----------------------------------------------------- Attributs protégés
    map<string, string> metaDonnees;

	multimap<string, Empreinte> dictionnaire;

	vector<Empreinte> ensembleEmpreinte;
};
#endif // Donnees_H
