#ifndef XENON_GPU_IGLCONTEXT_H
#define XENON_GPU_IGLCONTEXT_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>

#include <stdint.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class IGLContext
		{
		public:
			
			static const int32_t kMakeCurrentStatus_Success = 0;
			
			virtual int32_t MakeCurrent () = 0;
			
		};
		
	}
	
}

#endif
