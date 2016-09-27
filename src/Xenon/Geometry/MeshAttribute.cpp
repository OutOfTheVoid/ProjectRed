#include <Xenon/Geometry/MeshAttribute.h>
#include <Xenon/Geometry/MeshAttributeData.h>

Xenon::Geometry::MeshAttribute :: MeshAttribute ( const std :: string & Name, GPU::VertexArray :: FPAttributeInputType FloatingType, bool Normalized, GLuint Size, GLuint Stride, GLvoid * Offset, MeshAttributeData * Data, GLuint InstanceDivisor ):
	RefCounted ( 0 ),
	Name ( Name ),
	FloatingPointInput ( true ),
	FloatingType ( FloatingType ),
	Normalized ( Normalized ),
	Size ( Size ),
	Stride ( Stride ),
	Offset ( Offset ),
	InstanceDivisor ( InstanceDivisor ),
	Data ( Data )
{
	
	if ( Data != NULL )
		Data -> Reference ();
	
}

Xenon::Geometry::MeshAttribute :: MeshAttribute ( const std :: string & Name, GPU::VertexArray :: IntegerAttributeInputType IntegerType, GLuint Size, GLuint Stride, GLvoid * Offset, MeshAttributeData * Data, GLuint InstanceDivisor ):
	RefCounted ( 0 ),
	Name ( Name ),
	FloatingPointInput ( false ),
	IntegerType ( IntegerType ),
	Normalized ( false ),
	Size ( Size ),
	Stride ( Stride ),
	Offset ( Offset ),
	InstanceDivisor ( InstanceDivisor ),
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
		Target.AddFPAttribute ( Name, Size, FloatingType, Normalized, Stride, Offset, Data -> GetBuffer (), InstanceDivisor );
	else
		Target.AddIntegerAttribute ( Name, Size, IntegerType, Stride, Offset, Data -> GetBuffer (), InstanceDivisor );
	
}

Xenon::Geometry :: MeshAttributeData * Xenon::Geometry::MeshAttribute :: GetDataPointer ()
{
	
	return Data;
	
}

GLvoid * Xenon::Geometry::MeshAttribute :: GetDataOffset ()
{
	
	return Offset;
	
}

GLuint Xenon::Geometry::MeshAttribute :: GetStride ()
{
	
	return Stride;
	
}

GLuint Xenon::Geometry::MeshAttribute :: GetSize ()
{
	
	return Size;
	
}

GLuint Xenon::Geometry::MeshAttribute :: GetInstanceDivisor ()
{
	
	return InstanceDivisor;
	
}

bool Xenon::Geometry::MeshAttribute :: IsFloatingPoint ()
{
	
	return FloatingPointInput;
	
}

Xenon::GPU::VertexArray :: FPAttributeInputType Xenon::Geometry::MeshAttribute :: GetFloatingType ()
{
	
	return FloatingType;
	
}

Xenon::GPU::VertexArray :: IntegerAttributeInputType Xenon::Geometry::MeshAttribute :: GetIntegerType ()
{
	
	return IntegerType;
	
}

const std :: string & Xenon::Geometry::MeshAttribute :: GetName ()
{
	
	return Name;
	
}
