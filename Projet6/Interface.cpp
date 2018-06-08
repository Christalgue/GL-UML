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

static string saisieClavier()
{
    string ligne;
    do
    {
        getline(cin,ligne);
    } while (ligne.empty());
    return ligne;
}

static bool fichierExiste (string nomFichier)
{
    ifstream infile(nomFichier);
    if (infile)
    {
        return true;
    }
    else
    {
        cout << "Ce fichier n'existe pas.\n"
                "Réessayez." << endl;
        return false;
    }
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

static string entreeNomFichier()
{
    string saisie;
    do
    {
        saisie = saisieClavier();
    }while (!fichierExiste(saisie));
    return saisie;
}

static void choixDonneesEntrees(LectureAffichage &lA)
{
    string saisie;
    cout << "Choix des données pour les tests : \n"
            "1. Importer vos propres fichiers\n"
            "2. Utiliser les fichiers pré-sélectionnés\n" << endl;
    
    switch (saisieChoix(1, 2))
    {
        case 1:
            cout << "Veuillez entrer le nom du fichier contenant les méta données" << endl;
            lA.LectureMetaDonnees(entreeNomFichier());

            cout << "Veuillez entrer le nom du fichier contenant les maladies associées aux empreintes connues" << endl;
            lA.LectureDictionnaire(entreeNomFichier());
            break;
        case 2:
            cout << "Les fichiers par défaut sont \"HealthMeasurementDescription.txt\" pour les métadonnées "
                    "et \"HealthMeasurementsWithLabels.txt\" pour le dictionnaire des maladies." << endl;
            lA.LectureMetaDonnees("HealthMeasurementDescription.txt");
            lA.LectureDictionnaire("HealthMeasurementsWithLabels.txt");
            break;
    }    
}

enum Choix { ANALYSE, LISTE_MALADIES, CARACTERISTIQUES_MALADIE, SORTIE, CHANGER_METADONNEES_DICTIONNAIRE };

static Choix afficherMenu()
{
    string menu = "Menu :\n"
                       "1. Analyser une ou plusieurs empreintes\n"
                       "2. Lister les maladies prises en comptes\n"
                       "3. Afficher les caractéristiques déterminantes d'une maladie\n"
                       "4. Choisir une autre métadonnées et un autre dictionnaire de maladies\n"
                       "5. Quitter\n"
                       "\n"
                       "Votre choix : ";
    cout << menu;

    switch (saisieChoix(1, 5))
    {
        case 1:
            return ANALYSE;
        case 2:
            return LISTE_MALADIES;
        case 3:
            return CARACTERISTIQUES_MALADIE;
        case 4:
            return CHANGER_METADONNEES_DICTIONNAIRE;
        case 5:
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

    choixDonneesEntrees(lA);    
    
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
                lA.LectureEmpreintes(entreeNomFichier());
                lA.DemandeAnalyse();
                break;
            case LISTE_MALADIES:
                lA.AfficherMaladiesPrisesEnCompte();
                break;
            case CARACTERISTIQUES_MALADIE:
                cout << "Veuillez entrez le nom de la maladie que vous recherchez." << endl;
                lA.AfficherCaracteristiquesMaladie(saisieClavier(), true);
                break;
            case CHANGER_METADONNEES_DICTIONNAIRE:
                choixDonneesEntrees(lA);
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
    Executer();
    
    
    
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
	
	string nomFichierEmpreintes = "HealthMeasurements.txt";

	lA.LectureEmpreintes(nomFichierEmpreintes);
	
	cout << "-------------------" << endl;
	
	string maladie1 = "Nevrose du pancreas";
	string maladie2 = "M3";
	string maladie3 = "Maladie1";
	lA.AfficherCaracteristiquesMaladie(maladie2,true);
	*/
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
