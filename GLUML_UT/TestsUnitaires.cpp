#include "stdafx.h"
#include "CppUnitTest.h"
#include "Empreinte.h"
#include "Donnees.h"
#include "LectureAffichage.h"

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
			LectureAffichage monTest;
			Donnees mesDonnees;
			map<string, string> maMap;

			// Lecture d'un fichier existant
			monTest.LectureMetaDonnees("../../GLUML_UT/DataFiles/MetaDonnees1.txt");
			maMap = monTest.getLAMetaDonnees();
			Assert::AreEqual(5, (int)maMap.size());
			Assert::AreEqual((string)"int", maMap["A0"]);
			Assert::AreEqual((string)"string", maMap["A1"]);
			Assert::AreEqual((string)"int", maMap["A2"]);
			Assert::AreEqual((string)"string", maMap["A3"]);
			Assert::AreEqual((string)"int", maMap["A4"]);
			
			// Lecture d'un fichier inexistant
			monTest.LectureMetaDonnees("x");
			maMap = monTest.getLAMetaDonnees();
			Assert::AreEqual(0, (int)maMap.size());
		}

		TEST_METHOD(TestLectureDictionnaire)
		{
			LectureAffichage monTest;
			Donnees mesDonnees;
			multimap<string, Empreinte> monDictionnaire;

			// Lecture d'un fichier existant
			monTest.LectureDictionnaire("../../GLUML_UT/DataFiles/Dictionnaire1.txt");
			monDictionnaire = monTest.getLADictionnaire();
			Assert::AreEqual(4, (int)monDictionnaire.size());

			// Lecture d'un fichier inexistant
			monTest.LectureDictionnaire("x");
			monDictionnaire = monTest.getLADictionnaire();
			Assert::AreEqual(0, (int)monDictionnaire.size());
		}

		TEST_METHOD(TestLectureEmpreintes)
		{

			LectureAffichage monTest;
			Donnees mesDonnees;

			vector<Empreinte> ensembleEmpreinte;

			// Lecture d'un fichier existant
			monTest.LectureEmpreintes("../../GLUML_UT/DataFiles/HealthMesure1.txt");
			ensembleEmpreinte = monTest.getLAEnsembleEmpreinte();
			Assert::AreEqual(10, (int)ensembleEmpreinte.size());

			// Lecture d'un fichier inexistant
			monTest.LectureEmpreintes("x");
			ensembleEmpreinte = monTest.getLAEnsembleEmpreinte();
			Assert::AreEqual(0, (int)ensembleEmpreinte.size());

		}
	};

}