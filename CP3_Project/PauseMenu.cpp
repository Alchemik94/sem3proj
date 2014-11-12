#include "PauseMenu.h"
#include "SingleDataKeeper.h"
#include "GameHolder.h"

namespace Game
{
//TODO
//error throwing
	PauseMenu::PauseMenu(Display::IGameDisplayer* gameholder)
	{
		_activeOption = GetOptions().begin();
		if (dynamic_cast<GameHolder*>(gameholder) == NULL)
		{
//throw an error
		}
		_gameholder = gameholder;
		Show();
	}

	inline PauseMenu::~PauseMenu()
	{
		Hide();
	}

	void PauseMenu::CatchedKeyHandler(Application::Keys key)
	{
		if (key == Application::Keys::Up)
		{
			--_activeOption;
			OptionChanged();
		}
		else if (key == Application::Keys::Down)
		{
			++_activeOption;
			OptionChanged();
		}
		else if (key == Application::Keys::Enter)
		{
			if (*_activeOption == Continue || *_activeOption == NewGame)
			{
				ReturnControl();
				dynamic_cast<GameHolder*>(_gameholder)->EnteredGame();
			}
		}
		else if (key == Application::Keys::Escape)
		{
			ReturnControl();
			dynamic_cast<GameHolder*>(_gameholder)->Exit();
		}
		else
		{
			//nothing to do here
		}
	}

	std::string PauseMenu::GetActiveOption()
	{
		return Application::SingleDataKeeper::Instance()->GetString("PauseMenuOption"+MenuOptionName(*_activeOption));
	}

	std::vector<MenuOption> PauseMenu::GetOptions()
	{
		static std::vector<MenuOption> result{
										MenuOption::Continue,
										MenuOption::NewGame,
										//MenuOption::Options,
										//MenuOption::Credits,
										MenuOption::NewGame,
										};
		return result;
	}

//TODO
//error throwing
	std::string PauseMenu::MenuOptionName(MenuOption option)
	{
		switch (option)
		{
		case Continue:
			return "Continue";
		case NewGame:
			return "NewGame";
		case Options:
			return "Options";
		case Credits:
			return "Credits";
		case Exit:
			return "Exit";
		default:
			//throw an error
			break;
		}
	}
}