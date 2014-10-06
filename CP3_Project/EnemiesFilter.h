#ifndef _ENEMIES_FILTER_DECLARATION
#define _ENEMIES_FILTER_DECLARATION

#include "Champion.h"

namespace Game
{
	class EnemiesFilter
	{
		private:
			EnemiesFilter* next;
		public:
			EnemiesFilter()
			{
				next = NULL;
			}
			EnemiesFilter* Append(EnemiesFilter* filter)
			{
				if (next == NULL)
					next = filter;
				else
					next->Append(filter);
				return this;
			}
			virtual std::vector<Champion*> Filter(Champion* attackingChampion,std::vector<Champion*> enemies)
			{
				if (next != NULL)
					return next->Filter(attackingChampion, enemies);
				else
					return enemies;
			}
	};

#define ABS(x) ((x)>=0 ? (x) : -(x))

	class DistanceEnemiesFilter : EnemiesFilter
	{
		public:
			virtual std::vector<Champion*> Filter(Champion* attackingChampion, std::vector<Champion*> enemies)
			{
				std::vector<Champion*> filtered = std::vector<Champion*>();
				for (int i = 0; i < enemies.size(); ++i)
				if (ABS(attackingChampion->GetParameter(ChampionParameters::DistanceFromCastle)-enemies[i]->GetParameter(ChampionParameters::DistanceFromCastle))<=attackingChampion->GetParameter(ChampionParameters::Range))
					filtered.push_back(enemies[i]);
				return EnemiesFilter::Filter(attackingChampion, filtered);
			}
	};

	class ClosestOneEnemiesFilter:EnemiesFilter
	{
		public:
			virtual std::vector<Champion*> Filter(Champion* attackingChampion, std::vector<Champion*> enemies)
			{
				Champion* closest = NULL;
				for (int i = 0; i < enemies.size(); ++i)
					if (closest==NULL || ABS(attackingChampion->GetParameter(ChampionParameters::DistanceFromCastle) - enemies[i]->GetParameter(ChampionParameters::DistanceFromCastle)) <= ABS(attackingChampion->GetParameter(ChampionParameters::DistanceFromCastle) - closest->GetParameter(ChampionParameters::DistanceFromCastle)))
						closest = enemies[i];
				std::vector<Champion*> filtered = std::vector<Champion*>();
				filtered.push_back(closest);
				return EnemiesFilter::Filter(attackingChampion, filtered);
			}
	};

#undef ABS(x)

	class LaneEnemiesFilter : EnemiesFilter
	{
		public:
			virtual std::vector<Champion*> Filter(Champion* attackingChampion, std::vector<Champion*> enemies)
			{
				std::vector<Champion*> filtered = std::vector<Champion*>();
				for (int i = 0; i < enemies.size(); ++i)
				if (attackingChampion->GetParameter(ChampionParameters::Lane) == enemies[i]->GetParameter(ChampionParameters::Lane))
					filtered.push_back(enemies[i]);
				return EnemiesFilter::Filter(attackingChampion, filtered);
			}
	};
}

#endif