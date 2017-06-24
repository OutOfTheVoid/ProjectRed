#ifndef XENON_ITEXURE_H
#define XENON_ITEXURE_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/IGPUResourceUser.h>
#include <Xenon/GPU/GLInclude.h>

#include <Red/Util/IRefCounted.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class ITexture : public virtual IGPUResourceUser, public virtual Red::Util :: IRefCounted
		{
		public:
			
			virtual void GPUResourceAlloc () = 0;
			virtual void GPUResourceFree () = 0;
			
			virtual bool GPUResourceAllocated () = 0;
			
			virtual void Bind () = 0;
			
			virtual void AssignToTextureUnit ( GLuint ) = 0;
			
		};
		
	}
	
}

#endif
