#ifndef RED_GRAPHICS_LAMINAR_IRENDERABLE2DTEXTURESOURCE_H
#define RED_GRAPHICS_LAMINAR_IRENDERABLE2DTEXTURESOURCE_H

#include <Red/Graphics/Laminar/Laminar.h>
#include <Xenon/Math/Matrix3x3.h>
#include <Red/Util/IRefCounted.h>

namespace Red
{
	
	namespace Graphics
	{
		
		namespace Laminar
		{
			
			class I2DTextureSource : public virtual Util :: IRefCounted
			{
			public:
				
				inline virtual ~I2DTextureSource () {};
				
				virtual Xenon::GPU :: ITexture * GetOutputTexture () = 0;
				virtual Xenon::Math :: Matrix3x3 * GetOutputTextureTransform () = 0;
				
			};
			
		}
		
	}
	
}

#endif
