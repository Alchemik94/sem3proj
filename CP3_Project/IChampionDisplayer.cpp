#ifndef _ICHAMPIONDISPLAYER_DEFINITION
#define _ICHAMPIONDISPLAYER_DEFINITION

#include "IChampionDisplayer.h"
#include "GameEnums.h"

namespace Display
{
	template <class ChampionType>
	void IChampionDisplayer<ChampionType>::DisplayBeingAttacked()
	{
		//TODO
	}

	template <class ChampionType>
	void IChampionDisplayer<ChampionType>::DisplayCurrentHealthChange(Game::TypeOfChange type, int change)
	{
		//TODO
	}

	template <class ChampionType>
	void IChampionDisplayer<ChampionType>::DisplayMaximumHealthChange(Game::TypeOfChange type, int change)
	{
		//TODO - maybe as DisplayCurrentHealthChange if whole health bar will possibly be updated?
	}

	template <class ChampionType>
	void IChampionDisplayer<ChampionType>::DisplayOnMap()
	{
		//TODO
	}
}

#endif