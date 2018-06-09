/************************************************************************************
LECTUREAFFICHAGE  -  description
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

//---------- Interface de la classe <LectureAffichage> (fichier LectureAffichage.h) ----------------
#if ! defined ( LectureAffichage_H )
#define LectureAffichage_H

//--------------------------------------------------- Interfaces utilisées
#include "Donnees.h"
#include <string>
#include <vector>
#include <map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LectureAffichage>
// Classe qui s'occupe de la lecture des fichiers métadonnées, dictionnaire 
// et des empreintes à analyser. Elle s'occupe aussi des analyses et de renvoyer
// l'affichage.
//------------------------------------------------------------------------

using namespace std;

class LectureAffichage
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	void LectureMetaDonnees(string nomFichierMetaDonnee);

	void LectureDictionnaire(string nomFichierDictionnaire);

	void LectureEmpreintes(string nomFichierEmpreintes);
	
	void AfficherMaladiesPrisesEnCompte();
    
	map<string, pair<string, string>> AfficherCaracteristiquesMaladie(string maladie, bool affichage);

	void DemandeAnalyse();
        
	//------------------------------------------------- Surcharge d'opérateurs
	LectureAffichage & operator = (const LectureAffichage & unLectureAffichage) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'opérateur = pour des objets LectureAffichage.
	// Contrat :
	// Déclaré mais non défini pour intercepter son éventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	LectureAffichage(const LectureAffichage & unLectureAffichage) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet LectureAffichage.
	// Contrat :
	// Déclaré mais non défini pour intercepter son éventuel appel.

	LectureAffichage();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans paramétre) par défaut des objets LectureAffichage.

	virtual ~LectureAffichage();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets LectureAffichage.

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Attributs protégés
	Donnees infoSysteme;

	string types[3] = {"string", "double", "int"};
};
#endif // LectureAffichage_H