#ifndef _KNIGHT_DEFINITION
#define _KNIGHT_DEFINITION

#include "Knight.h"
#include "EnemiesFilter.h"

namespace Game
{
	Knight::Knight() :Champion()
	{
		//we have to create balance of parameters
	}

	void Knight::Attack(std::vector<Champion*> enemies)
	{
		//needs implementation
		EnemiesFilter* filter = (new EnemiesFilter())->Append(dynamic_cast<EnemiesFilter*>(new LaneEnemiesFilter()))->Append(dynamic_cast<EnemiesFilter*>(new DistanceEnemiesFilter()))->Append(dynamic_cast<EnemiesFilter*>(new ClosestOneEnemiesFilter()));
		
		std::vector<Champion*> filteredEnemies = filter->Filter(this,enemies);

		if (filteredEnemies.size() == 1)
		{
			filteredEnemies[0]->ChangeStatistics(ChampionParameters::CurrentHealth, TypeOfChange::Loose, GetParameter(ChampionParameters::BasicDamage));
		}
		else if (filteredEnemies.size() > 1)
		{
			//throwing an error
		}
	}
}

#endif
