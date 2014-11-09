#pragma once

#include "ChampionController.h"

namespace Game
{
	class PlayerChampionController :public ChampionController
	{
//TODO
		public:
			PlayerChampionController(Champion* controlledChampion);
	};
}