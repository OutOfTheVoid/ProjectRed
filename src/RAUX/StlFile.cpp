#include <RAUX/StlFile.h>

#ifdef RAUX_XENON_INTERFACE

	#include <Xenon/Util/RCMem.h>
	#include <Xenon/Geometry/MeshAttribute.h>
	#include <Xenon/Geometry/MeshAttributeData.h>
	#include <Xenon/GPU/GLInclude.h>
	#include <Xenon/GPU/IndexBuffer.h>
	#include <Xenon/GPU/VertexArray.h>
	#include <Xenon/GPU/VertexBuffer.h>

#endif

#include <RAUX/Endian.h>

#include <limits>
#include <iostream>
#include <float.h>

RAUX::StlFile :: StlFile ( const std :: string & Name ):
	FileInstance ( Name ),
	TriangleCount ( 0 ),
	TriangleList ( NULL ),
	Flags ( 0 )
{
}

RAUX::StlFile :: ~StlFile ()
{
	
	if ( TriangleList != NULL )
	{
		
		delete [] TriangleList;
		TriangleList = NULL;
		
	}
	
}

bool RAUX::StlFile :: Exists () const
{
	
	return FileInstance.Exists ();
	
}

void RAUX::StlFile :: Load ( uint32_t * Status, uint32_t Flags )
{
	
	if ( TriangleList != NULL )
		return;
	
	static_assert ( std::numeric_limits <float> :: is_iec559, "RAUX STL decoding requires IEEE-754 encoding for single precision floating point types." );
	
	uint32_t SubStatus;
	
	if ( ! FileInstance.Exists () )
	{
		
		* Status = kStatus_Failure_NonExistantFile;
		
		return;
		
	}
	
	FileInstance.Open ( & SubStatus );
	
	if ( SubStatus != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	TriangleCount = 0;
	FileInstance.Read ( & TriangleCount, 4, 80, & SubStatus );
	
	if ( SubStatus != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
#ifndef RAUX_LITTLE_ENDIAN_DEFINITE
	TriangleCount = LittleToHostEndian32 ( TriangleCount );
#endif
	
	TriangleList = new Triangle [ TriangleCount ];
	
	for ( uint32_t I = 0; I < TriangleCount; I ++ )
	{
		
		char Buffer [ 14 ];
		
		FileInstance.Read ( reinterpret_cast <void *> ( Buffer ), 50, 84 + 50 * I, & SubStatus );
		
		TriangleList [ I ].Normal.X = * reinterpret_cast <float *> ( & Buffer [ 0 ] );
		TriangleList [ I ].Normal.Y = * reinterpret_cast <float *> ( & Buffer [ 4 ] );
		TriangleList [ I ].Normal.Z = * reinterpret_cast <float *> ( & Buffer [ 8 ] );
		TriangleList [ I ].P1.X = * reinterpret_cast <float *> ( & Buffer [ 12 ] );
		TriangleList [ I ].P1.Y = * reinterpret_cast <float *> ( & Buffer [ 16 ] );
		TriangleList [ I ].P1.Z = * reinterpret_cast <float *> ( & Buffer [ 20 ] );
		TriangleList [ I ].P2.X = * reinterpret_cast <float *> ( & Buffer [ 24 ] );
		TriangleList [ I ].P2.Y = * reinterpret_cast <float *> ( & Buffer [ 28 ] );
		TriangleList [ I ].P2.Z = * reinterpret_cast <float *> ( & Buffer [ 32 ] );
		TriangleList [ I ].P3.X = * reinterpret_cast <float *> ( & Buffer [ 36 ] );
		TriangleList [ I ].P3.Y = * reinterpret_cast <float *> ( & Buffer [ 40 ] );
		TriangleList [ I ].P3.Z = * reinterpret_cast <float *> ( & Buffer [ 44 ] );
		
	};
	
	
	
	if ( SubStatus != File :: kStatus_Success )
	{
		
		delete TriangleList;
		TriangleCount = 0;
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	Vec3 MaxPositions ( 0.0f, 0.0f, 0.0f );
	Vec3 MinPositions ( FLT_MAX, FLT_MAX, FLT_MAX );
	
	for ( uint32_t I = 0; I < TriangleCount; I ++ )
	{
		
#ifndef RAUX_LITTLE_ENDIAN_DEFINITE
		
		TriangleList [ I ].Normal.X = LittleToHostEndianFloat ( TriangleList [ I ].Normal.X );
		TriangleList [ I ].Normal.Y = LittleToHostEndianFloat ( TriangleList [ I ].Normal.Y );
		TriangleList [ I ].Normal.Z = LittleToHostEndianFloat ( TriangleList [ I ].Normal.Z );
		
		TriangleList [ I ].P1.X = LittleToHostEndianFloat ( TriangleList [ I ].P1.X );
		TriangleList [ I ].P1.Y = LittleToHostEndianFloat ( TriangleList [ I ].P1.Y );
		TriangleList [ I ].P1.Z = LittleToHostEndianFloat ( TriangleList [ I ].P1.Z );
		
		TriangleList [ I ].P2.X = LittleToHostEndianFloat ( TriangleList [ I ].P2.X );
		TriangleList [ I ].P2.Y = LittleToHostEndianFloat ( TriangleList [ I ].P2.Y );
		TriangleList [ I ].P2.Z = LittleToHostEndianFloat ( TriangleList [ I ].P2.Z );
		
		TriangleList [ I ].P3.X = LittleToHostEndianFloat ( TriangleList [ I ].P3.X );
		TriangleList [ I ].P3.Y = LittleToHostEndianFloat ( TriangleList [ I ].P3.Y );
		TriangleList [ I ].P3.Z = LittleToHostEndianFloat ( TriangleList [ I ].P3.Z );
		
#endif
		
		if ( ( ( Flags & kFlags_ReplaceNormalsForced ) != 0 ) || ( ( ( Flags & kFlags_ReplaceNormalsConditional ) != 0 ) && ( ( TriangleList [ I ].Normal.X == TriangleList [ I ].Normal.Y ) && ( TriangleList [ I ].Normal.Y == TriangleList [ I ].Normal.Z ) && ( TriangleList [ I ].Normal.Z == 0.0f ) ) ) )
		{
			
			Vec3 D1 ( STLFILE_VEC3_NOINIT );
			Vec3 D2 ( STLFILE_VEC3_NOINIT );
			
			STLFILE_VEC3_SUBTRACT ( D1, TriangleList [ I ].P2, TriangleList [ I ].P1 );
			STLFILE_VEC3_SUBTRACT ( D2, TriangleList [ I ].P3, TriangleList [ I ].P2 );
			
			if ( ( Flags & kFlags_ForwardFace_CounterClockwise ) == 0 )
				STLFILE_VEC3_CROSS ( TriangleList [ I ].Normal, D1, D2 );
			else
				STLFILE_VEC3_CROSS ( TriangleList [ I ].Normal, D2, D1 );
			
			STLFILE_VEC3_NORMALIZE ( TriangleList [ I ].Normal );
			
		}
		
	}
	
	if ( ( ( Flags & kFlags_CenterPositions ) != 0 ) || ( ( Flags & kFlags_NormalizePositions ) != 0 ) )
	{
		
		for ( uint32_t I = 0; I < TriangleCount; I ++ )
		{
			
			if ( MaxPositions.X < TriangleList [ I ].P1.X )
				MaxPositions.X = TriangleList [ I ].P1.X;
			
			if ( MaxPositions.Y < TriangleList [ I ].P1.Y )
				MaxPositions.Y = TriangleList [ I ].P1.Y;
			
			if ( MaxPositions.Z < TriangleList [ I ].P1.Z )
				MaxPositions.Z = TriangleList [ I ].P1.Z;
			
			if ( MaxPositions.X < TriangleList [ I ].P2.X )
				MaxPositions.X = TriangleList [ I ].P2.X;
			
			if ( MaxPositions.Y < TriangleList [ I ].P2.Y )
				MaxPositions.Y = TriangleList [ I ].P2.Y;
			
			if ( MaxPositions.Z < TriangleList [ I ].P2.Z )
				MaxPositions.Z = TriangleList [ I ].P2.Z;
			
			if ( MaxPositions.X < TriangleList [ I ].P3.X )
				MaxPositions.X = TriangleList [ I ].P3.X;
			
			if ( MaxPositions.Y < TriangleList [ I ].P3.Y )
				MaxPositions.Y = TriangleList [ I ].P3.Y;
			
			if ( MaxPositions.Z < TriangleList [ I ].P3.Z )
				MaxPositions.Z = TriangleList [ I ].P3.Z;
			
			if ( MinPositions.X > TriangleList [ I ].P1.X )
				MinPositions.X = TriangleList [ I ].P1.X;
			
			if ( MinPositions.Y > TriangleList [ I ].P1.Y )
				MinPositions.Y = TriangleList [ I ].P1.Y;
			
			if ( MinPositions.Z > TriangleList [ I ].P1.Z )
				MinPositions.Z = TriangleList [ I ].P1.Z;
			
			if ( MinPositions.X > TriangleList [ I ].P2.X )
				MinPositions.X = TriangleList [ I ].P2.X;
			
			if ( MinPositions.Y > TriangleList [ I ].P2.Y )
				MinPositions.Y = TriangleList [ I ].P2.Y;
			
			if ( MinPositions.Z > TriangleList [ I ].P2.Z )
				MinPositions.Z = TriangleList [ I ].P2.Z;
			
			if ( MinPositions.X > TriangleList [ I ].P3.X )
				MinPositions.X = TriangleList [ I ].P3.X;
			
			if ( MinPositions.Y > TriangleList [ I ].P3.Y )
				MinPositions.Y = TriangleList [ I ].P3.Y;
			
			if ( MinPositions.Z > TriangleList [ I ].P3.Z )
				MinPositions.Z = TriangleList [ I ].P3.Z;
			
		}
		
	}
	
	Vec3 LimitRange ( 0.0f, 0.0f, 0.0f );
	STLFILE_VEC3_SUBTRACT ( LimitRange, MaxPositions, MinPositions );
	
	LimitRange.X = fabs ( LimitRange.X );
	LimitRange.Y = fabs ( LimitRange.Y );
	LimitRange.Z = fabs ( LimitRange.Z );
	float RangeMax = fmax ( LimitRange.Z, fmax ( LimitRange.X, LimitRange.Y ) );
	
	Vec3 Origin ( 0.0f, 0.0f, 0.0f );
	Vec3 OffsetToOrigin ( STLFILE_VEC3_NOINIT );
	
	STLFILE_VEC3_SUBTRACT ( OffsetToOrigin, Origin, MinPositions );
	
	for ( uint32_t I = 0; I < TriangleCount; I ++ )
	{
		
		STLFILE_VEC3_ADD ( TriangleList [ I ].P1, OffsetToOrigin );
		STLFILE_VEC3_ADD ( TriangleList [ I ].P2, OffsetToOrigin );
		STLFILE_VEC3_ADD ( TriangleList [ I ].P3, OffsetToOrigin );
		
	}
	
	float ScaleMultiplier = 1.0f;
	
	if ( ( Flags & kFlags_CenterPositions ) != 0 )
		ScaleMultiplier = 2.0f;
	
	if ( ( Flags & kFlags_NormalizePositions ) != 0 )
		ScaleMultiplier /= RangeMax;
	
	if ( ScaleMultiplier != 1.0f )
	{
		
		for ( uint32_t I = 0; I < TriangleCount; I ++ )
		{
			
			STLFILE_VEC3_MULTIPLYSCALAR ( TriangleList [ I ].P1, ScaleMultiplier );
			STLFILE_VEC3_MULTIPLYSCALAR ( TriangleList [ I ].P2, ScaleMultiplier );
			STLFILE_VEC3_MULTIPLYSCALAR ( TriangleList [ I ].P3, ScaleMultiplier );
			
		}
		
	}
	
	if ( ( Flags & kFlags_CenterPositions ) != 0 )
	{
		
		Vec3 PositionOffset ( - 1.0f, - 1.0f, - 1.0f );
		
		if ( ( Flags & kFlags_NormalizePositions ) == 0 )
			STLFILE_VEC3_MULTIPLYSCALAR ( PositionOffset, RangeMax );
		
		for ( uint32_t I = 0; I < TriangleCount; I ++ )
		{
			
			STLFILE_VEC3_ADD ( TriangleList [ I ].P1, PositionOffset );
			STLFILE_VEC3_ADD ( TriangleList [ I ].P2, PositionOffset );
			STLFILE_VEC3_ADD ( TriangleList [ I ].P3, PositionOffset );
			
		}
		
	}
	
}

void RAUX::StlFile :: CloseFile ()
{
	
	uint32_t Status;
	
	FileInstance.Close ( & Status );
	
}

#ifdef RAUX_XENON_INTERFACE

Xenon::Geometry :: Mesh * RAUX::StlFile :: CreateMesh ( const MeshParameters & Params ) const
{
	
	if ( ( TriangleList == NULL ) || ( TriangleCount == 0 ) )
		return NULL;
	
	Xenon::Util :: RCMem * IndexMemory = new Xenon::Util :: RCMem ( sizeof ( GLuint ) * 3 * TriangleCount );
	
	if ( IndexMemory -> GetData () == NULL )
	{
		
		delete IndexMemory;
		
		return NULL;
		
	}
	
	GLuint * Indexes = reinterpret_cast <GLuint *> ( IndexMemory -> GetData () );
	
	if ( Params.Flags & kMeshParameterFlags_ReverseWindingOrder )
	{
		
		for ( uint32_t I = 0; I < TriangleCount; I ++ )
		{
			
			Indexes [ I * 3 ] = I * 3 + 2;
			Indexes [ I * 3 + 1 ] = I * 3 + 1;
			Indexes [ I * 3 + 2 ] = I * 3;
			
		}
		
	}
	else
	{
		
		for ( uint32_t I = 0; I < TriangleCount; I ++ )
		{
			
			Indexes [ I * 3 ] = I * 3;
			Indexes [ I * 3 + 1 ] = I * 3 + 1;
			Indexes [ I * 3 + 2 ] = I * 3 + 2;
			
		}
		
	}
	
	Xenon::Geometry :: Mesh * OutMesh = new Xenon::Geometry :: Mesh ( Xenon::Geometry::Mesh :: kDrawMode_Triangle, IndexMemory, 3 * TriangleCount, Xenon::GPU::IndexBuffer :: kIndexType_UInts, Xenon::GPU::IndexBuffer :: kUsageType_Static_Draw );
	
	Xenon::Geometry :: MeshAttributeData * PositionAttributeData = NULL;
	Xenon::Geometry :: MeshAttribute * PositionMeshAttribute = NULL;
	void * PositionAttributeMemory = NULL;
	size_t PositionStride = 0;
	size_t PositionOffset = 0;
	
	Xenon::Geometry :: MeshAttributeData * NormalAttributeData = NULL;
	Xenon::Geometry :: MeshAttribute * NormalMeshAttribute = NULL;
	void * NormalAttributeMemory = NULL;
	size_t NormalStride = 0;
	size_t NormalOffset = 0;
	
	if ( ( Params.Flags & kMeshParameterFlags_Normals ) != 0 )
	{
		
		if ( ( ( Params.Flags & kMeshParameterFlags_SeperateStaticAttributes ) == 0 ) && ( ( Params.Flags & ( kMeshParameterFlags_DynamicNormals | kMeshParameterFlags_DynamicPositions ) ) == 0 ) )
		{
			
			GLsizei StaticBufferSize = sizeof ( float ) * 18 * TriangleCount;
			Xenon::Util :: RCMem * StaticAttributeMemory = new Xenon::Util :: RCMem ( StaticBufferSize );
			
			if ( StaticAttributeMemory -> GetData () == NULL )
			{
				
				delete OutMesh;
				
				return NULL;
				
			}
			
			PositionAttributeMemory = StaticAttributeMemory -> GetData ();
			PositionStride = sizeof ( float ) * ( ( ( Params.Flags & kMeshParameterFlags_InterleavedAttributes ) != 0 ) ? 6 : 3 );
			PositionOffset = 0;
			
			NormalAttributeMemory = StaticAttributeMemory -> GetData ();
			NormalStride = sizeof ( float ) * ( ( ( Params.Flags & kMeshParameterFlags_InterleavedAttributes ) != 0 ) ? 6 : 3 );
			NormalOffset = sizeof ( float ) * ( ( ( Params.Flags & kMeshParameterFlags_InterleavedAttributes ) != 0 ) ? 3 : ( TriangleCount * 6 ) );
			
			Xenon::Geometry :: MeshAttributeData * StaticAttributeData = new Xenon::Geometry :: MeshAttributeData ( StaticAttributeMemory, StaticBufferSize, Xenon::GPU::VertexBuffer :: kUsageType_Static_Draw );
			
			PositionAttributeData = StaticAttributeData;
			NormalAttributeData = StaticAttributeData;
			
			PositionMeshAttribute = new Xenon::Geometry :: MeshAttribute ( Params.PositionAttributeName, Xenon::GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, PositionStride, reinterpret_cast <void *> ( PositionOffset ), StaticAttributeData );
			NormalMeshAttribute = new Xenon::Geometry :: MeshAttribute ( Params.NormalAttributeName, Xenon::GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, NormalStride, reinterpret_cast <void *> ( NormalOffset ), StaticAttributeData );
			
		}
		else
		{
			
			// TODO: One might be static, the other not, either way, seperate data.
			
		}
		
	}
	else
	{
		
		GLsizei BufferSize = sizeof ( float ) * 12 * TriangleCount;
		Xenon::Util :: RCMem * AttributeMemory = new Xenon::Util :: RCMem ( BufferSize );
		
		if ( AttributeMemory -> GetData () == NULL )
		{
			
			delete OutMesh;
			
			return NULL;
			
		}
		
		PositionAttributeMemory = AttributeMemory -> GetData ();
		PositionStride = sizeof ( float ) * 3;
		PositionOffset = 0;
		
		Xenon::Geometry :: MeshAttributeData * AttributeData = new Xenon::Geometry :: MeshAttributeData ( AttributeMemory, BufferSize, ( ( Params.Flags & kMeshParameterFlags_DynamicPositions ) == 0 ) ? Xenon::GPU::VertexBuffer :: kUsageType_Static_Draw : Xenon::GPU::VertexBuffer :: kUsageType_Dynamic_Draw );
		PositionAttributeData = AttributeData;
		
		PositionMeshAttribute = new Xenon::Geometry :: MeshAttribute ( Params.PositionAttributeName, Xenon::GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, PositionStride, reinterpret_cast <void *> ( PositionOffset ), AttributeData );
		
	}
	
	// Position data
	{
		
		for ( uint32_t I = 0; I < TriangleCount; I ++ )
		{
			
			STLFILE_VEC3_COPY ( * reinterpret_cast <Vec3 *> ( reinterpret_cast <char *> ( PositionAttributeMemory ) + PositionOffset + PositionStride * ( I * 3 ) ), TriangleList [ I ].P1 );
			STLFILE_VEC3_COPY ( * reinterpret_cast <Vec3 *> ( reinterpret_cast <char *> ( PositionAttributeMemory ) + PositionOffset + PositionStride * ( I * 3 + 1 ) ), TriangleList [ I ].P2 );
			STLFILE_VEC3_COPY ( * reinterpret_cast <Vec3 *> ( reinterpret_cast <char *> ( PositionAttributeMemory ) + PositionOffset + PositionStride * ( I * 3 + 2 ) ), TriangleList [ I ].P3 );
			
		}
		
	}
	
	if ( ( Params.Flags & kMeshParameterFlags_Normals ) != 0 )
	{
		
		for ( uint32_t I = 0; I < TriangleCount; I ++ )
		{
			
			STLFILE_VEC3_COPY ( * reinterpret_cast <Vec3 *> ( reinterpret_cast <char *> ( NormalAttributeMemory ) + NormalOffset + NormalStride * ( I * 3 ) ), TriangleList [ I ].Normal );
			STLFILE_VEC3_COPY ( * reinterpret_cast <Vec3 *> ( reinterpret_cast <char *> ( NormalAttributeMemory ) + NormalOffset + NormalStride * ( I * 3 + 1 ) ), TriangleList [ I ].Normal );
			STLFILE_VEC3_COPY ( * reinterpret_cast <Vec3 *> ( reinterpret_cast <char *> ( NormalAttributeMemory ) + NormalOffset + NormalStride * ( I * 3 + 2 ) ), TriangleList [ I ].Normal );
			
		}
		
	}
	
	OutMesh -> AddAttribute ( PositionMeshAttribute );
	OutMesh -> AddAttributeData ( PositionAttributeData );
	
	if ( NormalMeshAttribute != NULL )
	{
		
		OutMesh -> AddAttribute ( NormalMeshAttribute );
		
		if ( NormalAttributeData != PositionAttributeData )
			OutMesh -> AddAttributeData ( NormalAttributeData );
		
	}
	
	return OutMesh;
	
}

#endif

uint32_t RAUX::StlFile :: GetTriangleCount () const
{
	
	return TriangleCount;
	
}

const RAUX::StlFile :: Triangle * RAUX::StlFile :: GetTriangle ( uint32_t Index ) const
{
	
	if ( Index < TriangleCount )
		return & TriangleList [ Index ];
	
	return NULL;
	
}
