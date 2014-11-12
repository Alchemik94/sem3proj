#ifndef _GAMEHOLDER_DEFINITION
#define _GAMEHOLDER_DEFINITION

#include "GameHolder.h"
#include "Application.h"
#include "Timer.h"

namespace Game
{
//TODO
//Get rid of hardcode
	GameHolder::GameHolder()
	{
		_team1 = new Team();
		_team2 = new AutogeneratingTeam(5, ReadyPreset::AIKnight);
		_roundsNumber = 1;
		_currentRound = 0;
		_keyCatcher = this;
		_paused = true;
		_menu = new PauseMenu(this);
		_running = true;
		_runner = new std::thread(RoundsRunner, this);
	}

//TODO
//Get rid of hardcode
	GameHolder::GameHolder(int numberOfRounds)
	{
		_team1 = new Team();
		_team2 = new AutogeneratingTeam(5, ReadyPreset::AIKnight);
		_roundsNumber = numberOfRounds;
		_currentRound = 0;
		_keyCatcher = this;
		_paused = true;
		_menu = new PauseMenu(this);
		_running = true;
		_runner = new std::thread(RoundsRunner, this);
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
		LOCK_APPLICATION_VARIABLES(Application::EmptyTimer::Instance());
//TODO
//error throwing
		if (_currentRound++ >= _roundsNumber)
		{
			UNLOCK_APPLICATION_VARIABLES;
			return; //throw an error
		}
		UNLOCK_APPLICATION_VARIABLES;
		while (_team2->size() > 0 && _running) std::this_thread::yield();
		if (_running)
		{
			LOCK_APPLICATION_VARIABLES(Application::EmptyTimer::Instance());
			delete _team2;
			IGameDisplayer::NewRound();
			_team2 = new AutogeneratingTeam(numberOfEnemies, AIKnight);
			UNLOCK_APPLICATION_VARIABLES;
		}
		else
		{
			//do nothing, just exit
		}
	}

	inline int GameHolder::CurrentRound()
	{
		return _currentRound;
	}

	inline int GameHolder::RoundsNumber()
	{
		return _roundsNumber;
	}

	void GameHolder::EnteredGame()
	{
		_menu->Hide();
		GiveControl(GetPlayerController());
		Unpause();
	}

	void GameHolder::PausedGame()
	{
		Pause();
		_menu->Show();
		GiveControl(_menu);
	}

	void GameHolder::Exit()
	{
		Pause();
		_menu->Hide();
		_running = false;
		_currentRound = _roundsNumber;
		_runner->join();
		delete _team1;
		delete _team2;
		delete _menu;
	}

	inline void GameHolder::Pause()
	{
		_paused = true;
	}

	inline void GameHolder::Unpause()
	{
		_paused = false;
	}

	inline bool GameHolder::Running()
	{
		return _running;
	}

	void GameHolder::RoundsRunner(GameHolder* holder)
	{
		while (holder->_running && holder->_currentRound < holder->_roundsNumber)
			holder->NewRound(5);
	}
}

#endif