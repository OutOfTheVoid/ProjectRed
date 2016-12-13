#ifndef XENON_GEOMETRY_MESH_H
#define XENON_GEOMETRY_MESH_H

#include <Xenon/Xenon.h>

#include <Xenon/Geometry/Geometry.h>
#include <Xenon/Geometry/MeshAttribute.h>
#include <Xenon/Geometry/MeshAttributeData.h>

#include <Xenon/GPU/IGPUResourceUser.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/DrawCall.h>
#include <Xenon/GPU/IndexedDrawCall.h>
#include <Xenon/GPU/InstancedIndexedDrawCall.h>
#include <Xenon/GPU/IndexBuffer.h>
#include <Xenon/GPU/VertexArray.h>
#include <Xenon/GPU/VertexBuffer.h>

#include <Red/Util/RCMem.h>
#include <Red/Util/RefCounted.h>

#include <stdint.h>

namespace Xenon
{
	
	namespace Geometry
	{
		
		class Mesh : public GPU :: IGPUResourceUser, public Red::Util :: RefCounted
		{
		public:
			
			enum MemMapIndexData
			{
				
				MAP_INDEXBUFFER_WRITEONLY,
				
			};
			
			Mesh ( GPU::DrawCall :: DrawMode Mode, Red::Util :: RCMem * IndexData, uint32_t IndexCount, GPU::IndexBuffer :: IndexType IType = GPU::IndexBuffer :: kIndexType_UInts, GPU::IndexBuffer :: UsageType IUsage = GPU::IndexBuffer :: kUsageType_Static_Draw );
			Mesh ( MemMapIndexData MAP_INDEXBUFFER_WRITEONLY, GPU::DrawCall :: DrawMode Mode, uint32_t IndexCount, GPU::IndexBuffer :: IndexType IType = GPU::IndexBuffer :: kIndexType_UInts, bool Draw = true );
			
			virtual ~Mesh ();
			
			void SetDrawMode ( GPU::DrawCall :: DrawMode Mode );
			
			void ReIndex ( uint32_t IndexCount, Red::Util :: RCMem * IndexData );
			void ReIndex ( MemMapIndexData MapIndexBufferMemory, uint32_t IndexCount );
			
			void * GetIndexMemoryPointer ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			void FlushIndexes ( bool DiscardDataReference );
			void FlushVertexes ( bool FreeDataReferences );
			
			GPU::DrawCall :: DrawMode GetDrawMode ();
			
			void FlushData ();
			
			void BuildVertexArray ( GPU :: VertexArray & Target );
			
			void AddAttributeData ( MeshAttributeData * AttributeData );
			void AddAttribute ( MeshAttribute * Attribute );
			
			uint32_t GetIndexCount ();
			GPU::IndexBuffer :: IndexType GetIndexType ();
			
			void ConfigureIndexedDrawCall ( GPU :: IndexedDrawCall & ToConfigure );
			void ConfigureInstancedIndexedDrawCall ( GPU :: InstancedIndexedDrawCall & ToConfigure, GLuint InstanceCount = 0 );
			
		private:
			
			GPU :: IndexBuffer IndexBuff;
			
			Red::Util :: RCMem * IndexData;
			uint32_t IndexCount;
			
			GPU::DrawCall :: DrawMode Mode;
			
			bool IndexDirty;
			bool GPUAllocated;
			bool Mapped;
			
			std :: vector <MeshAttribute *> AttributeList;
			std :: vector <MeshAttributeData *> AttributeDataList;
			
		};
		
	}
	
}

#endif
