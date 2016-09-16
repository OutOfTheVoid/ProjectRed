#ifndef RED_GRAPHICS_SCENE3D_H
#define RED_GRAPHICS_SCENE3D_H

#include <Red/Graphics/Graphics.h>

namespace Red
{
	
	namespace Graphics
	{
		
		class Scene3D
		{
		public:
			
			Scene3D ( const std :: string & Name, uint32_t FragmentWidth = 0, uint32_t FragmentHeight = 0 );
			~Scene3D ();
			
			void SetTargetRenderDimensions ( int32_t Width, int32_t Height );
			void SetTargetRenderOffset ( int32_t OffsetX, int32_t OffsetY );
			
		private:
			
			int32_t TargetWidth;
			int32_t TargetHeight;
			int32_t TargetX;
			int32_t TargetY;
			
		};
		
	}
	
}

#endif
