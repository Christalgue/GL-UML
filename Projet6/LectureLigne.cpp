/*******************************************************************************************
LectureLigne  -  description
-------------------
d�but                : 10/01/2018
copyright            : (C) 2018 par Christophe Gibert - Alexandra Verrier
e-mail               : christophe.gibert@insa-lyon.fr - alexandra.verrier@insa-lyon.fr
********************************************************************************************/

//---------- R�alisation de la classe <LectureLigne> (fichier LectureLigne.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

#include <iostream>

//------------------------------------------------------ Include personnel
#include "LectureLigne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

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
// Algorithme : On place un it�rateur invers� sur le string pass� en param�tre
//		et on r�cup�re tous les caract�res, en appelant extractionPage, jusqu'� rencontrer un point.
{
	string::const_reverse_iterator it = page.rbegin();
	string extension = extractionPage(it, '.');
	return extension;
} //----- Fin de ExtractionExtension

  //------------------------------------------------- Surcharge d'op�rateurs

  //-------------------------------------------- Constructeurs - destructeur
LectureLigne::LectureLigne(const string& ligneLog)
// Algorithme : On coupe la ligne avec l'appel de splitter et on rempli les 
//		attributs en �vocant �ventuellement des m�thodes.
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

  //----------------------------------------------------- M�thodes prot�g�es
vector<string> LectureLigne::spliter(const string& ligne)
// Algorithme : On coupe la ligne donn�e en param�tre avec comme caract�re de s�paration l'espace.
//		Si on est entre des crochets on ignore l'espace.
{
	vector<string> tableau(9, "");
	unsigned int compteur = 0;
	bool espace = true; // permet de savoir si on prend l'espace comme s�parateur ou si on l'ignore
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
// Algorithme : On place un it�rateur sur la date et on en extrait seulement l'heure 
//		(les 2 caract�res suivants le premier ":").
//		On convertit les caract�res obtenus en entiers.
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
// Algorithme : On utilise un it�rateur invers� sur un string pass� en param�tre
//		pour r�cup�rer tous les caract�res jusqu'� rencontrer du caract�re s�parateur.
//		On inverse la cha�ne de caract�re obtenue pour qu'elle corresponde � la bonne extraction.
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
// Algorithme : On place correctement un it�rateur invers� sur le string pass� en param�tre
//				et on r�cup�re tous les caract�res, en appelant extractionPage, jusqu'� rencontrer un espace.
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
