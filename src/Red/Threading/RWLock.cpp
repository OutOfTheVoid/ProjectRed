#include <Red/Threading/RWLock.h>

Red::Threading::RWLock :: RWLock ():
	ReaderCount ( 0 ),
	ReaderAcquired ( false ),
	LockInternal ()
{	
}

Red::Threading::RWLock :: ~RWLock ()
{
}

void Red::Threading::RWLock :: LockRead ( bool Spin )
{
	
	int32_t PreCount = ReaderCount.fetch_add ( 1, std :: memory_order_relaxed );
	
	if ( PreCount == 0 )
	{
		
		LockInternal.lock ();
		
		ReaderAcquired = true;
		
	}
	else
	{
		
		if ( ! Spin )
		{
			
			while ( ! ReaderAcquired )
				if ( ReaderCount == 0 )
					return LockRead (); // Hopefully this turns into a tail call.
				
			
		}
		else
		{
			
			while ( ! ReaderAcquired )
			{
				
				if ( ReaderCount == 0 )
					return LockRead (); // This too :(
				
				std :: this_thread :: yield ();
				
			}
			
		}
		
	}
	
}

bool Red::Threading::RWLock :: TryLockRead ( bool Spin )
{
	
	int32_t PreCount = ReaderCount.fetch_add ( 1, std :: memory_order_relaxed );
	
	if ( PreCount == 0 )
	{
		
		if ( ! LockInternal.try_lock () )
		{
			
			ReaderCount --;
			
			return false;
			
		}
		
		ReaderAcquired = true;
		
	}
	else
	{
		
		if ( ! Spin )
		{
			
			while ( ! ReaderAcquired )
			{
				
				if ( ReaderCount == 0 )
				{
					
					return TryLockRead ();// Hopefully this turns into a tail call.
					
				}
				
			}
				
			
		}
		else
		{
			
			while ( ! ReaderAcquired )
			{
				
				if ( ReaderCount == 0 )
					return TryLockRead (); // This too :(
				
				std :: this_thread :: yield ();
				
			}
			
		}
		
	}
	
	return true;
	
}

void Red::Threading::RWLock :: UnlockRead ()
{
	
	uint32_t PreCount = ReaderCount.fetch_sub ( 1, std :: memory_order_relaxed );
	
	if ( PreCount == 1 )
	{
		
		ReaderAcquired = false;
		LockInternal.unlock ();
		
	}
	
}

void Red::Threading::RWLock :: LockWrite ()
{
	
	LockInternal.lock ();
	
}

bool Red::Threading::RWLock :: TryLockWrite ()
{
	
	return LockInternal.try_lock ();
	
}

void Red::Threading::RWLock :: UnlockWrite ()
{
	
	LockInternal.unlock ();
	
}
