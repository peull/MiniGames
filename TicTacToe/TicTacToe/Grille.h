#pragma once

#include <vector>

class Grille
{
public:
	Grille();

	void Afficher();
	void AffecterCase(const int& a_Range, const int& a_Colonne, const char& a_Symbole);
	bool VerifierVictoire();

	bool ResteCasesVide();
	bool EstVide(const int& a_Range, const int& a_Colonne);

private:
	const int NOMBRE_DE_CASE = 9;

	bool VictoireHorizontal();
	bool VictoireVertical();
	bool VictoireDiagonale();

	std::vector<std::vector<char> > m_Grille;
};