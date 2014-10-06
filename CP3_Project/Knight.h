#ifndef _KNIGHT_DECLARATION
#define _KNIGHT_DECLARATION

#include "Champion.h"

namespace Game
{
	class Knight : Game::Champion
	{
		public:
			Knight();
			//Knight attacks first enemy in range on his lane.
			virtual void Attack(std::vector<Champion*> enemies);
	};
}

#endif