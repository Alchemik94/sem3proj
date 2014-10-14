#ifndef _APPLICATION_INITIALIZER
#define _APPLICATION_INITIALIZER

#include <atomic>
#include "Application.h"

#ifdef _DEBUG
	#include "Team.h"
	#include "Knight.h"
	#include <iostream>
#endif

namespace Application
{
	std::atomic_flag MainApplication::Lock = ATOMIC_FLAG_INIT;

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
		t->push_back(new Game::Knight(Game::ReadyPreset::AIKnight));
	}
}

#endif