#ifndef RED_UTIL_REFCOUNTED_H
#define RED_UTIL_REFCOUNTED_H

#include <Red/Util/Util.h>

#include <Red/Util/IRefCounted.h>

#include <atomic>

namespace Red
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
			
			inline RefCounted ( const RefCounted & CopyFrom ):
				RefCount ( CopyFrom.RefCount.load () )
			{
			};
			
			inline ~RefCounted ()
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
