#pragma once

class Joueur
{
public:
	Joueur(const char& a_Symbole);

	std::pair<int, int> DemanderInput();
	const char& GetSymbole() { return m_Symbole; }

private:
	char m_Symbole;
};