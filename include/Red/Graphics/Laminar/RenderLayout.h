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
			
			class Renderer;
			
			class RenderLayout
			{
			public:
				
				RenderLayout ( RenderMode Mode, const Xenon::Math :: Vec2 & SpriteArea, const Xenon::Math :: Vec2 & BaseCoordinateOffset );
				RenderLayout ( const RenderLayout & Layout );
				~RenderLayout ();
				
				RenderMode GetRenderMode () const;
				
				const Xenon::Math :: Vec2 & GetSpriteArea () const;
				const Xenon::Math :: Vec2 & GetBaseCoordinateOffset () const;
				
			private:
				
				friend class Renderer;
				
				RenderMode Mode;
				
				Xenon::Math :: Vec2 SpriteArea;
				Xenon::Math :: Vec2 BaseCoordinateOffset;
				
			};
			
		}
		
	}
	
}

#endif
