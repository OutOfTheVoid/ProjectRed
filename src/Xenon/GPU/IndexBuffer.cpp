#include <Xenon/GPU/IndexBuffer.h>
#include <Xenon/GPU/Context.h>

Xenon::GPU::IndexBuffer :: IndexBuffer ( UsageType Usage, IndexType Type ):
	RefCounted ( 0 ),
	Usage ( Usage ),
	Type ( Type ),
	Allocated ( false ),
	MMapped ( false ),
	ReadableMap ( false ),
	MapAddress ( NULL ),
	BHandle ( 0 ),
	Count ( 0 )
{
}

Xenon::GPU::IndexBuffer :: ~IndexBuffer ()
{
	
	GPUResourceFree ();
	
}

void Xenon::GPU::IndexBuffer :: GPUResourceAlloc ()
{
	
	if ( Allocated )
		return;
	
	glGenBuffers ( 1, & BHandle );
	
	if ( BHandle != 0 )
		Allocated = true;
	
}

void Xenon::GPU::IndexBuffer :: GPUResourceFree ()
{
	
	if ( ! Allocated )
		return;
	
	Unmap ();
	
	glDeleteBuffers ( 1, & BHandle );
	BHandle = 0;
	
	Allocated = false;
	
}

bool Xenon::GPU::IndexBuffer :: GPUResourceAllocated ()
{
	
	return Allocated;
	
}

void Xenon::GPU::IndexBuffer :: Buffer ( const GLvoid * Data, GLuint Count )
{
	
	Bind ();
	
	this -> Count = Count;
	
	switch ( Type )
	{
		
		case kIndexType_UBytes:
			glBufferData ( GL_ELEMENT_ARRAY_BUFFER, sizeof ( GLubyte ) * Count, Data, Usage );
			break;
		
		case kIndexType_UShorts:
			glBufferData ( GL_ELEMENT_ARRAY_BUFFER, sizeof ( GLushort ) * Count, Data, Usage );
			break;
		
		case kIndexType_UInts:
			glBufferData ( GL_ELEMENT_ARRAY_BUFFER, sizeof ( GLuint ) * Count, Data, Usage );		
			break;
		
		default:
			Count = 0;
			break;
		
	}
	
}

void Xenon::GPU::IndexBuffer :: SubBuffer ( const GLvoid * SubData, GLuint Count, GLuint Offset )
{
	
	Bind ();
	
	switch ( Type )
	{
		
		case kIndexType_UBytes:
			glBufferSubData ( GL_ELEMENT_ARRAY_BUFFER, sizeof ( GLubyte ) * Offset, sizeof ( GLubyte ) * Count, SubData );
			break;
		
		case kIndexType_UShorts:
			glBufferSubData ( GL_ELEMENT_ARRAY_BUFFER, sizeof ( GLushort ) * Offset, sizeof ( GLushort ) * Count, SubData );
			break;
		
		case kIndexType_UInts:
			glBufferSubData ( GL_ELEMENT_ARRAY_BUFFER, sizeof ( GLuint ) * Offset, sizeof ( GLuint ) * Count, SubData );
			break;
		
	}
	
}

void * Xenon::GPU::IndexBuffer :: Map ( bool Read )
{
	
	Bind ();
	
	if ( MMapped )
	{
		
		if ( ReadableMap == Read )
			return MapAddress;
		
		Unmap ();
		
	} 
	
	MapAddress = glMapBuffer ( GL_ELEMENT_ARRAY_BUFFER, Read ? GL_WRITE_ONLY | GL_MAP_UNSYNCHRONIZED_BIT : GL_READ_WRITE );
	
	ReadableMap = Read;
	MMapped = MapAddress != NULL;
	
	return MapAddress;
	
}

void Xenon::GPU::IndexBuffer :: Unmap ()
{
	
	Bind ();
	
	if ( ! MMapped )
		return;
	
	glUnmapBuffer ( GL_ELEMENT_ARRAY_BUFFER );
	
	MMapped = false;
	
}

bool Xenon::GPU::IndexBuffer :: Mapped ()
{
	
	return MMapped;
	
}

void Xenon::GPU::IndexBuffer :: FlushMap ()
{
	
	if ( ! MMapped )
		return;
	
	Bind ();
	
	switch ( Type )
	{
		
		case kIndexType_UBytes:
			glFlushMappedBufferRange ( GL_ELEMENT_ARRAY_BUFFER, 0, sizeof ( GLubyte ) * Count );
			break;
			
		case kIndexType_UShorts:
			glFlushMappedBufferRange ( GL_ELEMENT_ARRAY_BUFFER, 0, sizeof ( GLushort ) * Count );
			break;
			
		case kIndexType_UInts:
			glFlushMappedBufferRange ( GL_ELEMENT_ARRAY_BUFFER, 0, sizeof ( GLuint ) * Count );
			break;
			
	}
	
}

void Xenon::GPU::IndexBuffer :: Orphan ()
{
	
	Bind ();
	
	if ( MMapped )
	{
		
		if ( ! ReadableMap )
		{
			
			switch ( Type )
			{
				
				case kIndexType_UBytes:
					MapAddress = glMapBufferRange ( GL_ELEMENT_ARRAY_BUFFER, 0, sizeof ( GLubyte ) * Count, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT );
					break;
				
				case kIndexType_UShorts:
					MapAddress = glMapBufferRange ( GL_ELEMENT_ARRAY_BUFFER, 0, sizeof ( GLushort ) * Count, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT );
					break;
				
				case kIndexType_UInts:
					MapAddress = glMapBufferRange ( GL_ELEMENT_ARRAY_BUFFER, 0, sizeof ( GLuint ) * Count, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT );
					break;
					
				default:
					break;
					
			}
			
			return;
		
		}
		
	}
	
	switch ( Type )
	{
		
		case kIndexType_UBytes:
			glBufferData ( GL_ELEMENT_ARRAY_BUFFER, sizeof ( GLubyte ) * Count, NULL, Usage );
			break;
		
		case kIndexType_UShorts:
			glBufferData ( GL_ELEMENT_ARRAY_BUFFER, sizeof ( GLushort ) * Count, NULL, Usage );
			break;
		
		case kIndexType_UInts:
			glBufferData ( GL_ELEMENT_ARRAY_BUFFER, sizeof ( GLuint ) * Count, NULL, Usage );	
			break;
		
		default:
			break;
		
	}
	
}

void Xenon::GPU::IndexBuffer :: Bind ()
{
	
	if ( ! Allocated )
	{
		
		GPUResourceAlloc ();
		
		if ( ! Allocated )
			return;
		
	}
	
	glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER, BHandle );
	
}

Xenon::GPU::IndexBuffer :: IndexType Xenon::GPU::IndexBuffer :: GetIndexType ()
{
	
	return Type;
	
}

GLuint Xenon::GPU::IndexBuffer :: GetIndexCount ()
{
	
	return Count;
	
}
