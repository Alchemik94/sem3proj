#ifndef _CHAMPION_INTERFACE_DEFINITION
#define _CHAMPION_INTERFACE_DEFINITION

#include "Champion.h"
#include "EnemiesFilter.h"

namespace Game
{
	Champion::Champion()
	{
		_attackSpeed = 0;
		_basicDamage = 0;
		_currentHealth = 0;
		_currentPower = 0;
		_distanceFromCastle = 0;
		_experience = 0;
		_lane = 0;
		_level = 0;
		_maximumHealth = 0;
		_maximumPower = 0;
		_movementSpeed = 0;
		_range = 0;
	}

	int Champion::Modification(TypeOfChange type, int change)
	{
		switch (type)
		{
			case TypeOfChange::Gain:
			case TypeOfChange::Up:
				return change;
				break;
			case TypeOfChange::Loose:
			case TypeOfChange::Down:
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
			case ChampionParameters::DistanceFromCastle:
				return _distanceFromCastle;
				break;
			case ChampionParameters::Experience:
				return _experience;
				break;
			case ChampionParameters::Lane:
				return _lane;
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
		DisplayChange(param,type,change);
	}

	void Champion::DisplayChange(ChampionParameters param, TypeOfChange type, int change)
	{
		switch (param)
		{
			case ChampionParameters::CurrentHealth:
				break;
			case ChampionParameters::CurrentPower:
				break;
			case ChampionParameters::DistanceFromCastle:
				break;
			case ChampionParameters::Experience:
				break;
			case ChampionParameters::Lane:
				break;
			case ChampionParameters::Level:
				break;
			case ChampionParameters::MaximumHealth:
				break;
			case ChampionParameters::MaximumPower:
				break;
			case ChampionParameters::AttackSpeed:
			case ChampionParameters::BasicDamage:
			case ChampionParameters::MovementSpeed:
			case ChampionParameters::Range:
			default:
				//not necessarily displayed
				break;
		}
	}

	void Champion::DisplayBeingAttacked()
	{
		//to implement
	}

	void Champion::Attack(std::vector<Champion*> enemies)
	{
		EnemiesFilter* filter = static_cast<EnemiesFilter*>(CreateFilter());

		std::vector<Champion*> filteredEnemies = filter->Filter(this, enemies);

		DisplayAttack(filteredEnemies);

		for (int i = 0; i < filteredEnemies.size(); ++i)
		{
			filteredEnemies[i]->DisplayBeingAttacked();
			filteredEnemies[i]->ChangeStatistics(CurrentHealth, Loose, GetParameter(BasicDamage));
		}
	}
}

#endif