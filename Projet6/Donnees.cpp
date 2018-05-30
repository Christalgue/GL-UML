/*******************************************************************************************
Donnees  -  description
-------------------
début                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
********************************************************************************************/


//---------- Réalisation de la classe <Donnees> (fichier Donnees.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;


//------------------------------------------------------ Include personnel
#include "Donnees.h"
#include <fstream>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Donnees::Donnees()
// Algorithme : 
{
#ifdef MAP
	cout << "Appel au constructeur de <Donnees>" << endl;
#endif
} //----- Fin de Donnees


Donnees::~Donnees()
{
#ifdef MAP
	cout << "Appel au destructeur de <Donnees>" << endl;
#endif
} //----- Fin de ~Donnees



  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées