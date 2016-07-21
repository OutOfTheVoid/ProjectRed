#ifndef SDLX_MUTEX_H
#define SDLX_MUTEX_H

#include <SDLX/SDLX.h>

#include <SDL2/SDL.h>

namespace SDLX
{

	class Mutex
	{
	public:
		
		typedef int MutexStatus;
		
		static const MutexStatus kMutexStatus_Success = 0;
		static const MutexStatus kMutexStatus_Timeout = SDL_MUTEX_TIMEDOUT;
		static const MutexStatus kMutexStatus_Error = - 1;
		
		static Mutex * Create ();
		
		~Mutex ();
		
		MutexStatus Lock ();
		MutexStatus TryLock ();
		MutexStatus Unlock ();
		
	private:
		
		Mutex ( SDL_mutex * MHandle );
		
		SDL_mutex * MHandle;
		
	};

}

#endif
