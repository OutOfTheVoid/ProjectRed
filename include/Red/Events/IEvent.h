#ifndef RED_EVENTS_IEVENT_H
#define RED_EVENTS_IEVENT_H

#include <Red/Red.h>
#include <Red/Events/Events.h>

#include <string>

/*
* IEvent: The interface that all events must implement in order to be valid for an IEventDispatcher.
*/

namespace Red
{
	
	namespace Events
	{
		
		class IEvent
		{
		public:
			
			inline virtual ~IEvent ()
			{
			};
			
			// The ID string of this event.
			virtual const std :: string & GetID () const = 0;
			
		};
		
	}
	
}

#endif
