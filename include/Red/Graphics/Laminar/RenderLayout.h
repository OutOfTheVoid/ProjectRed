#ifndef RED_GRAPHICS_LAMINAR_RENDERLAYOUT_H
#define RED_GRAPHICS_LAMINAR_RENDERLAYOUT_H

#include <Red/Graphics/Laminar/Laminar.h>

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
				
				RenderLayout ( RenderMode Mode,  );
				~RenderLayout ();
				
				bool GetZSortRequired ();
				
				uint32_t GetTextureCount ();
				
			private:
				
				RenderMode Mode;
				
				
			}
			
		}
		
	}
	
}

#endif
