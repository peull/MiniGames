#include <iostream>

#include "SquadState.h"
#include "Squad.h"
#include "Warrior.h"
#include "Mage.h"

SquadState::SquadState()
{
	do 
	{
		system("cls");
		std::cout << "Choix disponibles:\n" <<
			"   1 : Ajouter un character\n" <<
			"   2 : Enlever tout les characters\n" <<
			"  -1 : Revenir au menu precedent\n" <<
			" Entrer votre choix: ";
		int choix = 0;
		std::cin >> choix;

		switch (choix)
		{
		case -1:
			return;
		case 1:
			AjoutCharacter();
			break;
		case 2:
			EnleverCharacters();
			break;
		}
	} while (true);
}

SquadState::~SquadState()
{
}

void SquadState::AjoutCharacter()
{
	const std::vector<Character*>& characters = Squad::GetCharacters();
	if (characters.size() == Squad::MAX_CHARACTERS)
	{
		std::cout << "Squad full.\n";
		return;
	}

	do
	{
		system("cls");
		std::cout << "Choix disponibles:\n" <<
			"   1 : Ajout d'un warrior\n" <<
			"   2 : Ajout d'un mage\n" <<
			/*"   3 : Ajout d'un healer\n" <<*/
			"  -1 : Revenir menu precedent\n" <<
			" Entrer votre choix: ";
		int choix = 0;
		std::cin >> choix;

		switch (choix)
		{
		case -1:
			return;
		case 1:
			Squad::AddCharacter(new Warrior());
			break;
		case 2:
			Squad::AddCharacter(new Mage());
			break;
		/*case 3:
			Squad::AddCharacter(new Character());
			break;*/
		}

	} while (characters.size() < Squad::MAX_CHARACTERS);
}

void SquadState::EnleverCharacters()
{
	Squad::ClearAllCharacters();
}
