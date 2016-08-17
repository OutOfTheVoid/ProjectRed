#ifndef RED_EVENTS_BASICEVENT_H
#define RED_EVENTS_BASICEVENT_H

#include <Red/Red.h>
#include <Red/Events/Events.h>
#include <Red/Events/IEvent.h>

#include <string>

/*
* BasicEvent: A simple implementation of the IEvent interface used soley to pass the event ID.
*/

namespace Red
{
	
	namespace Events
	{
		
		class BasicEvent : public virtual IEvent
		{
		public:
			
			// An ID to represent generic update events.
			static const std :: string kEvent_Update;
			// An ID for event testing purposes.
			static const std :: string kEvent_Test;
			
			// Constructor takes event ID.
			BasicEvent ( const std :: string & ID );
			~BasicEvent ();
			
			// Return the ID.
			const std :: string & GetID () const;
			
		private:
			
			std :: string ID;
			
		};
		
	}
	
}

#endif
