#include <Xenon/Geometry/MeshAttribute.h>
#include <Xenon/Geometry/MeshAttributeData.h>

Xenon::Geometry::MeshAttribute :: MeshAttribute ( const std :: string & Name, GPU::VertexArray :: FPAttributeInputType FloatingType, bool Normalized, GLuint Size, GLuint Stride, GLvoid * Offset, MeshAttributeData * Data, GLuint InstanceDivisor, GLuint MatrixRowing, GLuint RowStride ):
	RefCounted ( 0 ),
	Name ( Name ),
	FloatingPointInput ( true ),
	FloatingType ( FloatingType ),
	Normalized ( Normalized ),
	Size ( Size ),
	Stride ( Stride ),
	Offset ( Offset ),
	InstanceDivisor ( InstanceDivisor ),
	Data ( Data ),
	MatrixRowing ( MatrixRowing ),
	RowStride ( RowStride )
{
	
	if ( Data != NULL )
		Data -> Reference ();
	
}

Xenon::Geometry::MeshAttribute :: MeshAttribute ( const std :: string & Name, GPU::VertexArray :: IntegerAttributeInputType IntegerType, GLuint Size, GLuint Stride, GLvoid * Offset, MeshAttributeData * Data, GLuint InstanceDivisor, GLuint MatrixRowing, GLuint RowStride ):
	RefCounted ( 0 ),
	Name ( Name ),
	FloatingPointInput ( false ),
	IntegerType ( IntegerType ),
	Normalized ( false ),
	Size ( Size ),
	Stride ( Stride ),
	Offset ( Offset ),
	InstanceDivisor ( InstanceDivisor ),
	Data ( Data ),
	MatrixRowing ( MatrixRowing ),
	RowStride ( RowStride )
{
	
	if ( Data != NULL )
		Data -> Reference ();
	
}

Xenon::Geometry::MeshAttribute :: MeshAttribute ( MeshAttribute & CopyFrom ):
	RefCounted ( CopyFrom ),
	Name ( CopyFrom.Name ),
	FloatingPointInput ( CopyFrom.FloatingPointInput ),
	Normalized ( CopyFrom.Normalized ),
	Size ( CopyFrom.Size ),
	Stride ( CopyFrom.Stride ),
	Offset ( CopyFrom.Offset ),
	InstanceDivisor ( CopyFrom.InstanceDivisor ),
	Data ( CopyFrom.Data ),
	MatrixRowing ( CopyFrom.MatrixRowing ),
	RowStride ( CopyFrom.RowStride )
{
	
	if ( FloatingPointInput )
		this -> FloatingType = CopyFrom.FloatingType;
	else
		this -> IntegerType = CopyFrom.IntegerType;
	
	CopyFrom.Data = NULL;
	
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
	{
		
		for ( uint32_t I = 0; I < MatrixRowing; I ++ )
			Target.AddFPAttribute ( Name, Size, FloatingType, Normalized, Stride, & reinterpret_cast <GLchar *> ( Offset ) [ RowStride * I ], Data -> GetBuffer (), InstanceDivisor, I );
		
	}
	else
	{
		
		for ( uint32_t I = 0; I < MatrixRowing; I ++ )
			Target.AddIntegerAttribute ( Name, Size, IntegerType, Stride, & reinterpret_cast <GLchar *> ( Offset ) [ RowStride * I ], Data -> GetBuffer (), InstanceDivisor, I );
		
	}
	
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

GLuint Xenon::Geometry::MeshAttribute :: GetMatrixRowing ()
{
	
	return MatrixRowing;
	
}

GLuint Xenon::Geometry::MeshAttribute :: GetRowStride ()
{
	
	return RowStride;
	
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
