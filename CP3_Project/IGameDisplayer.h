#pragma once

namespace Display
{
	class IGameDisplayer
	{
		public:
			IGameDisplayer(){}
			IGameDisplayer(int numberOfRounds){}
			virtual void ShowGame(){}
			virtual void HideGame(){}
			virtual int RoundsNumber() = 0;
			virtual int CurrentRound() = 0;
			virtual void NewRound(){}
	};
}