/*******************************************************************************************
Donnees  -  description
-------------------
d�but                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
********************************************************************************************/


//---------- R�alisation de la classe <Donnees> (fichier Donnees.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;


//------------------------------------------------------ Include personnel
#include "Donnees.h"
#include <fstream>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques



//------------------------------------------------- Surcharge d'op�rateurs

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

  //----------------------------------------------------- M�thodes prot�g�es