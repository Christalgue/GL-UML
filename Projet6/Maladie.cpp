/*******************************************************************************************
Maladie  -  description
-------------------
début                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
********************************************************************************************/


//---------- Réalisation de la classe <Maladie> (fichier Maladie.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Maladie.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

string Maladie::getNom()
{
	return nom;
}

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Maladie::Maladie(string nomMaladie)
{
#ifdef MAP
	cout << "Appel au constructeur de <Maladie>" << endl;
#endif
	nom = nomMaladie;
}


Maladie::Maladie()
// Algorithme : 
{
#ifdef MAP
	cout << "Appel au constructeur de <Maladie>" << endl;
#endif
} //----- Fin de Maladie

Maladie::~Maladie()
{
#ifdef MAP
	cout << "Appel au destructeur de <Maladie>" << endl;
#endif
} //----- Fin de ~Maladie


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées
