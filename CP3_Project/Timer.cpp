#ifndef _TIMER_DEFINITION
#define _TIMER_DEFINITION

#include "Timer.h"
#include <Windows.h>

namespace Application
{
	//template <class Function>
	Timer/*<Function>*/::Timer/*<Function>*/(int msec, Function function, ITimerParameter* parameter)
	{
		_gap = msec;
		_internalFunction = function;
		_parameter = parameter;
		_running = false;
	}

	//template <class Function>
	void Timer/*<Function>*/::Caller(Timer/*<Function>*/* timer)
	{
		while (timer->_running)
		{
			Sleep(timer->_gap);
			timer->_internalFunction(timer->_parameter);
		}
	}

	//template <class Function>
	void Timer/*<Function>*/::Run()
	{
		//avoids to loose the handle to thread and memory leakage
		if (_running) return;

		_running = true;
		_functionRunner = new std::thread(Caller,this);
	}

	//template <class Function>
	void Timer/*<Function>*/::Stop()
	{
		//avoids access violations
		if (_running == false) return;
		
		_running = false;
		_functionRunner->join();
		delete _functionRunner;
	}

	//template <class Function>
	Timer/*<Function>*/::~Timer/*<Function>*/()
	{
		Stop();
	}
}

#endif