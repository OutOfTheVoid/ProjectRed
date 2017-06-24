#ifndef RED_GRAPHICS_LAMINAR_RAW2DTEXTURESOURCE_H
#define RED_GRAPHICS_LAMINAR_RAW2DTEXTURESOURCE_H

#include <Red/Graphics/Laminar/I2DTextureSource.h>

#include <Red/Util/RefCounted.h>

#include <Xenon/GPU/ITexture.h>
#include <Xenon/GPU/Texture2D.h>
#include <Xenon/Math/Matrix3x3.h>

namespace Red
{
	
	namespace Graphics
	{
		
		namespace Laminar
		{
			
			class Raw2DTextureSource : public virtual I2DTextureSource, public Util :: RefCounted
			{
			public:
				
				Raw2DTextureSource ( Xenon::GPU :: Texture2D * Tex, const Xenon::Math :: Matrix3x3 & Transform = Xenon::Math :: Matrix3x3 () );
				~Raw2DTextureSource ();
				
				Xenon::GPU :: ITexture * GetOutputTexture ();
				Xenon::Math :: Matrix3x3 * GetOutputTextureTransform ();
				
			private:
				
				Xenon::GPU :: Texture2D * Tex;
				Xenon::Math :: Matrix3x3 Transform;
				
			};
			
		}
		
	}
	
}

#endif
