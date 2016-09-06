#ifndef RED_TEXT_RENDERING_FREETYPE_FONTRENDERER_H
#define RED_TEXT_RENDERING_FREETYPE_FONTRENDERER_H

#include <Red/Options.h>

#ifdef RED_OPT_TEXT_RENDERING_FREETYPE

#include <Red/Text/Rendering/FreeType/FreeType.h>
#include <Red/Text/Rendering/FreeType/FontFace.h>

#include <Red/Text/Rendering/IFontLayoutSource.h>
#include <Red/Text/Rendering/IFontTextureAtlasFactory.h>
#include <Red/Text/Rendering/IFontReference.h>
#include <Red/Text/Rendering/FontRenderData.h>

#include <Red/Util/RefCounted.h>

namespace Red
{
	
	namespace Text
	{
		
		namespace Rendering
		{
			
			namespace FreeType
			{
				
				class FreeTypeFontRenderData : public Util :: RefCounted, public virtual IFontLayoutSource, public virtual IFontTextureAtlasFactory
				{
				public:
					
					static FontRenderData * CreateRenderData ( FontFace * Face, const std :: u32string & CharSet, FontRenderData :: AtlasGenerationMode GenerationMode );
					
					~FreeTypeFontRenderData ();
					
					void GetAdvance ( RawFontTextureAtlas * Atlas, char32_t Current, char32_t Last, double & AdvanceX, double & AdvanceY ) const;
					void GetAdvance ( RawFontTextureAtlas * Atlas, char32_t Last, double & AdvanceX, double & AdvanceY ) const;
					
					void GetOffset ( RawFontTextureAtlas * Atlas, char32_t Current, double & OffsetX, double & OffsetY ) const;
					
					double GetFontHeight ( RawFontTextureAtlas * Atlas ) const;
					
					double GetScalingFactor ( RawFontTextureAtlas * Atlas, double PixelSize ) const;
					
					LayoutDirection GetLayoutDirection () const;
					
					RawFontTextureAtlas * CreateAtlas ( uint32_t PixelSize, const std :: u32string & CharSet, FontRenderData :: AtlasGenerationMode GenerationMode ) const;
						
				private:
					
					FreeTypeFontRenderData ( FontFace * Font );
					
					FontFace * Font;
					
				};
				
			}
			
		}
		
	}
	
}

#endif

#endif
