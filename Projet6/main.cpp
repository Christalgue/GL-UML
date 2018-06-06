using namespace std;
#include "Maladie.h"
#include "Empreinte.h"
#include "LectureAffichage.h"
#include <string>
#include <iostream>
#include <fstream>


int main()
{
	/*
	string a = "nomDeMaladie";
	Maladie hoi (a);
	cout << hoi.getNom() << endl;*/

	LectureAffichage lA;
	
	// Test le chargement de la mE½ta donnE½e
	string nomFichierMetaDonnee = "HealthMeasurementDescription.txt";

	lA.LectureMetaDonnees(nomFichierMetaDonnee);

	cout << "-------------------" << endl;

	// Test le chargement du dictionnaire

	string nomFichierDico = "HealthMeasurementsWithLabels2.txt";

	lA.LectureDictionnaire(nomFichierDico);
    
	cout << "-------------------" << endl;

    lA.AfficherMaladiesPrisesEnCompte();

	cout << "-------------------" << endl;

	string nomFichierEmpreintes = "HealthMeasurements.txt";

	lA.LectureEmpreintes(nomFichierEmpreintes);


	//LectureAffichage::LectureMetaDonnees();

	/*
	string monEmpreinteID = "562";
	string monEmpreinteMaladie = "unemaladie";
	string monEmpreinteAttributs = "AA;152.522201822802;147.966461981174;132.340194347595";
	string mesAttributs = "string;double;double; double";
	string nomAttributs = "A1;A2;A3;A4";
	*/


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



// TEST POUR GIT