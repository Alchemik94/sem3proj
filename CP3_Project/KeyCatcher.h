#pragma once

#include "KeyboardKeysEnum.h"

namespace Application
{
	class KeyCatcher
	{
		private:
			KeyCatcher* _next;
		protected:
			virtual void CatchedKeyHandler(Keys key) = 0;
		public:
			KeyCatcher();
			void Catched(Keys key);
			KeyCatcher* ReturnControl();
			void GiveControl(KeyCatcher* catcher);
	};
}