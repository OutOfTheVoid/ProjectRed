#ifndef RED_GRAPHICS_LAMINAR_SPRITE_H
#define RED_GRAPHICS_LAMINAR_SPRITE_H

#include <Red/Graphics/Laminar/Laminar.h>

#include <Xenon/Math/Transform2D.h>
#include <Xenon/GPU/Texture2D.h>

#include <Red/Graphics/Laminar/RenderLayout.h>
#include <Red/Graphics/Laminar/I2DTextureSource.h>

namespace Red
{
	
	namespace Graphics
	{
		
		namespace Laminar
		{
			
			class Renderer;
			
			class Sprite
			{
			public:	
				
				Sprite ( I2DTextureSource * TextureSource, const RenderLayout & Layout ); // 1:15:19
				~Sprite ();
				
				const RenderLayout & GetRenderLayout () const;
				RenderLayout & GetRenderLayout ();
				
				const Xenon::Math :: Transform2D & GetTransform () const;
				Xenon::Math :: Transform2D & GetTransform ();
				
				I2DTextureSource * GetTextureSource () const;
				
			private:
				
				friend class Renderer;
				
				Xenon::Math :: Transform2D Transform;
				
				I2DTextureSource * TextureSource;
				
				RenderLayout Layout;
				
				Sprite * Next;
				Sprite * Last;
				Renderer * RenderInstance;
				uint32_t Layer;
				
			};
			
		}
		
	}
	
}

#endif
