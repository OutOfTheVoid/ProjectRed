#ifndef RED_GRAPHICS_LAMINAR_IRENDERABLE2D_H
#define RED_GRAPHICS_LAMINAR_IRENDERABLE2D_H

#include <Red/Graphics/Laminar/Laminar.h>

namespace Red
{
	
	namespace Grahpics
	{
		
		namespace Laminar
		{
			
			class IRenderable2D
			{
			public:
				
				virtual ~IRenderable2D () {};
				
				virtual void Render ( Xenon::Math :: Matrix3x3 & CameraTransform );
				
			}
			
		}
		
	}
	
}

#endif
