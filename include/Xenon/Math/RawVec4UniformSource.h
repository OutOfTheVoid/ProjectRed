#ifndef XENON_MATH_RAWVEC4UNIFORMSOURCE_H
#define XENON_MATH_RAWVEC4UNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>
#include <Xenon/Math/Vec4.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/IFloatVec4UniformSource.h>

#include <Red/Util/RefCounted.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class RawVec4UniformSource : public GPU :: IFloatVec4UniformSource, public Red::Util :: RefCounted
		{
		public:
			
			RawVec4UniformSource ( const Vec4 * Source );
			~RawVec4UniformSource ();
			
			void SetSource ( const Vec4 * Source );
			void SetDirty ();
			
			const GLfloat * GetFloatVector () const;
			
			int64_t GetIteration () const;
			
		private:
			
			const Vec4 * Source;
			
			int64_t Iteration;
			
		};
		
	}
	
}

#endif
