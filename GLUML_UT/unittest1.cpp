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
			// Verifier qu'une paire pair<string,string>
			// est ajoutée à la map 
			// map<string, string> metaDonnees;
		}

		TEST_METHOD(TestAddEnsembleEmpreinte)
		{
			// Verifier qu'une Empreinte e
			// est ajoutée à  vector<Empreinte> ensembleEmpreinte;
		}

		TEST_METHOD(TestClearMetaDonnees)
		{
			// Verifier que vide meta map<string, string> metaDonnees;
		}

		TEST_METHOD(TestClearDictionnaire)
		{
			// Verifier vide multimap<string, Empreinte> dictionnaire;
		}

		TEST_METHOD(TestClearEnsembleEmpreinte)
		{
			// Verifier vide vector<Empreinte> ensembleEmpreinte;
		}

	};

	TEST_CLASS(LectureAffichageTest)
	{
	public:
		TEST_METHOD(TestLectureMetaDonnees)
		{
			// void LectureMetaDonnees(string nomFichierMetaDonnee);
		}

		TEST_METHOD(TestLectureDictionnaire)
		{
			// void LectureDictionnaire(string nomFichierDictionnaire);
		}

		TEST_METHOD(TestLectureEmpreintes)
		{
			// void LectureEmpreintes(string nomFichierEmpreintes);
		}
		
		TEST_METHOD(TestAfficherMaladiesPrisesEnCompte)
		{
			// void AfficherMaladiesPrisesEnCompte();
		}

		
		TEST_METHOD(TestAfficherCaracteristiquesMaladie)
		{
			// map<string, pair<string, string>> AfficherCaracteristiquesMaladie(string maladie, bool affichage);

		}

		TEST_METHOD(TestDemandeAnalyse)
		{
			// void DemandeAnalyse();
		}
		
	};

}