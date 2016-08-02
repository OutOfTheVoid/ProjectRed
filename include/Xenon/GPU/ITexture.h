#ifndef XENON_ITEXURE_H
#define XENON_ITEXURE_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/IGPUResourceUser.h>
#include <Xenon/Util/IRefCounted.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class ITexture : public IGPUResourceUser, public Util :: IRefCounted
		{
		public:
			
			virtual void GPUResourceAlloc () = 0;
			virtual void GPUResourceFree () = 0;
			
			virtual bool GPUResourceAllocated () = 0;
			
			virtual void Bind () = 0;
			
		};
		
	}
	
}

#endif
