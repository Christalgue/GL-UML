using namespace std;
#include "Maladie.h"
#include "Empreinte.h"
#include <string>
#include <iostream>


int main()
{
	string a = "cancer_du_sida";
	Maladie cancer_du_sida (a);
	cout << cancer_du_sida.getNom() << endl;
	string monEmpreinteID = "562";
	string monEmpreinteMaladie = "tamaman";
	string monEmpreinteAttributs = "AA;152.522201822802;147.966461981174;132.340194347595";
	string mesAttributs = "string;double;double; double";

	int id = stoi(monEmpreinteID);
	Maladie uneMaladie(monEmpreinteMaladie);
	Empreinte monEmpreinte(id, &uneMaladie);

	cout << monEmpreinte.getID() << endl;
	cout << monEmpreinte.getMaladie()->getNom() << endl;

	string bite;
	cin >> bite;

	cout << "Hello world !" << endl;
	cout << "Bonjour monde !" << endl;
	cout << "adieu !" << endl;

	return 0;
}//----- Fin de main