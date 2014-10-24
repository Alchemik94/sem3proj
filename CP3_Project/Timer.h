#ifndef _TIMER_DECLARATION
#define _TIMER_DECLARATION

#include <time.h>
#include <thread>
#include "ITimerParam.h"

namespace Application
{
	//template <class Function>
	class Timer
	{
		private:
			int _gap;
			volatile bool _running;
			std::thread* _functionRunner;
			typedef void(*Function)(ITimerParameter*);
			Function _internalFunction;
			ITimerParameter* _parameter;
			//Calls _internalFunction in a specified period of time. Ran only on _functionRunner thread.
			static void Caller(Timer* timer);
		public:
			//Standard constructor. Defines the time timer runs in miliseconds before using the function passed as second argument.
			Timer/*<Function>*/(int msec, Function function, ITimerParameter* parameter);
			//Starts timer to perform its work.
			void Run();
			//Stops timer.
			void Stop();
			virtual ~Timer/*<Function>*/();
	};
}

#endif