#ifndef XENON_MATH_RAWVEC2UNIFORMSOURCE_H
#define XENON_MATH_RAWVEC2UNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>
#include <Xenon/Math/Vec2.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/IFloatVec2UniformSource.h>

#include <Red/Util/RefCounted.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class RawVec2UniformSource : public GPU :: IFloatVec2UniformSource, public Red::Util :: RefCounted
		{
		public:
			
			RawVec2UniformSource ( const Vec2 * Source );
			~RawVec2UniformSource ();
			
			void SetSource ( const Vec2 * Source );
			void SetDirty ();
			
			const GLfloat * GetFloatVector () const;
			
			int64_t GetIteration () const;
			
		private:
			
			const Vec2 * Source;
			
			int64_t Iteration;
			
		};
		
	}
	
}

#endif
