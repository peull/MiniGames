/// <summary>
/// Ce programme fait un jeu de tic-tac-toe contre l'ordinateur.
/// </summary>

#include <iostream>
#include <vector>

#include "Grille.h"
#include "Joueur.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	Grille grille;
	Joueur joueur1('X');
	Joueur joueur2('O');

	// Afficher les instructions
	cout << "Bienvenue dans le monde du tic-tac-toe." << endl <<
		    "Voici les instructions:" << endl <<
			" 1- Pour gagner, vous devez aligner horizontalement, verticalement ou diagonalement trois symboles identiques." << endl << 
			" 2- Vous pouvez placer un seul symbole par tour." << endl << 
			" 3- S'il y a egalite, la partie est nulle." << endl << endl;

	while (true)
	{
		if (grille.ResteCasesVide())
		{
			std::pair<int, int> coordonnees = joueur1.DemanderInput();
			grille.AffecterCase(coordonnees.first, coordonnees.second, joueur1.GetSymbole());
		}
		else
		{
			break;
		}

		grille.Afficher();

		// On sait que le joueur 1 vient de jouer, donc le joueur 1 qui gagne 
		if (grille.VerifierVictoire())
		{
			cout << "Le joueur 1 gagne!" << endl;
			break;
		}

		if (grille.ResteCasesVide())
		{
			std::pair<int, int> coordonnees = joueur2.DemanderInput();
			grille.AffecterCase(coordonnees.first, coordonnees.second, joueur2.GetSymbole());
		}
		else
		{
			break;
		}

		grille.Afficher();

		// On sait que le joueur 2 vient de jouer, donc le joueur 2 qui gagne 
		if (grille.VerifierVictoire())
		{
			cout << "Le joueur 2 gagne!" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}