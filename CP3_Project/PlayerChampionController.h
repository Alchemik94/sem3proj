#pragma once

#include "ChampionController.h"
#include "KeyCatcher.h"

namespace Game
{
	class PlayerChampionController :public ChampionController, public Application::KeyCatcher
	{
//TODO
		public:
			PlayerChampionController(Champion* controlledChampion);
	};
}