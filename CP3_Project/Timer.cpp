#ifndef _TIMER_DEFINITION
#define _TIMER_DEFINITION

#include "Timer.h"

namespace Application
{
	Timer::Timer(int msec, Function function)
	{
		_gap = msec;
		_internalFunction = function;
	}

	void Timer::Caller()
	{
		//TODO
	}

	void Timer::Run()
	{
		//TODO
	}

	void Timer::Stop()
	{
		//TODO
	}

	void Timer::Reset()
	{
		//TODO
	}

	Timer::~Timer()
	{
		Stop();
	}
}

#endif