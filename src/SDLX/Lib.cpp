#include <SDLX/Lib.h>
#include <SDLX/Window.h>
#include <SDLX/UserEvent.h>
#include <SDLX/Keyboard.h>
#include <SDLX/Mouse.h>

#include <SDL2/SDL.h>

void SDLX::Lib :: Init ( uint32_t * Status, uint32_t SDLFlags )
{
	
	if ( SDL_Init ( SDLFlags ) < 0 )
		* Status = kStatus_SDLInitFailed;
	else
		* Status = kStatus_Success;
	
	UserEvent :: Init ( Status );
	Keyboard :: Init ();
	Mouse :: Init ();
	
	if ( * Status != kStatus_Success )
	{
		
		* Status = kStatus_LibInitFailed;
		
		return;
		
	}
	
};

void SDLX::Lib :: EventLoop ( uint32_t * Status )
{
	
	SDL_Event Event;
	
	bool Quit = false;
	
	while ( ! Quit )
	{
		
		if ( SDL_WaitEvent ( & Event ) )
		{
			
			switch ( Event.type )
			{
				
			case SDL_QUIT:
				
				* Status = kStatus_SDLQuit;
				
				Quit = true;
				
				return;
				
			case SDL_WINDOWEVENT:
			{
				
				SDL_Window * WHandle = SDL_GetWindowFromID ( Event.window.windowID );
				
				if ( WHandle != NULL )
				{
					
					Window * Win = reinterpret_cast <Window *> ( SDL_GetWindowData ( WHandle, Window :: kDataName_WindowClassInstancePointer ) );
					
					if ( Win != NULL )
						Win -> Event ( & Event.window );
					
				}
				
				break;
				
			}
			
			case SDL_KEYDOWN:
			case SDL_KEYUP:
			{
				
				Keyboard :: EventInternal ( & Event.key );
				
				break;
				
			}
			
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			{
				
				Mouse :: ButtonEventInternal ( & Event.button );
				
				break;
				
			}
			
			case SDL_MOUSEMOTION:
			{
				
				Mouse :: MotionEventInternal ( & Event.motion );
				
				break;
				
			}
			
			case SDL_USEREVENT:
			{
				
				UserEvent :: EventInternal ( & Event.user );
				
				break;
				
			}
				
			default:
				break;
				
			}
			
		}
		else
		{
			
			* Status = kStatus_SDLWaitEventFailed;
			
			return;
			
		}
		
	}
	
};

void SDLX::Lib :: PushEvent ( SDL_Event * Event )
{
	
	SDL_PushEvent ( Event );
	
};

void SDLX::Lib :: DeInit ()
{
	
	SDL_Quit ();
	
};
