/************************************************************************************
TestPerformance  -  description
-------------------
d�but                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <TestPerformance> (fichier TestPerformance.h) ----------------
#if ! defined ( TestPerformance_H )
#define TestPerformance_H

//--------------------------------------------------- Interfaces utilis�es
#include "LectureAffichage.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TestPerformance>
//------------------------------------------------------------------------

using namespace std;

class TestPerformance
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- M�thodes publiques

    void Tester();

    //------------------------------------------------- Surcharge d'op�rateurs
    TestPerformance & operator = (const TestPerformance & unTestPerformance) = delete;
    // Mode d'emploi :
    // Il s'agit de la surcharge de l'op�rateur = pour des objets TestPerformance.
    // Contrat :
    // d�clar�Emais non d�fini pour intersepter son �ventuel appel.

    //-------------------------------------------- Constructeurs - destructeur
    TestPerformance(const TestPerformance & unTestPerformance) = delete;
    // Mode d'emploi :
    // Il s'agit du constructueur de copie du objet TestPerformance.
    // Contrat :
    // d�clar�Emais non d�fini pour intersepter son �ventuel appel.

    TestPerformance();
    // Mode d'emploi :
    // Il s'agit du constructueur (sans param�tre) par d�faut des objets TestPerformance.

    virtual ~TestPerformance();
    // Mode d'emploi :
    // Il s'agit du destructeur des objets TestPerformance.

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- M�thodes prot�g�es

    //----------------------------------------------------- Attributs prot�g�s

    const string folder = "TestPerformance/TestDico";

    const string dictionnaire = "/Dictionnaire1.txt";
    const string mesures = "/HealthMesure1.txt";
    const string metaDonnee = "/MetaDonnees1.txt";

};

//-------------------------------- Autres d�finitions d�pendantes de <TestPerformance>

#endif // TestPerformance_H