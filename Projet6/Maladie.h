/************************************************************************************
MALADIE  -  description
-------------------
dÈbut                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <Maladie> (fichier Maladie.h) ----------------
#if ! defined ( MALADIE_H )
#define MALADIE_H

//--------------------------------------------------- Interfaces utilisÈes
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// RÙle de la classe <Maladie>
//------------------------------------------------------------------------

class Maladie
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- MÈthodes publiques

	string getNom();

	//------------------------------------------------- Surcharge d'opÈrateurs
	Maladie & operator = (const Maladie & unMaladie) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'opÈrateur = pour des objets Maladie.
	// Contrat :
	// dÈclarÅEmais non dÈfini pour intersepter son Èventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Maladie(const Maladie & unMaladie) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Maladie.
	// Contrat :
	// dÈclarÅEmais non dÈfini pour intersepter son Èventuel appel.

	Maladie(string nomMaladie);

	Maladie();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans paramËtre) par dÈfaut des objets Maladie.



	virtual ~Maladie();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Maladie.

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- MÈthodes protÈgÈes

	//----------------------------------------------------- Attributs protÈgÈs

	string nom;

};

//-------------------------------- Autres dÈfinitions dÈpendantes de <Maladie>

#endif // MALADIE_H