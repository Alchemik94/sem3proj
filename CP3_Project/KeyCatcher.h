#pragma once

namespace Application
{
	class KeyCatcher
	{
		private:
			KeyCatcher* _next;
		protected:
			virtual void CatchedKeyHandler(int primaryCode, int secondaryCode) = 0;
		public:
			KeyCatcher();
			void Catched(int primaryCode, int secondaryCode = -1);
			KeyCatcher* ReturnControl();
			void GiveControl(KeyCatcher* catcher);
	};
}