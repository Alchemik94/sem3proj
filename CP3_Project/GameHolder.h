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
			Team* _team1;
			Team* _team2;
		public:
			GameHolder();
	};
}

#endif