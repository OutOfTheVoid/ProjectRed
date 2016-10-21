#include <Red/Events/EventDispatcher.h>

#include <algorithm>

Red::Events::EventDispatcher :: EventDispatcher ():
	FreeCount ( 0 ),
	FreeList ( NULL ),
	Registrations ()
{
}

Red::Events::EventDispatcher :: ~EventDispatcher ()
{
	
	for ( uint32_t I = 0; I < Registrations.size (); I ++ )
	{
		
		delete Registrations [ I ];
		Registrations.clear ();
		
	}
	
}

Red::Events::EventDispatcher::EventRegistration_Struct :: EventRegistration_Struct ():
	HolderCount ( 0 ),
	Key ( kEventKey_Invalid ),
	NextFree ( NULL ),
	EventID ( "" ),
	Listeners ()
{
}

Red::Events::EventDispatcher::EventRegistration_Struct :: ~EventRegistration_Struct ()
{
	
	Listeners.clear ();
	
}

Red::Events::IEventDispatcher :: EventKey Red::Events::EventDispatcher :: FindHeldEventKey ( const std :: string & EventID )
{
	
	if ( EventID == "" )
		return kEventKey_Invalid;
	
	for ( uint32_t I = 0; I < Registrations.size (); I ++ )
	{
		
		if ( Registrations [ I ] -> EventID == EventID )
			return I;
		
	}
	
	return kEventKey_Invalid;
	
}

Red::Events::IEventDispatcher :: EventKey Red::Events::EventDispatcher :: HoldEventKey ( const std :: string & EventID )
{
	
	if ( EventID == "" )
		return kEventKey_Invalid;
	
	for ( uint32_t I = 0; I < Registrations.size (); I ++ )
	{
		
		if ( Registrations [ I ] -> EventID == EventID )
		{
			
			Registrations [ I ] -> HolderCount ++;
			return I;
			
		}
		
	}
	
	EventRegistration * NewRegistration;
	
	if ( FreeCount != 0 )
	{
		
		NewRegistration = FreeList;
		FreeList = FreeList -> NextFree;
		NewRegistration -> NextFree = NULL;
		
		FreeCount --;
		
	}
	else
	{
		
		NewRegistration = new EventRegistration ();
		Registrations.push_back ( NewRegistration );
		
		NewRegistration -> NextFree = NULL;
		NewRegistration -> Key = static_cast <uint32_t> ( Registrations.size () - 1 );
		
	}
	
	NewRegistration -> HolderCount ++;
	NewRegistration -> EventID = EventID;
	
	return NewRegistration -> Key;
	
}

void Red::Events::EventDispatcher :: RetireEventKey ( EventKey Key )
{
	
	if ( Key < Registrations.size () )
	{
		
		if ( Registrations [ Key ] -> HolderCount > 0 )
		{
			
			Registrations [ Key ] -> HolderCount --;
			
			if ( Registrations [ Key ] -> HolderCount == 0 )
			{
				
				Registrations [ Key ] -> Listeners.clear ();
				Registrations [ Key ] -> EventID = "";
				
				Registrations [ Key ] -> NextFree = FreeList;
				FreeList = Registrations [ Key ];
				FreeCount ++;
				
			}
				
		}
		
	}
	
}

void Red::Events::EventDispatcher :: AddEventListener ( EventKey Target, Util :: IFunction1 <void, IEvent *> * Listener )
{
	
	if ( Target >= Registrations.size () )
		return;
	
	if ( Registrations [ Target ] -> HolderCount == 0 )
		return;
	
	Registrations [ Target ] -> Listeners.push_back ( Listener );
	
}

void Red::Events::EventDispatcher :: RemoveEventListener ( EventKey Target, Util :: IFunction1 <void, IEvent *> * Listener )
{
	
	if ( Target >= Registrations.size () )
		return;
	
	if ( Registrations [ Target ] -> HolderCount == 0 )
		return;
	
	std :: vector <Util :: IFunction1 <void, IEvent *> *> :: iterator ListenerPosition = std :: find ( Registrations [ Target ] -> Listeners.begin (), Registrations [ Target ] -> Listeners.end (), Listener );
	
	if ( ListenerPosition != Registrations [ Target ] -> Listeners.end () )
		Registrations [ Target ] -> Listeners.erase ( ListenerPosition );
	
}

void Red::Events::EventDispatcher :: AddEventListener ( const std :: string & EventID, Util :: IFunction1 <void, IEvent *> * Listener )
{
	
	EventKey Key = HoldEventKey ( EventID );
	AddEventListener ( Key, Listener );
	
}

void Red::Events::EventDispatcher :: RemoveEventListener ( const std :: string & EventID, Util :: IFunction1 <void, IEvent *> * Listener )
{
	
	EventKey Key = FindHeldEventKey ( EventID );
	RemoveEventListener ( Key, Listener );
	RetireEventKey ( Key );
	
}

void Red::Events::EventDispatcher :: DispatchEvent ( EventKey Target, IEvent & Event )
{
	
	if ( Target >= Registrations.size () )
		return;
	
	if ( Registrations [ Target ] -> HolderCount == 0 )
		return;
	
	std :: vector <Util :: IFunction1 <void, IEvent *> *> * ListenerVector = & Registrations [ Target ] -> Listeners;
	
	for ( uint32_t I = 0; I < ListenerVector -> size (); I ++ )
		( * ( * ListenerVector ) [ I ] ) ( & Event );
	
}

void Red::Events::EventDispatcher :: DispatchEvent ( IEvent & Event )
{
	
	EventKey Key = FindHeldEventKey ( Event.GetID () );
	DispatchEvent ( Key, Event );
	
}
