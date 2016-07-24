#ifndef XENON_MATH_RAWVEC3UNIFORMSOURCE_H
#define XENON_MATH_RAWVEC3UNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>
#include <Xenon/Math/Vec3.h>
#include <Xenon/GPU/GLinclude.h>
#include <Xenon/GPU/IFloatVec3UniformSource.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class RawVec3UniformSource : public GPU :: IFloatVec3UniformSource
		{
		public:
			
			RawVec3UniformSource ( const Vec3 * Source );
			~RawVec3UniformSource ();
			
			void SetSource ( const Vec3 * Source );
			void SetDirty ();
			
			const GLfloat * GetFloatVector () const;
			
			int64_t GetIteration () const;
			
		private:
			
			const Vec3 * Source;
			
			int64_t Iteration;
			
		};
		
	}
	
}

#endif