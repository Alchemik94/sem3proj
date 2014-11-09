#ifndef _GAMEHOLDER_DECLARATION
#define _GAMEHOLDER_DECLARATION

#include "IGameDisplayer.h"
#include "Champion.h"
#include <vector>
#include "Team.h"

namespace Game
{
	class GameHolder: protected Display::IGameDisplayer
	{
		private:
			Team* _team1;
			Team* _team2;
			int _roundsNumber;
			int _currentRound;
		public:
			GameHolder();
			GameHolder(int numberOfRounds);
			virtual ~GameHolder();
			virtual void NewRound(int numberOfEnemies);
			int RoundsNumber();
			int CurrentRound();
			
	};
}

#endif