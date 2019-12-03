#include "Character.h"

Character::Character(const int a_Hp, const int a_Damage)
	: m_AttackDamage(a_Damage)
	, m_Hp(a_Hp)
{
}

Character::~Character()
{
}
