#ifndef XENON_GEOMETRY_MESH_H
#define XENON_GEOMETRY_MESH_H

#include <Xenon/Xenon.h>

#include <Xenon/Geometry/Geometry.h>
#include <Xenon/Geometry/MeshAttribute.h>
#include <Xenon/Geometry/MeshAttributeData.h>

#include <Xenon/GPU/IGPUResourceUser.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/IndexBuffer.h>
#include <Xenon/GPU/VertexArray.h>
#include <Xenon/GPU/VertexBuffer.h>

#include <Xenon/Util/RCMem.h>

#include <stdint.h>

namespace Xenon
{
	
	namespace Geometry
	{
		
		class Mesh : public GPU :: IGPUResourceUser
		{
		public:
			
			typedef GLenum DrawMode;
			
			static const DrawMode kDrawMode_Point = GL_POINTS;
			
			static const DrawMode kDrawMode_Line_Strip = GL_LINE_STRIP;
			static const DrawMode kDrawMode_Line_Loop = GL_LINE_LOOP;
			static const DrawMode kDrawMode_Line = GL_LINES;
			static const DrawMode kDrawMode_Line_Adjecent = GL_LINES_ADJACENCY;
			static const DrawMode kDrawMode_Line_Strip_Adjacent = GL_LINE_STRIP_ADJACENCY;
			
			static const DrawMode kDrawMode_Triangle_Strip = GL_TRIANGLE_STRIP;
			static const DrawMode kDrawMode_Triangle_Fan = GL_TRIANGLE_FAN;
			static const DrawMode kDrawMode_Triangle = GL_TRIANGLES;
			static const DrawMode kDrawMode_Triangle_Strip_Adjacent = GL_TRIANGLE_STRIP_ADJACENCY;
			static const DrawMode kDrawMode_Triangle_Adjacency = GL_TRIANGLES_ADJACENCY;
			
			static const DrawMode kDrawMode_Patches = GL_PATCHES;
			
			enum MemMapIndexData
			{
				
				MAP_INDEXBUFFER_WRITEONLY,
				
			};
			
			Mesh ( DrawMode Mode, Util :: RCMem * IndexData, uint32_t IndexCount, GPU::IndexBuffer :: IndexType IType = GPU::IndexBuffer :: kIndexType_UInts, GPU::IndexBuffer :: UsageType IUsage = GPU::IndexBuffer :: kUsageType_Static_Draw );
			Mesh ( MemMapIndexData MAP_INDEXBUFFER_WRITEONLY, uint32_t IndexCount, GPU::IndexBuffer :: IndexType IType = GPU::IndexBuffer :: kIndexType_UInts, bool Draw = true );
			
			~Mesh ();
			
			void SetDrawMode ( DrawMode Mode );
			
			void ReIndex ( uint32_t IndexCount, Util :: RCMem * IndexData );
			void ReIndex ( MemMapIndexData MapIndexBufferMemory, uint32_t IndexCount );
			
			void * GetIndexMemoryPointer ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			void FlushIndexes ( bool DiscardDataReference );
			void FlushVertexes ( bool FreeDataReferences );
			
			DrawMode GetDrawMode ();
			
			void BindForDraw ();
			
			void BuildVertexArray ( GPU :: VertexArray & Target );
			
			void AddAttributeData ( MeshAttributeData * AttributeData );
			void AddAttribute ( MeshAttribute * Attribute );
			
			uint32_t GetIndexCount ();
			GPU::IndexBuffer :: IndexType GetIndexType ();
			
		private:
			
			GPU :: IndexBuffer IndexBuff;
			
			Util :: RCMem * IndexData;
			uint32_t IndexCount;
			
			DrawMode Mode;
			
			bool IndexDirty;
			bool GPUAllocated;
			bool Mapped;
			
			std :: vector <MeshAttribute *> AttributeList;
			std :: vector <MeshAttributeData *> AttributeDataList;
			
		};
		
	};
	
};

#endif
