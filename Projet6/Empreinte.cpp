/*******************************************************************************************
Empreinte  -  description
-------------------
début                : 10/01/2018
copyright            : (C) 2018 par COCQUIO-LESBRENE Clementine
                                    FERY Simon
                                    GIBERT Christophe
                                    SIMONIN Joseph
e-mail               : clementine.coquio--lebresne@insa-lyon.fr
                       simon.fery@insa-lyon.fr
                       christophe.gibert@insa-lyon.fr
                       joseph.simonin@insa-lyon.fr
*************************************************************************************/


//---------- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Empreinte.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int Empreinte::getID() {
	return ID;
}

map <string, string> Empreinte::getValeurEmpreinte() {
	return valeursAttributsEmpreinte;
}

  //-------------------------------------------- Constructeurs - destructeur

Empreinte::Empreinte()
// Algorithme : 
{
#ifdef MAP
	cout << "Appel au constructeur de <Empreinte>" << endl;
#endif
} //----- Fin de Empreinte

Empreinte::Empreinte(int id, map <string, string> mesValeursAttributsEmpreinte)
// Algorithme : 
{
#ifdef MAP
	cout << "Appel au constructeur de <Empreinte>" << endl;
#endif
	ID = id;
	valeursAttributsEmpreinte = mesValeursAttributsEmpreinte;
} //----- Fin de Empreinte

Empreinte::~Empreinte()
{
#ifdef MAP
	cout << "Appel au destructeur de <Empreinte>" << endl;
#endif
} //----- Fin de ~Empreinte