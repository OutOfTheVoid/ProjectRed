#ifndef RED_THREADING_RWLOCK_H
#define RED_THREADING_RWLOCK_H

#include <Red/Threading/Threading.h>

#include <atomic>
#include <mutex>
#include <thread>

namespace Red
{
	
	namespace Threading
	{
		
		class RWLock
		{
		public:
			
			RWLock ();
			~RWLock ();
			
			void LockRead ( bool Spin = false );
			bool TryLockRead ( bool Spin = false );
			void UnlockRead ();
			
			void LockWrite ();
			bool TryLockWrite ();
			void UnlockWrite ();
			
		private:
			
			std :: atomic <int32_t> ReaderCount;
			std :: atomic <bool> ReaderAcquired;
			
			std :: mutex LockInternal;
			
		};
		
	}
	
}

#endif
