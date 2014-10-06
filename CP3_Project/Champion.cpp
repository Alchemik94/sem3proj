#ifndef _CHAMPION_INTERFACE_DEFINITION
#define _CHAMPION_INTERFACE_DEFINITION

#include "Champion.h"

#define ABS(x) ((x)>=0 ? (x) : -(x))

namespace Game
{
	Champion::Champion()
	{
		_attackSpeed = 0;
		_basicDamage = 0;
		_currentHealth = 0;
		_currentPower = 0;
		_experience = 0;
		_level = 0;
		_maximumHealth = 0;
		_maximumPower = 0;
		_movementSpeed = 0;
		_range = 0;
	}

	int Champion::Modification(TypeOfChange type, int change)
	{
		change = ABS(change);
		switch (type)
		{
			case TypeOfChange::Gain:
				return change;
				break;
			case TypeOfChange::Loose:
				return -change;
				break;
			default:
				//error throwing
				break;
		}
	}

	int& Champion::GetChangingParameter(ChampionParameters param)
	{
		switch (param)
		{
			case ChampionParameters::AttackSpeed:
				return _attackSpeed;
				break;
			case ChampionParameters::BasicDamage:
				return _basicDamage;
				break;
			case ChampionParameters::CurrentHealth:
				return _currentHealth;
				break;
			case ChampionParameters::CurrentPower:
				return _currentPower;
				break;
			case ChampionParameters::Experience:
				return _experience;
				break;
			case ChampionParameters::Level:
				return _level;
				break;
			case ChampionParameters::MaximumHealth:
				return _maximumHealth;
				break;
			case ChampionParameters::MaximumPower:
				return _maximumPower;
				break;
			case ChampionParameters::MovementSpeed:
				return _movementSpeed;
				break;
			case ChampionParameters::Range:
				return _range;
				break;
			default:
				//error throwing
				break;
		}
	}

	int Champion::GetParameter(ChampionParameters param)
	{
		return GetChangingParameter(param);
	}

	void Champion::ChangeStatistics(ChampionParameters param, TypeOfChange type, int change)
	{
		int& parameter = GetChangingParameter(param);
		parameter += Modification(type, change);
	}
}

#undef ABS(x)

#endif