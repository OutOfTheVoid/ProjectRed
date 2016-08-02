#include <Xenon/GPU/VertexBuffer.h>

#include <Xenon/GPU/Context.h>

Xenon::GPU::VertexBuffer :: VertexBuffer ( UsageType Usage ):
	RefCounted ( 0 ),
	Usage ( Usage ),
	Allocated ( false ),
	Size ( 0 ),
	Written ( false ),
	BHandle ( 0 )
{
}

Xenon::GPU::VertexBuffer :: ~VertexBuffer ()
{
	
	GPUResourceFree ();
	
}

void Xenon::GPU::VertexBuffer :: GPUResourceAlloc ()
{
	
	if ( Allocated )
		return;
	
	glGenBuffers ( 1, & BHandle );
	
	if ( BHandle != 0 )
		Allocated = true;
	
}

void Xenon::GPU::VertexBuffer :: GPUResourceFree ()
{
	
	if ( ! Allocated )
		return;
	
	glDeleteBuffers ( 1, & BHandle );
	BHandle = 0;
	
	Allocated = false;
	
}

bool Xenon::GPU::VertexBuffer :: GPUResourceAllocated ()
{
	
	return Allocated;
	
}

void Xenon::GPU::VertexBuffer :: Buffer ( const GLvoid * Data, GLsizeiptr Size )
{
	
	Bind ();
	
	glBufferData ( GL_ARRAY_BUFFER, Size, Data, Usage );
	
	this -> Size = Size;
	Written = true;
	
}

void Xenon::GPU::VertexBuffer :: SubBuffer ( const GLvoid * SubData, GLsizeiptr Size, GLintptr Offset )
{
	
	Bind ();
	
	glBufferSubData ( GL_ARRAY_BUFFER, Offset, Size, SubData );
	
}

void Xenon::GPU::VertexBuffer :: Orphan ()
{
	
	glBufferData ( GL_ARRAY_BUFFER, Size, NULL, Usage );
	
}

void Xenon::GPU::VertexBuffer :: Bind ()
{
	
	if ( ! Allocated )
	{
		
		GPUResourceAlloc ();
	
		if ( ! Allocated )
			return;
		
	}
	
	if ( Context :: CurrentBoundContext -> CurrentBoundArrayBuffer != this )
	{
		
		glBindBuffer ( GL_ARRAY_BUFFER, BHandle );
		
		Context :: CurrentBoundContext -> CurrentBoundArrayBuffer = this;
	
	}
	
}

