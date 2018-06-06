/************************************************************************************
MALADIE  -  description
-------------------
d�but                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <Maladie> (fichier Maladie.h) ----------------
#if ! defined ( MALADIE_H )
#define MALADIE_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Maladie>
//------------------------------------------------------------------------

class Maladie
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	string getNom();

	//------------------------------------------------- Surcharge d'op�rateurs
	Maladie & operator = (const Maladie & unMaladie) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'op�rateur = pour des objets Maladie.
	// Contrat :
	// d�clar�Emais non d�fini pour intersepter son �ventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Maladie(const Maladie & unMaladie) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Maladie.
	// Contrat :
	// d�clar�Emais non d�fini pour intersepter son �ventuel appel.

	Maladie(string nomMaladie);

	Maladie();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans param�tre) par d�faut des objets Maladie.



	virtual ~Maladie();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Maladie.

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

	string nom;

};

//-------------------------------- Autres d�finitions d�pendantes de <Maladie>

#endif // MALADIE_H