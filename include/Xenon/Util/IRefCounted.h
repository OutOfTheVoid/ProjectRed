#ifndef XENON_UTIL_IREFCOUNTED_H
#define XENON_UTIL_IREFCOUNTED_H

#include <Xenon/Xenon.h>
#include <Xenon/Util/Util.h>

namespace Xenon
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
