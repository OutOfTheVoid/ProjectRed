#ifndef RED_EVENTS_IEVENTDISPATCHER_H
#define RED_EVENTS_IEVENTDISPATCHER_H

#include <Red/Red.h>
#include <Red/Events/Events.h>
#include <Red/Events/IEvent.h>

#include <Red/Util/Function.h>

namespace Red
{
	
	namespace Events
	{
		
		class IEventDispatcher
		{
		public:
			
			typedef uint32_t EventKey;
			
			static const EventKey kEventKey_Invalid = 0xFFFFFFFF;
			
			virtual ~IEventDispatcher ()
			{	
			};
			
			virtual EventKey HoldEventKey ( const std :: string & EventID ) = 0;
			virtual EventKey FindHeldEventKey ( const std :: string & EventID ) = 0;
			virtual void RetireEventKey ( EventKey Key ) = 0;
			
			virtual void AddEventListener ( EventKey Target, Util :: IFunction1 <void, IEvent *> * Listener ) = 0;
			virtual void RemoveEventListener ( EventKey Target, Util :: IFunction1 <void, IEvent *> * Listener ) = 0;
			
			virtual void AddEventListener ( const std :: string & EventID, Util :: IFunction1 <void, IEvent *> * Listener ) = 0;
			virtual void RemoveEventListener ( const std :: string & EventID, Util :: IFunction1 <void, IEvent *> * Listener ) = 0;
			
			virtual void DispatchEvent ( EventKey Target, IEvent & Event ) = 0;
			
		};
		
	}
	
}

#endif
