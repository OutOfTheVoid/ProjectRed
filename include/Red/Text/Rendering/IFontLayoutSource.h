#ifndef RED_TEXT_RENDERING_IFONTLAYOUTSOURCE_H
#define RED_TEXT_RENDERING_IFONTLAYOUTSOURCE_H

#include <Red/Text/Rendering/Rendering.h>

#include <Red/Util/IRefCounted.h>

#include <stdint.h>

namespace Red
{
	
	namespace Text
	{
		
		namespace Rendering
		{
			
			class IFontLayoutSource : public Util :: IRefCounted
			{
			public:
				
				virtual ~IFontLayoutSource ()
				{
				};
				
				virtual int32_t GetAdvanceX ( char32_t Current, char32_t Last ) = 0;
				virtual int32_t GetAdvanceX ( char32_t Current ) = 0;
				virtual int32_t GetAdvanceY ( char32_t Current ) = 0;
				
				virtual int32_t GetOffsetX ( char32_t Current ) = 0;
				virtual int32_t GetOffsetY ( char32_t Current ) = 0;
								
			};
			
		}
		
	}
	
}

#endif
