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
	char mesAttributs[] = "string;double;double;double";

	string pch = strtok(mesAttributs, ";");
	printf("%s\n", pch);

	vector<string> mesAttributs;

	//vector<string> Empreinte::attributs = mesAttributs;

	int id = stoi(monEmpreinteID);
	Maladie uneMaladie(monEmpreinteMaladie);
	vector<S> mesMesures;
	/*
	Empreinte monEmpreinte(id, &uneMaladie, mesMesures);

	cout << monEmpreinte.getID() << endl;
	cout << monEmpreinte.getMaladie()->getNom() << endl;
	*/
	string b;
	cin >> b;

	return 0;
}//----- Fin de main