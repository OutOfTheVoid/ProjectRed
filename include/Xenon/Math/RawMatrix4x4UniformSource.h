#ifndef XENON_MATH_RAWMATRIX4X4UNIFORMSOURCE_H
#define XENON_MATH_RAWMATRIX4X4UNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>
#include <Xenon/Math/Matrix4x4.h>
#include <Xenon/GPU/GLinclude.h>
#include <Xenon/GPU/IMatrix4x4UniformSource.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class RawMatrix4x4UniformSource : public GPU :: IMatrix4x4UniformSource
		{
		public:
			
			RawMatrix4x4UniformSource ( const Matrix4x4 * Source, bool Transposed );
			~RawMatrix4x4UniformSource ();
			
			void SetSource ( const Matrix4x4 * Source, bool Transposed );
			void SetDirty ();
			
			const GLfloat * GetFloatArray () const;
			
			const bool IsTransposed () const;
			
			int64_t GetIteration () const;
			
		private:
			
			const Matrix4x4 * Source;
			bool Transposed;
			
			int64_t Iteration;
			
		};
		
	};
	
};

#endif
