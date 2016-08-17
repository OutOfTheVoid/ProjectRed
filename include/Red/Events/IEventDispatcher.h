#ifndef RED_EVENTS_IEVENTDISPATCHER_H
#define RED_EVENTS_IEVENTDISPATCHER_H

#include <Red/Red.h>
#include <Red/Events/Events.h>
#include <Red/Events/IEvent.h>

#include <Red/Util/Function.h>

/*
* IEventDispatcher: An interface for an object which dispatches events.
*/

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
			
			// Hold an event key. Allocates a slot for event listeners waiting on the id <EventID> and returns a local key to that slot.
			virtual EventKey HoldEventKey ( const std :: string & EventID ) = 0;
			// Find a currently held slot key for the id <EventID>. Returns IEventDispatcher :: kEventKey_Invalid if the ID wasn't found.
			virtual EventKey FindHeldEventKey ( const std :: string & EventID ) = 0;
			// Stop holding an event key. If all holders release this key, then the allocated slot will be added to a free pool for re-use with another ID.
			virtual void RetireEventKey ( EventKey Key ) = 0;
			
			// Add an event listener by EventKey. Listener is an IFunction1 representing the callback to be executed when the event keyed by <Target> is dispatched, passing the address of that IEvent object to the callback.
			// You will always be dispatching something of higher order than IEvent, so if you care about the data in the underlying event object, perform a dynamic_cast to the type you expect.
			virtual void AddEventListener ( EventKey Target, Util :: IFunction1 <void, IEvent *> * Listener ) = 0;
			// Remove an event listener keyed by the event key <Target>.
			virtual void RemoveEventListener ( EventKey Target, Util :: IFunction1 <void, IEvent *> * Listener ) = 0;
			
			// Add an event listener based on the event's ID string. This will hold an event key every time it is called.
			virtual void AddEventListener ( const std :: string & EventID, Util :: IFunction1 <void, IEvent *> * Listener ) = 0;
			// Remove and event listener based on the event's ID string. This will retire the event key every time it is called successfully.
			virtual void RemoveEventListener ( const std :: string & EventID, Util :: IFunction1 <void, IEvent *> * Listener ) = 0;
			
		};
		
	}
	
}

#endif
