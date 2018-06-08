/*******************************************************************************************
Donnees  -  description
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


//---------- Réalisation de la classe <Donnees> (fichier Donnees.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Donnees.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

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
} //----- Fin de ~Donnees---------------------- Méthodes protégées