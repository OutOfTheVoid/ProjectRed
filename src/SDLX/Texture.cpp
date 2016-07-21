#include <SDLX/Texture.h>

#include <SDL2/SDL.h>

SDLX::Texture :: Texture ( SDL_Texture * Handle ):
	THandle ( Handle )
{
}

SDLX::Texture :: ~Texture ()
{
	
	SDL_DestroyTexture ( THandle );
	
}
