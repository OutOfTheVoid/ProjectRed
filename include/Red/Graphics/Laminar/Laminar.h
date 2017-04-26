#ifndef RED_GRAPHICS_LAMINAR_LAMINAR_H
#define RED_GRAPHICS_LAMINAR_LAMINAR_H

#include <Red/Graphics/Graphics.h>

namespace Red
{
	
	namespace Graphics
	{
		
		namespace Laminar
		{
			
			typedef enum
			{
				
				kRenderMode_Overlay,
				kRenderMode_Add,
				kRenderMode_Subtract,
				kRenderMode_Multiply,
				kRenderMode_Max,
				kRenderMode_Min,
				kRenderMode_Mask,
				kRenderMode_NegativeMask,
				kRenderMode_Default
				
			} RenderMode;
			
		}
		
	}
	
}

#endif
