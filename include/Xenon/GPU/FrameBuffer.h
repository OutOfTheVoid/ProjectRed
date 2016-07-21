#ifndef XENON_FRAMEBUFFER_H
#define XENON_FRAMEBUFFER_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/IGPUResourceUser.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class Context;
		
		class FrameBuffer : public IGPUResourceUser
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
			
			FrameBuffer ();
			~FrameBuffer ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			void Bind ( FrameBufferBindingFlag FrameBuffers = kFrameBufferBindingFlag_ReadDraw );
			
			void SetClearColor ( GLfloat Red, GLfloat Green, GLfloat Blue, GLfloat Alpha = 1.0f );
			void SetClearDepth ( GLfloat Depth );
			void SetClearStencil ( GLint Value );
			
			void Clear ( FrameBufferComponent Components = kFrameBufferComponent_Color | kFrameBufferComponent_Depth );
			
		private:
			
			friend class Context;
			
			FrameBuffer ( GLuint FHandle );
			
			bool Allocated;
			
			GLuint FHandle;
			
		};
		
	}
	
}

#endif
