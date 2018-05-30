/************************************************************************************
LectureAffichage  -  description
-------------------
début                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <LectureAffichage> (fichier LectureAffichage.h) ----------------
#if ! defined ( LectureAffichage_H )
#define LectureAffichage_H

//--------------------------------------------------- Interfaces utilisées
#include "Maladie.h"
#include "Donnees.h"
#include <string>
#include <vector>
#include <map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LectureAffichage>
//------------------------------------------------------------------------

class LectureAffichage
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	void LectureMetaDonnees();


	//------------------------------------------------- Surcharge d'opérateurs
	LectureAffichage & operator = (const LectureAffichage & unLectureAffichage) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'opérateur = pour des objets LectureAffichage.
	// Contrat :
	// déclaré mais non défini pour intercepter son éventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	LectureAffichage(const LectureAffichage & unLectureAffichage) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet LectureAffichage.
	// Contrat :
	// déclaré mais non défini pour intercepter son éventuel appel.

	LectureAffichage();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans paramètre) par défaut des objets LectureAffichage.

	virtual ~LectureAffichage();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets LectureAffichage.

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées


	//----------------------------------------------------- Attributs protégés
	Donnees infoSysteme;
};

//-------------------------------- Autres définitions dépendantes de <LectureAffichage>

#endif // LectureAffichage_H