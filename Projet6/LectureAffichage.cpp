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
#include "Donnees.h"
#include "Empreinte.h"
#include "Maladie.h"
#include <fstream>
#include <iostream>
#include <sstream>
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void LectureAffichage::LectureMetaDonnees(string nomFichier) 
{	
	ifstream infile(nomFichier);

	if (infile)
	{
		string nomAttribut;
		string typeAttribut;
		map<string, string>::iterator it = infoSysteme.metaDonnees.begin();
		getline(infile, nomAttribut); // Pour sauter la 1�re ligne qui ne nous int�resse pas

		while (getline(infile, nomAttribut, ';'))
		{
			getline(infile, typeAttribut);
			infoSysteme.metaDonnees.insert(it, make_pair(nomAttribut, typeAttribut));
			cout << nomAttribut << " => " << typeAttribut << endl;
		}
		// Pour regarder si la map est bien remplie
		/*for (map<string, string>::iterator ita = infoSysteme.metaDonnees.begin(); ita != infoSysteme.metaDonnees.end(); ++ita)
		{
			cout << ita->first << " => " << ita->second << endl;
		}*/
	}
	else {
		cout << "Il n'y a pas de metadonn�es" << endl;
	}
}

void LectureAffichage::LectureDictionnaire(string nomFichier)
{
	ifstream infile(nomFichier);

	if (infile)
	{
		multimap<string, Empreinte>::iterator itMultimap = infoSysteme.dictionnaire.begin();
		string valeurAttribut;
		string ligne;
		getline(infile,ligne); // 1�re ligne inutile
		
		while (!infile.eof())
		{
			getline(infile, ligne);

			vector<string> valeurs;
			stringstream fluxString(ligne);

			string id;
			//getline(fluxString, ligne);
			getline(fluxString, id, ';');

			//cout << ligne << endl;

			cout << id << endl;

			while (getline(fluxString, valeurAttribut, ';'))
			{
				valeurs.push_back(valeurAttribut);
				cout << "Valeur : " << valeurAttribut << endl;
			}
			string nomMaladie = valeurAttribut;
			//getline(fluxString, nomMaladie);
			cout << "Valeur M : " << nomMaladie << endl;

			if (!nomMaladie.empty()) {
				Empreinte e(stoi(id), valeurs);
				infoSysteme.dictionnaire.insert(make_pair(nomMaladie, e));
			}
		}
	}

	for (multimap<string, Empreinte>::iterator ita = infoSysteme.dictionnaire.begin(); ita != infoSysteme.dictionnaire.end(); ++ita)
	{
		cout << ita->first << " => " << ita->second.getID() << endl;
	}
}

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

LectureAffichage::LectureAffichage() : infoSysteme()
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