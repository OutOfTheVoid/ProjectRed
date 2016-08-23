#ifndef XENON_MATH_CONSTANTUINTUNIFORMSOURCE_H
#define XENON_MATH_CONSTANTUINTUNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>
#include <Xenon/GPU/IUIntUniformSource.h>
#include <Xenon/GPU/GLInclude.h>

#include <Red/Util/RefCounted.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class ConstantUIntUniformSource : public GPU :: IUIntUniformSource, public Red::Util :: RefCounted
		{
		public:
			
			ConstantUIntUniformSource ( GLuint Value );
			~ConstantUIntUniformSource ();
			
			GLuint GetValue () const;
			void Write ( GLuint Value );
			
			int64_t GetIteration () const;
			
		private:
			
			GLuint Value;
			
			int64_t Iteration;
			
		};
		
	}
	
}

#endif
