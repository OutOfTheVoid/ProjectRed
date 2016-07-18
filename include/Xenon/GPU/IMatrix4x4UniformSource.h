#ifndef XENON_GPU_IMATRIX4X4UNIFORMSOURCE_H
#define XENON_GPU_IMATRIX4X4UNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/GLInclude.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class IMatrix4x4UniformSource
		{
		public:
			
			virtual const GLfloat * GetFloatArray () const = 0;
			virtual const bool IsTransposed () const = 0;
			
			virtual int64_t GetIteration () const = 0;
			
		};
		
	};
	
};

#endif
