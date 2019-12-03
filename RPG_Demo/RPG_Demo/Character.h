#pragma once
class Character
{
public:
	Character(const int a_Hp, const int a_Damage);
	virtual ~Character();

	const int GetAttackDamage() { return m_AttackDamage; }
	void TakeDamage(const int a_Damage) { m_Hp -= a_Damage; }

	const int GetHp() { return m_Hp; }

private:
	int m_AttackDamage;
	int m_Hp;
};

