/************************************************************************************
LectureAffichage  -  description
-------------------
d�but                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <LectureAffichage> (fichier LectureAffichage.h) ----------------
#if ! defined ( LectureAffichage_H )
#define LectureAffichage_H

//--------------------------------------------------- Interfaces utilis�es
#include "Maladie.h"
#include "Donnees.h"
#include <string>
#include <vector>
#include <map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <LectureAffichage>
//------------------------------------------------------------------------

class LectureAffichage
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	void LectureMetaDonnees(string nomFichierMetaDonnee);

	void LectureDictionnaire(string nomFichierDictionnaire);

       void AfficherMaladiesPrisesEnCompte();
        
        
	//------------------------------------------------- Surcharge d'op�rateurs
	LectureAffichage & operator = (const LectureAffichage & unLectureAffichage) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'op�rateur = pour des objets LectureAffichage.
	// Contrat :
	// d�clar�Emais non d�fini pour intercepter son �ventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	LectureAffichage(const LectureAffichage & unLectureAffichage) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet LectureAffichage.
	// Contrat :
	// d�clar�Emais non d�fini pour intercepter son �ventuel appel.

	LectureAffichage();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans param�tre) par d�faut des objets LectureAffichage.

	virtual ~LectureAffichage();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets LectureAffichage.

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es


	//----------------------------------------------------- Attributs prot�g�s
	Donnees infoSysteme;
};

//-------------------------------- Autres d�finitions d�pendantes de <LectureAffichage>

#endif // LectureAffichage_H