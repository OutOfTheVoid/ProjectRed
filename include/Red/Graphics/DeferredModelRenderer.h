#ifndef RED_GRAPHICS_DEFERREDMODELRENDERER_H
#define RED_GRAPHICS_DEFERREDMODELRENDERER_H

#include <Red/Graphics/Graphics.h>
#include <Red/Graphics/Model.h>
#include <Red/Graphics/IRenderer3D.h>

#include <Xenon/Math/Vec2.h>
#include <Xenon/Math/Matrix4x4.h>
#include <Xenon/Math/ConstantIntUniformSource.h>
#include <Xenon/Math/ConstantBoolUniformSource.h>

#include <Xenon/GPU/IMatrix4x4UniformSource.h>

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
#include <Xenon/GPU/IndexedDrawCall.h>

#include <Xenon/Geometry/Mesh.h>

#include <vector>

namespace Red
{
	
	namespace Graphics
	{
		
		class DeferredModelRenderer;
		
		class alignas ( 16 ) DeferredModelRenderer : public Util :: RefCounted, public virtual IRenderer3D
		{
		public:
			
			static const std :: string kModelAttributeName_Position;
			static const std :: string kModelAttributeName_Normal;
			static const std :: string kModelAttributeName_Tangent;
			static const std :: string kModelAttributeName_Color;
			static const std :: string kModelAttributeName_TextureCoords;
			
			static const std :: string kModelAttributeName_InstancedModelMatrix;
			static const std :: string kModelAttributeName_InstancedNormalMatrix;
			
			static const std :: string kUniformName_ModelMatrix;
			static const std :: string kUniformName_NormalMatrix;
			
			static const std :: string kUniformName_DoInstancedTransforms;
			static const std :: string kUniformName_DoNormalTexture;
			static const std :: string kUniformName_DoColorTexture;
			
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
			
			static const Model :: ModelShaderConfigurationNames & GetShaderConfigurationNames ();
			
			void Initialize ( Xenon::GPU :: Context * GPUContext );
			
			void SetProjectionSource ( Xenon::GPU :: IMatrix4x4UniformSource * ProjectionMatrixSource );
			void SetViewSource ( Xenon::GPU :: IMatrix4x4UniformSource * ViewMatrixSource );
			
			void SetupRender ( Xenon::GPU :: FrameBuffer * RenderTarget, Xenon::Math :: Vec2 Dimensions );
			void DestroyRender ();
			
			void Render ();
			
			void AddModel ( Model * ToAdd );
			void RemoveModel ( Model * ToRemove );
						
		private:
				
			class PerModelRenderData
			{
			public:
				
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
				
				~PerModelRenderData ();
				
			private:
				
				friend class DeferredModelRenderer;
				
				PerModelRenderData ( Model * RenderModel );
				
				Model * RenderModel;
				
				Xenon::GPU :: UniformSet Uniforms;
				Xenon::GPU :: VertexArray VArray;
				
				bool GPUAllocated;
				
			};
			
			void GPUAllocModelData ( PerModelRenderData * Data );
			void GPUFreeModelData ( PerModelRenderData * Data );
			
			Xenon::GPU :: Context * GPUContext;
			Xenon::GPU :: FrameBuffer * RenderTarget;
			
			bool GPUAllocated;
			
			// Geometry pass
			
			Xenon::GPU :: UniformSet GeometryUniforms;
			
			Xenon::GPU :: FrameBuffer GBuffer;
			GLuint AttachmentList [ 4 ];
			
			Xenon::GPU :: Texture2D AlbedoSpecularTexture;
			Xenon::GPU :: Texture2D NormalTexture;
			Xenon::GPU :: Texture2D PositionTexture;
			
			Xenon::GPU :: RenderBuffer DepthBuffer;
			
			Xenon::GPU :: VertexShader GeometryVShader;
			Xenon::GPU :: FragmentShader GeometryFShader;
			
			Xenon::GPU :: ShaderProgram GeometryProgram;
			
			Xenon::GPU :: IMatrix4x4UniformSource * ProjectionMatrixSource;
			Xenon::GPU :: IMatrix4x4UniformSource * ViewMatrixSource;
			
			int64_t LastProjectionIteration;
			int64_t LastViewIteration;
			
			Xenon::Math :: Matrix4x4 ViewProjectionMatrix;
			
			Xenon::Math :: RawMatrix4x4UniformSource ViewProjectionMatrixUniform;
			
			// Lighting pass
			
			Xenon::GPU :: IndexedDrawCall LightingDrawCall;
			
			Xenon::GPU :: VertexArray LightingVAO;
			
			Xenon::GPU :: UniformSet LightingUniforms;
			
			Xenon::Math :: ConstantIntUniformSource AlbedoSpecularSamplerUniform;
			Xenon::Math :: ConstantIntUniformSource NormalSamplerUniform;
			Xenon::Math :: ConstantIntUniformSource PositionSamplerUniform;
			
			Xenon::GPU :: VertexShader LightingVShader;
			Xenon::GPU :: FragmentShader LightingFShader;
			
			Xenon::GPU :: ShaderProgram LightingProgram;
			
			Xenon::Geometry :: Mesh * RenderQuad;
			
			// Objects to render:
			
			std :: vector <PerModelRenderData *> RenderDataSet;
			
		};
		
	}
	
}

#endif
