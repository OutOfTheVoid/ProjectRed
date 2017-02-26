#ifndef XENON_FRAMEBUFFER_H
#define XENON_FRAMEBUFFER_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/IGPUResourceUser.h>

#include <Red/Util/RefCounted.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class Context;
		class Texture2D;
		class RenderBuffer;
		
		class FrameBuffer : public IGPUResourceUser, public Red::Util :: RefCounted
		{
		public:
			
			typedef uint32_t FrameBufferBindingFlag;
			
			static const FrameBufferBindingFlag kFrameBufferBindingFlag_Draw = 1;
			static const FrameBufferBindingFlag kFrameBufferBindingFlag_Read = 2;
			static const FrameBufferBindingFlag kFrameBufferBindingFlag_ReadDraw = 3;
			
			typedef GLbitfield FrameBufferComponent;
			
			static const FrameBufferComponent kFrameBufferComponent_Color = GL_COLOR_BUFFER_BIT;
			static const FrameBufferComponent kFrameBufferComponent_Depth = GL_DEPTH_BUFFER_BIT;
			static const FrameBufferComponent kFrameBufferComponent_Stencil = GL_STENCIL_BUFFER_BIT;
			
			typedef GLenum OutputAttachment;
			
			static const OutputAttachment kOutputAttachment_ColorBuffer = GL_COLOR_ATTACHMENT0;
			static const OutputAttachment kOutputAttachment_DepthBuffer = GL_DEPTH_ATTACHMENT;
			static const OutputAttachment kOutputAttachment_StencilBuffer = GL_STENCIL_ATTACHMENT;
			static const OutputAttachment kOutputAttachment_DepthStencilBuffer = GL_DEPTH_STENCIL_ATTACHMENT;
			
			FrameBuffer ();
			~FrameBuffer ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			void Bind ( FrameBufferBindingFlag FrameBuffers = kFrameBufferBindingFlag_ReadDraw );
			
			static void SetClearColor ( GLfloat Red, GLfloat Green, GLfloat Blue, GLfloat Alpha = 1.0f );
			static void SetClearDepth ( GLfloat Depth );
			static void SetClearStencil ( GLint Value );
			
			void Clear ( FrameBufferComponent Components = kFrameBufferComponent_Color | kFrameBufferComponent_Depth );
			
			void SetRenderTexture2D ( OutputAttachment Attachment, GLuint AttachmentIndex, Texture2D & Texture, GLuint Level );
			void SetRenderBuffer ( OutputAttachment Attachment, GLuint AttachmentIndex, RenderBuffer & Buffer );
			
		private:
			
			friend class Context;
			
			FrameBuffer ( GLuint FHandle );
			
			bool Allocated;
			
			GLuint FHandle;
			
		};
		
	}
	
}

#endif
