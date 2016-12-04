#include <Red/Threading/Mutex.h>

Red::Threading::Mutex :: Mutex ()
{	
	
	__Platform_Red_Threading_Mutex_Init ( Mut );
	
}

Red::Threading::Mutex :: ~Mutex ()
{
	
	__Platform_Red_Threading_Mutex_Destroy ( Mut );
	
}

void Red::Threading::Mutex :: Lock ()
{
	
	__Platform_Red_Threading_Mutex_Lock ( Mut );
	
}

bool Red::Threading::Mutex :: TryLock ()
{
	
	return __Platform_Red_Threading_Mutex_TryLock ( Mut );
	
}

void Red::Threading::Mutex :: Unlock ()
{
	
	__Platform_Red_Threading_Mutex_Release ( Mut );
	
}
