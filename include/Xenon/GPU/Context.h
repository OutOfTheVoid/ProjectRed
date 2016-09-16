#ifndef XENON_CONTEXT_H
#define XENON_CONTEXT_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/IGLContext.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/FrameBuffer.h>

#include <Red/Util/RefCounted.h>

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
		class RenderBuffer;
		
		class Context : public Red::Util :: RefCounted
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
			
			typedef GLenum BlendOperator;
			
			static const BlendOperator kBlendOperator_Add = GL_FUNC_ADD;
			static const BlendOperator kBlendOperator_Subtract = GL_FUNC_SUBTRACT;
			static const BlendOperator kBlendOperator_ReverseSubtract = GL_FUNC_REVERSE_SUBTRACT;
			static const BlendOperator kBlendOperator_Min = GL_MIN;
			static const BlendOperator kBlendOperator_Max = GL_MAX;
			
			typedef GLenum CullingFace;
			
			static const CullingFace kCullingFace_Front = GL_FRONT;
			static const CullingFace kCullingFace_Back = GL_BACK;
			
			typedef GLenum FrontFace;
			
			static const FrontFace kFrontFace_Clockwise = GL_CW;
			static const FrontFace kFrontFace_CounterClockwise = GL_CCW;
			
			Context ( IGLContext * GLContext );
			~Context ();
			
			void MakeCurrent ();
			
			void BlendFunc ( BlendFactor SourceRGB, BlendFactor DestinationRGB, BlendFactor SourceAlpha = kBlendFactor_One, BlendFactor DestinationAlpha = kBlendFactor_Zero );
			void BlendEquation ( BlendOperator OperatorRGB, BlendOperator OperatorAlpha );
			
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
			friend class RenderBuffer;
			
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
			RenderBuffer * CurrentBoundRenderBuffer;
			
			FrameBuffer DefaultFrameBuffer;
			
			bool CullingEnabledCurrent;
			CullingFace CullingFaceCurrent;
			
			FrontFace FrontFaceCurrent;
			
			bool DepthTestEnabledCurrent;
			
		};
		
	}
	
}

#endif
