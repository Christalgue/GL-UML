/*******************************************************************************************
LectureLigne  -  description
-------------------
début                : 10/01/2018
copyright            : (C) 2018 par Christophe Gibert - Alexandra Verrier
e-mail               : christophe.gibert@insa-lyon.fr - alexandra.verrier@insa-lyon.fr
********************************************************************************************/

//---------- Réalisation de la classe <LectureLigne> (fichier LectureLigne.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>

//------------------------------------------------------ Include personnel
#include "LectureLigne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string LectureLigne::GetID() const
{
	return source;
} //----- Fin de GetSource

string LectureLigne::GetDestination() const
{
	return destination;
}//----- Fin de GetDestination

int LectureLigne::GetHeure() const
{
	return heure;
} //----- Fin de GetHeure

string LectureLigne::ExtractionExtension(const string& page)
// Algorithme : On place un itérateur inversé sur le string passé en paramètre
//		et on récupère tous les caractères, en appelant extractionPage, jusqu'à rencontrer un point.
{
	string::const_reverse_iterator it = page.rbegin();
	string extension = extractionPage(it, '.');
	return extension;
} //----- Fin de ExtractionExtension

  //------------------------------------------------- Surcharge d'opérateurs

  //-------------------------------------------- Constructeurs - destructeur
LectureLigne::LectureLigne(const string& ligneLog)
// Algorithme : On coupe la ligne avec l'appel de splitter et on rempli les 
//		attributs en évocant éventuellement des méthodes.
{
	vector<string> ligne(spliter(ligneLog));
	adresseIP = ligne[0];
	date = ligne[3];
	requete = ligne[4];
	status = atoi(ligne[5].c_str());
	tailleOctet = atoi(ligne[6].c_str());
	adresseSource = ligne[7];
	idNavigateur = ligne[8];
	heure = extractionHeure(date);
	destination = extractionDestination(requete);
	source = extractionSource(adresseSource);
}


LectureLigne::~LectureLigne()
{
#ifdef MAP
	cout << "Appel au destructeur de <LectureLigne>" << endl;
#endif
} //----- Fin de ~LectureLigne


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées
vector<string> LectureLigne::spliter(const string& ligne)
// Algorithme : On coupe la ligne donnée en paramètre avec comme caractère de séparation l'espace.
//		Si on est entre des crochets on ignore l'espace.
{
	vector<string> tableau(9, "");
	unsigned int compteur = 0;
	bool espace = true; // permet de savoir si on prend l'espace comme séparateur ou si on l'ignore
	string::const_iterator it;
	for (it = ligne.begin(); it != ligne.end(); ++it)
	{
		if (*it == '[')
		{
			espace = false;
		}
		else if (*it == ']')
		{
			espace = true;
		}
		else if (*it == '"')
		{
			espace = !espace;
		}
		else if ((espace) && (*it == ' '))
		{
			compteur++;
			if (compteur == tableau.size())
			{
				tableau.push_back("");
			}
		}
		else
		{
			tableau[compteur] += *it;
		}
	}
	return tableau;
}

int LectureLigne::extractionHeure(const string& date)
// Algorithme : On place un itérateur sur la date et on en extrait seulement l'heure 
//		(les 2 caractères suivants le premier ":").
//		On convertit les caractères obtenus en entiers.
{
	string::const_iterator it = date.begin();
	while (*it != ':')
	{
		++it;
	}
	string sHeure = "";
	sHeure += *(++it);
	++it;
	sHeure += *it;

	int iHeure = atoi(sHeure.c_str());

	return iHeure;
}

string LectureLigne::extractionPage(string::const_reverse_iterator it, const char separateur)
// Algorithme : On utilise un itérateur inversé sur un string passé en paramètre
//		pour récupérer tous les caractères jusqu'à rencontrer du caractère séparateur.
//		On inverse la chaîne de caractère obtenue pour qu'elle corresponde à la bonne extraction.
{
	string page = "";
	//remplissage de la destination
	while (*it != separateur)
	{
		page += *it;
		++it;
	}
	//Inversion du string
	int n = page.length();
	for (int i = 0; i<n / 2; i++)
	{
		swap(page[i], page[n - i - 1]);
	}
	return page;
}

string LectureLigne::extractionDestination(const string& requete)
// Algorithme : On place correctement un itérateur inversé sur le string passé en paramètre
//				et on récupère tous les caractères, en appelant extractionPage, jusqu'à rencontrer un espace.
{
	string::const_reverse_iterator it = requete.rbegin();
	while (*it != ' ')
	{
		++it;
	}
	++it;

	string destination = extractionPage(it, ' ');
	return destination;
}

string LectureLigne::extractionSource(const string& adresseSource)
// Algorithme : On teste si l'adresse de la source contient la base de l'url local.
//				Si c'est le cas on le supprime.
{
	string source = adresseSource;
	string ref = "http://intranet-if.insa-lyon.fr";
	string sourceFinale = "";
	if (source.compare(0, ref.length(), ref) == 0) {
		for (unsigned int i = ref.length(); i< source.length(); ++i)
		{
			sourceFinale += source[i];
		}
	}
	else
	{
		sourceFinale = source;
	}
	return sourceFinale;
}
