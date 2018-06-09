/************************************************************************************
TestPerformance  -  description
-------------------
dÈbut                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
*************************************************************************************/

//---------- Interface de la classe <TestPerformance> (fichier TestPerformance.h) ----------------
#if ! defined ( TestPerformance_H )
#define TestPerformance_H

//--------------------------------------------------- Interfaces utilisÈes
#include "LectureAffichage.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// RÙle de la classe <TestPerformance>
//------------------------------------------------------------------------

using namespace std;

class TestPerformance
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- MÈthodes publiques

    void Tester();

    //------------------------------------------------- Surcharge d'opÈrateurs
    TestPerformance & operator = (const TestPerformance & unTestPerformance) = delete;
    // Mode d'emploi :
    // Il s'agit de la surcharge de l'opÈrateur = pour des objets TestPerformance.
    // Contrat :
    // dÈclarÅEmais non dÈfini pour intersepter son Èventuel appel.

    //-------------------------------------------- Constructeurs - destructeur
    TestPerformance(const TestPerformance & unTestPerformance) = delete;
    // Mode d'emploi :
    // Il s'agit du constructueur de copie du objet TestPerformance.
    // Contrat :
    // dÈclarÅEmais non dÈfini pour intersepter son Èventuel appel.

    TestPerformance();
    // Mode d'emploi :
    // Il s'agit du constructueur (sans paramËtre) par dÈfaut des objets TestPerformance.

    virtual ~TestPerformance();
    // Mode d'emploi :
    // Il s'agit du destructeur des objets TestPerformance.

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- MÈthodes protÈgÈes

    //----------------------------------------------------- Attributs protÈgÈs

    const string folder = "TestPerformance/Test";

    const string dictionnaire = "/Dictionnaire1.txt";
    const string mesures = "/HealthMesure1.txt";
    const string metaDonnee = "/MetaDonnees1.txt";

};

//-------------------------------- Autres dÈfinitions dÈpendantes de <TestPerformance>

#endif // TestPerformance_H