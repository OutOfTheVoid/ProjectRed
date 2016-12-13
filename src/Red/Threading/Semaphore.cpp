#include <Red/Threading/Semaphore.h>

Red::Threading::Semaphore :: Semaphore ( uint32_t InitialCount )
{
	
	__Platform_Red_Threading_Semaphore_Init ( Sem, InitialCount );
	
}

Red::Threading::Semaphore :: ~Semaphore ()
{
	
	__Platform_Red_Threading_Semaphore_Destroy ( Sem );
	
}

void Red::Threading::Semaphore :: Take ()
{
	
	__Platform_Red_Threading_Semaphore_Wait ( Sem );
	
}

bool Red::Threading::Semaphore :: TryTake ()
{
	
	return __Platform_Red_Threading_Semaphore_TryWait ( Sem );
	
}

bool Red::Threading::Semaphore :: TimedTake ( const Util::Time :: Duration & Timeout )
{
	
	return __Platform_Red_Threading_Semaphore_TimeoutWait ( Sem, Timeout );
	
}

void Red::Threading::Semaphore :: Post ( uint32_t Count )
{
	
	__Platform_Red_Threading_Semaphore_Post ( Sem, Count );
	
}