#include "stdafx.h"
#include "CppUnitTest.h"
#include "Empreinte.h"

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
		}

	};
}