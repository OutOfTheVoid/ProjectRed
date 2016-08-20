#ifndef RED_THREADING_TIME_H
#define RED_THREADING_TIME_H

#include <Red/Red.h>
#include <Red/Threading/Threading.h>

#include <chrono>

namespace Red
{
	
	namespace Threading
	{
		
		namespace Time
		{
			
			class Duration
			{
			public:
				
				Duration ( uint64_t Seconds, uint64_t NanoSeconds = 0 );
				Duration ( double Seconds );
				~Duration ();
				
				int64_t GetNanoSeconds ();
				int64_t GetSeconds ();
				
				double GetFPSeconds ();
				
			private:
				
				friend void BlockFor ( const Duration & TimeSpan );
				
				std::chrono :: seconds Seconds;
				std::chrono :: nanoseconds NanoSeconds;
				
			};
			
			void BlockFor ( const Duration & TimeSpan );
			
		}
		
	}
	
}

#endif
