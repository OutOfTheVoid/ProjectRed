#ifndef XENON_GPU_IUINTUNIFORMSOURCE_H
#define XENON_GPU_IUINTUNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/GLinclude.h>
#include <Xenon/Util/IRefCounted.h>

#include <stdint.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class IUIntUniformSource : public virtual Util :: IRefCounted
		{
		public:
			
			virtual GLuint GetValue () const = 0;
			
			virtual int64_t GetIteration () const = 0;
			
		};
		
	}
	
}

#endif
