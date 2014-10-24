#ifndef _KNIGHT_DECLARATION
#define _KNIGHT_DECLARATION

#include "Champion.h"
#include "IKnightDisplayer.h"

namespace Game
{
	class Knight :protected Display::IKnightDisplayer, public Champion
	{
		protected:
			//Knight attacks all enemies in range on his lane.
			virtual Application::IFilter* CreateFilter();
		public:
			Knight(ReadyPreset preset);
	};
}

#endif