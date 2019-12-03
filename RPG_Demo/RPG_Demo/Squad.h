#pragma once

#include <vector>
#include "Character.h"

class Squad
{
public:
	Squad();
	~Squad();

	static const int MAX_CHARACTERS = 3;

	static void AddCharacter(Character* a_Character) { m_Characters.push_back(a_Character); }
	static std::vector<Character*>& GetCharacters() { return m_Characters; }
	static void ClearAllCharacters() { m_Characters.clear(); }

	static Character* GetCharacter(const int index) { return m_Characters[index]; }

private:
	static std::vector<Character*> m_Characters;
	
};

