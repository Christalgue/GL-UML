/*******************************************************************************************
Empreinte  -  description
-------------------
d�but                : 10/01/2018
copyright            : (C) 2018 par 
e-mail               : 
********************************************************************************************/


//---------- R�alisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;


//------------------------------------------------------ Include personnel
#include "Empreinte.h"
#include <fstream>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

int Empreinte::getID() {
	return ID;
}

/*Maladie* Empreinte::getMaladie() {
	return maMaladie;
}*/

  //------------------------------------------------- Surcharge d'op�rateurs

  //-------------------------------------------- Constructeurs - destructeur

Empreinte::Empreinte()
// Algorithme : 
{
#ifdef MAP
	cout << "Appel au constructeur de <Empreinte>" << endl;
#endif
} //----- Fin de Empreinte



Empreinte::Empreinte(int id, /*Maladie * uneMaladie,*/ vector<string> mesValeursAttributsEmpreinte)
// Algorithme : 
{
#ifdef MAP
	cout << "Appel au constructeur de <Empreinte>" << endl;
#endif
	ID = id;
	//maMaladie = uneMaladie;
	valeursAttributsEmpreinte = mesValeursAttributsEmpreinte;
} //----- Fin de Empreinte



Empreinte::~Empreinte()
{
#ifdef MAP
	cout << "Appel au destructeur de <Empreinte>" << endl;
#endif
} //----- Fin de ~Empreinte



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
