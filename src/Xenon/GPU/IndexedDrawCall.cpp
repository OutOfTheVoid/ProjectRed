#include <Xenon/GPU/IndexedDrawCall.h>

Xenon::GPU::IndexedDrawCall :: IndexedDrawCall ( DrawCall :: DrawMode Mode, GLuint ElementCount, IndexBuffer :: IndexType Type, void * IndexBufferOffset ):
	RefCounted ( 0 ),
	Mode ( Mode ),
	ElementCount ( ElementCount ),
	Type ( Type ),
	IndexBufferOffset ( IndexBufferOffset )
{
}

Xenon::GPU::IndexedDrawCall :: IndexedDrawCall ( NoInit NO_INIT ):
	RefCounted ( 0 ),
	Mode ( DrawCall :: kDrawMode_Point ),
	ElementCount ( 0 ),
	Type ( IndexBuffer :: kIndexType_UBytes ),
	IndexBufferOffset ( NULL )
{
	
	(void) NO_INIT;
	
}

Xenon::GPU::IndexedDrawCall :: ~IndexedDrawCall ()
{
}

void Xenon::GPU::IndexedDrawCall :: SetDrawMode ( DrawCall :: DrawMode Mode )
{
	
	this -> Mode = Mode;
	
}

void Xenon::GPU::IndexedDrawCall :: SetElementCount ( GLuint ElementCount )
{
	
	this -> ElementCount = ElementCount;
	
}

void Xenon::GPU::IndexedDrawCall :: SetIndexType ( IndexBuffer :: IndexType Type )
{
	
	this -> Type = Type;
	
}

void Xenon::GPU::IndexedDrawCall :: SetIndexBufferOffset ( void * IndexBufferOffset )
{
	
	this -> IndexBufferOffset = IndexBufferOffset;
	
}

void Xenon::GPU::IndexedDrawCall :: Draw ()
{
	
	glDrawElements ( Mode, ElementCount, Type, IndexBufferOffset );
	
}


