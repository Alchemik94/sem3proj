#ifndef _SINGLE_DATA_KEEPER_INITIALIZER
#define _SINGLE_DATA_KEEPER_INITIALIZER

#include "SingleDataKeeper.h"

using namespace std;

namespace Application
{
	bool SingleDataKeeper::_initialized;
	SingleDataKeeper* SingleDataKeeper::_instance;

	SingleDataKeeper* SingleDataKeeper::Instance()
	{
		if (!_initialized)
		{
			_initialized = true;
			_instance = new SingleDataKeeper();
		}
		return _instance;
	}

	SingleDataKeeper::SingleDataKeeper()
	{

	}

	bool SingleDataKeeper::Contains(string name)
	{
		return _dictionary.count(name)>0;
	}

	void SingleDataKeeper::Keep(string name, string value)
	{
		if (Contains(name))
			Get(name) = value;
		else
			_dictionary.emplace(name, value);
	}

	string& SingleDataKeeper::Get(string name)
	{
		return _dictionary[name];
	}
}

#endif