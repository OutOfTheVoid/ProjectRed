#ifndef SDLX_TIMER_H
#define SDLX_TIMER_H

#include <SDL2/SDL.h>

#include <SDLX/RefCounted.h>
#include <SDLX/Mutex.h>

namespace SDLX
{

	class Timer
	{
	public:
		
		Timer ( void ( * Callback ) ( Timer * Source, void * Data ), void * Data );
		~Timer ();
		
		void Start ( uint32_t Delay );
		void Stop ();
		
		Mutex * GetMutex ();
		
		void SetCallback ( void ( * Callback ) ( Timer * Source, void * Data ) );
		void SetData ( void * Data );
		
	private:
		
		uint32_t CallbackInternal ( uint32_t Interval );
		
		static uint32_t TimerCallback ( uint32_t Interval, void * Parameter );
		
		void ( * Callback ) ( Timer * Source, void * Data );
		void * Data;
		
		SDL_TimerID ID;
		bool Valid;
		
		Mutex * MLock;
		
	};

};

#endif
