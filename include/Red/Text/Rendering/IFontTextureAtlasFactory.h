#ifndef RED_TEXT_RENDERING_IFONTTEXTUREATLASFACTORY_H
#define RED_TEXT_RENDERING_IFONTTEXTUREATLASFACTORY_H

#include <Red/Text/Rendering/Rendering.h>
#include <Red/Text/Rendering/FontRenderData.h>

#include <Red/Util/IRefCounted.h>

#include <string>

namespace Red
{
	
	namespace Text
	{
		
		namespace Rendering
		{
			
			class RawFontTextureAtlas;
			
			class IFontTextureAtlasFactory : public virtual Util :: IRefCounted
			{
			public:
				
				virtual inline ~IFontTextureAtlasFactory ()
				{
				};
				
				virtual RawFontTextureAtlas * CreateAtlas ( uint32_t PixelSize, const std :: u32string & CharSet, FontRenderData :: AtlasGenerationMode ) const = 0;
				
			};
			
		}
		
	}
	
}

#endif
