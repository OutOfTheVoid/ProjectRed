#include <Red/Threading/ThreadEvent.h>
#include <Red/Threading/Thread.h>

const std :: string Red::Threading::ThreadEvent :: kThreadEvent_Started ( "thread_started" );
const std :: string Red::Threading::ThreadEvent :: kThreadEvent_Finished ( "thread_finished" );

Red::Threading::ThreadEvent :: ThreadEvent ( const std :: string & EventID, Thread * Sender, std::thread :: id ThreadID ):
	BasicEvent ( EventID ),
	Sender ( Sender ),
	ThreadID ( ThreadID )
{
}

Red::Threading::ThreadEvent :: ~ThreadEvent ()
{
}

Red::Threading :: Thread * Red::Threading::ThreadEvent :: GetSender ()
{
	
	return Sender;
	
}

std::thread :: id Red::Threading::ThreadEvent :: GetThreadID ()
{
	
	return ThreadID;
	
}
