#ifndef RED_GRAPHICS_LAMINAR_IRENDERABLE2D_H
#define RED_GRAPHICS_LAMINAR_IRENDERABLE2D_H

#include <Red/Graphics/Laminar/Laminar.h>
#include <Red/Graphics/Laminar/RenderLayout.h>

#include 

namespace Red
{
	
	namespace Grahpics
	{
		
		namespace Laminar
		{
			
			class IRenderable2D : public virtual I2DTextureSource
			{
			public:
				
				virtual ~IRenderable2D () {};
				
				const RenderLayout & GetRenderLayout () const;
				
			}
			
		}
		
	}
	
}

#endif
