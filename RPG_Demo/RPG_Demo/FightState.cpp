#include <iostream>

#include "FightState.h"
#include "EnemySquad.h"
#include "Enemy.h"
#include "Squad.h"

FightState::FightState()
{
	EnemySquad::RollEnemies();

	do 
	{
		system("cls");

		std::cout << "Avec quel character vous voulez attaquer?:\n";
		for (unsigned int i = 0; i < Squad::GetCharacters().size(); i++)
		{
			std::cout << "   " << i + 1 << " : Le character numero " << i + 1 << 
				"\n      Hp: " << Squad::GetCharacter(i)->GetHp() << 
				"\n      Damage: " << Squad::GetCharacter(i)->GetAttackDamage() << "\n";
		}
		std::cout << " Entrer votre choix: ";
		int choixCharacter = 0;
		std::cin >> choixCharacter;
		choixCharacter--;

		system("cls");
		std::cout << "Vous voulez attaquer quel ennemie?:\n";
		for (unsigned int i = 0; i < EnemySquad::GetEnemies().size(); i++)
		{
			std::cout << "   " << i + 1 << " : L'ennemie numero " << i + 1 <<
				"\n      Hp: " << EnemySquad::GetEnemy(i)->GetHp() <<
				"\n      Damage: " << EnemySquad::GetEnemy(i)->GetAttackDamage() << "\n";
		}
		std::cout << " Entrer votre choix: ";
		int choixEnemy = 0;
		std::cin >> choixEnemy;
		choixEnemy--;

		// Appliquer les degats à l'ennemie
		const int damage = Squad::GetCharacter(choixCharacter)->GetAttackDamage();
		EnemySquad::GetEnemy(choixEnemy)->TakeDamage(damage);

		// Faire attaquer les enemies
		for (unsigned int i = 0; i < EnemySquad::GetEnemies().size(); i++)
		{
			const int randomCharacter = rand() % Squad::GetCharacters().size();
			const int enemyDamage = EnemySquad::GetEnemy(i)->GetAttackDamage();
			Squad::GetCharacter(randomCharacter)->TakeDamage(enemyDamage);
		}
	} while (EnemySquad::GetEnemies().size() > 0);
	
}

FightState::~FightState()
{
}
