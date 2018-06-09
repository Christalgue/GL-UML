#include "stdafx.h"
#include "CppUnitTest.h"
#include "Empreinte.h"
#include "Donnees.h"

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
			Assert::AreEqual(1, (int)mesDonnees.getDictionnaire().size());
			
		}

	};
}