#ifndef RED_EVENTS_BASICEVENT_H
#define RED_EVENTS_BASICEVENT_H

#include <Red/Red.h>
#include <Red/Events/Events.h>
#include <Red/Events/IEvent.h>

#include <string>

namespace Red
{
	
	namespace Events
	{
		
		class BasicEvent : public virtual IEvent
		{
		public:
			
			static const std :: string kEvent_Update;
			static const std :: string kEvent_Test;
			
			BasicEvent ( const std :: string & ID );
			~BasicEvent ();
			
			const std :: string & GetID () const;
			
		private:
			
			std :: string ID;
			
		};
		
	}
	
}

#endif
