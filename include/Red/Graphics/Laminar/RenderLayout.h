#ifndef RED_GRAPHICS_LAMINAR_RENDERLAYOUT_H
#define RED_GRAPHICS_LAMINAR_RENDERLAYOUT_H

#include <Red/Graphics/Laminar/Laminar.h>

#include <Xenon/Math/Vec2.h>

namespace Red
{
	
	namespace Graphics
	{
		
		namespace Laminar
		{
			
			class RenderLayout
			{
			public:
				
				typedef enum
				{
					
					kRenderMode_Overlay = 0;
					kRenderMode_Add = 1;
					kRenderMode_Subtract = 2;
					kRenderMode_Multiply = 3;
					kRenderMode_Max = 4;
					kRenderMode_Min = 5;
					kRenderMode_Mask = 6;
					
				} RenderMode;
				
				RenderLayout ( RenderMode Mode, bool ZSortRequired, const Xenon::Math :: Vec2 & SpriteArea, const Xenon::Math :: Vec2 & BaseCoordinateOffset );
				~RenderLayout ();
				
				RenderMode GetRenderMode () const;
				
				bool GetZSortRequired () const;
				
				const Vec2 & GetSpriteArea () const;
				const Vec2 & GetBaseCoordinateOffset () const;
				
			private:
				
				RenderMode Mode;
				bool ZSortRequired;
				
				Xenon::Math :: Vec2 SpriteArea;
				Xenon::Math :: Vec2 BaseCoordinateOffset;
				
			}
			
		}
		
	}
	
}

#endif
