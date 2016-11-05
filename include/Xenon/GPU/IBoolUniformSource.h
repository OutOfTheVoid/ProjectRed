#ifndef XENON_GPU_IBOOLUNIFORMSOURCE_H
#define XENON_GPU_IBOOLUNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/GLInclude.h>
#include <Red/Util/IRefCounted.h>

#include <stdint.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class IBoolUniformSource : public virtual Red::Util :: IRefCounted
		{
		public:
			
			virtual GLboolean GetValue () const = 0;
			
			virtual int64_t GetIteration () const = 0;
			
		};
		
	}
	
}

#endif
