#pragma once
#include "BaseGameState.h"
class SquadState :
	public BaseGameState
{
public:
	SquadState();
	~SquadState();

	void AjoutCharacter();
	void EnleverCharacters();
private:
};

