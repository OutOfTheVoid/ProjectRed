#ifndef SDLX_RENDERER_H
#define SDLX_RENDERER_H

#include <SDLX/SDLX.h>
#include <SDLX/Window.h>

namespace SDLX
{
	
	class Texture;
	class Surface;
	
	class Renderer
	{
	public:
		
		~Renderer ();
		
		void SetDrawColor ( uint8_t Red, uint8_t Green, uint8_t Blue, uint8_t Alpha = SDL_ALPHA_OPAQUE );
		
		Texture * CreateTexture ( uint32_t Width, uint32_t Height, uint32_t Access, uint32_t Depth = 32, uint32_t RedMask = 0xFF000000, uint32_t GreenMask = 0x00FF0000, uint32_t BlueMask = 0x0000FF00, uint32_t AlphaMask = 0x000000FF );
		Texture * CreateTextureFromSurface ( Surface * Source );
		
		void Clear ();
		
		void Present ();
		
	private:
		
		friend class Window;
		
		static Renderer * FromWindow ( Window * Wind, bool Accellerated, bool VSync );
		
		Renderer ( SDL_Renderer * Handle );
		
		SDL_Renderer * RHandle;
		
	};
	
}

#endif
