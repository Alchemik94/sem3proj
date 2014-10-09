#ifndef _APPLICATION_INITIALIZER
#define _APPLICATION_INITIALIZER

#include <atomic>
#include "Application.h"

#ifdef _DEBUG
	#include <vector>
	#include <iostream>
	#include <conio.h>
	#include "Knight.h"
	#include "Champion.h"
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

	}
}

#endif