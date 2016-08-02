#include <Xenon/Geometry/MeshAttribute.h>
#include <Xenon/Geometry/MeshAttributeData.h>

Xenon::Geometry::MeshAttribute :: MeshAttribute ( const std :: string Name, GPU::VertexArray :: FPAttributeInputType FloatingType, bool Normalized, GLuint Size, GLuint Stride, GLvoid * Offset, MeshAttributeData * Data ):
	RefCounted ( 0 ),
	Name ( Name ),
	FloatingPointInput ( true ),
	FloatingType ( FloatingType ),
	Normalized ( Normalized ),
	Size ( Size ),
	Stride ( Stride ),
	Offset ( Offset ),
	Data ( Data )
{
	
	if ( Data != NULL )
		Data -> Reference ();
	
}

Xenon::Geometry::MeshAttribute :: MeshAttribute ( const std :: string Name, GPU::VertexArray :: IntegerAttributeInputType IntegerType, GLuint Size, GLuint Stride, GLvoid * Offset, MeshAttributeData * Data ):
	RefCounted ( 0 ),
	Name ( Name ),
	FloatingPointInput ( false ),
	IntegerType ( IntegerType ),
	Normalized ( false ),
	Size ( Size ),
	Stride ( Stride ),
	Offset ( Offset ),
	Data ( Data )
{
	
	if ( Data != NULL )
		Data -> Reference ();
	
}

Xenon::Geometry::MeshAttribute :: MeshAttribute ( NoInit NO_INIT ):
	Data ( NULL )
{
	
	(void) NO_INIT;
	
}

Xenon::Geometry::MeshAttribute :: ~MeshAttribute ()
{
	
	if ( Data != NULL )
		Data -> Dereference ();
	
	Data = NULL;
	
}

void Xenon::Geometry::MeshAttribute :: ApplyToVertexArray ( GPU :: VertexArray & Target )
{
	
	if ( Data == NULL )
		return;
	
	if ( FloatingPointInput )
		Target.AddFPAttribute ( Name, Size, FloatingType, Normalized, Stride, Offset, Data -> GetBuffer () );
	else
		Target.AddIntegerAttribute ( Name, Size, IntegerType, Stride, Offset, Data -> GetBuffer () );
	
}
