#ifndef XENON_MATH_RAWFLOATUNIFORMSOURCE_H
#define XENON_MATH_RAWFLOATUNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>

#include <Xenon/GPU/IFloatUniformSource.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class RawFloatUniformSource : public GPU :: IFloatUniformSource
		{
		public:
			
			RawFloatUniformSource ( GLfloat ValueInitial );
			~RawFloatUniformSource ();
			
			void SetValue ( GLfloat Value );
			
			const GLfloat GetValue () const;
			
			int64_t GetIteration () const;
			
		private:
			
			GLfloat Value;
			
			int64_t Iteration;
			
		};
		
	};
	
};

#endif
