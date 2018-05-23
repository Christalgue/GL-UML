/*******************************************************************************************
LectureLigne  -  description
-------------------
d�but                : 10/01/2018
copyright            : (C) 2018 par Christophe Gibert -
e-mail               : christophe.gibert@insa-lyon.fr
********************************************************************************************/

//---------- Interface de la classe <LectureLigne> (fichier LectureLigne.h) ----------------
#if ! defined ( LECTURELIGNE_H )
#define LECTURELIGNE_H
using namespace std;
#include <vector>
#include <string>
//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <LectureLigne>
// Cette classe permet d'analyser une ligne d'un fichier log et d'en extraire 
// les informations utiles.
//------------------------------------------------------------------------

class LectureLigne
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	string GetID() const;
	// Mode d'emploi : Renvoie le referer de la ligne lue dans le fichier .log.

	string GetDestination() const;
	// Mode d'emploi : Renvoie la requ�te de la ligne lue dans le fichier .log.

	int GetHeure() const;
	// Mode d'emploi : Renvoie l'heure de la requ�te de la ligne lue dans le fichier .log.

	string ExtractionExtension(const string& page);
	// Mode d'emploi : Renvoie l'extension du referer ou de la destination de la requ�te.

	//------------------------------------------------- Surcharge d'op�rateurs
	LectureLigne & operator = (const LectureLigne & unLectureLigne) = delete;
	// Mode d'emploi :
	// Surcharge de l'op�rateur = pour les objets LectureLigne.
	// Contrat :
	// d�claration mais pas de d�finition pour intercepter son utilisation �ventuelle.

	//-------------------------------------------- Constructeurs - destructeur
	LectureLigne(const LectureLigne & unLectureLigne) = delete;
	// Mode d'emploi :
	// Constructeur de copie
	// Contrat :
	// d�claration mais pas de d�finition pour intercepter son utilisation �ventuelle

	LectureLigne();
	// Mode d'emploi :
	// Constructeur par d�faut, sans param�tre

	LectureLigne(const string& ligneLog);
	// Mode d'emploi :
	// Constructeur d'objet LectureLigne avec une ligne du fichier log en param�tre

	virtual ~LectureLigne();
	// Mode d'emploi :
	// Destructeur d'objet LectureLigne

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es
	int extractionHeure(const string& date);
	// Mode d'emploi :
	// Permet d'extraire seulement l'entier correspondant � l'heure � partir de la date.

	string extractionDestination(const string& requete);
	// Mode d'emploi :
	// Permet d'extraire seulement la destination correspondant une requ�te. 

	string extractionSource(const string& adresseSource);
	// Mode d'emploi :
	// Permet d'extraire seulement la source correspondant une adresse.
	// Contrat :
	// Si la source est locale alors la base de l'url est retir�e.

	vector<string> spliter(const string& ligne);
	// Mode d'emploi :
	// Coupe la ligne de code du fichier log pour s�parer les diff�rentes parties qui sont stock�es dans un vecteur.

	string extractionPage(string::const_reverse_iterator it, const char separateur);
	// Mode d'emploi :
	// Permet d'extraire une partie d'un string associ� � un it�rateur.
	// Contrat :
	// Le caract�re permettant de d�finir ce que l'on veut extraire doit �tre sp�cifi� en param�tre.

	//----------------------------------------------------- Attributs prot�g�s
	int ID;


	string adresseSource;
	string source;
	string destination;
	string date;
	string adresseIP;
	string requete;
	int status;
	int tailleOctet;
	string idNavigateur;
	int heure;

};

//-------------------------------- Autres d�finitions d�pendantes de <LectureLigne>

#endif // LECTURELIGNE_H