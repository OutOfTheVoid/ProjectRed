#include <SDLX/Window.h>
#include <SDLX/Surface.h>
#include <SDLX/Renderer.h>
#include <SDLX/GLContext.h>

#include <iostream>
#include <algorithm>

const char * SDLX::Window :: kDataName_WindowClassInstancePointer = "_WinInst";

SDLX::Window * SDLX::Window :: Create ( uint32_t * Status, const std :: string & Name, uint32_t Width, uint32_t Height, uint32_t Flags )
{
	
	SDL_Window * WHandle = SDL_CreateWindow ( Name.c_str (), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, ( ( Flags & kCreateFlag_OpenGL ) ? SDL_WINDOW_OPENGL : 0 ) | ( ( Flags & kCreateFlag_Shown ) ? SDL_WINDOW_SHOWN : 0 ) | ( ( Flags & kCreateFlag_Resizable ) ? SDL_WINDOW_RESIZABLE : 0 ) | ( ( Flags & kCreateFlag_HighDPI ) ? SDL_WINDOW_ALLOW_HIGHDPI : 0 ) );
	Window * New = NULL;
	
	if ( WHandle == NULL )
	{
		
		* Status = kStatus_SDLCreateWindowFailed;
		
		return NULL;
		
	}
	
	try
	{
		
		New = new Window ( WHandle, Name, Flags );
		
	}
	catch (...)
	{
		
		* Status = kStatus_AllocationError;
		
		SDL_DestroyWindow ( WHandle );
		
	}
	
	* Status = kStatus_Success;
	
	return New;
	
}

SDLX::Window :: Window ( SDL_Window * WHandle, std :: string Name, uint32_t Flags ):
	RefCounted (),
	Flags ( Flags ),
	WHandle ( WHandle ),
	SurfaceInst ( NULL ),
	RenderInst ( NULL ),
	GLInst ( NULL ),
	Name ( Name ),
	Destroyed ( false ),
	EventMap ()
{
	
	SDL_SetWindowData ( WHandle, kDataName_WindowClassInstancePointer, reinterpret_cast <void *> ( this ) );
	
}

SDLX::Window :: ~Window ()
{
	
	if ( SurfaceInst != NULL )
			delete SurfaceInst;
	
	if ( ! Destroyed )
		SDL_DestroyWindow ( WHandle );
	
}

SDLX::Mutex * SDLX::Window :: GetMutex ()
{
	
	return MLock;
	
}

void SDLX::Window :: AddEventHook ( uint32_t SDLWindowEventID, void ( * EventCallback ) ( SDL_WindowEvent * Event, Window * Origin, void * Data ), void * Data, int32_t Position )
{
	
	if ( EventMap.count ( SDLWindowEventID ) <= 0 )
		EventMap [ SDLWindowEventID ] = std :: vector <CallbackPair> ();
	
	std :: vector <CallbackPair> & CallbackList = EventMap [ SDLWindowEventID ];
	
	CallbackPair Pair { EventCallback, Data };
	
	if ( Position < 0 )
		CallbackList.push_back ( Pair );
	else
		CallbackList.insert ( CallbackList.begin () + static_cast <uint32_t> ( Position ), Pair );
	
}

void SDLX::Window :: RemoveEventHook ( uint32_t SDLWindowEventID, void ( * EventCallbackPtr ) ( SDL_WindowEvent * Event, Window * Origin, void * Data ) )
{
	
	if ( EventMap.count ( SDLWindowEventID ) > 0 )
	{
		
		std :: vector <CallbackPair> & CallbackList = EventMap [ SDLWindowEventID ];
		
		std::vector <CallbackPair> :: iterator Index = std :: find_if ( CallbackList.begin (), CallbackList.end (), EventMatchCompare ( EventCallbackPtr ) );
		
		if ( Index != CallbackList.end () )
			CallbackList.erase ( Index );
		
	}
	
}

void SDLX::Window :: Close ( uint32_t * Status )
{
	
	if ( Destroyed )
	{
		
		* Status = kStatus_AlreadyClosed;
		
		return;
		
	}
	
	SDL_DestroyWindow ( WHandle );
	
	Destroyed = true;
	
	* Status = kStatus_Success;
	
}

void SDLX::Window :: Event ( SDL_WindowEvent * Event )
{
		
	if ( EventMap.count ( Event -> event ) > 0 )
	{
		
		std :: vector <CallbackPair> & CallbackList = EventMap [ Event -> event ];
		
		uint32_t I;
		
		for ( I = 0; I < CallbackList.size (); I ++ )
			CallbackList [ I ].EventCallback ( Event, this, CallbackList [ I ].Data );
		
	}
	
}

SDLX :: Surface * SDLX::Window :: GetWindowSurface ()
{
	
	if ( SurfaceInst == NULL )
		SurfaceInst = Surface :: FromWindowSurface ( SHandle, this );
	
	return SurfaceInst;
	
}

SDLX :: Renderer * SDLX::Window :: GetRenderer ()
{
	
	if ( RenderInst == NULL )
		RenderInst = Renderer :: FromWindow ( this, ( Flags & kCreateFlag_AcceleratedRender ) != 0, ( Flags & kCreateFlag_VSyncedRender ) != 0 );
	
	return RenderInst;
	
}

SDLX :: GLContext * SDLX::Window :: GetOpenGLContext ()
{
	
	if ( GLInst == NULL )
	{
		
		SDL_GLContext Context = SDL_GL_CreateContext ( WHandle );
		
		if ( Context == NULL )
			return NULL;
		
		GLInst = new GLContext ( Context, this );
	}
	
	return GLInst;
	
}

void SDLX::Window :: GLSwap ()
{
	
	SDL_GL_SwapWindow ( WHandle );
	
}

void SDLX::Window :: UpdateSurface ()
{
	
	SDL_UpdateWindowSurface ( WHandle );
	
}

void SDLX::Window :: Resize ( uint32_t Width, uint32_t Height )
{
	
	SDL_SetWindowSize ( WHandle, Width, Height );
	
}
