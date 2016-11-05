#ifndef XENON_GPU_IFLOATVEC2UNIFORMSOURCE_H
#define XENON_GPU_IFLOATVEC2UNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/GLInclude.h>
#include <Red/Util/IRefCounted.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class IFloatVec2UniformSource : public virtual Red::Util :: IRefCounted
		{
		public:
			
			virtual const GLfloat * GetFloatVector () const = 0;
			
			virtual int64_t GetIteration () const = 0;
			
		};
		
	}
	
}

#endif
