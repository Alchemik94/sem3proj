#ifndef _SINGLE_DATA_KEEPER_INITIALIZER
#define _SINGLE_DATA_KEEPER_INITIALIZER

#include "SingleDataKeeper.h"
#include "Application.h"

using namespace std;

namespace Application
{
	bool SingleDataKeeper::_initialized;
	SingleDataKeeper* SingleDataKeeper::_instance;

	SingleDataKeeper::~SingleDataKeeper()
	{
		delete _instance;
	}

	SingleDataKeeper* SingleDataKeeper::Instance()
	{
		if (!_initialized)
		{
			LOCK_APPLICATION_VARIABLES;
			if (!_initialized)
			{
				_initialized = true;
				_instance = new SingleDataKeeper();
			}
			UNLOCK_APPLICATION_VARIABLES;
		}
		return _instance;
	}

	bool SingleDataKeeper::ContainsString(string name)
	{
		return _stringDictionary.count(name)>0;
	}

	bool SingleDataKeeper::ContainsInt(string name)
	{
		return _intDictionary.count(name)>0;
	}

	void SingleDataKeeper::KeepString(string name, string value)
	{
//		LOCK_APPLICATION_VARIABLES;
		_stringDictionary.emplace(name, value);
//		UNLOCK_APPLICATION_VARIABLES;
	}

	void SingleDataKeeper::KeepInt(string name, int value)
	{
//		LOCK_APPLICATION_VARIABLES;
		_intDictionary.emplace(name, value);
//		UNLOCK_APPLICATION_VARIABLES;
	}

	string SingleDataKeeper::GetString(string name)
	{
		return _stringDictionary[name];
	}
	
	int SingleDataKeeper::GetInt(string name)
	{
		return _intDictionary[name];
	}

	void SingleDataKeeper::SavePreset(Game::ReadyPreset preset, int attackSpeed, int basicDamage, int currentHealth, int currentPower, int distanceFromCastle, int experience, int lane, int level, int maximumHealth, int maximumPower, int movementSpeed, int range)
	{
		char* tmp = new char[20];
		sprintf(tmp, "ReadyPreset%d", preset);
		std::string name = tmp;
		delete tmp;
		KeepInt(name + "AttackSpeed", attackSpeed);
		KeepInt(name + "BasicDamage", basicDamage);
		KeepInt(name + "CurrentHealth", currentHealth);
		KeepInt(name + "CurrentPower", currentPower);
		KeepInt(name + "DistanceFromCastle", distanceFromCastle);
		KeepInt(name + "Experience", experience);
		KeepInt(name + "Lane", lane);
		KeepInt(name + "Level", level);
		KeepInt(name + "MaximumHealth", maximumHealth);
		KeepInt(name + "MaximumPower", maximumPower);
		KeepInt(name + "MovementSpeed", movementSpeed);
		KeepInt(name + "Range", range);
	}

	void SingleDataKeeper::LoadPreset(Game::ReadyPreset preset, int& attackSpeed, int& basicDamage, int& currentHealth, int& currentPower, int& distanceFromCastle, int& experience, int& lane, int& level, int& maximumHealth, int& maximumPower, int& movementSpeed, int& range)
	{
		std::string name;
		char* tmp = new char[20];
		sprintf(tmp, "ReadyPreset%d", preset);
		name = tmp;
		delete tmp;
		attackSpeed = GetInt(name + "AttackSpeed");
		basicDamage = GetInt(name + "BasicDamage");
		currentHealth = GetInt(name + "CurrentHealth");
		currentPower = GetInt(name + "CurrentPower");
		distanceFromCastle = GetInt(name + "DistanceFromCastle");
		experience = GetInt(name + "Experience");
		lane = GetInt(name + "Lane");
		level = GetInt(name + "Level");
		maximumHealth = GetInt(name + "MaximumHealth");
		maximumPower = GetInt(name + "MaximumPower");
		movementSpeed = GetInt(name + "MovementSpeed");
		range = GetInt(name + "Range");
	}
}

#endif