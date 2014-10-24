#ifndef _TEAM_DECLARATION
#define _TEAM_DECLARATION

#include "Champion.h"
#include <vector>
#include "GameEnums.h"
#include "Timer.h"
#include "ITimerParam.h"

namespace Game
{
	class Team: public virtual std::vector<Champion*>, public Application::ITimerParameter
	{
		private:
			Application::Timer _timer;
			static void EraseDead(ITimerParameter* parameter);
		public:
			Team();
			virtual ~Team();
	};

	class AutogeneratingTeam : public Team, public virtual std::vector<Champion*>
	{
		public:
			AutogeneratingTeam(int size, ReadyPreset preset);
	};
}

#endif