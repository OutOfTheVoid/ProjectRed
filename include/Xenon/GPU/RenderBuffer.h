#ifndef XENON_GPU_RENDERBUFFER_H
#define XENON_GPU_RENDERBUFFER_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/IGPUResourceUser.h>
#include <Xenon/GPU/Texture2D.h>

#include <Red/Util/RefCounted.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class FrameBuffer;
		
		class RenderBuffer : public IGPUResourceUser, public Red::Util :: RefCounted
		{
		public:
			
			RenderBuffer ();
			~RenderBuffer ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			void Bind ();
			
			void AllocateStorage ( Texture2D :: InternalFormat Format, GLuint Width, GLuint Height, GLuint MultisampleLevel = 0 );
			
		private:
			
			friend class FrameBuffer;
			
			bool Allocated;
			
			GLuint RHandle;
			
		};
		
	}
	
}

#endif
