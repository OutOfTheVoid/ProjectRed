#include <SDLX/UserEvent.h>

std :: vector <void ( * ) ( SDL_UserEvent * )> SDLX::UserEvent :: EventHooks;
SDLX :: Mutex * SDLX::UserEvent :: HookMutex = NULL;

uint32_t SDLX::UserEvent :: EventBase = 0xFFFFFFFF;

void SDLX::UserEvent :: Init ( uint32_t * Status )
{
	
	HookMutex = Mutex :: Create ();
	
	if ( HookMutex == NULL )
		* Status = kStatus_LibInitFailed;
	
	* Status = kStatus_Success;
	
};

uint32_t SDLX::UserEvent :: GetNewEventID ( uint32_t * Status )
{
	
	uint32_t Beginning = SDL_RegisterEvents ( 1 );
	
	if ( Beginning == 0xFFFFFFFF )
	{
		
		* Status = kStatus_RegisterEventsFailed;
		
		return 0xFFFFFFFF;
		
	}
	
	if ( EventBase == 0xFFFFFFFF )
		EventBase = Beginning;
	
	* Status = kStatus_Success;
	
	return Beginning - EventBase;
	
};

void SDLX::UserEvent :: SetEventHook ( uint32_t EventID, void ( * EventHook ) ( SDL_UserEvent * Event ) )
{
	
	if ( EventBase == 0xFFFFFFFF )
		return;
	
	HookMutex -> Lock ();
	
	while ( EventID >= EventHooks.size () )
		EventHooks.push_back ( NULL );
	
	EventHooks [ EventID ] = EventHook;
	
	HookMutex -> Unlock ();
	
};

void SDLX::UserEvent :: ClearEventHook ( uint32_t EventID )
{
	
	if ( EventBase == 0xFFFFFFFF )
		return;
	
	HookMutex -> Lock ();
	
	if ( EventID < EventHooks.size () )
		EventHooks [ EventID ] = NULL;
	
	HookMutex -> Unlock ();
	
};

void SDLX::UserEvent :: EventInternal ( SDL_UserEvent * Event )
{
	
	if ( EventBase == 0xFFFFFFFF )
		return;
	
	HookMutex -> Lock ();
	
	if ( static_cast <uint32_t> ( Event -> type - EventBase ) < EventHooks.size () )
	{
		
		if ( EventHooks [ static_cast <uint32_t> ( Event -> type ) - EventBase ] != NULL )
			EventHooks [ static_cast <uint32_t> ( Event -> type ) - EventBase ] ( Event );
		
	}
	
	HookMutex -> Unlock ();
	
};

void SDLX::UserEvent :: PushEvent ( uint32_t EventID, void * Data1, void * Data2 )
{
	
	if ( EventBase == 0xFFFFFFFF )
		return;
	
	SDL_Event Event;
	SDL_memset ( & Event, 0, sizeof ( SDL_Event ) );
	
	Event.type = EventBase + EventID;
	Event.user.code = EventID;
	Event.user.data1 = Data1;
	Event.user.data2 = Data2;
	
	SDL_PushEvent ( & Event );
	
};
