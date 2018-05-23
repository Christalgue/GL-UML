/************************************************************************************
LECTURELIGNE  -  description
-------------------
d�but                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( LECTURELIGNE_H )
#define LECTURELIGNE_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Empreinte>
//------------------------------------------------------------------------

class Empreinte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	//------------------------------------------------- Surcharge d'op�rateurs
	Empreinte & operator = (const Empreinte & unEmpreinte) = delete;
	// Mode d'emploi :
	// Il s'agit de la surcharge de l'op�rateur = pour des objets Empreinte.
	// Contrat :
	// d�clar� mais non d�fini pour intercepter son �ventuel appel.

	//-------------------------------------------- Constructeurs - destructeur
	Empreinte(const Empreinte & unEmpreinte) = delete;
	// Mode d'emploi :
	// Il s'agit du constructueur de copie du objet Empreinte.
	// Contrat :
	// d�clar� mais non d�fini pour intercepter son �ventuel appel.


	Empreinte();
	// Mode d'emploi :
	// Il s'agit du constructueur (sans param�tre) par d�faut des objets Empreinte.

	virtual ~Empreinte();
	// Mode d'emploi :
	// Il s'agit du destructeur des objets Empreinte.

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es


	//----------------------------------------------------- Attributs prot�g�s


};

//-------------------------------- Autres d�finitions d�pendantes de <Empreinte>

#endif // LECTURELIGNE_H#pragma once
