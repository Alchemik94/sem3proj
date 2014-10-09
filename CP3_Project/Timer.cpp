#ifndef _TIMER_DEFINITION
#define _TIMER_DEFINITION

#include "Timer.h"
#include <Windows.h>

namespace Application
{
	Timer::Timer(int msec, Function function)
	{
		_gap = msec;
		_internalFunction = function;
		_running = false;
	}

	void Timer::Caller(Timer* timer)
	{
		while (timer->_running)
		{
			Sleep(timer->_gap);
			timer->_internalFunction();
		}
	}

	void Timer::Run()
	{
		//avoids to loose the handle to thread and memory leakage
		if (_running) return;

		_running = true;
		_functionRunner = new std::thread(Caller,this);
	}

	void Timer::Stop()
	{
		//avoids access violations
		if (_running == false) return;
		
		_running = false;
		_functionRunner->join();
		delete _functionRunner;
	}

	Timer::~Timer()
	{
		Stop();
	}
}

#endif