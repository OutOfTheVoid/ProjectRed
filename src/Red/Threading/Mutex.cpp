#include <Red/Threading/Mutex.h>

Red::Threading::Mutex :: Mutex ():
	Mut ()
{	
}

Red::Threading::Mutex :: ~Mutex ()
{
}

void Red::Threading::Mutex :: Lock ()
{
	
	Mut.lock ();
	
}

bool Red::Threading::Mutex :: TryLock ()
{
	
	return Mut.try_lock ();
	
}

void Red::Threading::Mutex :: Unlock ()
{
	
	Mut.unlock ();
	
}
