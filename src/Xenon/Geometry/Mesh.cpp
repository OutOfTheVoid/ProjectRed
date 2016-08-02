#include <Xenon/Geometry/Mesh.h>

Xenon::Geometry::Mesh :: Mesh ( DrawMode Mode, Util :: RCMem * IndexData, uint32_t IndexCount, GPU::IndexBuffer :: IndexType IType, GPU::IndexBuffer :: UsageType IUsage ):
	IndexBuff ( IUsage, IType ),
	IndexData ( IndexData ),
	IndexCount ( IndexCount ),
	Mode ( Mode ),
	IndexDirty ( true ),
	GPUAllocated ( false ),
	Mapped ( false ),
	AttributeList (),
	AttributeDataList ()
{
	
	IndexData -> Reference ();
	
}

Xenon::Geometry::Mesh :: Mesh ( MemMapIndexData MAP_INDEXBUFFER, DrawMode Mode, uint32_t IndexCount, GPU::IndexBuffer :: IndexType IType, bool Draw ):
	IndexBuff ( Draw ? GPU::IndexBuffer :: kUsageType_Stream_Draw : GPU::IndexBuffer :: kUsageType_Stream_Copy, IType ),
	IndexData ( NULL ),
	IndexCount ( IndexCount ),
	Mode ( Mode ),
	IndexDirty ( true ),
	GPUAllocated ( false ),
	Mapped ( false )
{
	
	(void) MAP_INDEXBUFFER;
	
}

Xenon::Geometry::Mesh :: ~Mesh ()
{
	
	if ( IndexData != NULL )
	{
		
		IndexData -> Dereference ();
		
		IndexData = NULL;
		
	}
	
	while ( AttributeDataList.size () > 0 )
	{
		
		AttributeList [ AttributeDataList.size () - 1 ] -> Dereference ();
		
		AttributeDataList.pop_back ();
		
	}
	
	if ( GPUAllocated )
		GPUResourceFree ();
	
}
			
void Xenon::Geometry::Mesh :: SetDrawMode ( DrawMode Mode )
{
	
	this -> Mode = Mode;
	
}

void Xenon::Geometry::Mesh :: ReIndex ( uint32_t IndexCount, Util :: RCMem * IndexData )
{
	
	if ( GPUAllocated && IndexBuff.Mapped () )
		return;
	
	if ( this -> IndexData != NULL )
		this -> IndexData -> Dereference ();
	
	this -> IndexData = IndexData;
	this -> IndexCount = IndexCount;
	
	IndexDirty = true;
	
}

void Xenon::Geometry::Mesh :: ReIndex ( MemMapIndexData MAP_INDEXBUFFER, uint32_t IndexCount )
{
	
	(void) MAP_INDEXBUFFER;
	
	if ( GPUAllocated && ! IndexBuff.Mapped () )
		return;
	
	this -> IndexCount = IndexCount;
	
	IndexDirty = true;
	
}

void * Xenon::Geometry::Mesh :: GetIndexMemoryPointer ()
{
	
	if ( IndexData != NULL )
		return IndexData -> GetData ();
	
	if ( ! GPUAllocated )
	{
		
		GPUResourceAlloc ();
		IndexBuff.Buffer ( NULL, IndexCount );
		
	}
	
	return IndexBuff.Map ();
	
}

void Xenon::Geometry::Mesh :: GPUResourceAlloc ()
{
	
	if ( GPUAllocated )
		return;
	
	IndexBuff.GPUResourceAlloc ();
	
	GPUAllocated = IndexBuff.GPUResourceAllocated ();
	
}

void Xenon::Geometry::Mesh :: GPUResourceFree ()
{
	
	if ( ! GPUAllocated )
		return;
	
	IndexBuff.GPUResourceFree ();
	
	GPUAllocated = false;
	
}

bool Xenon::Geometry::Mesh :: GPUResourceAllocated ()
{
	
	return GPUAllocated;
	
}

void Xenon::Geometry::Mesh :: FlushIndexes ( bool DiscardDataReference )
{
	
	IndexBuff.Bind ();
	
	if ( IndexDirty )
	{
		
		if ( IndexBuff.Mapped () )
			IndexBuff.FlushMap ();
		else if ( IndexData != NULL )
		{
			
			IndexBuff.Buffer ( IndexData -> GetData (), IndexCount );
			
			IndexDirty = false;
			
		}
		
	}
	
	if ( DiscardDataReference && ( IndexData != NULL ) )
	{
		
		IndexData -> Dereference ();
		
		IndexData = NULL;
		
	}
	
}

Xenon::Geometry::Mesh :: DrawMode Xenon::Geometry::Mesh :: GetDrawMode ()
{
	
	return Mode;
	
}

void Xenon::Geometry::Mesh :: BindForDraw ()
{
	
	FlushIndexes ( false );
	FlushVertexes ( false );
	
}

void Xenon::Geometry::Mesh :: FlushVertexes ( bool FreeDataReferences )
{
	
	for ( uint32_t I = 0; I < AttributeDataList.size (); I ++ )
		AttributeDataList [ I ] -> Update ( FreeDataReferences );
	
}

void Xenon::Geometry::Mesh :: BuildVertexArray ( GPU :: VertexArray & Target )
{
	
	if ( ! GPUAllocated )
		GPUResourceAlloc ();
	
	BindForDraw ();
	
	for ( uint32_t I = 0; I < AttributeList.size (); I ++ )
		AttributeList [ I ] -> ApplyToVertexArray ( Target );
	
	Target.SetIndexBuffer ( & IndexBuff );
	
}

void Xenon::Geometry::Mesh :: AddAttribute ( MeshAttribute * Attribute )
{
	
	AttributeList.push_back ( Attribute );
	
}

void Xenon::Geometry::Mesh :: AddAttributeData ( MeshAttributeData * AttributeData )
{
	
	AttributeDataList.push_back ( AttributeData );
	
}

uint32_t Xenon::Geometry::Mesh :: GetIndexCount ()
{
	
	return IndexBuff.GetIndexCount ();
	
}

Xenon::GPU::IndexBuffer :: IndexType Xenon::Geometry::Mesh :: GetIndexType ()
{
	
	return IndexBuff.GetIndexType ();
	
}
