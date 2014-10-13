#ifndef _MAIN_APPLICATION
#define _MAIN_APPLICATION

#include "SingleDataKeeper.h"
#include <atomic>

#define LOCK_APPLICATION_VARIABLES while (Application::MainApplication::Lock.test_and_set())
#define UNLOCK_APPLICATION_VARIABLES Application::MainApplication::Lock.clear()

namespace Application
{
	class MainApplication
	{
		public:
			//Creates application instance
			MainApplication();
			//Runs standard application actions
			int Run();
			//Tests current module
			void Test();
			//Multithreading lock
			static std::atomic_flag Lock;
	};
}
#endif