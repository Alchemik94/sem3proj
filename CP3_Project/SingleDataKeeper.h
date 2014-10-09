#ifndef _SINGLE_DATA_KEEPER
#define _SINGLE_DATA_KEEPER

#include <unordered_map>
#include <string>
#include "Champion.h"

namespace Application
{
	class SingleDataKeeper
	{
		private:
			//singleton structure
			SingleDataKeeper()
			{
				KeepInt("distanceBetweenLanes", 20);
				//To change
				SavePreset(Game::ReadyPreset::AIKnight, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				SavePreset(Game::ReadyPreset::PlayerKnight, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			~SingleDataKeeper();
			static SingleDataKeeper* _instance;
			static bool _initialized;
			//dictionary
			std::unordered_map<std::string,std::string> _stringDictionary;
			std::unordered_map<std::string, int> _intDictionary;
			void InitializeComponent();
		public:
			//Gives access to single instance in whole program
			static SingleDataKeeper* Instance();
			//Keeps string value under specified name
			void KeepString(std::string name, std::string value);
			//Keeps int value under specified name
			void KeepInt(std::string name, int value);
			//Gets string value from specified name
			std::string GetString(std::string name);
			//Gets int value from specified name
			int GetInt(std::string name);
			//Checks if specified name of string exists
			bool ContainsString(std::string name);
			//Checks if specified name of int exists
			bool ContainsInt(std::string name);

			//Facade for saving presets
			void SavePreset(
				Game::ReadyPreset preset,
				int attackSpeed,
				int basicDamage,
				int currentHealth,
				int currentPower,
				int distanceFromCastle,
				int experience,
				int lane,
				int level,
				int maximumHealth,
				int maximumPower,
				int movementSpeed,
				int range
				);
			//Facade for loading presents
			void LoadPreset(
				Game::ReadyPreset preset,
				int& attackSpeed,
				int& basicDamage,
				int& currentHealth,
				int& currentPower,
				int& distanceFromCastle,
				int& experience,
				int& lane,
				int& level,
				int& maximumHealth,
				int& maximumPower,
				int& movementSpeed,
				int& range
				);
	};
}

#endif