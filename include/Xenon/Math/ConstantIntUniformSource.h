#ifndef XENON_MATH_CONSTANTINTUNIFORMSOURCE_H
#define XENON_MATH_CONSTANTINTUNIFORMSOURCE_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>
#include <Xenon/GPU/IIntUniformSource.h>
#include <Xenon/GPU/GLInclude.h>

#include <Red/Util/RefCounted.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class ConstantIntUniformSource : public GPU :: IIntUniformSource, public Red::Util :: RefCounted
		{
		public:
			
			ConstantIntUniformSource ( GLint Value );
			~ConstantIntUniformSource ();
			
			GLint GetValue () const;
			void Write ( GLint Value );
			
			int64_t GetIteration () const;
			
		private:
			
			GLint Value;
			
			int64_t Iteration;
			
		};
		
	}
	
}

#endif
