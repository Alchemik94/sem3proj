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
		
	}
}

#endif