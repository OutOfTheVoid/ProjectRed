#ifndef XENON_GPU_IMATRIX3X3UNIFORMSOURCE_H
#define XENON_GPU_IMATRIX3X3UNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/GLInclude.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class IMatrix3x3UniformSource
		{
		public:
			
			virtual const GLfloat * GetFloatArray () const = 0;
			virtual bool IsTransposed () const = 0;
			
			virtual int64_t GetIteration () const = 0;
			
		};
		
	}
	
}

#endif
