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


#endif //__APPLE__
