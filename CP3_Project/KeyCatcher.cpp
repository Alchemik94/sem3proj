#include "KeyCatcher.h"

namespace Application
{
	KeyCatcher::KeyCatcher()
	{
		_next = nullptr;
	}

	KeyCatcher* KeyCatcher::ReturnControl()
	{
		if (_next == nullptr)
			return nullptr;
		_next = _next->ReturnControl();
		return this;
	}

	void KeyCatcher::Catched(Keys key)
	{
		if (_next != nullptr)
			_next->Catched(key);
		else
			CatchedKeyHandler(key);
	}
	
	void KeyCatcher::GiveControl(KeyCatcher* catcher)
	{
		if (_next == nullptr)
			_next = catcher;
		else
			_next->GiveControl(catcher);
	}
}