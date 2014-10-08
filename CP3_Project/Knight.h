#ifndef _KNIGHT_DECLARATION
#define _KNIGHT_DECLARATION

#include "Champion.h"

namespace Game
{
	class Knight : public Champion
	{
		protected:
			//Knight attacks first enemy in range on his lane.
			virtual Application::Filter* CreateFilter();
			virtual void DisplayAttack(std::vector<Champion*> filteredEnemies);
			virtual void DisplayDeath();
			virtual void DisplayMove(Direction direction, int change);
		public:
			Knight();
	};
}

#endif