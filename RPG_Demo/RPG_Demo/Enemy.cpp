#include "Enemy.h"
#include "EnemySquad.h"

Enemy::Enemy()
	: m_AttackDamage(3)
	, m_Hp(15)
{
}

Enemy::~Enemy()
{
}

void Enemy::TakeDamage(const int a_Damage)
{
	m_Hp -= a_Damage;

	if (m_Hp <= 0)
	{
		EnemySquad::RemoveEnemy(this);
	}
}
