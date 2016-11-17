#ifndef RED_GRAPHICS_LAMINAR_SPRITE_H
#define RED_GRAPHICS_LAMINAR_SPRITE_H

#include <Red/Graphics/Laminar/Laminar.h>

#include <Xenon/Math/Transform2D.h>
#include <Xenon/GPU/Texture2D.h>

#include <Red/Graphics/Laminar/RenderLayout.h>

namespace Red
{
	
	namespace Graphics
	{
		
		namespace Laminar
		{
			
			class Sprite
			{
			public:	
				
				Sprite ( Texture2D * Texture );
				~Sprite ();
				
				const RenderLayout & GetRenderLayout ();
				
				Transform2D & GetTransform ();
				
				int32_t GetZ ();
				
			private:
				
				Transform2D Transform;
				int32_t Z;
				
				Texture2D * Texture;
				
				RenderLayout Layout ();
				
			};
			
		}
		
	}
	
}

#endif
