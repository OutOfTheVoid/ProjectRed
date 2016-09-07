#ifndef RED_TEXT_RENDERING_SHADEDRENDERER_H
#define RED_TEXT_RENDERING_SHADEDRENDERER_H

#include <Red/Text/Rendering/Rendering.h>
#include <Red/Text/Rendering/FontRenderData.h>

#include <Xenon/Geometry/Mesh.h>

#include <Xenon/Math/Matrix3x3.h>
#include <Xenon/Math/Vec4.h>
#include <Xenon/Math/Vec2.h>
#include <Xenon/Math/RawVec4UniformSource.h>
#include <Xenon/Math/RawMatrix3x3UniformSource.h>
#include <Xenon/Math/RawFloatUniformSource.h>
#include <Xenon/Math/ConstantIntUniformSource.h>

#include <Xenon/GPU/IGPUResourceUser.h>
#include <Xenon/GPU/VertexBuffer.h>
#include <Xenon/GPU/VertexShader.h>
#include <Xenon/GPU/FragmentShader.h>
#include <Xenon/GPU/ShaderProgram.h>
#include <Xenon/GPU/UniformSet.h>
#include <Xenon/GPU/FrameBuffer.h>
#include <Xenon/GPU/VertexArray.h>
#include <Xenon/GPU/Texture2D.h>

#include <Red/Util/RefCounted.h>

#include <string>

namespace Red
{
	
	namespace Text
	{
		
		namespace Rendering
		{
			
			class ShadedRenderer : public Util :: RefCounted, public virtual Xenon::GPU :: IGPUResourceUser
			{
			public:
				
				static constexpr double kWidth_Unbounded = - 1.0;
				static constexpr double kHeight_Unbounded = - 1.0;
				
				ShadedRenderer ( FontRenderData * FontData );
				~ShadedRenderer ();
				
				void SetFontData ( FontRenderData * FontData );
				
				void SetScalingTolerance ( double Tolerance );
				double GetScalingTolerance ();
				
				void SetSize ( double Pixels );
				double GetSize ();
				
				void SetRenderTarget ( Xenon::GPU :: Context * Context, Xenon::GPU :: FrameBuffer * RenderTarget, Xenon::Math :: Vec2 Dimensions );
				
				void SetColor ( const Xenon::Math :: Vec4 Color );
				Xenon::Math :: Vec4 GetColor ();
				
				void SetGlobalTransform ( const Xenon::Math :: Matrix3x3 & Transform );
				
				void SetBounds ( Xenon::Math :: Vec2 Bounds );
				Xenon::Math :: Vec2 GetBounds ();
				
				void SetRenderDepth ( double Depth );
				double GetRenderDepth ();
				
				void SetDepthTestEnabled ( bool Enabled );
				bool GetDepthTestEnabled ();
				
				void PreAllocBuffer ( uint32_t MaxCharCount );
				void TrimBuffer ( uint32_t MaxCharCount );
				
				void RenderUnicodeString ( const std :: u32string & String );
				void RenderASCIIString ( const std :: string & String );
				
				void SetPreviousStringDirty ();
				
				void GPUResourceAlloc ();
				void GPUResourceFree ();
			
				bool GPUResourceAllocated ();
				
			private:
				
				void UploadTexture ( bool ForceReupload );
				
				FontRenderData * FontData;
				
				RawFontTextureAtlas * CurrentAtlas;
				
				Xenon::GPU :: Texture2D AtlasTexture;
				Xenon::Math :: ConstantIntUniformSource AtlasSamplerUniform;
				bool TextureUploaded;
				
				double PixelSize;
				double ScalingTolerance;
				
				Xenon::Geometry :: Mesh * QuadMesh;
				
				Xenon::GPU :: VertexBuffer CharachterTransformBuffer;
				Xenon::GPU :: VertexBuffer CharachterTexturePositionBuffer;
				
				uint32_t CurrenBufferLength;
				Xenon::Math :: Vec4 * TextureCoordinateArray;
				Xenon::Math :: Matrix3x3 * TransformArray;
				
				Xenon::GPU :: VertexShader VShader;
				Xenon::GPU :: FragmentShader FShader;
				Xenon::GPU :: ShaderProgram Program;
				
				Xenon::GPU :: UniformSet Uniforms;
				
				Xenon::Math :: Vec4 Color;
				Xenon::Math :: RawVec4UniformSource ColorUniform;
				
				Xenon::Math :: Matrix3x3 ExternalGlobalTransform;
				Xenon::Math :: Matrix3x3 GlobalTransform;
				Xenon::Math :: RawMatrix3x3UniformSource GlobalTransformUniform;
				
				Xenon::Math :: RawFloatUniformSource DepthUniform;
				
				bool DepthTesting;
				
				Xenon::Math :: Vec2 Bounds;
				
				Xenon::GPU :: VertexArray VArray;
				
				Xenon::GPU :: Context * Cont;
				Xenon::GPU :: FrameBuffer * RenderTarget;
				Xenon::Math :: Vec2 RenderTargetDimensions;
				
				bool CachedRenderDirty;
				std :: u32string LastString;
				
				bool GPUAllocated;
				
			};
			
		}
		
	}
	
}

#endif
