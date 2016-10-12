#include <iostream>

#include <SDLX/Lib.h>
#include <SDLX/Window.h>

#include <SDLX/AudioDevice.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data );

int main ( int argc, char const * argv [] )
{
	
	( void ) argc;
	( void ) argv;
	
	uint32_t Status;
	
	SDLX::Lib :: Init ( & Status, SDLX::Lib :: kSDLFlag_Video | SDLX::Lib :: kSDLFlag_Audio );
	
	if ( Status != SDLX :: kStatus_Success )
		return - 1;
	
	SDLX::Window * Win = SDLX::Window :: CreateWindow ( & Status, "Test", WINDOW_WIDTH, WINDOW_HEIGHT, SDLX::Window :: kCreateFlag_Shown | SDLX::Window :: kCreateFlag_HighDPI | SDLX::Window :: kCreateFlag_OpenGL );
	
	if ( Status != SDLX::Window :: kStatus_Success )
	{
		
		SDLX::Lib :: DeInit ();
		
		return - 2;
		
	}
	
	Win -> Own ();
	Win -> AddEventHook ( SDL_WINDOWEVENT_CLOSE, & WindowCloseEvent, NULL );
	
	SDLX::Lib :: EventLoop ( & Status );
	 
	Win -> Disown ();
	
	SDLX::Lib :: DeInit ();
	
	return 0;

}

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data )
{
	
	uint32_t Status;
	
	( void ) Event;
	( void ) Data;
	
	Win -> Close ( & Status );
	
}
