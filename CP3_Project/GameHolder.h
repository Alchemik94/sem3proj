#ifndef _GAMEHOLDER_DECLARATION
#define _GAMEHOLDER_DECLARATION

#include "Champion.h"
#include <vector>
#include "Team.h"

namespace Game
{
	class GameHolder
	{
		private:
			Team* _team1, _team2;
		public:
			GameHolder()
			{
				_team1 = new Team();
				_team2 = new AutogeneratingTeam(5, ReadyPreset::AIKnight);
			}
	};
}

#endif