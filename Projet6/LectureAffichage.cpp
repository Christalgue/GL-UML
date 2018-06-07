﻿/*******************************************************************************************
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

using std::string;
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
		map<string, string>::iterator it = infoSysteme.getMetaDonnees().begin();
		getline(infile, nomAttribut); // Pour sauter la 1�re ligne qui ne nous int�resse pas

		getline(infile, nomAttribut); // La deuxieme ligne comprend l'id qui ne doit pas rentrer dans la metadonnee

		while (getline(infile, nomAttribut, ';'))
		{
			getline(infile, typeAttribut);
			infoSysteme.addMetaDonnees(make_pair(nomAttribut, typeAttribut));
			//cout << nomAttribut << " => " << typeAttribut << endl;
		}
		map<string, string> maMap = infoSysteme.getMetaDonnees();
		// Pour regarder si la map est bien remplie
		for (map<string, string>::iterator ita = maMap.begin(); ita != maMap.end(); ++ita)
		{
			cout << ita->first << " => " << ita->second << endl;
		}
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
		//multimap<string, Empreinte>::iterator itMultimap = infoSysteme.getDictionnaire().begin();
		string valeurAttribut;
		string nomAttribut;
		string ligne;

		vector <string>  attributs; 

		getline(infile,ligne);
                
                /* Comme c'est compliqué d'obtenir les valeurs d'attributs et de savoir en même temps si on est au niveau de la lecture du nom de
                 la maladie, on lit la ligne du fichier, on transforme cette ligne en un flux pour le lire avec getline et comme on sait qu'après 
                 le dernier ';' c'est la maladie, on récupère toute la ligne facilement. Le problème qui était posé par la lecture direct du fichier
                 était que le dernier caractère était le retour à la ligne. Bref, ça marche bien comme ça :D*/
                
		stringstream fluxString(ligne);
		
                // On récupère d'abord le nom de tous les attributs via la 1ère ligne du fichier
		while (getline(fluxString, nomAttribut, ';'))
		{
			attributs.push_back(nomAttribut);
			//cout << "Valeur : " << nomAttribut << endl;
		}
                
                // On récupère maintenant les valeurs des attributs
		while (!infile.eof())
		{
			getline(infile, ligne);
			if (!ligne.empty()) {
				map <string, string> valeurs;
				stringstream fluxString(ligne);

				string id;
				getline(fluxString, id, ';');

				//cout << ligne << endl;
				//cout << id << endl;
				vector<string>::iterator it = attributs.begin();
				++it;
				while (getline(fluxString, valeurAttribut, ';'))
				{
					// La maladie est stockée dans les valeurs
					valeurs.insert(make_pair(*it, valeurAttribut));
					//cout << "Valeur : " << *it << " => " << valeurAttribut << endl;
					++it;
				}
				--it;
				// Effacer la maladie de la map
				map<string, string>::iterator mal = valeurs.find(*it);
				valeurs.erase(mal);

				string nomMaladie = valeurAttribut;
				//getline(fluxString, nomMaladie);
				//cout << "Valeur M : " << nomMaladie << endl;

				if (!nomMaladie.empty()) {
					Empreinte e(stoi(id), valeurs);
					infoSysteme.addDictionnaire(make_pair(nomMaladie, e));
				}
			}
		}
	}
	// AFFICHAGE (A METTRE DANS LE TEST)
	/*
	multimap<string, Empreinte> monDictionnaire = infoSysteme.getDictionnaire();
	for (multimap<string, Empreinte>::iterator ita = monDictionnaire.begin(); ita != monDictionnaire.end(); ++ita)
	{
		// Maladie => id de l'empreinte
		cout << ita->first << " => " << ita->second.getID() << endl;
		map <string, string> val = ita->second.getValeurEmpreinte();
		for (map <string, string>::iterator itb = val.begin(); itb != val.end(); ++itb) {
			// nomAttribut => valeur
			cout << itb->first << " => " << itb->second << endl;
		}
	}*/
}

void LectureAffichage::LectureEmpreintes(string nomFichier)
{
	ifstream infile(nomFichier);
	if (infile)
	{
		string valeurAttribut;
		string nomAttribut;
		string ligne;

		vector <string>  attributs;

		getline(infile, ligne);
		stringstream fluxString(ligne);

		while (getline(fluxString, nomAttribut, ';'))
		{
			attributs.push_back(nomAttribut);
			//cout << "Attribut : " << nomAttribut << endl;
		}

		while (!infile.eof())
		{
			getline(infile, ligne);
			if (!ligne.empty()) {
				map <string, string> valeurs;
				stringstream fluxString(ligne);

				string id;
				//getline(fluxString, ligne);
				getline(fluxString, id, ';');

				//cout << ligne << endl;
				//cout << "ID : " << id << endl;
				vector<string>::iterator it = attributs.begin();
				++it;
				while (getline(fluxString, valeurAttribut, ';'))
				{
					// La maladie est stockée dans les valeurs
					valeurs.insert(make_pair(*it, valeurAttribut));
					//cout << "Valeur : " << *it << " => " << valeurAttribut << endl;
					++it;
				}

				Empreinte e(stoi(id), valeurs);
				infoSysteme.addEnsembleEmpreinte(e);
				//infoSysteme.getEnsembleEmpreinte().push_back(e);
			}
		}
	}
	/*
	// AFFICHAGE (A METTRE DANS LE TEST)
	vector<Empreinte> monEnsembleEmpreinte = infoSysteme.getEnsembleEmpreinte();
	for (vector<Empreinte>::iterator ita = monEnsembleEmpreinte.begin(); ita != monEnsembleEmpreinte.end(); ++ita)
	{
		cout << "Id de l'empreinte : " << ita->getID() << endl;
		map <string, string> uneEmpreinte = ita->getValeurEmpreinte();
		for (map <string, string>::iterator itb = uneEmpreinte.begin(); itb != uneEmpreinte.end(); ++itb) {
			// nomAttribut => valeur
			cout << itb->first << " => " << itb->second << endl;
		}
	}
	*/
}

void LectureAffichage::AfficherMaladiesPrisesEnCompte()
{
    cout << "Liste des maladies prises en compte dans l'analyse des empreintes : " << endl;
    vector<string> maladies;
	multimap<string, Empreinte> monDictionnaire = infoSysteme.getDictionnaire();
    for (multimap<string, Empreinte>::iterator itDico = monDictionnaire.begin(); itDico != monDictionnaire.end(); itDico = monDictionnaire.upper_bound(itDico->first))
    {
        cout << " - " << itDico->first << endl;
    }
}

void LectureAffichage::AfficherCaracteristiquesMaladie(string maladie, bool affichage) 
{
	multimap<string, Empreinte> monDictionnaire = infoSysteme.getDictionnaire();
	multimap<string,Empreinte>::iterator it1 = monDictionnaire.find(maladie);
	if (it1== monDictionnaire.end()) {
		cout << "La maladie que vous recherchez n'existe pas!" << endl;
	}
	else {
		cout << "Recherche des caractéristiques de : " << maladie << endl;
		// Map contenant uniquement les attributs caractéristiques de la maladie
		// <nomAttribut,<Esperance,EcartType>>
		map<string,pair<string,string>> attributsImportants;

		//map <string, string> uneEmpreinte = it1->second.getValeurEmpreinte();
		//map <string, string>::iterator itb = uneEmpreinte.begin(); itb != uneEmpreinte.end(); ++itb

		//cout << types[0] << " - " << types[1] << " - " << types[2] << endl;

		// Parcours selon les attributs de la métadonné : on prend un attribut et on regarde la valeur
		// de chaque empreinte correspondant à la maladie sur cet attribut
		map<string, string> maMap = infoSysteme.getMetaDonnees();
		for (map <string, string>::iterator itb = maMap.begin(); itb != maMap.end(); ++itb) {
			// Affichage de l'attribut : nomAttribut => type
			cout << "----------" << endl;
			cout << itb->first << " => " << itb->second << endl;
			string type = itb->second;

			double Esperance = 0;
			int nbEmpreintesConsiderees = 0;
			double Variance = 0;

			// calcul de l'index correspondant au type dans le tableau
			int index = distance(types, std::find(types, types + 3, type));
			//cout << "ind : " << index << endl;
			for (multimap<string, Empreinte>::iterator it2 = it1; it2 != (monDictionnaire.upper_bound(it1->first)); ++it2) {
				//cout << "Empreinte : " << it2->second.getID() << endl;
				//cout << "recherche sur : " << itb->first << endl;
				//Pour chaque empreinte de la maladie, on récupère ses données
				map<string, string> mapValeur = it2->second.getValeurEmpreinte();
				// On cherche l'attribut (nom+valeur) dans l'empreinte
				map <string, string>::iterator itValeur = mapValeur.find(itb->first);
				// Si on trouve l'attribut, alors...
				if (itValeur != mapValeur.end()) {
					cout << itValeur->first << " =>> " << itValeur->second << endl;
					switch (index) {
					case 0:
						// cas string
						break;
					case 1:
						// cas double
						Esperance += stoi(itValeur->second);
						Variance += pow(stoi(itValeur->second),2);
						nbEmpreintesConsiderees++;
						break;
					case 2:
						// cas int
						Esperance += stoi(itValeur->second);
						Variance += pow(stoi(itValeur->second), 2);
						nbEmpreintesConsiderees++;
						break;
					}
				}
			}
			switch (index) {
			case 0:
				// cas string
				break;
			case 1:
				// cas double
				Esperance = Esperance / nbEmpreintesConsiderees;
				Variance = Variance / nbEmpreintesConsiderees - pow(Esperance,2);
				cout << "Esperance (D): " << Esperance << endl;
				cout << "Ecart Type (D): " << sqrt(Variance) << endl;
				break;
			case 2:
				// cas int
				Esperance = Esperance / nbEmpreintesConsiderees;
				Variance = Variance / nbEmpreintesConsiderees - pow(Esperance, 2);
				cout << "Esperance (I): " << Esperance << endl;
				cout << "Ecart Type (I): " << sqrt(Variance) << endl;
				break;
			}
		}
	}
	// Affichage des caractéristiques
	if (affichage) {
		cout << "Affichage des caractéristiques de la maladie suivante : " << maladie << endl;
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
