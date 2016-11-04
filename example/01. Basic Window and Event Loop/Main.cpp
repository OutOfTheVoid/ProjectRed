#include <SDLX/SDLX.h>
#include <SDLX/Lib.h>
#include <SDLX/Window.h>

#include <stdint.h>

#include <iostream>

// Forward declaration
void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX :: Window * Origin, void * Data );

int main ( int argc, const char * argv [] )
{
	
	uint32_t Status;
	// Initialize SDLX/SDL2
	SDLX::Lib :: Init ( & Status, SDLX::Lib :: kSDLFlag_Video );
	
	// Check that everything's OK
	if ( SDLX :: kStatus_Success )
		return - 1;
	
	// Open a window!
	SDLX::Window * MyWindow = SDLX::Window :: CreateWindow ( & Status, "My First Window", 800, 600 );
	
	// Check that everything's OK
	if ( Status != SDLX::Window :: kStatus_Success )
	{
	
		// Do this wherever we potentially exit the application.
		SDLX::Lib :: DeInit ();
	
		return - 2;
		
	}
	
	// Take ownership (in terms of reference counting)
	MyWindow -> Own ();
	// Hook the close event
	MyWindow -> AddEventHook ( SDLX::Window :: kWindowEventID_Closed, & WindowCloseEvent, NULL );
	
	// Enter our event loop
	SDLX::Lib :: EventLoop ( & Status );
	
	// Always a good idea to NULL a pointer we no longer own.
	MyWindow -> Disown ();
	MyWindow = NULL;
	
	// Cleans up any resources that SDL2/SDLX might be using
	SDLX::Lib :: DeInit ();
	
}

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX :: Window * Origin, void * Data )
{
	
	std :: cout << "Closing window!" << std :: endl;
	
    uint32_t Status;
	// Close the window
    Origin -> Close ( & Status );

    // Just to suppress unused argument warnings, we'll cast these to void.
    (void) Event;
    (void) Data;
	
}
