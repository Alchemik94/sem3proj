#ifndef _ENEMIES_FILTER_DECLARATION
#define _ENEMIES_FILTER_DECLARATION

#include "Champion.h"
#include "Filter.h"

namespace Game
{
	class EnemiesFilter: public Application::Filter
	{
		private:
			EnemiesFilter* next;
		public:
			EnemiesFilter();
			//Adds next filter to the chain
			EnemiesFilter* Append(EnemiesFilter* filter);
			//Filters enemies with respect to current filter type
			virtual std::vector<Champion*> Filter(Champion* attackingChampion, std::vector<Champion*> enemies);
	};

	class DistanceEnemiesFilter : public EnemiesFilter
	{
		protected:
			virtual int Distance(Champion* first, Champion* second);
		public:
			virtual std::vector<Champion*> Filter(Champion* attackingChampion, std::vector<Champion*> enemies);
	};

	class ClosestOneEnemiesFilter : public DistanceEnemiesFilter
	{
		public:
			virtual std::vector<Champion*> Filter(Champion* attackingChampion, std::vector<Champion*> enemies);
	};

	class LaneEnemiesFilter : public EnemiesFilter
	{
		public:
			virtual std::vector<Champion*> Filter(Champion* attackingChampion, std::vector<Champion*> enemies);
	};
}

#endif