using namespace std;
#include "Maladie.h"
#include "Empreinte.h"
#include "LectureAffichage.h"
#include <string>
#include <iostream>
#include <fstream>
#include <limits>

static void afficheRepete(char c, unsigned int fois)
{
    for (unsigned int i = 0; i < fois; i++)
    {
        cout << c;
    }
}

static string saisieFichier()
{
    string a;
    cin >> a;
    return a;
}

static void afficheCentre(char c, string msg, unsigned int largeur)
// Algorithme :
//      Calcule l'espacement à gauche et à droite du message par rapport à la largeur.
//      Affiche la bordure, l'espacement gauche, le message, l'espacement droit puis la bordure.
//
{
    cout << c;
    int padding = largeur - 2 - msg.size();
    int halfPadding = padding/2;
    afficheRepete(' ', halfPadding);
    cout << msg;
    afficheRepete(' ', padding-halfPadding);
    cout << c;
}

static unsigned int saisieChoix (unsigned int min, unsigned int max)
// Algorithme :
//      On tente d'extraire un nombre depuis l'entrée standard
//      Tant que l'extraction n'a pas réussi ou que le nombre n'est pas entre les bornes voulues,
//          On réinitialise l'état du flux, on ignore tous les caractères de cette line,
//          et on redemande un choix.
{
    unsigned int choix;
    cin >> choix;
    while (cin.fail() || choix < min || choix > max)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Choix impossible." << endl;
        cout << "Votre choix : ";
        cin >> choix;
    }
    return choix;
}

enum Choix { ANALYSE, LISTE_MALADIES, CARACTERISTIQUES_MALADIE, SORTIE };

static Choix afficherMenu()
{
    string menu = "Menu :\n"
                       "1. Analyser une ou plusieurs empreintes\n"
                       "2. Lister les maladies prises en comptes\n"
                       "3. Afficher les caractéristiques déterminantes d'une maladie\n"
                       "4. Quitter\n"
                       "\n"
                       "Votre choix : ";
    cout << menu;

    switch (saisieChoix(1, 4))
    {
        case 1:
            return ANALYSE;
        case 2:
            return LISTE_MALADIES;
        case 3:
            return CARACTERISTIQUES_MALADIE;   
        case 4:
            return SORTIE;
        default:
            cerr << "Choix impossible !" << endl;
            return SORTIE;
    }
}

static void Executer()
{
    // Affichage du titre
    const unsigned int LARGEUR = 20;
    afficheRepete('*', LARGEUR);
    cout << endl;
    afficheCentre('*', "Malad'IF", LARGEUR);
    cout << endl;
    afficheRepete('*', LARGEUR);
    cout << endl;
    
    LectureAffichage lA;
    cout << "Veuillez entrer le nom du fichier contenant les méta données" << endl;
    lA.LectureMetaDonnees(saisieFichier());
    cout << "Veuillez entrer le nom du fichier contenant les maladies associées aux empreintes connues" << endl;
    lA.LectureDictionnaire(saisieFichier());

    //Affichage du menu et sélection du choix
    Choix choix;
    do
    {
        cout << endl;
        choix = afficherMenu();
        cout << endl;
        switch (choix)
        {
            case ANALYSE:
                cout << "Veuillez entrez le nom du fichier des empreintes à analyser." << endl;
                lA.LectureEmpreintes(saisieFichier());
                //lA.TrouverMaladie();
                break;
            case LISTE_MALADIES:
                lA.AfficherMaladiesPrisesEnCompte();
                break;
            case CARACTERISTIQUES_MALADIE:
                cout << "Veuillez entrez le nom de la maladie que vous recherchez." << endl;
                lA.AfficherCaracteristiquesMaladie(saisieFichier(), true);
                break;
            case SORTIE:
                break;
            default:
                cout << "Choix non implémenté !" << endl;
                break;
        }
    } while (choix != SORTIE);
}

int main()
{
	/*
	string a = "nomDeMaladie";
	Maladie hoi (a);
	cout << hoi.getNom() << endl;*/
        
        // Lance le menu
        //Executer();
    
    
    
	/*LectureAffichage lA;
	
	// Test le chargement de la m・ｽta donn・ｽe
	string nomFichierMetaDonnee = "HealthMeasurementDescription2.txt";

	lA.LectureMetaDonnees(nomFichierMetaDonnee);

	cout << "-------------------" << endl;

	// Test le chargement du dictionnaire
	
	string nomFichierDico = "HealthMeasurementsWithLabels2.txt";

	lA.LectureDictionnaire(nomFichierDico);
    
	cout << "-------------------" << endl;
	
    lA.AfficherMaladiesPrisesEnCompte();

	cout << "-------------------" << endl;
	/*
	string nomFichierEmpreintes = "HealthMeasurements.txt";

	lA.LectureEmpreintes(nomFichierEmpreintes);
	*/
	cout << "-------------------" << endl;
	
	string maladie1 = "Nevrose du pancreas";
	string maladie2 = "M3";
	string maladie3 = "Maladie1";
	lA.AfficherCaracteristiquesMaladie(maladie2,true);
	
	//LectureAffichage::LectureMetaDonnees();

	
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
/*
	string i;
	cin >> i;
*/
	/*
	int id = stoi(monEmpreinteID);
	Maladie uneMaladie(monEmpreinteMaladie);
	Empreinte monEmpreinte(id, &uneMaladie);

	cout << monEmpreinte.getID() << endl;
	cout << monEmpreinte.getMaladie()->getNom() << endl;*/
        
	return 0;
}//----- Fin de main
