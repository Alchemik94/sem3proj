#ifndef _TIMER_DECLARATION
#define _TIMER_DECLARATION

#include <time.h>
#include <thread>

namespace Application
{
	class Timer
	{
		private:
			int _gap;
			volatile int _current;
			volatile bool _running;
			std::thread* _functionRunner;
			typedef void(*Function)();
			Function _internalFunction;
			//Calls _internalFunction in a specified period of time. Ran only on _functionRunner thread.
			void Caller();
		public:
			//Standard constructor. Defines the time timer runs the function passed as second argument.
			Timer(int msec, Function function);
			//Starts timer to perform its work.
			void Run();
			//Stops timer.
			void Stop();
			//Resets timer current period.
			void Reset();
			~Timer();
	};
}

#endif