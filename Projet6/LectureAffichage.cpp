/*******************************************************************************************
LectureAffichage  -  description
-------------------
d�but                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
********************************************************************************************/


//---------- R�alisation de la classe <LectureAffichage> (fichier LectureAffichage.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;


//------------------------------------------------------ Include personnel
#include "LectureAffichage.h"
#include <fstream>
#include <iostream>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void LectureAffichage::LectureMetaDonnees() {
	string nomAttribut;
	string typeAttribut;
	string nomFichier = "HealthMeasurementDescription.txt";
	ifstream infile(nomFichier);
	if (infile)
	{
		while (getline(infile, nomAttribut, ';'))
		{
			getline(infile, typeAttribut);

			cout << nomAttribut << endl;
			cout << typeAttribut << endl;
		}
	}
	else {
		cout << "Il n'y a pas de metadonn�es" << endl;
	}
}

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

LectureAffichage::LectureAffichage()
// Algorithme : 
{
#ifdef MAP
	cout << "Appel au constructeur de <LectureAffichage>" << endl;
#endif
} //----- Fin de LectureAffichage


LectureAffichage::~LectureAffichage()
{
#ifdef MAP
	cout << "Appel au destructeur de <LectureAffichage>" << endl;
#endif
} //----- Fin de ~LectureAffichage



  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es