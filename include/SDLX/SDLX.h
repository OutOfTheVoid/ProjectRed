#ifndef SDLX_SDLX_H
#define SDLX_SDLX_H

/*
* SDLX: An object-oriented SDL2 extension library that intends to provide an even easier to use interface to SDL2.
*/

#include <stdint.h>

#include <SDL2/SDL.h>

#undef main

#define SDLX_XENON_GL_INTERFACE

namespace SDLX
{
	
	const uint32_t kStatus_Success = 0;
	const uint32_t kStatus_SDLInitFailed = 1;
	const uint32_t kStatus_SDLWaitEventFailed = 2;
	const uint32_t kStatus_SDLQuit = 3;
	const uint32_t kStatus_LibInitFailed = 4;
	const uint32_t kStatus_RegisterEventsFailed = 5;
	
}

#endif /* SDLX_SDLX_H */
