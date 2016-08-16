#ifndef RED_EVENTS_IEVENT_H
#define RED_EVENTS_IEVENT_H

#include <Red/Red.h>
#include <Red/Events/Events.h>

#include <string>

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
			
			virtual const std :: string & GetID () const = 0;
			
		};
		
	}
	
}

#endif
