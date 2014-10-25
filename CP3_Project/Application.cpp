#ifndef _APPLICATION_INITIALIZER
#define _APPLICATION_INITIALIZER

#include <atomic>
#include "Application.h"

#ifdef _DEBUG
	#include "Team.h"
	#include "Knight.h"
	#include <iostream>
	#include <Windows.h>
#endif

namespace Application
{
#ifndef LOCK_VERSION_ONE
	std::atomic_flag MainApplication::Lock = ATOMIC_FLAG_INIT;
#else
	std::atomic<bool> MainApplication::Lock(false);
#endif

	MainApplication::MainApplication()
	{
		
	}

	int MainApplication::Run()
	{
		return 0;
	}

	void MainApplication::Test()
	{
		Game::Team* at = new Game::AutogeneratingTeam(3, Game::ReadyPreset::AIKnight);
		Game::Team* t = new Game::Team();
		t->push_back(new Game::Knight(Game::ReadyPreset::PlayerKnight));
		for (unsigned int i = 0; i < t->size(); ++i)
			(*t)[i]->Attack(*(static_cast<std::vector<Game::Champion*>*>(at)));
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		//Sleep(100);
		delete t;
		t = NULL;
		//Sleep(100);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		delete at;
		at = NULL;
		//Sleep(100);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

#endif