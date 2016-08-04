#ifndef XENON_GPU_IMATRIX4X4UNIFORMSOURCE_H
#define XENON_GPU_IMATRIX4X4UNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/Util/IRefCounted.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class IMatrix4x4UniformSource : public virtual Util :: IRefCounted
		{
		public:
			
			virtual const GLfloat * GetFloatArray () const = 0;
			virtual bool IsTransposed () const = 0;
			
			virtual int64_t GetIteration () const = 0;
			
		};
		
	}
	
}

#endif
