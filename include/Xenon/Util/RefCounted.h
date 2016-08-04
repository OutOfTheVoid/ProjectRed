#ifndef XENON_UTIL_REFCOUNTED_H
#define XENON_UTIL_REFCOUNTED_H

#include <Xenon/Xenon.h>
#include <Xenon/Util/Util.h>

#include <Xenon/Util/IRefCounted.h>

#include <atomic>

namespace Xenon
{
	
	namespace Util
	{
		
		class RefCounted : public virtual IRefCounted
		{
		public:
			
			inline RefCounted ( uint32_t RefCountInitial = 0 ):
				RefCount ( RefCountInitial )
			{
			};
			
			inline virtual ~RefCounted ()
			{
			};
			
			inline void Reference ()
			{
				
				RefCount ++;
				
			};
			
			inline void Dereference ()
			{
				
				RefCount --;
				
				if ( RefCount == 0 )
					delete this;
				
			};
			
		protected:
			
			std::atomic <uint32_t> RefCount;
			
		};
		
	}
	
}

#endif
