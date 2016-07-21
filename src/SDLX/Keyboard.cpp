#include <SDLX/Keyboard.h>

#include <iostream>

const uint8_t * SDLX::Keyboard :: KeyArray = NULL;
int32_t SDLX::Keyboard :: KeyCount = 0;

std :: vector <SDLX::Keyboard :: ListenerStruct> SDLX::Keyboard :: Listeners;
SDLX :: Mutex * SDLX::Keyboard :: ListenerLock = NULL;

void SDLX::Keyboard :: Init ()
{
	
	KeyArray = SDL_GetKeyboardState ( & KeyCount );
	
	ListenerLock = Mutex :: Create ();
	
}

bool SDLX::Keyboard :: GetKeyState ( int32_t Key )
{
	
	int32_t ScanCode = SDL_GetScancodeFromKey ( Key );
	
	if ( ScanCode >= KeyCount )
		return false;
	
	return KeyArray [ ScanCode ];
	
}

bool SDLX::Keyboard :: GetScanState ( int32_t ScanCode )
{
	
	if ( ScanCode >= KeyCount )
		return false;
	
	return KeyArray [ ScanCode ];
	
}

void SDLX::Keyboard :: AddKeyListener ( void ( * Listener ) ( int32_t ScanCode, int32_t KeyCode, bool Down, void * Data ), void * Data )
{
	
	ListenerLock -> Lock ();
	
	ListenerStruct New;
	
	New.Listener = Listener;
	New.Data = Data;
	
	Listeners.push_back ( New );
	
	ListenerLock -> Unlock ();
	
}

void SDLX::Keyboard :: RemoveKeyListener ( void ( * Listener ) ( int32_t ScanCode, int32_t KeyCode, bool Down, void * Data ) )
{
	
	ListenerLock -> Lock ();
	
	std::vector <SDLX::Keyboard :: ListenerStruct> :: iterator Index = std :: find_if ( Listeners.begin (), Listeners.end (), ListenerCompare ( Listener ) );
	
	if ( Index != Listeners.end () )
		Listeners.erase ( Index );
	
	ListenerLock -> Unlock ();
	
}

void SDLX::Keyboard :: EventInternal ( SDL_KeyboardEvent * Event )
{
	
	uint32_t I;
	uint32_t Length;
	
	ListenerLock -> Lock ();
	
	Length = Listeners.size ();
	
	std :: vector <ListenerStruct> ListenersCopy ( Listeners );
	
	ListenerLock -> Unlock ();
	
	for ( I = 0; I < Length; I ++ )
		ListenersCopy [ I ].Listener ( Event -> keysym.scancode, Event -> keysym.sym, Event -> type == SDL_KEYDOWN, ListenersCopy [ I ].Data );

}

const char * SDLX::Keyboard :: GetKeyName ( int32_t Key )
{
	
	return SDL_GetKeyName ( Key );
	
}

const char * SDLX::Keyboard :: GetScanName ( int32_t ScanCode )
{
	
	if ( ScanCode < KeyCount )
		return SDL_GetScancodeName ( static_cast <SDL_Scancode> ( ScanCode ) );
	
	return "";
	
}
