#ifndef XENON_CONTEXT_H
#define XENON_CONTEXT_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/IGLContext.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/FrameBuffer.h>
#include <Xenon/Util/RefCounted.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class ShaderProgram;
		class VertexBuffer;
		class IndexBuffer;
		class VertexArray;
		class Texture2D;
		class FrameBuffer;
		
		class Context : public Util :: RefCounted
		{
		public:
			
			typedef GLenum BlendFactor;
			
			static const BlendFactor kBlendFactor_Zero = GL_ZERO;
			static const BlendFactor kBlendFactor_One = GL_ONE;
			
			static const BlendFactor kBlendFactor_SourceColor = GL_SRC_COLOR;
			static const BlendFactor kBlendFactor_OneMinusSourceColor = GL_ONE_MINUS_SRC_COLOR;
			static const BlendFactor kBlendFactor_SourceAlpha = GL_SRC_ALPHA;
			static const BlendFactor kBlendFactor_OneMinusSourceAlpha = GL_ONE_MINUS_SRC_ALPHA;
			
			static const BlendFactor kBlendFactor_DestinaionColor = GL_DST_COLOR;
			static const BlendFactor kBlendFactor_OneMinusDestinaionColor = GL_ONE_MINUS_DST_COLOR;
			static const BlendFactor kBlendFactor_DestinaionAlpha = GL_DST_ALPHA;
			static const BlendFactor kBlendFactor_OneMinusDestinaionAlpha = GL_ONE_MINUS_DST_ALPHA;
			
			static const BlendFactor kBlendFactor_ConstantColor = GL_CONSTANT_COLOR;
			static const BlendFactor kBlendFactor_OneMinusConstantColor = GL_ONE_MINUS_CONSTANT_COLOR;
			static const BlendFactor kBlendFactor_ConstantAlpha = GL_CONSTANT_ALPHA;
			static const BlendFactor kBlendFactor_OneMinusConstantAlpha = GL_ONE_MINUS_CONSTANT_ALPHA;
			
			static const BlendFactor kBlendFactor_SourceAlphaSaturate = GL_SRC_ALPHA_SATURATE;
			
			static const BlendFactor kBlendFactor_SourceOneColor = GL_SRC1_COLOR;
			static const BlendFactor kBlendFactor_OneMinusSourceOneColor = GL_ONE_MINUS_SRC1_COLOR;
			static const BlendFactor kBlendFactor_SourceOneAlpha = GL_SRC1_ALPHA;
			static const BlendFactor kBlendFactor_OneMinusSourceOneAlpha = GL_ONE_MINUS_SRC1_ALPHA;
			
			typedef GLenum CullingFace;
			
			static const CullingFace kCullingFace_Front = GL_FRONT;
			static const CullingFace kCullingFace_Back = GL_BACK;
			
			typedef GLenum FrontFace;
			
			static const FrontFace kFrontFace_Clockwise = GL_CW;
			static const FrontFace kFrontFace_CounterClockwise = GL_CCW;
			
			Context ( IGLContext * GLContext );
			~Context ();
			
			void MakeCurrent ();
			
			void BlendFunc ( BlendFactor Source, BlendFactor Destination );
			
			void SetCullingEnabled ( bool Enabled );
			void SetCullingFace ( CullingFace Face );
			void SetFrontFace ( FrontFace Face );
			
			void SetDepthTestEnabled ( bool Enabled );
			
			FrameBuffer * GetDefaultFrameBuffer ();
			
		private:
			
			friend class ShaderProgram;
			friend class VertexBuffer;
			friend class IndexBuffer;
			friend class VertexArray;
			friend class Texture2D;
			friend class FrameBuffer;
			
			static Context NullContext;
			
			static thread_local Context * CurrentBoundContext;
			
			IGLContext * GLContext;
			
			ShaderProgram * CurrentBoundShader;
			VertexBuffer * CurrentBoundArrayBuffer;
			IndexBuffer * CurrentBoundIndexBuffer;
			VertexArray * CurrentBoundVertexArray;
			Texture2D * CurrentBoundTexture2D;
			FrameBuffer * CurrentBoundReadFrameBuffer;
			FrameBuffer * CurrentBoundDrawFrameBuffer;
			
			FrameBuffer DefaultFrameBuffer;
			
			bool CullingEnabledCurrent;
			CullingFace CullingFaceCurrent;
			
			FrontFace FrontFaceCurrent;
			
			bool DepthTestEnabledCurrent;
			
		};
		
	}
	
}

#endif
