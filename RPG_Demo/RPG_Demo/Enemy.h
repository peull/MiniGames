

class Enemy
{
public:
	Enemy();
	~Enemy();

	const int GetAttackDamage() { return m_AttackDamage; }
	void TakeDamage(const int a_Damage);

	const int GetHp() { return m_Hp; }

private:
	int m_AttackDamage;
	int m_Hp;
};