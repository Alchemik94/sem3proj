#ifndef _IKNIGHTDISPLAYER_DECLARATION
#define _IKNIGHTDISPLAYER_DECLARATION

#include "IChampionDisplayer.h"
#include "Champion.h"
#include "GameEnums.h"

namespace Display
{
	class IKnightDisplayer : public virtual IChampionDisplayer<Game::Champion>
	{
		public:
			virtual void DisplayAttack(std::vector<Game::Champion*> filteredEnemies)
			{
				//TODO
			}
			virtual void DisplayDeath()
			{
				//TODO
			}
			virtual void DisplayMove(Game::Direction direction, int change)
			{
				//TODO
			}
	};
}

#endif