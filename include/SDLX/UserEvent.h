#ifndef SDLX_UserEvent_H
#define SDLX_UserEvent_H

#include <SDLX/SDLX.h>
#include <SDLX/Mutex.h>

#include <vector>

namespace SDLX
{
	
	class Lib;
	
	class UserEvent
	{
	public:
		
		static uint32_t GetNewEventID ( uint32_t * Status );
		
		static void SetEventHook ( uint32_t EventID, void ( * EventHook ) ( SDL_UserEvent * Event ) );
		static void ClearEventHook ( uint32_t EventID );
		
		static void PushEvent ( uint32_t EventID, void * Data1, void * Data2 );
		
	private:
		
		friend class Lib;
		
		static std :: vector <void ( * ) ( SDL_UserEvent * )> EventHooks;
		static Mutex * HookMutex;
		
		static uint32_t EventBase;
		
		static void Init ( uint32_t * Status );
		static void EventInternal ( SDL_UserEvent * Event );
		
	};
	
};

#endif
