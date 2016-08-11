#include <SDLX/Mouse.h>

#include <SDLX/Window.h>

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
		ButtonStates [ I ] = SDL_BUTTON ( I ) & ButtonMask;
	
	SDL_SetRelativeMouseMode ( SDL_FALSE );
	
	Locked = false;
	
}

void SDLX::Mouse :: DeInit ()
{
	
	Unlock ();
	
}

void SDLX::Mouse :: ButtonEventInternal ( SDL_MouseButtonEvent * Event )
{
	
	(void) Event;
	
}

void SDLX::Mouse :: MotionEventInternal ( SDL_MouseMotionEvent * Event )
{
	
	uint32_t I;
	uint32_t Length;
	
	MotionListenerLock -> Lock ();
	
	Length = MotionListeners.size ();
	
	std :: vector <MotionListenerStruct> MotionListenersCopy ( MotionListeners );
	
	MotionListenerLock -> Unlock ();
	
	for ( I = 0; I < Length; I ++ )
		MotionListenersCopy [ I ].Listener ( Event, MotionListenersCopy [ I ].Data );
	
}

void SDLX::Mouse :: InjectMouseMotionEvent ( int32_t X, int32_t Y, int32_t DX, int32_t DY, uint32_t TimeStamp, Window * Source, uint32_t ButtonState, bool Touch )
{
	
	SDL_MouseMotionEvent Event;
	
	Event.x = X;
	Event.y = Y;
	Event.xrel = DX;
	Event.yrel = DY;
	Event.state = ButtonState;
	Event.windowID = ( Source != NULL ) ? SDL_GetWindowID ( Source -> WHandle ) : 0;
	Event.which = Touch ? SDL_TOUCH_MOUSEID : 0;
	Event.timestamp = TimeStamp;
	Event.type = SDL_MOUSEMOTION;
	
	MotionEventInternal ( & Event );
	
}

void SDLX::Mouse :: InjectButtonEvent ( SDL_MouseButtonEvent * Event )
{
	
	(void) Event;
	
}

void SDLX::Mouse :: Lock ()
{
	
	if ( Locked )
		return;
	
	if ( SDL_SetRelativeMouseMode ( SDL_TRUE ) == 0 )
		Locked = true;
	
}

void SDLX::Mouse :: Unlock ()
{
	
	if ( ! Locked )
		return;
	
	if ( SDL_SetRelativeMouseMode ( SDL_FALSE ) == 0 )
		Locked = false;
	
}

bool SDLX::Mouse :: IsLocked ()
{
	
	return Locked;
	
}

void SDLX::Mouse :: AddMotionListener ( void ( * Listener ) ( SDL_MouseMotionEvent * Event, void * Data ), void * Data )
{
	
	MotionListenerStruct NewListener;
	
	NewListener.Listener = Listener;
	NewListener.Data = Data;
	
	MotionListenerLock -> Lock ();
	
	MotionListeners.push_back ( NewListener );
	
	MotionListenerLock -> Unlock ();
	
}

void SDLX::Mouse :: RemoveMotionListener ( void ( * Listener ) ( SDL_MouseMotionEvent * Event, void * Data ) )
{
	
	MotionListenerLock -> Lock ();
	
	std::vector <MotionListenerStruct> :: iterator Index = std :: find_if ( MotionListeners.begin (), MotionListeners.end (), MotionListenerCompare ( Listener ) );
	
	if ( Index != MotionListeners.end () )
		MotionListeners.erase ( Index );
	
	MotionListenerLock -> Unlock ();
	
}

