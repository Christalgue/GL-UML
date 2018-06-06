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
			//cout << nomAttribut << " => " << typeAttribut << endl;
		}
		// Pour regarder si la map est bien remplie
		for (map<string, string>::iterator ita = infoSysteme.metaDonnees.begin(); ita != infoSysteme.metaDonnees.end(); ++ita)
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
		string valeurAttribut;
		string nomAttribut;
		string ligne;

		vector <string> attributs; 
                
		getline(infile,ligne); // 1ère ligne qu'on ne veut pas
                
                /* Ici, comme c'est compliqué de connaître quand on est à la fin de la ligne quand on lit le fichier, on récupère chaque ligne
                qu'on va transformé en flux (comme si c'était un fichier donc on peut le lire avec getline) comme ça c'est plus facile pour ne 
                prendre que les valeurs des attributsqui sont séparés par des ';' et on sait que le dernier truc qui reste, c'est le nom de 
                la maladie*/
		stringstream fluxString(ligne);
		
		while (getline(fluxString, nomAttribut, ';'))
		{
			attributs.push_back(nomAttribut);
			//cout << "Valeur : " << nomAttribut << endl;
		}

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
                            //cout << "Valeur M : " << nomMaladie << endl;

                            if (!nomMaladie.empty()) {
                                Empreinte e(stoi(id), valeurs);
                                infoSysteme.dictionnaire.insert(make_pair(nomMaladie, e));
                            }
			}
		}
	}
        
        // Pour afficher si on a fait du bon boulot et voir si ça rempli correctement.
        
	/*for (multimap<string, Empreinte>::iterator ita = infoSysteme.dictionnaire.begin(); ita != infoSysteme.dictionnaire.end(); ++ita)
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
		multimap<string, Empreinte>::iterator itMultimap = infoSysteme.dictionnaire.begin();
		string valeurAttribut;
		string ligne;
		getline(infile, ligne); // 1�re ligne inutile

		while (!infile.eof())
		{
			getline(infile, ligne);

			vector<string> valeurs;
			stringstream fluxString(ligne);

			string id;
			//getline(fluxString, ligne);
			getline(fluxString, id, ';');

			//cout << ligne << endl;
			//cout << id << endl;

			while (getline(fluxString, valeurAttribut, ';'))
			{
				// La maladie est stockée dans les valeurs
				valeurs.push_back(valeurAttribut);
				//cout << "Valeur : " << valeurAttribut << endl;
			}
			string nomMaladie = valeurAttribut;
			//getline(fluxString, nomMaladie);
			//cout << "Valeur M : " << nomMaladie << endl;

			if (!nomMaladie.empty()) {
				// Enlever la maladie du vecteur valeurs
				valeurs.pop_back();
				//Empreinte e(stoi(id), valeurs);
				//infoSysteme.dictionnaire.insert(make_pair(nomMaladie, e));
			}
		}
	}
}

void LectureAffichage::AfficherMaladiesPrisesEnCompte()
{
    cout << "Liste des maladies prises en compte dans l'analyse des empreintes : " << endl;
    vector<string> maladies;
    for (multimap<string, Empreinte>::iterator itDico = infoSysteme.dictionnaire.begin(); itDico != infoSysteme.dictionnaire.end(); itDico = infoSysteme.dictionnaire.upper_bound(itDico->first))
    {
        cout << " - " << itDico->first << endl;
    }
}

multimap<string, double> LectureAffichage::TrouverMaladie(vector<Empreinte>)
{
    
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