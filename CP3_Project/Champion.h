#ifndef _CHAMPION_INTERFACE
#define _CHAMPION_INTERFACE

#include <vector>
#include "Filter.h"

namespace Game
{
	enum ChampionParameters
	{
		CurrentHealth,
		MaximumHealth,
		CurrentPower,
		MaximumPower,
		Range,
		MovementSpeed,
		BasicDamage,
		AttackSpeed,
		Level,
		Experience,
		Lane,
		DistanceFromCastle,
	};

	enum TypeOfChange
	{
		Gain,
		Loose,
		Up,
		Down,
	};

	class Champion
	{
		private:
			int _currentHealth,
				_maximumHealth,
				_currentPower,
				_maximumPower,
				_range,
				_movementSpeed,
				_basicDamage,
				_attackSpeed,
				_level,
				_experience,
				_lane,
				_distanceFromCastle;
			int& GetChangingParameter(ChampionParameters param);
			int Modification(TypeOfChange type, int change);
			void DisplayChange(ChampionParameters param, TypeOfChange type, int change);
		protected:
			virtual Application::Filter* CreateFilter() = NULL;
			virtual void DisplayAttack(std::vector<Champion*> filteredEnemies) = NULL;
			virtual void DisplayBeingAttacked();
			virtual void DisplayDeath() = NULL;
		public:
			Champion();
			virtual void ChangeStatistics(ChampionParameters param, TypeOfChange type, int change);
			virtual int GetParameter(ChampionParameters param);
			virtual void Attack(std::vector<Champion*> enemies);
	};
}

#endif