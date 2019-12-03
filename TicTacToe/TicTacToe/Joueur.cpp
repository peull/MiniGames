#include <iostream>
#include "Joueur.h"

using std::cout; 
using std::cin;

Joueur::Joueur(const char & a_Symbole)
	: m_Symbole(a_Symbole)
{
}

std::pair<int, int> Joueur::DemanderInput()
{
	int range = 0;
	int colonne = 0;
	cout << "Entrer la range choisie: ";
	do
	{
		cin >> range;
	} while (range < 1 || range > 3);

	cout << "Entrer la colonne choisie: ";
	do
	{
		cin >> colonne;
	} while (colonne < 1 || colonne > 3);

	return std::pair<int, int>(range - 1, colonne - 1);
}
