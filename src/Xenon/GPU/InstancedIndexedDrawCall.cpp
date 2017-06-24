#include <Xenon/GPU/InstancedIndexedDrawCall.h>

Xenon::GPU::InstancedIndexedDrawCall :: InstancedIndexedDrawCall ( DrawCall :: DrawMode Mode, GLuint ElementCount, IndexBuffer :: IndexType Type, GLuint InstanceCount, void * IndexBufferOffset ):
	RefCounted ( 0 ),
	Mode ( Mode ),
	ElementCount ( ElementCount ),
	Type ( Type ),
	InstanceCount ( InstanceCount ),
	IndexBufferOffset ( IndexBufferOffset )
{
}

Xenon::GPU::InstancedIndexedDrawCall :: InstancedIndexedDrawCall ( DrawCall :: DrawMode Mode, IndexBuffer & ForBuffer, GLuint InstanceCount, void * IndexBufferOffset ):
	RefCounted ( 0 ),
	Mode ( Mode ),
	ElementCount ( ForBuffer.GetIndexCount () ),
	Type ( ForBuffer.GetIndexType () ),
	InstanceCount ( InstanceCount ),
	IndexBufferOffset ( IndexBufferOffset )
{
}

Xenon::GPU::InstancedIndexedDrawCall :: InstancedIndexedDrawCall ( NoInit NO_INIT ):
	RefCounted ( 0 ),
	Mode ( DrawCall :: kDrawMode_Point ),
	ElementCount ( 0 ),
	Type ( IndexBuffer :: kIndexType_UBytes ),
	InstanceCount ( 0 ),
	IndexBufferOffset ( NULL )
{
	
	(void) NO_INIT;
	
}

Xenon::GPU::InstancedIndexedDrawCall :: ~InstancedIndexedDrawCall ()
{
}

void Xenon::GPU::InstancedIndexedDrawCall :: SetDrawMode ( DrawCall :: DrawMode Mode )
{
	
	this -> Mode = Mode;
	
}

void Xenon::GPU::InstancedIndexedDrawCall :: SetElementCount ( GLuint ElementCount )
{
	
	this -> ElementCount = ElementCount;
	
}

void Xenon::GPU::InstancedIndexedDrawCall :: SetIndexType ( IndexBuffer :: IndexType Type )
{
	
	this -> Type = Type;
	
}

void Xenon::GPU::InstancedIndexedDrawCall :: SetIndexBufferOffset ( void * IndexBufferOffset )
{
	
	this -> IndexBufferOffset = IndexBufferOffset;
	
}

void Xenon::GPU::InstancedIndexedDrawCall :: SetInstanceCount ( GLuint InstanceCount )
{
	
	this -> InstanceCount = InstanceCount;
	
}

void Xenon::GPU::InstancedIndexedDrawCall :: Draw ()
{
	
	if ( InstanceCount != 0 )
		glDrawElementsInstanced ( Mode, ElementCount, Type, IndexBufferOffset, InstanceCount );
	
}


