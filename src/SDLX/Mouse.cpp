#include <SDLX/Mouse.h>

std :: vector <SDLX::Mouse :: MotionListenerStruct> SDLX::Mouse :: MotionListeners;
SDLX :: Mutex * SDLX::Mouse :: MotionListenerLock;

std :: vector <SDLX::Mouse :: ButtonListenerStruct> SDLX::Mouse :: ButtonListeners;
SDLX :: Mutex * SDLX::Mouse :: ButtonListenerLock;

bool SDLX::Mouse :: ButtonStates [ 32 ];

bool SDLX::Mouse :: Locked;

void SDLX::Mouse :: Init ()
{
	
	MotionListenerLock = Mutex :: Create ();
	ButtonListenerLock = Mutex :: Create ();
	
	uint32_t ButtonMask = SDL_GetMouseState ( NULL, NULL );
	
	for ( uint32_t I = 0; I < 32; I ++ )
		ButtonStates [ I ] = SDL_BUTTON ( I );
	
	SDL_SetRelativeMouseMode ( SDL_FALSE );
	
	Locked = false;
	
};

void SDLX::Mouse :: DeInit ()
{
	
	Unlock ();
	
};

void SDLX::Mouse :: ButtonEventInternal ( SDL_MouseButtonEvent * Event )
{
	
	
	
};

void SDLX::Mouse :: MotionEventInternal ( SDL_MouseMotionEvent * Event )
{
	
	uint32_t I;
	uint32_t Length;
	
	MotionListenerLock -> Lock ();
	
	Length = MotionListeners.size ();
	
	MotionListenerStruct MotionListenersCopy [ Length ];
	
	for ( I = 0; I < Length; I ++ )
		MotionListenersCopy [ I ] = MotionListeners [ I ];
	
	MotionListenerLock -> Unlock ();
	
	for ( I = 0; I < Length; I ++ )
		MotionListenersCopy [ I ].Listener ( Event, MotionListenersCopy [ I ].Data );
	
};

void SDLX::Mouse :: Lock ()
{
	
	if ( Locked )
		return;
	
	if ( SDL_SetRelativeMouseMode ( SDL_TRUE ) == 0 )
		Locked = true;
	
};

void SDLX::Mouse :: Unlock ()
{
	
	if ( ! Locked )
		return;
	
	if ( SDL_SetRelativeMouseMode ( SDL_FALSE ) == 0 )
		Locked = false;
	
};

bool SDLX::Mouse :: IsLocked ()
{
	
	return Locked;
	
};

void SDLX::Mouse :: AddMotionListener ( void ( * Listener ) ( SDL_MouseMotionEvent * Event, void * Data ), void * Data )
{
	
	MotionListenerStruct NewListener;
	
	NewListener.Listener = Listener;
	NewListener.Data = Data;
	
	MotionListenerLock -> Lock ();
	
	MotionListeners.push_back ( NewListener );
	
	MotionListenerLock -> Unlock ();
	
};

void SDLX::Mouse :: RemoveMotionListener ( void ( * Listener ) ( SDL_MouseMotionEvent * Event, void * Data ) )
{
	
	MotionListenerLock -> Lock ();
	
	MotionListenerStruct Comparison;
	
	Comparison.Listener = Listener;
	Comparison.Data = NULL;
	
	std::vector <MotionListenerStruct> :: iterator Index = std :: find_if ( MotionListeners.begin (), MotionListeners.end (), MotionListenerCompare ( Listener ) );
	
	if ( Index != MotionListeners.end () )
		MotionListeners.erase ( Index );
	
	MotionListenerLock -> Unlock ();
	
};

