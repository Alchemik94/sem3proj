#ifndef _SINGLE_DATA_KEEPER
#define _SINGLE_DATA_KEEPER

#include <unordered_map>
#include <string>

namespace Application
{
	class SingleDataKeeper
	{
		private:
			//singleton structure
			SingleDataKeeper();
			static SingleDataKeeper* _instance;
			static bool _initialized;
			//dictionary
			std::unordered_map<std::string,std::string> _dictionary;
		public:
			//Gives access to single instance in whole program
			static SingleDataKeeper* Instance();
			//Keeps value under specified name
			void Keep(std::string name, std::string value);
			//Gets value from specified name
			std::string& Get(std::string name);
			//Checks if specified name exists
			bool Contains(std::string name);
	};
}

#endif