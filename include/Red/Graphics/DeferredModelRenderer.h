#ifndef RED_GRAPHICS_DEFERREDMODELRENDERER_H
#define RED_GRAPHICS_DEFERREDMODELRENDERER_H

#include <Red/Graphics/Graphics.h>
#include <Red/Graphics/Model.h>
#include <Red/Graphics/IRenderer3D.h>

#include <Xenon/Math/Vec2.h>
#include <Xenon/Math/Matrix4x4.h>
#include <Xenon/Math/ConstantIntUniformSource.h>
#include <Xenon/Math/ConstantBoolUniformSource.h>
#include <Xenon/Math/RawMatrix4x4UniformSource.h>

#include <Xenon/GPU/Context.h>
#include <Xenon/GPU/FrameBuffer.h>
#include <Xenon/GPU/RenderBuffer.h>
#include <Xenon/GPU/IGPUResourceUser.h>
#include <Xenon/GPU/VertexShader.h>
#include <Xenon/GPU/FragmentShader.h>
#include <Xenon/GPU/ShaderProgram.h>
#include <Xenon/GPU/Texture2D.h>
#include <Xenon/GPU/VertexArray.h>
#include <Xenon/GPU/UniformSet.h>

#include <Xenon/Geometry/Mesh.h>

namespace Red
{
	
	namespace Graphics
	{
		
		class DeferredModelRenderer;
		
		class alignas ( 16 ) DeferredModelRenderer : public Util :: RefCounted, public virtual IRenderer3D
		{
		public:
			
			static const char * kModelAttributeName_Position;
			static const char * kModelAttributeName_Normal;
			static const char * kModelAttributeName_Tangent;
			static const char * kModelAttributeName_Color;
			static const char * kModelAttributeName_TextureCoords;
			
			static const char * kModelAttributeName_InstancedTransform;
			
			static const uint32_t kRenderFlags_InstancedTransform = 1;
			static const uint32_t kRenderFlags_NormalTexture = 2;
			static const uint32_t kRenderFlags_ColorTexture = 4;
			
			DeferredModelRenderer ();
			~DeferredModelRenderer ();

#ifdef _WIN32
			
			inline void * operator new ( size_t Size )
			{

				return _mm_malloc ( Size, 16 );

			}

			inline void operator delete ( void * ToFree )
			{

				_mm_free ( ToFree );

			}

#endif
			
			void Initialize ( Xenon::GPU :: Context * GPUContext );
			
			void SetProjection ( Xenon::Math :: Matrix4x4 & ProjectionMatrix );
			void SetView ( Xenon::Math :: Matrix4x4 & ViewMatrix );
			
			void SetupRender ( Xenon::GPU :: FrameBuffer * RenderTarget, Xenon::Math :: Vec2 Dimensions );
			void DestroyRender ();
			
			void Render ();
			
		private:
			
			class PerModelRenderData
			{
			public:
				
				~PerModelRenderData ();
				
			private:
				
				friend class DeferredModelRenderer;
				
				PerModelRenderData ( Model * RenderModel, uint32_t Flags );
				
				Model * RenderModel;
				
				Xenon::Math :: ConstantBoolUniformSource DoInstancedTransformUniform;
				Xenon::Math :: ConstantBoolUniformSource DoNormalTextureUniform;
				Xenon::Math :: ConstantBoolUniformSource DoColorTextureUniform;
				
				Xenon::GPU :: UniformSet Uniforms;
				Xenon::GPU :: VertexArray AttributeArray; 
				
				bool GPUAllocated;
				
			};
			
			Xenon::GPU :: Context * GPUContext;
			Xenon::GPU :: FrameBuffer * RenderTarget;
			
			bool GPUAllocated;
			
			// Geometry pass
			
			Xenon::GPU :: UniformSet GeometryUniforms;
			
			Xenon::GPU :: FrameBuffer GBuffer;
			GLuint AttachmentList [ 3 ];
			
			Xenon::GPU :: Texture2D AlbedoSpecularTexture;
			Xenon::GPU :: Texture2D NormalTexture;
			Xenon::GPU :: Texture2D PositionTexture;
			
			Xenon::GPU :: RenderBuffer DepthBuffer;
			
			Xenon::GPU :: VertexShader GeometryVShader;
			Xenon::GPU :: FragmentShader GeometryFShader;
			
			Xenon::GPU :: ShaderProgram GeometryProgram;
			
			Xenon::Math :: Matrix4x4 ProjectionMatrix;
			
			Xenon::Math :: RawMatrix4x4UniformSource NormalMatrixUniform;
			Xenon::Math :: RawMatrix4x4UniformSource ModelMatrixUniform;
			Xenon::Math :: RawMatrix4x4UniformSource ViewProjectionMatrixUniform;
			
			// Lighting pass
			
			Xenon::GPU :: VertexArray LightingVAO;
			
			Xenon::GPU :: UniformSet LightingUniforms;
			
			Xenon::Math :: ConstantIntUniformSource AlbedoSpecularSamplerUniform;
			Xenon::Math :: ConstantIntUniformSource NormalSamplerUniform;
			Xenon::Math :: ConstantIntUniformSource PositionSamplerUniform;
			
			Xenon::GPU :: VertexShader LightingVShader;
			Xenon::GPU :: FragmentShader LightingFShader;
			
			Xenon::GPU :: ShaderProgram LightingProgram;
			
			Xenon::Geometry :: Mesh * RenderQuad;
			
		};
		
	}
	
}

#endif
