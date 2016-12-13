#include <Red/Threading/Platform/Mutex.h>

#ifdef _WIN32

bool __Platform_Red_Threading_Mutex_Init ( __Platform_Mutex_t & Mutex )
{
	
	InitializeCriticalSection ( & Mutex );
	
	return true;
	
}

void __Platform_Red_Threading_Mutex_Destroy ( __Platform_Mutex_t & Mutex )
{
	
	DeleteCriticalSection ( & Mutex );
	
}

bool __Platform_Red_Threading_Mutex_TryLock ( __Platform_Mutex_t & Mutex )
{
	
	__try
	{
		
		return TryEnterCriticalSection ( & Mutex );
		
	}
	__except ( ( GetExceptionCode () == EXCEPTION_POSSIBLE_DEADLOCK ) ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH )
	{
		
		return false;
		
	}
	
}

bool __Platform_Red_Threading_Mutex_Lock ( __Platform_Mutex_t & Mutex )
{
	
	__try
	{
		
		EnterCriticalSection ( & Mutex );
		
	}
	__except ( ( GetExceptionCode () == EXCEPTION_POSSIBLE_DEADLOCK ) ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH )
	{
		
		return false;
		
	}
	
	return true;
	
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
