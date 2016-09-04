#ifndef RED_TEXT_RENDERING_IFONTTEXTUREATLASFACTORY_H
#define RED_TEXT_RENDERING_IFONTTEXTUREATLASFACTORY_H

#include <Red/Text/Rendering/Rendering.h>

#include <string>

namespace Red
{
	
	namespace Text
	{
		
		namespace Rendering
		{
			
			class RawFontTextureAtlas;
			
			class IFontTextureAtlasFactory
			{
			public:
				
				virtual inline ~IFontTextureAtlasFactory ()
				{
				};
				
				virtual RawFontTextureAtlas * CreateAtlas ( double PixelSize, const std :: u32string & CharSet ) = 0;
				
			};
			
		}
		
	}
	
}

#endif
