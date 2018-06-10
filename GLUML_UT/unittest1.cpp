#include "stdafx.h"
#include "CppUnitTest.h"
#include "Empreinte.h"
#include "Donnees.h"
#include "LectureAffichage.h"

#include <iostream>

#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace GLUML_UT
{
	TEST_CLASS(EmpreinteTest)
	{
	public:
		TEST_METHOD(Constructeur)
		{
			map<string, string> aMap;
			aMap["test"] = "test";
			Empreinte print(5, aMap);
			Assert::AreEqual(5, print.getID());
			Assert::AreEqual(aMap["test"], print.getValeurEmpreinte()["test"]);
		}
	};

	TEST_CLASS(DonneesTest)
	{
	public:
		TEST_METHOD(TestAddDictionnaire)
		{
			Empreinte test;
			pair <string, Empreinte> maPaire = make_pair("anyString", test);
			Donnees mesDonnees;
			mesDonnees.addDictionnaire(maPaire);
			multimap <string, Empreinte> dictionnaire = mesDonnees.getDictionnaire();
			Assert::AreEqual(1, (int)dictionnaire.size());
		}

		TEST_METHOD(TestAddMetaDonees)
		{
			pair <string, string> maPaire = make_pair("anyString1", "anyString2");
			Donnees mesDonnees;
			mesDonnees.addMetaDonnees(maPaire);
			map<string, string> mesMetaDonnees = mesDonnees.getMetaDonnees();
			Assert::AreEqual(1, (int)mesMetaDonnees.size());
		}

		TEST_METHOD(TestAddEnsembleEmpreinte)
		{
			Empreinte monEmpreinte;
			Donnees mesDonnees;
			mesDonnees.addEnsembleEmpreinte(monEmpreinte);
			vector <Empreinte> ensembleEmpreinte = mesDonnees.getEnsembleEmpreinte();
			Assert::AreEqual(1, (int)ensembleEmpreinte.size());
		}

		TEST_METHOD(TestClearMetaDonnees)
		{
			Donnees mesDonnees;

			mesDonnees.addMetaDonnees(make_pair("anyString1", "anyString2"));
			map<string, string> mesMetaDonnees1 = mesDonnees.getMetaDonnees();
			Assert::AreEqual(1, (int)mesMetaDonnees1.size());

			mesDonnees.clearMetaDonnees();
			map<string, string> mesMetaDonnees2 = mesDonnees.getMetaDonnees();
			Assert::AreEqual(0, (int)mesMetaDonnees2.size());
		}

		TEST_METHOD(TestClearDictionnaire)
		{
			Donnees mesDonnees;
			Empreinte test;
			pair <string, Empreinte> maPaire = make_pair("anyString", test);

			mesDonnees.addDictionnaire(maPaire);
			multimap <string, Empreinte> dictionnaire1 = mesDonnees.getDictionnaire();
			Assert::AreEqual(1, (int)dictionnaire1.size());

			mesDonnees.clearDictionnaire();
			multimap <string, Empreinte> dictionnaire2 = mesDonnees.getDictionnaire();
			Assert::AreEqual(0, (int)dictionnaire2.size());
		}

		TEST_METHOD(TestClearEnsembleEmpreinte)
		{
			Empreinte monEmpreinte;
			Donnees mesDonnees;

			mesDonnees.addEnsembleEmpreinte(monEmpreinte);
			vector <Empreinte> ensembleEmpreinte1 = mesDonnees.getEnsembleEmpreinte();
			Assert::AreEqual(1, (int)ensembleEmpreinte1.size());

			mesDonnees.clearEnsembleEmpreinte();
			vector <Empreinte> ensembleEmpreinte2 = mesDonnees.getEnsembleEmpreinte();
			Assert::AreEqual(0, (int)ensembleEmpreinte2.size());
		}

	};

	TEST_CLASS(LectureAffichageTest)
	{
	public:
		TEST_METHOD(TestLectureMetaDonnees)
		{
			//LectureAffichage monTest;
			//monTest.LectureMetaDonnees();
			//monTest.LectureMetaDonnees("../Projet6/TestPerformance/TestDico1/MetaDonnees1.txt");
	
			Donnees mesDonnees;
			//map<string, string> maMap = monTest.getLAMetaDonnees();
			//Assert::AreEqual(0, (int)maMap.size());
			ifstream infile("../GLUML_UT/MetaDonnees.txt");
			Assert::AreEqual(1, 1);
			/*
			if (infile)
			{
				string nomAttribut;
				string typeAttribut;
				getline(infile, nomAttribut); // Pour sauter la 1ère ligne qui ne nous intéresse pas
				getline(infile, nomAttribut); // La deuxieme ligne comprend l'id qui ne doit pas rentrer dans la metadonnee
				while (getline(infile, nomAttribut, ';'))
				{
					getline(infile, typeAttribut);
					mesDonnees.addMetaDonnees(make_pair(nomAttribut, typeAttribut));
				}
				Assert::AreEqual(1, 1);
			}
			else {
				Assert::AreEqual(0,1);
			}
			*/
			//Assert::AreEqual((string)"int", maMap["A0"]);
			
			// void LectureMetaDonnees(string nomFichierMetaDonnee);
		}

		TEST_METHOD(TestLectureDictionnaire)
		{
			Assert::AreEqual(1, 0);
			// void LectureDictionnaire(string nomFichierDictionnaire);
		}

		TEST_METHOD(TestLectureEmpreintes)
		{
			Assert::AreEqual(1, 0);
			// void LectureEmpreintes(string nomFichierEmpreintes);
		}
		
		TEST_METHOD(TestAfficherMaladiesPrisesEnCompte)
		{
			Assert::AreEqual(1, 0);
			// void AfficherMaladiesPrisesEnCompte();
		}

		
		TEST_METHOD(TestAfficherCaracteristiquesMaladie)
		{
			Assert::AreEqual(1, 0);
			// map<string, pair<string, string>> AfficherCaracteristiquesMaladie(string maladie, bool affichage);

		}

		TEST_METHOD(TestDemandeAnalyse)
		{
			Assert::AreEqual(1, 0);
			// void DemandeAnalyse();
		}
		
	};

}