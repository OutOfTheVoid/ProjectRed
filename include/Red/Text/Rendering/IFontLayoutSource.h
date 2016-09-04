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
				
				enum LayoutDirection
				{
					
					kLayoutDirection_HorizontalRightward,
					kLayoutDirection_HorizontalLeftward,
					kLayoutDirection_Downward
					
				};
				
				virtual ~IFontLayoutSource ()
				{
				};
				
				virtual double GetUnitAdvanceX ( char32_t Current, char32_t Last ) const = 0;
				virtual double GetUnitAdvanceX ( char32_t Current ) const = 0;
				virtual double GetUnitAdvanceY ( char32_t Current ) const = 0;
				
				virtual double GetUnitOffsetX ( char32_t Current ) const = 0;
				virtual double GetUnitOffsetY ( char32_t Current ) const = 0;
				
				virtual double GetUnitFontHeight () const = 0;
				
				virtual double GetPointScaleFactor ( double PointSize ) const = 0;
				virtual double GetPixelScaleFactor ( double PixelSize ) const = 0;
				
				virtual LayoutDirection GetLayoutDirection () const = 0;
								
			};
			
		}
		
	}
	
}

#endif
