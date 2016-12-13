#ifndef RED_UTIL_UID_H
#define RED_UTIL_UID_H

#include <Red/Util/Util.h>

#include <stdint.h>
#include <atomic>

namespace Red
{
	
	namespace Util
	{
		
		class UID
		{
		public:
			
			typedef uint64_t UID_t;
			
			static UID_t Generate ();
			
		private:
			
			static std :: atomic <uint64_t> CurrentTop;
			
		};
		
	}
	
}

#endif
