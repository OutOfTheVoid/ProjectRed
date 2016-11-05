#ifndef XENON_MATH_RAWMATRIX3X3UNIFORMSOURCE_H
#define XENON_MATH_RAWMATRIX3X3UNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>
#include <Xenon/Math/Matrix3x3.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/IMatrix3x3UniformSource.h>

#include <Red/Util/RefCounted.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class RawMatrix3x3UniformSource : public GPU :: IMatrix3x3UniformSource, public Red::Util :: RefCounted
		{
		public:
			
			RawMatrix3x3UniformSource ( const Matrix3x3 * Source, bool Transposed );
			~RawMatrix3x3UniformSource ();
			
			void SetSource ( const Matrix3x3 * Source, bool Transposed );
			void SetDirty ();
			
			const GLfloat * GetFloatArray () const;
			
			bool IsTransposed () const;
			
			int64_t GetIteration () const;
			
		private:
			
			const Matrix3x3 * Source;
			bool Transposed;
			
			int64_t Iteration;
			
		};
		
	}
	
}

#endif
