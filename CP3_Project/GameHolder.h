#ifndef _GAMEHOLDER_DECLARATION
#define _GAMEHOLDER_DECLARATION

#include "IGameDisplayer.h"
#include "Champion.h"
#include <vector>
#include "Team.h"
#include "KeyCatcher.h"
#include "Timer.h"
#include "ITimerParam.h"

namespace Game
{
	class GameHolder: protected Display::IGameDisplayer, public Application::KeyCatcher, private Application::ITimerParameter
	{
		private:
			Team* _team1;
			Team* _team2;
			int _roundsNumber;
			int _currentRound;
			Application::KeyCatcher* _keyCatcher;
			//probably the only solution for now
			//main thread will catch keys
			//rounds will be run in this function by timer or another thread
			//(thread maybe?)
			//static void RoundRunner(Application::ITimerParameter* param);
		public:
			GameHolder();
			GameHolder(int numberOfRounds);
			//probably everything has to be in another thread
			virtual ~GameHolder();
			virtual void NewRound(int numberOfEnemies);
			virtual int RoundsNumber();
			virtual int CurrentRound();
			
	};
}

#endif