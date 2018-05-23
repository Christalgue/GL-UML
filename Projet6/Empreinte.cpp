/*******************************************************************************************
Empreinte  -  description
-------------------
début                : 10/01/2018
copyright            : (C) 2018 par 
e-mail               : 
********************************************************************************************/


//---------- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;


//------------------------------------------------------ Include personnel
#include "Empreinte.h"
#include <fstream>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int Empreinte::getID() {
	return ID;
}

Maladie* Empreinte::getMaladie() {
	return maMaladie;
}

  //------------------------------------------------- Surcharge d'opérateurs

  //-------------------------------------------- Constructeurs - destructeur

Empreinte::Empreinte()
// Algorithme : 
{
#ifdef MAP
	cout << "Appel au constructeur de <Empreinte>" << endl;
#endif
} //----- Fin de Empreinte

Empreinte::Empreinte(int id, Maladie * uneMaladie) 
// Algorithme : 
{
#ifdef MAP
	cout << "Appel au constructeur de <Empreinte>" << endl;
#endif
	ID = id;
	maMaladie = uneMaladie;
} //----- Fin de Empreinte

Empreinte::~Empreinte()
{
#ifdef MAP
	cout << "Appel au destructeur de <Empreinte>" << endl;
#endif
} //----- Fin de ~Empreinte



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
