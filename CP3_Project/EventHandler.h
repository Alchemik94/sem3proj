#pragma once

#include <list>

namespace Application
{
	class Object
	{

	};

	template <class T>
	class ParametrizedObject : public Object
	{
		T& _member;
		public:
		ParametrizedObject(const T& object)
		{
			_member = object;
		}
		const T& Value()
		{
			return _member;
		}
	};

	class EventArgs: public Object
	{

	};

	template <class T>
	class ParametrizedEventArgs : public EventArgs
	{
		T& _member;
		public:
			ParametrizedEventArgs(const T& eventArgs)
			{
				_member = eventArgs;
			}
			const T& Value()
			{
				return _member;
			}
	};

	class EventHandler
	{
		typedef void(*Function)(Object*, EventArgs*);
		std::list<std::pair<int,const Function&> > _functions;
		std::list<std::pair<int,const EventHandler&> > _anotherHandlers;
		public:
			//Called when such an event occurs
			void operator()(Object* sender, EventArgs* e) const
			{
				auto functionIt = _functions.begin();
				auto handlerIt = _anotherHandlers.begin();
				while (functionIt != _functions.end() || handlerIt != _anotherHandlers.end())
				{
					if (functionIt == _functions.end())
						handlerIt->second(sender, e);
					else if (handlerIt == _anotherHandlers.end())
						functionIt->second(sender, e);
					else
					{
						if (functionIt->first < handlerIt->first)
							functionIt++->second(sender, e);
						else
							handlerIt++->second(sender, e);
					}
				}
			}
			
			//Adds another event handler to handle an event
			const EventHandler& operator+=(const EventHandler& handler)
			{
				if (_functions.size()+_anotherHandlers.size() == 0)
					_anotherHandlers.push_back(std::make_pair<int, const EventHandler&>(_anotherHandlers.size() + _functions.size(), handler));
				else if (_functions.size() == 0)
					_anotherHandlers.push_back(std::make_pair<int, const EventHandler&>(_anotherHandlers.back().first+1, handler));
				else
#define MAX(a,b) ((a)<(b) ? (b) : (a))
					_anotherHandlers.push_back(std::make_pair<int, const EventHandler&>(MAX(_anotherHandlers.back().first,_functions.back().first)+1,handler));
#undef MAX
				return *this;
			}

			//Adds another function to handle the event
			const EventHandler& operator+=(const Function& function)
			{
				if (_functions.size() + _anotherHandlers.size() == 0)
					_functions.push_back(std::make_pair<int, const Function&>((int)(_anotherHandlers.size() + _functions.size()), function));
				else if (_anotherHandlers.size() == 0)
					_functions.push_back(std::make_pair<int, const Function&>(_functions.back().first + 1, function));
				else
#define MAX(a,b) ((a)<(b) ? (b) : (a))
					_functions.push_back(std::make_pair<int, const Function&>(MAX(_anotherHandlers.back().first, _functions.back().first) + 1, function));
#undef MAX
				return *this;
			}

			//Checks if the handlers are different
			bool operator!=(const EventHandler& handler) const
			{
				if (this->_functions != handler._functions)
					return true;
				if (this->_anotherHandlers != handler._anotherHandlers)
					return true;
				return false;
			}

			//Unregisters handler from handler
			const EventHandler& operator-=(const EventHandler& handler)
			{
				auto handlerIt = _anotherHandlers.begin();
				for (; handlerIt != _anotherHandlers.end() && handlerIt->second != handler; ++handlerIt);
				if (handlerIt != _anotherHandlers.end())
					_anotherHandlers.erase(handlerIt);
				return *this;
			}

			//Checks if the handlers are the same handler
			bool operator==(const EventHandler& handler) const
			{
				return (*this != handler) == false;
			}

			//Unregisters function from handler
			const EventHandler& operator-=(const Function& function)
			{
				auto functionIt = _functions.begin();
				for (; functionIt != _functions.end() && functionIt->second != function; ++functionIt);
				if (functionIt != _functions.end())
					_functions.erase(functionIt);
				return *this;
			}
	};
}