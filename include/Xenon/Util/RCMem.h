#ifndef XENON_UTIL_RCMEM_H
#define XENON_UTIL_RCMEM_H

#include <Xenon/Xenon.h>
#include <Xenon/Util/Util.h>

#include <Red/Util/RefCounted.h>

#include <stdint.h>
#include <stdlib.h>

namespace Xenon
{
	
	namespace Util
	{
		
		class RCMem : public Red::Util :: RefCounted
		{
		public:
			
			inline RCMem ( size_t Size ):
				RefCounted ( 0 ),
				Data ( malloc ( Size ) ),
				Delete ( & free )
			{	
			};
			
			inline RCMem ( void * Data, void ( * Delete ) ( void * ) ):
				RefCounted ( 1 ),
				Data ( Data ),
				Delete ( Delete )
			{
			};
			
			inline ~RCMem ()
			{
			
				if ( Data != NULL )
					Delete ( Data );
	
				Data = NULL;
				
			};
			
			inline void * GetData ()
			{
				
				return Data;
				
			};
			
		private:
			
			void * Data;
			
			void ( * Delete ) ( void * );
			
		};
		
	}
	
}

#endif
