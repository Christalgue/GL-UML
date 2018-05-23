/*******************************************************************************************
LectureLigne  -  description
-------------------
début                : 10/01/2018
copyright            : (C) 2018 par Christophe Gibert -
e-mail               : christophe.gibert@insa-lyon.fr
********************************************************************************************/

//---------- Interface de la classe <LectureLigne> (fichier LectureLigne.h) ----------------
#if ! defined ( LECTURELIGNE_H )
#define LECTURELIGNE_H
using namespace std;
#include <vector>
#include <string>
#include <map>
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LectureLigne>
// Cette classe permet d'analyser une ligne d'un fichier log et d'en extraire 
// les informations utiles.
//------------------------------------------------------------------------

class LectureLigne
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	string ExtractionExtension(const string& page);
	// Mode d'emploi : Renvoie l'extension du referer ou de la destination de la requête.

	//------------------------------------------------- Surcharge d'opérateurs
	LectureLigne & operator = (const LectureLigne & unLectureLigne) = delete;
	// Mode d'emploi :
	// Surcharge de l'opérateur = pour les objets LectureLigne.
	// Contrat :
	// déclaration mais pas de définition pour intercepter son utilisation éventuelle.

	//-------------------------------------------- Constructeurs - destructeur
	LectureLigne(const LectureLigne & unLectureLigne) = delete;
	// Mode d'emploi :
	// Constructeur de copie
	// Contrat :
	// déclaration mais pas de définition pour intercepter son utilisation éventuelle

	LectureLigne();
	// Mode d'emploi :
	// Constructeur par défaut, sans paramètre

	LectureLigne(const string& ligneLog);
	// Mode d'emploi :
	// Constructeur d'objet LectureLigne avec une ligne du fichier log en paramètre

	virtual ~LectureLigne();
	// Mode d'emploi :
	// Destructeur d'objet LectureLigne

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées



	int extractionHeure(const string& date);
	// Mode d'emploi :
	// Permet d'extraire seulement l'entier correspondant à l'heure à partir de la date.

	string extractionDestination(const string& requete);
	// Mode d'emploi :
	// Permet d'extraire seulement la destination correspondant une requête. 

	string extractionSource(const string& adresseSource);
	// Mode d'emploi :
	// Permet d'extraire seulement la source correspondant une adresse.
	// Contrat :
	// Si la source est locale alors la base de l'url est retirée.

	vector<string> spliter(const string& ligne);
	// Mode d'emploi :
	// Coupe la ligne de code du fichier log pour séparer les différentes parties qui sont stockées dans un vecteur.

	string extractionPage(string::const_reverse_iterator it, const char separateur);
	// Mode d'emploi :
	// Permet d'extraire une partie d'un string associé à un itérateur.
	// Contrat :
	// Le caractère permettant de définir ce que l'on veut extraire doit être spécifié en paramètre.

	//----------------------------------------------------- Attributs protégés
	union S {
		int i;
		double d;
		string s;
	};

	map < string, S > metadonnee;
	

};

//-------------------------------- Autres définitions dépendantes de <LectureLigne>

#endif // LECTURELIGNE_H