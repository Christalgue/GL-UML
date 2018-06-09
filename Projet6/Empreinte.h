/************************************************************************************
EMPREINTE  -  description
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

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( EMPREINTE_H )
#define EMPREINTE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>

//------------------------------------------------------------------------
// Rôle de la classe <Empreinte>
// Représente une empreinte à analyser avec son ID et un vecteur de string 
// représentant les valeurs de chaque attributs.
//------------------------------------------------------------------------

using namespace std;

class Empreinte
{
	//----------------------------------------------------------------- PUBLIC

public:
	
	//----------------------------------------------------- Méthodes publiques
	int getID();

	map <string,string> getValeurEmpreinte();

	//------------------------------------------------- Surcharge d'opérateurs
	Empreinte & operator = (const Empreinte & unEmpreinte) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'opérateur = pour des objets Empreinte.
	// Contrat :
	// Déclaré mais non défini pour intercepter son éventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Empreinte(const Empreinte & unEmpreinte) = default;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Empreinte.
	// Contrat :
	// Déclaré mais non défini pour intercepter son éventuel appel.

	Empreinte(int id, map<string,string> mesValeurs);

	Empreinte();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans paramètre) par défaut des objets Empreinte.

	virtual ~Empreinte();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Empreinte.
    
protected:
	//----------------------------------------------------- Attributs protégés
	int ID;
    
	map <string,string> valeursAttributsEmpreinte;	
};
#endif // EMPREINTE_H