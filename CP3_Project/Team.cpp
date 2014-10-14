#ifndef _TEAM_DEFINITION
#define _TEAM_DEFINITION

#include "Team.h"
#include "EnemiesFilter.h"
#include "GameEnums.h"
#include <vector>
#include "ChampionFactory.h"
#include "SingleDataKeeper.h"

namespace Game
{
	void Team::EraseDead(ITimerParameter* param)
	{
		Team* team = static_cast<Team*>(param);
		if (team->size() > 0)
		{
			EnemiesFilter* filter = new AliveEnemiesFilter();
			Team newTeam;
			static_cast<std::vector<Champion*> >(newTeam) = filter->Filter(NULL, (*team));
			
			for (int i = 0, j = 0; i < team->size() && j < newTeam.size(); ++i)
			{
				if ((*team)[i] == newTeam[j])
					++j;
				else
					delete (*team)[i];
			}

			*team = newTeam;
		}
	}

	Team::Team() :_timer(Application::SingleDataKeeper::Instance()->GetInt("deadChampionsEraserDelay"), EraseDead, this)
	{
		_timer.Run();
	}

	Team::~Team()
	{
		_timer.Stop();
	}

//TODO - for example choosing random presets from the list of them
	AutogeneratingTeam::AutogeneratingTeam(int size, ReadyPreset preset) : Team()
	{
		for (int i = 0; i < size; ++i)
			this->push_back(ChampionFactory::CreateChampion(preset));
	}
}

#endif