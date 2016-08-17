#include <Red/Threading/Thread.h>

Red::Threading::Thread :: Thread ( Util :: IFunction <void> * Entry, const std :: string & Name ):
	Entry ( Entry ),
	ThreadInstance ( NULL ),
	Lock (),
	Running ( false ),
	DispatcherInternal (),
	EventLock (),
	Name ( Name ),
	SelfDelete ( false )
{	
	
	StartKey = DispatcherInternal.HoldEventKey ( ThreadEvent :: kThreadEvent_Started );
	FinishKey = DispatcherInternal.HoldEventKey ( ThreadEvent :: kThreadEvent_Finished );
	
}

Red::Threading::Thread :: ~Thread ()
{
	
	if ( ThreadInstance != NULL )
		Join ();
	
}

void Red::Threading::Thread :: Delete ()
{
	
	Lock.lock ();
	
	if ( Running )
		SelfDelete = true;
	else
	{
		
		if ( ThreadInstance != NULL )
		{
			
			ThreadInstance -> detach ();
			delete ThreadInstance;
			
		}
				
		delete this;
		
		return;
		
	}
	
	Lock.unlock ();
	
}

const std :: string & Red::Threading::Thread :: GetName ()
{
	
	return Name;
	
}

void Red::Threading::Thread :: Start ()
{
	
	Lock.lock ();
	
	if ( Running )
	{
		
		Lock.unlock ();
		
		return;
		
	}
	
	if ( ThreadInstance != NULL )
	{
		
		delete ThreadInstance;
		
	}
	
	ThreadInstance = new std :: thread ( InternalThreadEntry, this );
	Running = true;
	
	Lock.unlock ();
	
}

void Red::Threading::Thread :: InternalThreadEntry ( Thread * ThreadPointer )
{
	
	ThreadPointer -> ThreadRun ();
	
}

inline void Red::Threading::Thread :: ThreadRun ()
{
	
	std::thread :: id ThreadID = ThreadInstance -> get_id ();
	
	EventLock.lock ();
	ThreadEvent StartEvent ( ThreadEvent :: kThreadEvent_Started, this, ThreadID );
	DispatcherInternal.DispatchEvent ( StartKey, StartEvent );
	EventLock.unlock ();
	
	this -> Entry -> Call ();
	
	Lock.lock ();
	
	this -> Running = false;
	
	Lock.unlock ();
	
	EventLock.lock ();
	ThreadEvent FinishEvent ( ThreadEvent :: kThreadEvent_Finished, this, ThreadID );
	DispatcherInternal.DispatchEvent ( FinishKey, FinishEvent );
	EventLock.unlock ();
	
	if ( SelfDelete )
	{
		
		ThreadInstance -> detach ();
		delete ThreadInstance;
		
		delete this;
		
	}
	
}

bool Red::Threading::Thread :: IsRunning ()
{
	
	Lock.lock ();
	
	bool Temp = Running;
	
	Lock.unlock ();
	
	return Temp;
	
}

bool Red::Threading::Thread :: Join ()
{
	
	Lock.lock ();
	
	if ( ! Running )
	{
		
		Lock.unlock ();
		
		return false;
		
	}
	
	std::thread :: id ThreadID;
	
	if ( ThreadInstance -> joinable () )
	{
		
		try
		{
			
			ThreadID = ThreadInstance -> get_id ();
			
			Lock.unlock ();
			
			ThreadInstance -> join ();
			
			Lock.lock ();
			
			delete ThreadInstance;
			ThreadInstance = NULL;
			
		}
		catch ( std :: system_error Error )
		{
			
			Lock.unlock ();
			
			return false;
			
		}
		
	}
	else
	{
		
		Lock.unlock ();
		
		return false;
		
	}
	
	Lock.unlock ();
	
	return true;
	
}

Red::Events::IEventDispatcher :: EventKey Red::Threading::Thread :: HoldEventKey ( const std :: string & EventID )
{
	
	Lock.lock ();
	
	Events::IEventDispatcher :: EventKey Key = DispatcherInternal.FindHeldEventKey ( EventID );
	
	Lock.unlock ();
	
	return Key;
	
}

Red::Events::IEventDispatcher :: EventKey Red::Threading::Thread :: FindHeldEventKey ( const std :: string & EventID )
{
	
	Lock.lock ();
	
	Events::IEventDispatcher :: EventKey Key =  DispatcherInternal.FindHeldEventKey ( EventID );
	
	Lock.unlock ();
	
	return Key;
	
}

void Red::Threading::Thread :: RetireEventKey ( Events::IEventDispatcher :: EventKey Key )
{
	
	(void) Key;
	
}

void Red::Threading::Thread :: AddEventListener ( Events::IEventDispatcher :: EventKey Target, Util :: IFunction1 <void, Events :: IEvent *> * Listener )
{
	
	EventLock.lock ();
	
	DispatcherInternal.AddEventListener ( Target, Listener );
	
	EventLock.unlock ();
	
}

void Red::Threading::Thread :: RemoveEventListener ( Events::IEventDispatcher :: EventKey Target, Util :: IFunction1 <void, Events :: IEvent *> * Listener )
{
	
	EventLock.lock ();
	
	DispatcherInternal.RemoveEventListener ( Target, Listener );
	
	EventLock.unlock ();
	
}

void Red::Threading::Thread :: AddEventListener ( const std :: string & EventID, Util :: IFunction1 <void, Events :: IEvent *> * Listener )
{
	
	EventLock.lock ();
	
	Events::IEventDispatcher :: EventKey Key = DispatcherInternal.FindHeldEventKey ( EventID );
	
	if ( Key != Events::IEventDispatcher :: kEventKey_Invalid )
		DispatcherInternal.AddEventListener ( Key, Listener );
	
	EventLock.unlock ();
	
}

void Red::Threading::Thread :: RemoveEventListener ( const std :: string & EventID, Util :: IFunction1 <void, Events :: IEvent *> * Listener )
{
	
	EventLock.lock ();
	
	Events::IEventDispatcher :: EventKey Key = DispatcherInternal.FindHeldEventKey ( EventID );
	
	if ( Key != Events::IEventDispatcher :: kEventKey_Invalid )
		DispatcherInternal.RemoveEventListener ( Key, Listener );
	
	EventLock.unlock ();
	
}
