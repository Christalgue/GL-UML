using namespace std;
#include "Maladie.h"
#include "Empreinte.h"
#include <string>
#include <iostream>
#include <fstream>


int main()
{
	string a = "cancer_du_sida";
	Maladie cancer_du_sida (a);
	cout << cancer_du_sida.getNom() << endl;
	string monEmpreinteID = "562";
	string monEmpreinteMaladie = "tamaman";
	string monEmpreinteAttributs = "AA;152.522201822802;147.966461981174;132.340194347595";
	string mesAttributs = "string;double;double; double";
	string nomAttributs = "A1;A2;A3;A4";

	map<string, string> attr;
	string monAttribut;


	string nomAttribut;
	string typeAttribut;

	string nomFichier = "HealthMeasurementDescription.txt";
	ifstream infile(nomFichier);
	if (infile)
	{
		while (getline(infile, nomAttribut, ';'))
		{
			getline(infile, typeAttribut);

			Empreinte::attributs.insert(make_pair(nomAttribut, typeAttribut));

			cout << nomAttribut << endl;
			cout << typeAttribut << endl;
		}
	}



	/*string fichierMesure = "HealthMeasurements.txt";
	ifstream infile2(fichierMesure);
	if (infile2)
	{
		while (getline(infile2))
		eeeeeeeeeeeee
	}*/

	string i;
	cin >> i;

	
	
	





	/*
	int id = stoi(monEmpreinteID);
	Maladie uneMaladie(monEmpreinteMaladie);
	Empreinte monEmpreinte(id, &uneMaladie);

	cout << monEmpreinte.getID() << endl;
	cout << monEmpreinte.getMaladie()->getNom() << endl;*/

	return 0;
}//----- Fin de main