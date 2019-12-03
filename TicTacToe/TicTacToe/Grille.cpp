#include <iostream>

#include "Grille.h"


using std::cout;
using std::endl;

/// <summary> Constructeur d'une grille </summary>
Grille::Grille()
{
	m_Grille.reserve(NOMBRE_DE_CASE);
	for (int i = 0; i < NOMBRE_DE_CASE / 3; i++)
	{
		m_Grille.push_back(std::vector<char>(3, ' '));
	}
}

/// <summary> Afficher le contenu de la grille. </summary>
void Grille::Afficher()
{
	cout << " Grille de jeu" << endl;
	for (std::vector<std::vector<char>>::const_iterator iter = m_Grille.begin(); iter != m_Grille.end(); iter++)
	{
		for (std::vector<char>::const_iterator iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++)
		{
			cout << " " << (*iter2) << " | ";
		}

		cout << "\n ---+---+---" << endl;
	}
}

/// <summary> Affecte un symbole a une case dans la grille </summary>
/// <param name="a_Range"> La range de la grille </param>
/// <param name="a_Colonne"> La colonne de la grille </param>
/// <param name="a_Symbole"> Le symbole a ajouter dans la grille </param>
void Grille::AffecterCase(const int & a_Range, const int & a_Colonne, const char & a_Symbole)
{
	m_Grille[a_Range][a_Colonne] = a_Symbole;
}

/// <summary> Verifie s'il y a une victoire </summary>
bool Grille::VerifierVictoire()
{
	return VictoireHorizontal() || VictoireVertical() || VictoireDiagonale();
}

// @brief	Retourne vrai s'il reste des cases vide.
// @return	bool : Vrai s'il reste des cases vide. False dans le cas contraire.
bool Grille::ResteCasesVide()
{
	for (int i = 0; i < m_Grille.size(); i++)
	{
		for (int j = 0; j < m_Grille[i].size(); j++)
		{
			if (EstVide(i, j))
			{
				return true;
			}
		}
	}

	return false;
}

// @brief	Verifie si une case est vide
// @param	const int& a_range : La range a verifier
// @param   const int& a_colonne : La colonne a verifier
// @return	bool : Vrai si la case est vide
bool Grille::EstVide(const int & a_Range, const int & a_Colonne)
{
	return m_Grille[a_Range][a_Colonne] == ' ';
}

/// <summary> Verifier s'il y a une victoire horizontale </summary>
/// <return> Vrai s'il y a une victoire horizontale. </return>
bool Grille::VictoireHorizontal()
{
	// 0 1 2, 3 4 5, 6 7 8
	for (int i = 0; i < m_Grille.size(); i++)
	{
		if (m_Grille[i][0] != ' ' && m_Grille[i][0] == m_Grille[i][1] && m_Grille[i][1] == m_Grille[i][2])
		{
			return true;
		}
	}

	return false;
}

/// <summary> Verifier s'il y a une victoire verticale </summary>
/// <return> Vrai s'il y a une victoire verticale. </return>
bool Grille::VictoireVertical()
{
	// (0,0) (1,0) (2,0) , (0,1) (1,1) (2,1) , (0,2) (1,2) (2,2)
	for (int j = 0; j < m_Grille.size(); j++)
	{
		if (m_Grille[0][j] != ' ' && m_Grille[0][j] == m_Grille[1][j] && m_Grille[1][j] == m_Grille[2][j])
		{
			return true;
		}
	}

	return false;
}

/// <summary> Verifier s'il y a une victoire diagonale </summary>
/// <return> Vrai s'il y a une victoire diagonale. </return>
bool Grille::VictoireDiagonale()
{
	// (2,0) (1,1) (0,2) , (0,0) (1,1) (2,2)
	return	(m_Grille[0][0] != ' ' && m_Grille[0][0] == m_Grille[1][1] && m_Grille[1][1] == m_Grille[2][2]) ||
		(m_Grille[2][0] != ' ' && m_Grille[2][0] == m_Grille[1][1] && m_Grille[1][1] == m_Grille[0][2]);
}
