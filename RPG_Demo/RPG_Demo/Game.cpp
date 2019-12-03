#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Game.h"
#include "SquadState.h"
#include "FightState.h"
#include "Squad.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Run()
{
	srand(time(NULL));
	do
	{
		system("cls");
		std::cout << "Voici les choix disponibles:\n" <<
			"    1 : Affecter notre squad\n" <<
			"    2 : Aller combattre!\n" << 
			"   -1 : Quitter le jeu\n" << 
			" Entrer votre choix: ";
		int choix = 0;
		std::cin >> choix;

		BaseGameState *state = nullptr;
		switch (choix)
		{
		case -1:
			return;
		case 1:
			state = new SquadState();
			break;
		case 2:
			if (Squad::GetCharacters().size() == 0)
			{
				std::cout << "La squad est vide. Veuillez ajouter des characters.\n";
				break;
			}
			
			state = new FightState();
			break;
		}

		delete state;
	
	} while (true);
}
