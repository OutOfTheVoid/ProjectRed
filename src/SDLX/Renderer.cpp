#include <SDLX/Renderer.h>
#include <SDLX/Texture.h>
#include <SDLX/Surface.h>

#include <SDL2/SDL.h>

SDLX :: Renderer * SDLX::Renderer :: FromWindow ( Window * Wind, bool Accellerated, bool VSync )
{
	
	SDL_Renderer * Handle = SDL_CreateRenderer ( Wind -> WHandle, - 1, ( Accellerated ? SDL_RENDERER_ACCELERATED : 0 ) | ( VSync ? SDL_RENDERER_PRESENTVSYNC : 0 ) );
	
	if ( Handle == NULL )
		return NULL;
	
	return new Renderer ( Handle );
	
};

SDLX::Renderer :: Renderer ( SDL_Renderer * Handle ):
	RHandle ( Handle )
{
};

SDLX::Renderer :: ~Renderer ()
{
	
	SDL_DestroyRenderer ( RHandle );
	
};

SDLX :: Texture * SDLX::Renderer :: CreateTexture ( uint32_t Width, uint32_t Height, uint32_t Access, uint32_t Depth, uint32_t RedMask, uint32_t GreenMask, uint32_t BlueMask, uint32_t AlphaMask )
{
	
	SDL_Texture * Handle = SDL_CreateTexture ( RHandle, SDL_MasksToPixelFormatEnum ( Depth, RedMask, GreenMask, BlueMask, AlphaMask ), Access, Width, Height );
	
	if ( Handle == NULL )
		return NULL;
	
	return new Texture ( Handle );
	
};

SDLX :: Texture * SDLX::Renderer :: CreateTextureFromSurface ( Surface * Source )
{
	
	SDL_Texture * Handle = SDL_CreateTextureFromSurface ( RHandle, Source -> SHandle );
	
	if ( Handle == NULL )
		return NULL;
	
	return new Texture ( Handle );
	
};

void SDLX::Renderer :: SetDrawColor ( uint8_t Red, uint8_t Green, uint8_t Blue, uint8_t Alpha )
{
	
	SDL_SetRenderDrawColor ( RHandle, Red, Green, Blue, Alpha );
	
};

void SDLX::Renderer :: Clear ()
{
	
	SDL_RenderClear ( RHandle );
	
};

void SDLX::Renderer :: Present ()
{
	
	SDL_RenderPresent ( RHandle );
	
};

