/************************************************************************************
LectureAffichage  -  description
-------------------
dÈbut                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <LectureAffichage> (fichier LectureAffichage.h) ----------------
#if ! defined ( LectureAffichage_H )
#define LectureAffichage_H

//--------------------------------------------------- Interfaces utilisÈes
#include "Maladie.h"
#include "Donnees.h"
#include <string>
#include <vector>
#include <map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// RÙle de la classe <LectureAffichage>
//------------------------------------------------------------------------

class LectureAffichage
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- MÈthodes publiques

	void LectureMetaDonnees(string nomFichierMetaDonnee);

	void LectureDictionnaire(string nomFichierDictionnaire);


	//------------------------------------------------- Surcharge d'opÈrateurs
	LectureAffichage & operator = (const LectureAffichage & unLectureAffichage) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'opÈrateur = pour des objets LectureAffichage.
	// Contrat :
	// dÈclarÅEmais non dÈfini pour intercepter son Èventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	LectureAffichage(const LectureAffichage & unLectureAffichage) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet LectureAffichage.
	// Contrat :
	// dÈclarÅEmais non dÈfini pour intercepter son Èventuel appel.

	LectureAffichage();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans paramËtre) par dÈfaut des objets LectureAffichage.

	virtual ~LectureAffichage();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets LectureAffichage.

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- MÈthodes protÈgÈes


	//----------------------------------------------------- Attributs protÈgÈs
	Donnees infoSysteme;
};

//-------------------------------- Autres dÈfinitions dÈpendantes de <LectureAffichage>

#endif // LectureAffichage_H