#ifndef RED_TEXT_RENDERING_IFONTLAYOUTSOURCE_H
#define RED_TEXT_RENDERING_IFONTLAYOUTSOURCE_H

#include <Red/Red.h>
#include <Red/Text/Text.h>
#include <Red/Text/Rendering/Rendering.h>

#include <stdint.h>

namespace Red
{
	
	namespace Text
	{
		
		namespace Rendering
		{
			
			class IFontLayoutSource
			{
			public:
				
				virtual ~IFontLayoutSource ()
				{
				};
				
				int32_t GetAdvance ( char32_t Current, char32_t Last );
				
			};
			
		}
		
	}
	
}

#endif
