#ifndef _GAMEHOLDER_DEFINITION
#define _GAMEHOLDER_DEFINITION

#include "GameHolder.h"

namespace Game
{
	GameHolder::GameHolder()
	{
		_team1 = new Team();
		_team2 = new AutogeneratingTeam(5, ReadyPreset::AIKnight);
		_roundsNumber = 1;
		_currentRound = 0;
		_keyCatcher = this;
	}

	GameHolder::GameHolder(int numberOfRounds)
	{
		_team1 = new Team();
		_team2 = new AutogeneratingTeam(5, ReadyPreset::AIKnight);
		_roundsNumber = numberOfRounds;
		_currentRound = 0;
		_keyCatcher = this;
	}

	GameHolder::~GameHolder()
	{
		if (_team1 != NULL)
			delete _team1;
		if (_team2 != NULL)
			delete _team2;
	}

	//TODO
	//Needs changes for various types of enemies
	//Makes game to proceed to the next round
	void GameHolder::NewRound(int numberOfEnemies)
	{
		if (_currentRound++ >= _roundsNumber) return; //throw an error
		while (_team2->size() > 0) std::this_thread::yield();
		delete _team2;
		IGameDisplayer::NewRound();
		_team2 = new AutogeneratingTeam(numberOfEnemies,AIKnight);
	}

	int GameHolder::CurrentRound()
	{
		return _currentRound;
	}

	int GameHolder::RoundsNumber()
	{
		return _roundsNumber;
	}
}

#endif