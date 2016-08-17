#ifndef RED_THREADING_THREADEVENT_H
#define RED_THREADING_THREADEVENT_H

#include <string>
#include <thread>

#include <Red/Red.h>
#include <Red/Threading/Threading.h>

#include <Red/Events/BasicEvent.h>

namespace Red
{
	
	namespace Threading
	{
		
		class Thread;
		
		class ThreadEvent : public Events :: BasicEvent
		{
		public:
			
			// Started and stoped events to signal a thread's execution state.
			static const std :: string kThreadEvent_Started;
			static const std :: string kThreadEvent_Finished;
			
			ThreadEvent ( const std :: string & EventID, Thread * Sender, std::thread :: id ThreadID );
			~ThreadEvent ();
			
			Thread * GetSender ();
			std::thread :: id GetThreadID ();
			
		private:
			
			Thread * Sender;
			std::thread :: id ThreadID;
			
		};
		
	}
	
}

#endif
