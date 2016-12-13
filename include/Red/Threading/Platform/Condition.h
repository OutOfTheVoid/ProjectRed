#ifndef RED_THREADING_PLATFORM_CONDITION_H
#define RED_THREADING_PLATFORM_CONDITION_H

#include <Red/Threading/Platform/Mutex.h>

#ifdef _WIN32
	
	#include <windows.h>
	
	typedef CONDITION_VARIABLE __Platform_Condition_t;
	
#else
	
	#include <pthread.h>
	
	typedef pthread_cond_t __Platform_Condition_t;
	
#endif

void __Red_Threading_Platform_Condition_Init ( __Platform_Condition_t & Condition );
void __Red_Threading_Platform_Condition_Destroy ( __Platform_Condition_t & Condition );

void __Red_Threading_Platform_Condition_Wait ( __Platform_Condition_t & Condition, __Platform_Mutex_t & Mutex );
void __Red_Threading_Platform_Condition_Signal ( __Platform_Condition_t & Condition );
void __Red_Threading_Platform_Condition_Broadcast ( __Platform_Condition_t & Condition );

#endif
