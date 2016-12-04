#ifndef RED_THREADING_PLATFORM_MUTEX_H
#define RED_THREADING_PLATFORM_MUTEX_H

#include <stdint.h>

#include <Red/Util/Time.h>

/*
 * Cross plaform mutex utilities.
 */

#ifdef _WIN32
	
	#include <windows.h>
	
	typedef HANDLE __Platform_Mutex_t;
	
#else

	#include <pthread.h>
	
	typedef pthread_mutex_t __Platform_Mutex_t;
	
#endif

bool __Platform_Red_Threading_Mutex_Init ( __Platform_Mutex_t & Mutex );
void __Platform_Red_Threading_Mutex_Destroy ( __Platform_Mutex_t & Mutex );

bool __Platform_Red_Threading_Mutex_TryLock ( __Platform_Mutex_t & Mutex );
bool __Platform_Red_Threading_Mutex_Lock ( __Platform_Mutex_t & Mutex );

void __Platform_Red_Threading_Mutex_Release ( __Platform_Mutex_t & Mutex );

#endif
