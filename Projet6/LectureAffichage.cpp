/*******************************************************************************************
LectureAffichage  -  description
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


//---------- Réalisation de la classe <LectureAffichage> (fichier LectureAffichage.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;


//------------------------------------------------------ Include personnel
#include "LectureAffichage.h"
#include "Donnees.h"
#include "Empreinte.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using std::string;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void LectureAffichage::LectureMetaDonnees(string nomFichier) 
{	
    // Réinitialisation des métadonnées
    infoSysteme.clearMetaDonnees();
	ifstream infile(nomFichier);

	if (infile)
	{
		string nomAttribut;
		string typeAttribut;
		getline(infile, nomAttribut); // Pour sauter la 1ère ligne qui ne nous intéresse pas

		getline(infile, nomAttribut); // La deuxieme ligne comprend l'id qui ne doit pas rentrer dans la metadonnee

		while (getline(infile, nomAttribut, ';'))
		{
			getline(infile, typeAttribut);
			infoSysteme.addMetaDonnees(make_pair(nomAttribut, typeAttribut));
		}
		
		// Pour regarder si la map est bien remplie
		/*
		map<string, string> maMap = infoSysteme.getMetaDonnees();
		for (map<string, string>::iterator ita = maMap.begin(); ita != maMap.end(); ++ita)
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
    // Réinitialisation du dictionnaire de maladies
    infoSysteme.clearDictionnaire();
    
	ifstream infile(nomFichier);

	if (infile)
	{
		//multimap<string, Empreinte>::iterator itMultimap = infoSysteme.getDictionnaire().begin();
		string valeurAttribut;
		string nomAttribut;
		string ligne;

		vector <string>  attributs; 

		getline(infile,ligne);
                
        // Pour savoir si on est au niveau de la lecture du nom de la maladie et non plus dans la lecture des valeurs des attributs,
        // on lit la ligne du fichier, on transforme cette ligne en un flux pour le lire avec getline car on sait qu'après 
        // le dernier ';' on lit la maladie.
                
		stringstream fluxString(ligne);
		
        // On récupère d'abord le nom de tous les attributs via la 1ère ligne du fichier
		while (getline(fluxString, nomAttribut, ';'))
		{
			attributs.push_back(nomAttribut);
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
				vector<string>::iterator it = attributs.begin();
				++it;
                
				while (getline(fluxString, valeurAttribut, ';'))
				{
					// La maladie est stockée dans les valeurs
					valeurs.insert(make_pair(*it, valeurAttribut));
					++it;
				}
				--it;
				// Effacer la maladie de la map
				map<string, string>::iterator mal = valeurs.find(*it);
				valeurs.erase(mal);

				string nomMaladie = valeurAttribut;

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
	}
	*/
}

void LectureAffichage::LectureEmpreintes(string nomFichier)
{
    //Réinitialisation de l'ensemble des empreintes
    infoSysteme.clearEnsembleEmpreinte();

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
		}

		while (!infile.eof())
		{
			getline(infile, ligne);
			if (!ligne.empty()) {
				map <string, string> valeurs;
				stringstream fluxString(ligne);

				string id;
				getline(fluxString, id, ';');

				vector<string>::iterator it = attributs.begin();
				++it;
				while (getline(fluxString, valeurAttribut, ';'))
				{
					// La maladie est stockée dans les valeurs
					valeurs.insert(make_pair(*it, valeurAttribut));
					++it;
				}
				Empreinte e(stoi(id), valeurs);
				infoSysteme.addEnsembleEmpreinte(e);
			}
		}
	}
	
	// AFFICHAGE (A METTRE DANS LE TEST)
	/*
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
	multimap<string, Empreinte> monDictionnaire = infoSysteme.getDictionnaire();
    for (multimap<string, Empreinte>::iterator itDico = monDictionnaire.begin(); itDico != monDictionnaire.end(); itDico = monDictionnaire.upper_bound(itDico->first))
    {
        cout << " - " << itDico->first << endl;
    }
}

map<string, pair<string, string>> LectureAffichage::AfficherCaracteristiquesMaladie(string maladie, bool affichage)
{
	map<string, pair<string, string>> attributsImportants;

	multimap<string, Empreinte> monDictionnaire = infoSysteme.getDictionnaire();
	multimap<string,Empreinte>::iterator it1 = monDictionnaire.find(maladie);
	if (it1== monDictionnaire.end()) {
		cout << "La maladie que vous recherchez n'existe pas!" << endl;
		return attributsImportants;
	}
	else {
		// Recherche des caractéristiques de la maladie
		// Map contenant uniquement les attributs caractéristiques de la maladie
		// <nomAttribut,<Esperance,EcartType>>
		
		// Parcours selon les attributs de la métadonné : on prend un attribut et on regarde la valeur
		// de chaque empreinte correspondant à la maladie sur cet attribut
		map<string, string> maMap = infoSysteme.getMetaDonnees();
		for (map <string, string>::iterator itb = maMap.begin(); itb != maMap.end(); ++itb) {
			string type = itb->second;

			double Esperance = 0;
			int nbEmpreintesConsiderees = 0;
			double Variance = 0;

			// Conteneur pour stocker chaque nom d'attribut et lui associer son nombre d'apparition
			map<string, int> stringAttributs;
                        
			// Calcul de l'index correspondant au type dans le tableau (string => 0 ; double => 1 ; int => 2)
			int index = distance(types, find(std::begin(types), std::end(types), type));
            
			for (multimap<string, Empreinte>::iterator it2 = it1; it2 != (monDictionnaire.upper_bound(it1->first)); ++it2) {
				// Pour chaque empreinte de la maladie, on récupère ses données
				map<string, string> mapValeur = it2->second.getValeurEmpreinte();
				// On cherche l'attribut (nom+valeur) dans l'empreinte
				map <string, string>::iterator itValeur = mapValeur.find(itb->first);
				// Si on trouve l'attribut, alors...
				if (itValeur != mapValeur.end()) {
					switch (index) {
					case 0:
						// Cas string
						if (stringAttributs.find(itValeur->second)!=stringAttributs.end()) {
							// L'attribut existe deja dans stringAttributs
							stringAttributs.find(itValeur->second)->second++;
						}
						else {
							// L'attribut n'existe pas encore dans stringAttributs
							stringAttributs.insert(make_pair(itValeur->second,1));
						}
						break;
					case 1:
						// Cas double
						Esperance += stod(itValeur->second);
						Variance += pow(stod(itValeur->second),2);
						nbEmpreintesConsiderees++;
						break;
					case 2:
						// Cas int
						Esperance += stoi(itValeur->second);
						Variance += pow(stoi(itValeur->second), 2);
						nbEmpreintesConsiderees++;
						break;
					}
				}
			}
			map<string, int>::iterator itSA;
			map<string, int>::iterator plusGrandeValeur;
			switch (index) {
			case 0:
				// Cas string
				plusGrandeValeur = stringAttributs.begin();
				for (itSA = stringAttributs.begin(); itSA != stringAttributs.end(); ++itSA) {
					if (itSA->second>plusGrandeValeur->second) {
						plusGrandeValeur = itSA;
					}
				}
				attributsImportants.insert(make_pair(itb->first,make_pair(plusGrandeValeur->first, to_string(plusGrandeValeur->second))));
				break;
			case 1:
				// Cas double
				Esperance = Esperance / nbEmpreintesConsiderees;
				Variance = Variance / nbEmpreintesConsiderees - pow(Esperance,2);
				attributsImportants.insert(make_pair(itb->first,make_pair(to_string(Esperance),to_string(sqrt(Variance)))));
				break;
			case 2:
				// Cas int
				Esperance = Esperance / nbEmpreintesConsiderees;
				Variance = Variance / nbEmpreintesConsiderees - pow(Esperance, 2);
				attributsImportants.insert(make_pair(itb->first, make_pair(to_string(Esperance), to_string(sqrt(Variance)))));
				break;
			}
		}
		// Affichage des caractéristiques
		if (affichage) {
			cout << endl;
			map<string, pair<string, string>>::iterator iComplet;
			for (iComplet = attributsImportants.begin(); iComplet != attributsImportants.end(); ++iComplet) {
				cout << "Attribut :                  " << iComplet->first << endl;
				cout << "Moyenne                     " << iComplet->second.first << endl;
				cout << "Ecart-type (/fréquence)     " << iComplet->second.second << endl;
				cout << endl;
			}
		}
		return attributsImportants;
	}
}

void LectureAffichage::DemandeAnalyse() {
    cout << endl;
	if (infoSysteme.getEnsembleEmpreinte().empty()) {
		cout << "Il n'y a pas d'empreintes à analyser!" << endl;
	}
	else {
		multimap<double, string> diagnosticFinal;
		map<string, string> valeursEmpreinte;
		vector<Empreinte> mesEmpreintes = infoSysteme.getEnsembleEmpreinte();
		multimap<string, Empreinte> monDictionnaire = infoSysteme.getDictionnaire();
        map<string, string> maMetadonnee = infoSysteme.getMetaDonnees();
		// On analyse une à une les empreintes
		for (vector<Empreinte>::iterator monEmpreinte = mesEmpreintes.begin(); monEmpreinte != mesEmpreintes.end(); ++monEmpreinte) {
			// Réinitialisation du diagnostic
			diagnosticFinal.clear();
			cout << "Diagnostic de l'empreinte numero "  << monEmpreinte->getID() << endl;
			valeursEmpreinte.clear();
			valeursEmpreinte = monEmpreinte->getValeurEmpreinte();
			// On compare l'empreinte à chaque maladie
			for (multimap<string, Empreinte>::iterator itDico = monDictionnaire.begin(); itDico != monDictionnaire.end(); itDico = monDictionnaire.upper_bound(itDico->first))
			{
				// Récupération des valeurs caractéristiques de chaque attribut (pour une maladie à la fois)
				map<string, pair<string, string>> diagnosticUneMaladie = AfficherCaracteristiquesMaladie(itDico->first, false);
				
                // Nombre d'attributs à traiter
                int nbAttr = 0;
                double note=0;

				map<string, pair<string, string>>::iterator itMaladie=diagnosticUneMaladie.begin();
				for (map<string, string>::iterator itValEmp = valeursEmpreinte.begin(); itMaladie!=diagnosticUneMaladie.end() && itValEmp != valeursEmpreinte.end();++itValEmp) {
                    // Trouver le type de l'attribut
                    map<string,string>::iterator itMeta = maMetadonnee.find(itValEmp->first);
                    int index = distance(types, find(std::begin(types), std::end(types), itMeta->second));

                    switch (index) {
                    case 0:
                        // Cas string
                        if (itValEmp->second== itMaladie->second.first) {
                            note += 1;
                        }
                        break;
                    case 1:
                        // Cas double
                        if (stod(itMaladie->second.second)!=0) {
                            // Translation qui donne selon l'ecart entre la moyenne de la maladie et la valeur de l'empreinte (sur un même attribut) un pourcentage
                            // Ecart de 0 (Esp=valeur de l'empreinte) => pourcentage = 1 ; Ecart de 3*ecart-type => pourcentage = 0
                            double chanceD = 1 - (1 / (2 * stod(itMaladie->second.second))) * abs(stod(itValEmp->second) - stod(itMaladie->second.first));
                            // Dans le cas où la valeur est trop éloignée (val-esp > 2 ecarts types), on ne considère pas l'attribut
                            if (chanceD>0) {
                                note += abs(chanceD);
                            }
                        }
                        else {
                            // Si l'ecart type est de 0, alors on a soit une empreinte unique, soit plusieurs empreinte tous parfaitement réparties sur une unique valeur
                            // ==> match parfait ou rien
                            if (stod(itValEmp->second) == stod(itMaladie->second.first)) {
                                note += 1;
                            }
                        }
                        break;
                    case 2:
                        // Cas int
                        if (stoi(itMaladie->second.second) != 0) {
                            // Translation qui donne selon l'ecart entre la moyenne de la maladie et la valeur de l'empreinte (sur un même attribut) un pourcentage
                            // Ecart de 0 (Esp=valeur de l'empreinte) => pourcentage = 1 ; Ecart de 3*ecart-type => pourcentage = 0
                            double chanceI = 1 - (1 / (2 * stod(itMaladie->second.second))) * abs(stoi(itValEmp->second) - stod(itMaladie->second.first));
                            // Dans le cas où la valeur est trop éloignée (val-esp > 2 ecarts types), on ne considère pas l'attribut
                            if (chanceI>0) {
                                note += abs(chanceI);
                            }
                        }
                        else {
                            // Si l'ecart type est de 0, alors on a soit une empreinte unique, soit plusieurs empreinte tous parfaitement réparties sur une unique valeur
                            // ==> match parfait ou rien
                            if (stoi(itValEmp->second) == stoi(itMaladie->second.first)) {
                                note += 1;
                            }
                        }
                        break;
                    }
                    nbAttr++;
                    ++itMaladie;
				}
                // Ajout de la maladie au diagnostic final
                diagnosticFinal.insert(make_pair(note/nbAttr,itDico->first));

			}
            int nbAffichages = 5;
            int nbAffichagesEnCours = 0;
			// Affichage du diagnostic
            cout << "Vos risques d'attraper des maladies sont les suivants :" << endl;
            for (multimap<double, string>::reverse_iterator itDiagnostic = diagnosticFinal.rbegin(); (nbAffichages>nbAffichagesEnCours)&&(itDiagnostic != diagnosticFinal.rend()); ++itDiagnostic)
            {
                cout << "   " << setprecision(3) << 100 * itDiagnostic->first << "% de pour la maladie suivante : " << itDiagnostic->second << endl;
                nbAffichagesEnCours++;
            }
            cout << endl;
		}
	}
}

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