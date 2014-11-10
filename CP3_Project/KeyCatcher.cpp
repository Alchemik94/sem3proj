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

	void KeyCatcher::Catched(int primaryCode, int secondaryCode = -1)
	{
		if (_next != nullptr)
			_next->Catched(primaryCode, secondaryCode);
		else
			CatchedKeyHandler(primaryCode, secondaryCode);
	}
	
	void KeyCatcher::GiveControl(KeyCatcher* catcher)
	{
		if (_next == nullptr)
			_next = catcher;
		else
			_next->GiveControl(catcher);
	}
}