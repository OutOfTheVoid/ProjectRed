#include <Red/Threading/Platform/Semaphore.h>

#ifdef __APPLE__

bool __Platform_Red_Threading_Semaphore_Init ( __Platform_Semaphore_t & ToInit, uint32_t ResourceCount )
{
	
	ToInit = dispatch_semaphore_create ( ResourceCount );
	
	return ToInit != NULL;
	
}

void __Platform_Red_Threading_Semaphore_Destroy ( __Platform_Semaphore_t & ToDestroy )
{
	
	dispatch_release ( ToDestroy );
	
	ToDestroy = NULL;
	
}

bool __Platform_Red_Threading_Semaphore_TryWait ( __Platform_Semaphore_t & Target )
{
	
	return dispatch_semaphore_wait ( Target, DISPATCH_TIME_NOW ) == 0;
	
}

bool __Platform_Red_Threading_Semaphore_TimeoutWait ( __Platform_Semaphore_t & Target, const Red::Util::Time :: Duration & Timeout )
{
	
	dispatch_time_t Delta = dispatch_time ( DISPATCH_TIME_NOW, Timeout.GetTotalNanoSeconds () );
	
	return dispatch_semaphore_wait ( Target, Delta ) != 0;
	
}

bool __Platform_Red_Threading_Semaphore_Wait ( __Platform_Semaphore_t & Target )
{
	
	return dispatch_semaphore_wait ( Target, DISPATCH_TIME_FOREVER ) != 0;
	
}

void __Platform_Red_Threading_Semaphore_Post ( __Platform_Semaphore_t & Target, uint32_t PostCount )
{
	
	for ( uint32_t I = 0; I < PostCount; I ++ )
		dispatch_semaphore_signal ( Target );
	
}

#endif //__APPLE__

#ifdef _WIN32

bool __Platform_Red_Threading_Semaphore_Init ( __Platform_Semaphore_t & ToInit, uint32_t ResourceCount )
{
	
	ToInit = CreateSemaphore ( NULL, ResourceCount, 0xFFFFFFFF, NULL );
	
	return ToInit != NULL;
	
}

void __Platform_Red_Threading_Semaphore_Destroy ( __Platform_Semaphore_t & ToDestroy )
{
	
	CloseHandle ( ToDestroy );
	
}

bool __Platform_Red_Threading_Semaphore_TryWait ( __Platform_Semaphore_t & Target )
{
	
	return WaitForSingleObject ( Target, 0 ) == WAIT_OBJECT_0;
	
}

bool __Platform_Red_Threading_Semaphore_TimeoutWait ( __Platform_Semaphore_t & Target, const Red::Util::Time :: Duration & Timeout )
{
	
	return WaitForSingleObject ( Target, Timeout.GetTotalNanoSeconds () / 1000000 ) == WAIT_OBJECT_0;
	
}

bool __Platform_Red_Threading_Semaphore_Wait ( __Platform_Semaphore_t & Target )
{
	
	return WaitForSingleObject ( Target, INFINITE ) == WAIT_OBJECT_0;
	
}

void __Platform_Red_Threading_Semaphore_Post ( __Platform_Semaphore_t & Target, uint32_t PostCount )
{
	
	ReleaseSemaphore ( Target, PostCount, NULL );
	
}

#endif

#ifndef _PLATFORM_SEMAPHORE_NOSYSV

#include <time.h>

bool __Platform_Red_Threading_Semaphore_Init ( __Platform_Semaphore_t & ToInit, uint32_t ResourceCount )
{
	
	return sem_init ( & ToInit, 0, ResourceCount ) != - 1;
	
}

void __Platform_Red_Threading_Semaphore_Destroy ( __Platform_Semaphore_t & ToDestroy )
{
	
	sem_destroy ( & ToDestroy );
	
}

bool __Platform_Red_Threading_Semaphore_TryWait ( __Platform_Semaphore_t & Target )
{
	
	return sem_trywait ( & Target ) == 0;
	
}

bool __Platform_Red_Threading_Semaphore_TimeoutWait ( __Platform_Semaphore_t & Target, const Red::Util::Time :: Duration & Timeout )
{
	
	struct timespec Delta;
	
	if ( clock_gettime ( CLOCK_REALTIME, & Delta ) == - 1 )
		return false;
	
	Delta.tv_nsec += static_cast <long> ( Timeout.GetNanoSeconds () );
	Delta.tv_sec += static_cast <time_t> ( Timeout.GetSeconds () );
	
	if ( Delta.tv_nsec > 1000000000 )
	{
		
		Delta.tv_sec ++;
		Delta.tv_nsec -= 1000000000;
		
	}
	
	return sem_timedwait ( & Target, & Delta ) == 0;
	
}

bool __Platform_Red_Threading_Semaphore_Wait ( __Platform_Semaphore_t & Target )
{
	
	return sem_wait ( & Target ) == 0;
	
}

void __Platform_Red_Threading_Semaphore_Post ( __Platform_Semaphore_t & Target, uint32_t PostCount )
{
	
	sem_post ( & Target, PostCount );
	
}

#endif // ! _PLATFORM_SEMAPHORE_NOSYSV
