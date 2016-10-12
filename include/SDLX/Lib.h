#ifndef SDLX_LIB_H
#define SDLX_LIB_H

#include <SDLX/SDLX.h>

namespace SDLX
{
	
	class Lib
	{
	public:
		
		static const uint32_t kSDLFlag_Video = SDL_INIT_VIDEO;
		static const uint32_t kSDLFlag_Audio = SDL_INIT_AUDIO;
		
		static void Init ( uint32_t * Status, uint32_t SDLFlags );
		static void DeInit ();
		
		static void EventLoop ( uint32_t * Status );
		
		static void PushEvent ( SDL_Event * Event );
		
	};
	
}

#endif
