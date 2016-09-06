#ifndef RED_TEXT_RENDERING_IFONTLAYOUTSOURCE_H
#define RED_TEXT_RENDERING_IFONTLAYOUTSOURCE_H

#include <Red/Text/Rendering/Rendering.h>
#include <Red/Text/Rendering/RawFontTextureAtlas.h>

#include <Red/Util/IRefCounted.h>

#include <stdint.h>

namespace Red
{
	
	namespace Text
	{
		
		namespace Rendering
		{
			
			class IFontLayoutSource : public virtual Util :: IRefCounted
			{
			public:
				
				enum LayoutDirection
				{
					
					kLayoutDirection_Horizontal,
					kLayoutDirection_Vertical
					
				};
				
				virtual ~IFontLayoutSource ()
				{
				};
				
				virtual void GetAdvance ( RawFontTextureAtlas * Atlas, char32_t Current, char32_t Last, double & AdvanceX, double & AdvanceY ) const = 0;
				virtual void GetAdvance ( RawFontTextureAtlas * Atlas, char32_t Last, double & AdvanceX, double & AdvanceY ) const = 0;
				
				virtual void GetOffset ( RawFontTextureAtlas * Atlas, char32_t Current, double & OffsetX, double & OffsetY ) const = 0;
				
				virtual double GetFontHeight ( RawFontTextureAtlas * Atlas ) const = 0;
				
				virtual double GetScalingFactor ( RawFontTextureAtlas * Atlas, double PixelSize ) const = 0;
				
				virtual LayoutDirection GetLayoutDirection () const = 0;
								
			};
			
		}
		
	}
	
}

#endif
