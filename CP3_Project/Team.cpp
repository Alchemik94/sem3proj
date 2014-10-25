#ifndef _TEAM_DEFINITION
#define _TEAM_DEFINITION

#include "Team.h"
#include "EnemiesFilter.h"
#include "GameEnums.h"
#include <vector>
#include "ChampionFactory.h"
#include "SingleDataKeeper.h"
#include "Application.h"

namespace Game
{
	void Team::EraseDead(ITimerParameter* param)
	{
		LOCK_APPLICATION_VARIABLES;
		Team* team = static_cast<Team*>(param);
		team->_erasing = true;
		if (team->size() > 0)
		{
			EnemiesFilter* filter = new AliveEnemiesFilter();
			std::vector<Champion*> newTeam;
			newTeam = filter->Filter(NULL, (*team));
			
			for (unsigned int i = 0, j = 0; i < team->size() && j < newTeam.size(); ++i)
			{
				if ((*team)[i] == newTeam[j])
					++j;
				else
					delete (*team)[i];
			}

			*team = newTeam;
		}
		team->_erasing = false;
		UNLOCK_APPLICATION_VARIABLES;
	}

	Team::Team() :_timer(Application::SingleDataKeeper::Instance()->GetInt("deadChampionsEraserDelay"), EraseDead, this)
	{
		_timer.Run();
	}

	Team::Team(std::vector<Champion*> team) : std::vector<Champion*>(team), _timer(Application::SingleDataKeeper::Instance()->GetInt("deadChampionsEraserDelay"), EraseDead, this)
	{
		_timer.Run();
	}

	Team::~Team()
	{
		_timer.Stop();
		if (!_erasing)
			for (int i = 0; i < this->size(); ++i)
				delete (*this)[i];
	}

//TODO - for example choosing random presets from the list of them
	AutogeneratingTeam::AutogeneratingTeam(int size, ReadyPreset preset) : Team()
	{
		for (int i = 0; i < size; ++i)
			this->push_back(ChampionFactory::CreateChampion(preset));
	}
}

#endif