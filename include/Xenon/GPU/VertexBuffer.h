#ifndef XENON_VERTEXDATA_H
#define XENON_VERTEXDATA_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/IGPUResourceUser.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/Util/RefCounted.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class VertexBuffer : public IGPUResourceUser, public Util :: RefCounted
		{
		public:
			
			typedef GLenum UsageType;
			
			static const UsageType kUsageType_Stream_Draw = GL_STREAM_DRAW;
			static const UsageType kUsageType_Stream_Read = GL_STREAM_READ;
			static const UsageType kUsageType_Stream_Copy = GL_STREAM_COPY;
			
			static const UsageType kUsageType_Static_Draw = GL_STATIC_DRAW;
			static const UsageType kUsageType_Static_Read = GL_STATIC_READ;
			static const UsageType kUsageType_Static_Copy = GL_STATIC_COPY;
			
			static const UsageType kUsageType_Dynamic_Draw = GL_DYNAMIC_DRAW;
			static const UsageType kUsageType_Dynamic_Read = GL_DYNAMIC_READ;
			static const UsageType kUsageType_Dynamic_Copy = GL_DYNAMIC_COPY;
			
			VertexBuffer ( UsageType Usage );
			~VertexBuffer ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			void Buffer ( const GLvoid * Data, GLsizeiptr Size );
			void SubBuffer ( const GLvoid * SubData, GLsizeiptr Size, GLintptr Offset );
			
			void Orphan ();
			
			void Bind ();
			
		private:
			
			UsageType Usage;
			
			bool Allocated;
			
			GLsizeiptr Size;
			bool Written;
			
			GLuint BHandle;
			
		};
		
	}
	
}

#endif
