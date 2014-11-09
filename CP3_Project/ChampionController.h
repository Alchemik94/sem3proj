#pragma once

#include "Champion.h"

namespace Game
{
	class ChampionController
	{
		protected:
			Champion* _controlledChampion;
		public:
			ChampionController(Champion* controlledChampion);
			virtual void Start() = 0;
			virtual void Stop() = 0;
			virtual ~ChampionController();
	};
}