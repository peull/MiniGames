#pragma once

#include <vector>

class Enemy;

class EnemySquad
{
public:
	EnemySquad();
	~EnemySquad();

	static void AddEnemy(Enemy* a_Enemy);
	static const std::vector<Enemy*>& GetEnemies();
	static void ClearAllEnemies();

	static Enemy* GetEnemy(const int index);

	static void RollEnemies();
	static void RemoveEnemy(Enemy* a_EnemyToRemove);

private:
	static std::vector<Enemy*> m_Enemies;
};

