#ifndef _SINGLE_DATA_KEEPER_INITIALIZER
#define _SINGLE_DATA_KEEPER_INITIALIZER

#include "SingleDataKeeper.h"

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
			_initialized = true;
			_instance = new SingleDataKeeper();
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
		if (ContainsString(name))
			GetString(name) = value;
		else
			_stringDictionary.emplace(name, value);
	}

	void SingleDataKeeper::KeepInt(string name, int value)
	{
		if (ContainsInt(name))
			GetInt(name) = value;
		else
			_intDictionary.emplace(name, value);
	}

	string& SingleDataKeeper::GetString(string name)
	{
		return _stringDictionary[name];
	}
	
	int& SingleDataKeeper::GetInt(string name)
	{
		return _intDictionary[name];
	}
}

#endif