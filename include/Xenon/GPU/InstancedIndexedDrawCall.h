#ifndef XENON_GPU_INSTANCEDINDEXEDDRAWCALL_H
#define XENON_GPU_INSTANCEDINDEXEDDRAWCALL_H

#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/DrawCall.h>
#include <Xenon/GPU/IndexBuffer.h>
#include <Xenon/GPU/GLInclude.h>

#include <Red/Util/RefCounted.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class InstancedIndexedDrawCall : public virtual DrawCall, public Red::Util :: RefCounted
		{
		public:
			
			typedef enum
			{
				
				NO_INIT
				
			} NoInit;
			
			InstancedIndexedDrawCall ( DrawCall :: DrawMode Mode, IndexBuffer & ForBuffer, GLuint InstanceCount, void * IndexBufferOffset = NULL );
			InstancedIndexedDrawCall ( DrawCall :: DrawMode Mode, GLuint ElementCount, IndexBuffer :: IndexType Type, GLuint InstanceCount, void * IndexBufferOffset = NULL );
			InstancedIndexedDrawCall ( NoInit NO_INIT );
			~InstancedIndexedDrawCall ();
			
			void SetDrawMode ( DrawCall :: DrawMode Mode );
			void SetElementCount ( GLuint ElementCount );
			void SetIndexType ( IndexBuffer :: IndexType Type );
			void SetIndexBufferOffset ( void * IndexBufferOffset );
			void SetInstanceCount ( GLuint InstanceCount );
			
			void Draw ();
			
		private:
			
			DrawCall :: DrawMode Mode;
			GLuint ElementCount;
			IndexBuffer :: IndexType Type;
			GLuint InstanceCount;
			void * IndexBufferOffset;
			
		};
		
	}
	
}

#endif
