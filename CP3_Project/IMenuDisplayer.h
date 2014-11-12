#pragma once

#include <string>
#include <vector>
#include "MenuOptionsEnum.h"

namespace Display
{
	class IMenuDisplayer
	{
		public:
//TODO
			virtual void Show()
			{

			}

//TODO
			virtual void Hide()
			{

			}

//TODO
			virtual void OptionChanged()
			{

			}

			virtual std::string GetActiveOption() = 0;
			virtual std::vector<Game::MenuOption> GetOptions() = 0;
	};
}