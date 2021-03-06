#include <Xenon/Geometry/MeshAttributeData.h>

Xenon::Geometry::MeshAttributeData :: MeshAttributeData ( Red::Util :: RCMem * Data, GLsizei Size, GPU::VertexBuffer :: UsageType UsageMode, bool Orphaning ):
	RefCounted ( 0 ),
	Data ( Data ),
	Size ( Size ),
	Written ( false ),
	Buffer ( UsageMode ),
	Dirty ( false ),
	Orphaning ( Orphaning )
{
	
	if ( Data != NULL )
		Data -> Reference ();
	
}

Xenon::Geometry::MeshAttributeData :: MeshAttributeData ( MeshAttributeData & CopyFrom ):
	RefCounted ( CopyFrom ),
	Data ( CopyFrom.Data ),
	Size ( CopyFrom.Size ),
	Written ( CopyFrom.Written ),
	Buffer ( CopyFrom.Buffer ),
	Dirty ( true ),
	Orphaning ( CopyFrom.Orphaning )
{
	
	CopyFrom.Data = NULL;
	
}

Xenon::Geometry::MeshAttributeData :: ~MeshAttributeData ()
{
	
	GPUResourceFree ();
	
	if ( Data != NULL )
		Data -> Dereference ();
	
}

void Xenon::Geometry::MeshAttributeData :: MarkDirty ()
{
	
	Dirty = true;
	
}

void Xenon::Geometry::MeshAttributeData :: GPUResourceAlloc ()
{
	
	Buffer.GPUResourceAlloc ();
	
}

void Xenon::Geometry::MeshAttributeData :: GPUResourceFree ()
{
	
	Buffer.GPUResourceFree ();
	
}

bool Xenon::Geometry::MeshAttributeData :: GPUResourceAllocated ()
{
	
	return Buffer.GPUResourceAllocated ();
	
}

void Xenon::Geometry::MeshAttributeData :: Update ( bool FreeDataReference )
{
	
	if ( Data == NULL )
		return;
	
	Buffer.Bind ();
	
	if ( ! Written )
	{
		
		Buffer.Buffer ( Data -> GetData (), Size );
		
		if ( FreeDataReference )
		{
			
			Data -> Dereference ();
			
			Data = NULL;
			
		}
		
		Written = true;
		
		return;
		
	}
	
	if ( Dirty )
	{
		
		if ( Orphaning )
			Buffer.Orphan ();
		
		Buffer.SubBuffer ( Data, Size, 0 );
		
	}
	
}

Xenon::GPU :: VertexBuffer * Xenon::Geometry::MeshAttributeData :: GetBuffer ()
{
	
	return & Buffer;
	
}
