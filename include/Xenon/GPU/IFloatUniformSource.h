#ifndef XENON_GPU_IFLOATUNIFORMSOURCE_H
#define XENON_GPU_IFLOATUNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/GLInclude.h>
#include <Red/Util/IRefCounted.h>

#include <stdint.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class IFloatUniformSource : public virtual Red::Util :: IRefCounted
		{
		public:
			
			virtual GLfloat GetValue () const = 0;
			
			virtual int64_t GetIteration () const = 0;
			
		};
		
	}
	
}

#endif
