#ifndef RED_THREADING_SEMAPHORE_H
#define RED_THREADING_SEMAPHORE_H

#include <Red/Threading/Threading.h>
#include <Red/Threading/Platform/Semaphore.h>

#include <Red/Util/Time.h>

#include <stdint.h>

namespace Red
{
	
	namespace Threading
	{
		
		class Semaphore
		{
		public:
			
			Semaphore ( uint32_t InitialCount );
			~Semaphore ();
			
			void Take ();
			bool TryTake ();
			
			bool TimedTake ( const Util::Time :: Duration & Timeout );
			
			void Post ( uint32_t Count = 1 );
			
		private:
			
			__Platform_Semaphore_t Sem;
			
		};
		
	}
	
}

#endif
