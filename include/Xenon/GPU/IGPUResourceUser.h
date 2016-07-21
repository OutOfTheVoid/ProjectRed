#ifndef XENON_GPU_IGPURESOURCEUSER_H
#define XENON_GPU_IGPURESOURCEUSER_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class IGPUResourceUser
		{
		public:
			
			virtual void GPUResourceAlloc () = 0;
			virtual void GPUResourceFree () = 0;
			
			virtual bool GPUResourceAllocated () = 0;
			
		};
		
	}
	
}

#endif
