/*******************************************************************************************
TestPerformance  -  description
-------------------
d饕ut                : 10/01/2018
copyright            : (C) 2018 par
e-mail               :
********************************************************************************************/


//---------- R饌lisation de la classe <TestPerformance> (fichier TestPerformance.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst鑪e
using namespace std;

//------------------------------------------------------ Include personnel
#include <iostream>
#include <ctime>
#include <string>
#include "TestPerformance.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

void TestPerformance::Tester() {
    cout << "Test de Performance" << endl;

    LectureAffichage leTest;
    string cheminMetaDonnee;
    string cheminDictionnaire;
    string cheminEmpreintes;


    // Notre test de performance s'étale sur 8 échelons
    for (int i = 1; i < 8;i++) {
        cout << endl;
        cout << "Echelon : " << i << endl;

        cheminMetaDonnee = folder + to_string(i) + metaDonnee;
        cheminDictionnaire = folder + to_string(i) +  dictionnaire;
        cheminEmpreintes = folder + to_string(i) + mesures;

        leTest.LectureMetaDonnees(cheminMetaDonnee);

        clock_t beginD = clock();
        leTest.LectureDictionnaire(cheminDictionnaire);
        clock_t endD = clock();

        leTest.LectureEmpreintes(cheminEmpreintes);

        clock_t beginA = clock();
        leTest.DemandeAnalyse();
        clock_t endA = clock();

        double elapsed_secsD = double(endD - beginD) / CLOCKS_PER_SEC;
        double elapsed_secsA = double(endA - beginA) / CLOCKS_PER_SEC;
        cout << endl;
        cout << "Temps de lecture du dictionnaire (s): " << elapsed_secsD << endl;
        cout << "Temps d'analayse (s): " << elapsed_secsA << endl;
        cout << endl;
    }

    cout << "Fin du Test de Performance." << endl;
}

//----------------------------------------------------- M騁hodes publiques

//------------------------------------------------- Surcharge d'op駻ateurs

//-------------------------------------------- Constructeurs - destructeur


TestPerformance::TestPerformance()
// Algorithme : 
{
#ifdef MAP
    cout << "Appel au constructeur de <TestPerformance>" << endl;
#endif
} //----- Fin de TestPerformance

TestPerformance::~TestPerformance()
{
#ifdef MAP
    cout << "Appel au destructeur de <TestPerformance>" << endl;
#endif
} //----- Fin de ~TestPerformance


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M騁hodes prot馮馥s
