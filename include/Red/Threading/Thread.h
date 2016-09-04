#ifndef RED_THREADING_THREAD_H
#define RED_THREADING_THREAD_H

#include <Red/Threading/Threading.h>
#include <Red/Threading/ThreadEvent.h>

#include <Red/Util/Function.h>

#include <Red/Events/IEventDispatcher.h>
#include <Red/Events/EventDispatcher.h>
#include <Red/Events/IEvent.h>

#include <thread>
#include <mutex>

namespace Red
{
	
	namespace Threading
	{
		
		class Thread : public Events :: IEventDispatcher
		{
		public:
			
			// Thread constructor takes an entry to the thread, IE the function to be called concurrently, and an optional name.
			// Note: holding a local to a Thread which is running will call Join () when it is destructed, so you don't want a local Thread in most cases.
			Thread ( Util :: IFunction <void> * Entry, const std :: string & Name = "Nameless" );
			~Thread ();
			
			// This is how to delete a dynamically allocated Thread object if you don't want to Join on delete. It works by leaving it up to the wrapper call around Entry to deallocate the thread object. You should drop your reference to the object after calling this. It WILL eventually deallocate storage, and therefore shouldn't be used on a local object.
			// Think of this: If you had a local to the object, it would be like writing "delete & LocalThread", something you should never try to do.
			void Delete ();
			
			// Start a thread.
			void Start ();
			
			// Is the thread running?
			bool IsRunning ();
			
			// Join with the thread.
			bool Join ();
			
			// Get the name supplied to the constructor.
			const std :: string & GetName ();
			
			// Get the keys for ThreadEvent :: kThreadEvent_Started and ThreadEvent :: kThreadEvent_Finished.
			EventKey HoldEventKey ( const std :: string & EventID );
			EventKey FindHeldEventKey ( const std :: string & EventID );
			// Noop.
			void RetireEventKey ( EventKey Key );
			
			// Add or remove a listener to events with the keys for ThreadEvent :: kThreadEvent_Started and ThreadEvent :: kThreadEvent_Finished.
			void AddEventListener ( EventKey Target, Util :: IFunction1 <void, Events :: IEvent *> * Listener );
			void RemoveEventListener ( EventKey Target, Util :: IFunction1 <void, Events :: IEvent *> * Listener );
			
			// Add or remove events with the ID ThreadEvent :: kThreadEvent_Started and ThreadEvent :: kThreadEvent_Finished.
			void AddEventListener ( const std :: string & EventID, Util :: IFunction1 <void, Events :: IEvent *> * Listener );
			void RemoveEventListener ( const std :: string & EventID, Util :: IFunction1 <void, Events :: IEvent *> * Listener );
			
		private:
			
			inline void ThreadRun ();
			
			static void InternalThreadEntry ( Thread * ThreadPointer );
			
			Util :: IFunction <void> * Entry;
			
			std :: thread * ThreadInstance;
			std :: mutex Lock;
			
			bool Running;
			
			Events :: EventDispatcher DispatcherInternal;
			std :: mutex EventLock;
			
			IEventDispatcher :: EventKey StartKey;
			IEventDispatcher :: EventKey FinishKey;
			
			const std :: string Name;
			
			bool SelfDelete;
			
		};
		
	}
	
}

#endif
