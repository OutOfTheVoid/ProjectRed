#ifndef XENON_RENDERING_IDEPENDANCY_H
#define XENON_RENDERING_IDEPENDANCY_H

#include <Xenon/Xenon.h>
#include <Xenon/Rendering/Rendering.h>

namespace Xenon
{
	
	namespace Rendering
	{
		
		class DependancyPassBlock;
		
		class IRenderDependancy
		{
		public:
			
			virtual int64_t GetCurrentSatisfiedIteration () = 0;
			
			void Reset ( DependancyPassBlock * Pass ) = 0;
			
			uint32_t GetSubDependancyCount ();
			IRenderDependancy * GetSubDependancy ( uint32_t Index );
			
		};
		
	};
	
};

#endif
