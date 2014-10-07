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

	Application::Filter* Knight::CreateFilter()
	{
		return (new EnemiesFilter())->Append(new LaneEnemiesFilter())->Append(new DistanceEnemiesFilter())->Append(new ClosestOneEnemiesFilter());
	}

	void Knight::DisplayAttack(std::vector<Champion*> filteredEnemies)
	{
		//to implement
	}

	void Knight::DisplayDeath()
	{
		//to implement
	}


}

#endif
