#ifndef RED_GRAPHICS_IRENDERER3D_H
#define RED_GRAPHICS_IRENDERER3D_H

#include <Red/Graphics/Graphics.h>

#include <Red/Util/IRefCounted.h>

#include <Xenon/Math/Vec2.h>
#include <Xenon/GPU/IMatrix4x4UniformSource.h>

#include <Xenon/GPU/Context.h>
#include <Xenon/GPU/FrameBuffer.h>
#include <Xenon/GPU/IGPUResourceUser.h>

namespace Red
{
	
	namespace Graphics
	{
		
		class IRenderer3D : public virtual Util :: IRefCounted
		{
		public:
			
			virtual inline ~IRenderer3D ()
			{
			};
			
			virtual void Initialize ( Xenon::GPU :: Context * GPUContext ) = 0;
			
			virtual void SetProjectionSource ( Xenon::GPU :: IMatrix4x4UniformSource * ProjectionMatrixSource ) = 0;
			virtual void SetViewSource ( Xenon::GPU :: IMatrix4x4UniformSource * ViewMatrixSource ) = 0;
			
			virtual void SetupRender ( Xenon::GPU :: FrameBuffer * RenderTarget, Xenon::Math :: Vec2 Dimensions ) = 0;
			virtual void DestroyRender () = 0;
			
			virtual void Render () = 0;
			
			
		};
		
	}
	
}

#endif
