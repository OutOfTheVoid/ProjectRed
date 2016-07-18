#ifndef XENON_GEOMETRY_MESHATTRIBUTEDATA_H
#define XENON_GEOMETRY_MESHATTRIBUTEDATA_H

#include <Xenon/Xenon.h>

#include <Xenon/Geometry/Geometry.h>
#include <Xenon/Geometry/MeshAttribute.h>

#include <Xenon/GPU/VertexBuffer.h>
#include <Xenon/GPU/IGPUResourceUser.h>

#include <Xenon/Util/RCMem.h>
#include <Xenon/Util/RefCounted.h>

namespace Xenon
{
	
	namespace Geometry
	{
		
		class MeshAttributeData : public GPU :: IGPUResourceUser, public Util :: RefCounted
		{
		public:
			
			MeshAttributeData ( Util :: RCMem * Data, GLsizei Size, GPU::VertexBuffer :: UsageType UsageMode, bool Orphaning = true );
			~MeshAttributeData ();
			
			void MarkDirty ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			void Update ( bool FreeDataReference = false );
			
			GPU :: VertexBuffer * GetBuffer ();
			
		private:
			
			Util :: RCMem * Data;
			GLsizei Size;
			GLintptr Offset;
			
			bool Written;
			
			GPU :: VertexBuffer Buffer;
			
			bool Dirty;
			
			bool Orphaning;
			
		};
		
	};
	
};

#endif