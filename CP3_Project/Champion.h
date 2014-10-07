#ifndef _CHAMPION_INTERFACE
#define _CHAMPION_INTERFACE

#include <vector>

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
		public:
			Champion();
			virtual void ChangeStatistics(ChampionParameters param, TypeOfChange type, int change);
			virtual int GetParameter(ChampionParameters param);
			virtual void Attack(std::vector<Champion*> enemies)=NULL;
	};
}

#endif