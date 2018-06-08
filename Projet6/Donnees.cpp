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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void Donnees::addMetaDonnees(pair<string, string> paire) 
{
	metaDonnees.insert(paire);
}

void Donnees::addDictionnaire(pair<string, Empreinte> paire) 
{
	dictionnaire.insert(paire);
}

void Donnees::addEnsembleEmpreinte(Empreinte e)
{
	ensembleEmpreinte.push_back(e);
}

void Donnees::clearMetaDonnees() {
    metaDonnees.clear();
}

void Donnees::clearDictionnaire() {
    dictionnaire.clear();
}

void Donnees::clearEnsembleEmpreinte() {
    ensembleEmpreinte.clear();
}

map<string, string> Donnees::getMetaDonnees()
{
    return metaDonnees;
}

multimap<string, Empreinte> Donnees::getDictionnaire()
{
    return dictionnaire;
}

vector<Empreinte> Donnees::getEnsembleEmpreinte()
{
    return ensembleEmpreinte;
}


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