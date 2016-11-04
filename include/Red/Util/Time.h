#ifndef RED_THREADING_TIME_H
#define RED_THREADING_TIME_H

#include <Red/Util/Util.h>

#include <chrono>

namespace Red
{
	
	namespace Util
	{
		
		namespace Time
		{
			
			class Duration
			{
			public:
				
				explicit Duration ( uint64_t Seconds, uint64_t NanoSeconds );
				explicit Duration ( double Seconds );
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
