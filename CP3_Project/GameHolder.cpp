#ifndef _GAMEHOLDER_DEFINITION
#define _GAMEHOLDER_DEFINITION

#include "GameHolder.h"

namespace Game
{
	GameHolder::GameHolder()
	{
		_team1 = new Team();
		_team2 = new AutogeneratingTeam(5, ReadyPreset::AIKnight);
	}
}

#endif