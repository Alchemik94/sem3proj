#ifndef _ICHAMPIONDISPLAYER_DECLARATION
#define _ICHAMPIONDISPLAYER_DECLARATION

#include "GameEnums.h"
#include <vector>

namespace Display
{
	//Interface to define graphics. ChampionType has to implement IChampionDisplayer.
	template <class ChampionType>
	class IChampionDisplayer
	{
		public:
			//Displays attack animation of a champion
			virtual void DisplayAttack(std::vector<ChampionType*> filteredEnemies) = NULL;
			//Displays death of a champion
			virtual void DisplayDeath() = NULL;
			//Displays move of a champion
			virtual void DisplayMove(Game::Direction direction, int change) = NULL;

			//Displays that champion is being attacked
			virtual void DisplayBeingAttacked();
			//Displays change in current health
			virtual void DisplayCurrentHealthChange(Game::TypeOfChange type, int change);
			//Displays change in maximum health
			virtual void DisplayMaximumHealthChange(Game::TypeOfChange type, int change);
			
			//Shows champion on map
			virtual void DisplayOnMap();

			//Returns selected champion parameter
			virtual int GetParameter(Game::ChampionParameters param) = NULL;
	};
}

#endif