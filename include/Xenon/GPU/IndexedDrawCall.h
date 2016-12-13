#ifndef XENON_GPU_INDEXEDDRAWCALL_H
#define XENON_GPU_INDEXEDDRAWCALL_H

#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/DrawCall.h>
#include <Xenon/GPU/IndexBuffer.h>
#include <Xenon/GPU/GLInclude.h>

#include <Red/Util/RefCounted.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class IndexedDrawCall : public virtual DrawCall, public Red::Util :: RefCounted
		{
		public:
			
			typedef enum
			{
				
				NO_INIT
				
			} NoInit;
			
			IndexedDrawCall ( DrawCall :: DrawMode Mode, GLuint ElementCount, IndexBuffer :: IndexType Type, void * IndexBufferOffset = NULL );
			IndexedDrawCall ( NoInit NO_INIT );
			~IndexedDrawCall ();
			
			void SetDrawMode ( DrawCall :: DrawMode Mode );
			void SetElementCount ( GLuint ElementCount );
			void SetIndexType ( IndexBuffer :: IndexType Type );
			void SetIndexBufferOffset ( void * IndexBufferOffset );
			
			void Draw ();
			
		private:
			
			DrawCall :: DrawMode Mode;
			GLuint ElementCount;
			IndexBuffer :: IndexType Type;
			void * IndexBufferOffset;
			
		};
		
	}
	
}

#endif
