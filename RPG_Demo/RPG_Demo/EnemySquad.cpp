#include <cstdlib>
#include <algorithm>

#include "Enemy.h"
#include "EnemySquad.h"

std::vector<Enemy*> EnemySquad::m_Enemies = {};

EnemySquad::EnemySquad()
{
}

EnemySquad::~EnemySquad()
{
}

void EnemySquad::AddEnemy(Enemy* a_Enemy)
{
	m_Enemies.push_back(a_Enemy);
}

const std::vector<Enemy*>& EnemySquad::GetEnemies()
{
	return m_Enemies; 
}

void EnemySquad::ClearAllEnemies()
{ 
	m_Enemies.clear(); 
}

Enemy* EnemySquad::GetEnemy(const int index)
{ 
	return m_Enemies[index]; 
}

void EnemySquad::RollEnemies()
{
	int enemiesNumber = rand() % 3 + 1;
	for (int i = 0; i < enemiesNumber; i++)
	{
		m_Enemies.push_back(new Enemy());
	}
}

void EnemySquad::RemoveEnemy(Enemy *a_EnemyToRemove)
{
	std::vector<Enemy*>::iterator enemy = std::find(m_Enemies.begin(), m_Enemies.end(), a_EnemyToRemove);
	if (enemy != m_Enemies.end())
	{
		m_Enemies.erase(enemy);
	}
}
