#pragma once

#include "Champion.h"

namespace Game
{
	class ChampionController
	{
		protected:
			volatile bool* _paused;
			Champion* _controlledChampion;
		public:
			ChampionController(Champion* controlledChampion, volatile bool* paused);
			virtual void Start() = 0;
			virtual void Stop() = 0;
			virtual ~ChampionController();
	};
}