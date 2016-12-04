#ifndef RED_THREADING_PLATFORM_SEMAPHORE_H
#define RED_THREADING_PLATFORM_SEMAPHORE_H

/*
 * Cross plaform semaphore utilities.
 */

#include <stdint.h>

#include <Red/Util/Time.h>

#ifdef __APPLE__
	
	#include <dispatch/dispatch.h>
	
	typedef dispatch_semaphore_t __Platform_Semaphore_t;
	
	#define _PLATFORM_SEMAPHORE_NOSYSV
	
#endif
#ifdef _WIN32
	
	#include <windows.h>
	
	typedef HANDLE __Platform_Semaphore_t;
	
	#define _PLATFORM_SEMAPHORE_NOSYSV
	
#endif
	
#ifndef _PLATFORM_SEMAPHORE_NOSYSV
	
	#include <semaphore.h>
	
	typedef sem_t __Platform_Semaphore_t;
	
#endif

bool __Platform_Red_Threading_Semaphore_Init ( __Platform_Semaphore_t & ToInit, uint32_t ResourceCount );
void __Platform_Red_Threading_Semaphore_Destroy ( __Platform_Semaphore_t & ToDestroy );

bool __Platform_Red_Threading_Semaphore_TryWait ( __Platform_Semaphore_t & Target );
bool __Platform_Red_Threading_Semaphore_TimeoutWait ( __Platform_Semaphore_t & Target, const Red::Util::Time :: Duration & Timeout );
bool __Platform_Red_Threading_Semaphore_Wait ( __Platform_Semaphore_t & Target );

void __Platform_Red_Threading_Semaphore_Post ( __Platform_Semaphore_t & Target, uint32_t PostCount );

#endif
