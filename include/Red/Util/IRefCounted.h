#ifndef RED_UTIL_IREFCOUNTED_H
#define RED_UTIL_IREFCOUNTED_H

#include <Red/Red.h>
#include <Red/Util/Util.h>

namespace Red
{
	
	namespace Util
	{
		
		class IRefCounted
		{
		public:
				
			virtual void Reference () = 0;
			virtual void Dereference () = 0;
			
		};
		
	}
	
}

#endif
