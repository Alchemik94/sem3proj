#ifndef _CHAMPION_INTERFACE
#define _CHAMPION_INTERFACE

#include <vector>
#include "Filter.h"
#include "ActionQueue.h"
#include "Timer.h"
#include "ITimerParam.h"

namespace Game
{
	enum ChampionParameters
	{
		CurrentHealth,
		MaximumHealth,
		CurrentPower,
		MaximumPower,
		Range,
		MovementSpeed,
		BasicDamage,
		AttackSpeed,
		Level,
		Experience,
		Lane,
		DistanceFromCastle,
	};

	enum TypeOfChange
	{
		Gain,
		Loose,
	};

	enum Direction
	{
		Up,
		Down,
		Left,
		Right,
		None,
	};

	enum Action
	{
		Attack,
		Move,
	};

	enum ReadyPreset
	{
		//any preset declared here have to be added as an entry in SingleDataKeeper constructor
		PlayerKnight,
		AIKnight,
	};

	class Champion: Application::ITimerParameter
	{
		private:
			int _currentHealth,
				_maximumHealth,
				_currentPower,
				_maximumPower,
				_range,
				_movementSpeed,
				_basicDamage,
				_attackSpeed,
				_level,
				_experience,
				_lane,
				_distanceFromCastle;
			bool _displayed;
			int& GetChangingParameter(ChampionParameters param);
			int Modification(TypeOfChange type, int change);
			void DisplayChange(ChampionParameters param, TypeOfChange type, int change);
			Champion();
			//potentially dangerous to be anywhere else
			void ChangeStatistics(ChampionParameters param, TypeOfChange type, int change);
			ActionQueue<Action,Direction> _actionQueue;
			static void MoveHandler(ITimerParameter* champion);
			volatile bool _afterAttack;
			static void AttackCounterResetter(ITimerParameter* champion);
			Application::Timer _attackTimer;
			Application::Timer _moveHandlerTimer;
			static std::pair<ChampionParameters, TypeOfChange> DirectionToParams(Direction direction);
		protected:
			//abstract ones, which will be defined for every derived class
			virtual Application::Filter* CreateFilter() = NULL;
			virtual void DisplayAttack(std::vector<Champion*> filteredEnemies) = NULL;
			virtual void DisplayDeath() = NULL;
			virtual void DisplayMove(Direction direction, int change) = NULL;
			
			//common, the same for every class (for now)
			virtual void DisplayBeingAttacked();
			virtual void DisplayCurrentHealthChange(TypeOfChange type, int change);
			virtual void DisplayMaximumHealthChange(TypeOfChange type, int change);
			//no sense to make it virtual - used only in constructor
			void DisplayOnMap();
		public:
			Champion(ReadyPreset preset);
			~Champion();
			virtual void Attack(std::vector<Champion*> enemies);
			virtual void Move(Direction direction);
			bool IsAlive();
			virtual int GetParameter(ChampionParameters param);
	};
}

#endif