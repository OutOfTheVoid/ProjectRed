#ifndef XENON_INDEXBUFFER_H
#define XENON_INDEXBUFFER_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/IGPUResourceUser.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/Util/RefCounted.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class IndexBuffer : public IGPUResourceUser, public Util :: RefCounted
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
			
			typedef GLenum IndexType;
			
			static const IndexType kIndexType_UBytes = GL_UNSIGNED_BYTE;
			static const IndexType kIndexType_UShorts = GL_UNSIGNED_SHORT;
			static const IndexType kIndexType_UInts = GL_UNSIGNED_INT;
			
			IndexBuffer ( UsageType Usage, IndexType Type );
			~IndexBuffer ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			void Buffer ( const GLvoid * Data, GLuint Count );
			void SubBuffer ( const GLvoid * SubData, GLuint Count, GLuint Offset );
			
			void Orphan ();
			
			void * Map ( bool Read = false );
			void Unmap ();
			
			void FlushMap ();
			
			bool Mapped ();
			
			void Bind ();
			
			IndexType GetIndexType ();
			GLuint GetIndexCount ();
			
		private:
			
			UsageType Usage;
			IndexType Type;
			
			bool Allocated;
			bool MMapped;
			bool ReadableMap;
			
			void * MapAddress;
			
			GLuint BHandle;
			
			GLuint Count;
			
		};
		
	}
	
}

#endif
