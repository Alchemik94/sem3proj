#ifndef _CHAMPION_INTERFACE_DEFINITION
#define _CHAMPION_INTERFACE_DEFINITION

#include "Champion.h"
#include "EnemiesFilter.h"

namespace Game
{
	Champion::Champion()
	{
		_displayed = false;
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
		if (_displayed)
			DisplayChange(param,type,change);
	}

	void Champion::DisplayChange(ChampionParameters param, TypeOfChange type, int change)
	{
		switch (param)
		{
			case ChampionParameters::CurrentHealth:
				DisplayCurrentHealthChange(type,change);
				if (IsAlive() == false)
					DisplayDeath();
				break;
			case ChampionParameters::DistanceFromCastle:
				Direction direction = type == TypeOfChange::Gain ? Direction::Right : Direction::Left;
				DisplayMove(direction,change);
				break;
			case ChampionParameters::Lane:
				Direction direction = type == TypeOfChange::Up ? Direction::Up : Direction::Down;
				DisplayMove(direction, change);
				break;
			case ChampionParameters::MaximumHealth:
				DisplayMaximumHealthChange(type,change);
				break;
			//may be implemented in further versions
			case ChampionParameters::CurrentPower:
				break;
			case ChampionParameters::Experience:
				break;
			case ChampionParameters::Level:
				break;
			case ChampionParameters::MaximumPower:
				break;
			//not necessarily displayed
			case ChampionParameters::AttackSpeed:
			case ChampionParameters::BasicDamage:
			case ChampionParameters::MovementSpeed:
			case ChampionParameters::Range:
			default:
				break;
		}
	}

	void Champion::Attack(std::vector<Champion*> enemies)
	{
		EnemiesFilter* filter = static_cast<EnemiesFilter*>(CreateFilter());

		std::vector<Champion*> filteredEnemies = filter->Filter(this, enemies);

		if (filteredEnemies.size>0)
			DisplayAttack(filteredEnemies);

		for (int i = 0; i < filteredEnemies.size(); ++i)
		{
			filteredEnemies[i]->DisplayBeingAttacked();
			filteredEnemies[i]->ChangeStatistics(CurrentHealth, Loose, GetParameter(BasicDamage));
		}
	}

	bool Champion::IsAlive()
	{
		return _currentHealth>0;
	}

	void Champion::DisplayBeingAttacked()
	{
		//to implement
	}

	void Champion::DisplayCurrentHealthChange(TypeOfChange type, int change)
	{
		//TODO
	}

	void Champion::DisplayMaximumHealthChange(TypeOfChange type, int change)
	{
		//TODO
	}

	void Champion::DisplayOnMap()
	{
		//TODO

		//must be here
		_displayed = true;
	}

	//TODO by GM
	void Champion::Move(Direction direction)
	{
		//TODO
	}
}

#endif