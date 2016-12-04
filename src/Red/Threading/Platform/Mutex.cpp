#include <Red/Threading/Platform/Mutex.h>

#ifdef _WIN32

bool __Platform_Red_Threading_Mutex_Init ( __Platform_Mutex_t & Mutex )
{
	
	Mutex = CreateMutex ( NULL, false, NULL );
	
	return Mutex != NULL;
	
}

void __Platform_Red_Threading_Mutex_Destroy ( __Platform_Mutex_t & Mutex )
{
	
	CloseHandle ( Mutex );
	
}

bool __Platform_Red_Threading_Mutex_TryLock ( __Platform_Mutex_t & Mutex )
{
	
	return WaitForSingleObject ( Mutex, 0 ) == WAIT_OBJECT_0;
	
}

bool __Platform_Red_Threading_Mutex_Lock ( __Platform_Mutex_t & Mutex )
{
	
	return WaitForSingleObject ( Mutex, INFINITE ) == WAIT_OBJECT_0;
	
}

void __Platform_Red_Threading_Mutex_Release ( __Platform_Mutex_t & Mutex )
{
	
	ReleaseMutex ( Mutex );
	
}

#else

bool __Platform_Red_Threading_Mutex_Init ( __Platform_Mutex_t & Mutex )
{
	
	return pthread_mutex_init ( & Mutex, NULL ) == 0;
		
}

void __Platform_Red_Threading_Mutex_Destroy ( __Platform_Mutex_t & Mutex )
{
	
	pthread_mutex_destroy ( & Mutex );
	
}

bool __Platform_Red_Threading_Mutex_TryLock ( __Platform_Mutex_t & Mutex )
{
	
	return pthread_mutex_trylock ( & Mutex ) == 0;
	
}

bool __Platform_Red_Threading_Mutex_Lock ( __Platform_Mutex_t & Mutex )
{
	
	return pthread_mutex_lock ( & Mutex ) == 0;
	
}

void __Platform_Red_Threading_Mutex_Release ( __Platform_Mutex_t & Mutex )
{
	
	pthread_mutex_unlock ( & Mutex );
	
}

#endif
