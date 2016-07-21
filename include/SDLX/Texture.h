#ifndef SDLX_TEXTURE_H
#define SDLX_TEXTURE_H

#include <SDLX/SDLX.h>
#include <SDLX/Surface.h>

namespace SDLX
{
	
	class Renderer;
	
	class Texture
	{
	public:
		
		static const uint32_t kAccess_Static = SDL_TEXTUREACCESS_STATIC;
		static const uint32_t kAccess_Streaming = SDL_TEXTUREACCESS_STREAMING;
		static const uint32_t kAccess_Target = SDL_TEXTUREACCESS_TARGET;
		
		~Texture ();
		
	private:
		
		friend class Renderer;
		
		Texture ( SDL_Texture * Handle );
		
		SDL_Texture * THandle;
		
	};
	
}

#endif
