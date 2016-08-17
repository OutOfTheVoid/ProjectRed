#ifndef RED_EVENTS_EVENTDISPATCHER_H
#define RED_EVENTS_EVENTDISPATCHER_H

#include <Red/Red.h>
#include <Red/Events/Events.h>
#include <Red/Events/IEvent.h>
#include <Red/Events/IEventDispatcher.h>

#include <Red/Util/Function.h>

#include <string>
#include <vector>

/*
* EventDispatcher: A simple implementation of the IEventDispatcher interface.
*/

namespace Red
{
	
	namespace Events
	{
		
		class EventDispatcher : public virtual IEventDispatcher
		{
		public:
			
			// See IEventDispatcher for documentation.
			
			EventDispatcher ();
			~EventDispatcher ();
			
			EventKey HoldEventKey ( const std :: string & EventID );
			EventKey FindHeldEventKey ( const std :: string & EventID );
			void RetireEventKey ( EventKey Key );
			
			void AddEventListener ( EventKey Target, Util :: IFunction1 <void, IEvent *> * Listener );
			void RemoveEventListener ( EventKey Target, Util :: IFunction1 <void, IEvent *> * Listener );
			
			void AddEventListener ( const std :: string & EventID, Util :: IFunction1 <void, IEvent *> * Listener );
			void RemoveEventListener ( const std :: string & EventID, Util :: IFunction1 <void, IEvent *> * Listener );
			
			// Dispatch an event based on it's key <Target>. Event is passed as a reference because it is not allowed to be null. The event object will be passed to all listeners in the order they are added.
			void DispatchEvent ( EventKey Target, IEvent & Event );
			
			// Dispatch an event and use it's ID to find the key for the slot containing the listener references. The event object will be passed to all listeners in the order they are added.
			void DispatchEvent ( IEvent & Event );
			
		private:
			
			typedef struct EventRegistration_Struct
			{
				
				EventRegistration_Struct ();
				~EventRegistration_Struct ();
				
				uint32_t HolderCount;
				EventKey Key;
				
				struct EventRegistration_Struct * NextFree;
				
				std :: string EventID;
				
				std :: vector <Util :: IFunction1 <void, IEvent *> *> Listeners;
				
			} EventRegistration;
			
			uint32_t FreeCount;
			EventRegistration * FreeList;
			
			std :: vector <EventRegistration *> Registrations;
			
		};
		
	}
	
}

#endif
