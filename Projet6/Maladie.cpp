/*******************************************************************************************
Maladie  -  description
-------------------
d�but                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
********************************************************************************************/


//---------- R�alisation de la classe <Maladie> (fichier Maladie.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;

//------------------------------------------------------ Include personnel
#include "Maladie.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

string Maladie::getNom()
{
	return nom;
}

//----------------------------------------------------- M�thodes publiques

//------------------------------------------------- Surcharge d'op�rateurs

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

  //----------------------------------------------------- M�thodes prot�g�es
