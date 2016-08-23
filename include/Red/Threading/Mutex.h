#ifndef RED_THREADING_MUTEX_H
#define RED_THREADING_MUTEX_H

#include <Red/Red.h>
#include <Red/Threading/Threading.h>

namespace Red
{
	
	namespace Threading
	{
		
		class Mutex
		{
		public:
			
			Mutex ();
			~Mutex ();
			
			void Lock ();
			bool TryLock ();
			void Unlock ();
			
		private:
			
			std :: mutex Mut;
			
		}
		
	}
	
}

#endif
