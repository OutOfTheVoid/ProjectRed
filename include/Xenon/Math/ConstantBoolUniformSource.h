#ifndef XENON_MATH_CONSTANTBOOLUNIFORMSOURCE_H
#define XENON_MATH_CONSTANTBOOLUNIFORMSOURCE_H

#include <Xenon/Math/Math.h>
#include <Xenon/GPU/IBoolUniformSource.h>

#include <Red/Util/RefCounted.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class ConstantBoolUniformSource : public GPU :: IBoolUniformSource, public Red::Util :: RefCounted
		{
		public:
			
			ConstantBoolUniformSource ( GLboolean Value );
			~ConstantBoolUniformSource ();
			
			GLboolean GetValue () const;
			void Write ( GLboolean Value );
			
			int64_t GetIteration () const;
			
		private:
			
			GLboolean Value;
			
			int64_t Iteration;
			
		};
		
	}
	
}

#endif
