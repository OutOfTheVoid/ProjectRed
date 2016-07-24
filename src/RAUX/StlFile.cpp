#include <RAUX/StlFile.h>

#include <RAUX/Endian.h>

#include <limits>
#include <iostream>

RAUX::StlFile :: StlFile ( const std :: string & Name ):
	FileInstance ( Name ),
	TriangleCount ( 0 ),
	TriangleList ( NULL )
{
}

RAUX::StlFile :: ~StlFile ()
{
	
	delete TriangleList;
	TriangleList = NULL;
	
}

bool RAUX::StlFile :: Exists () const
{
	
	return FileInstance.Exists ();
	
}

void RAUX::StlFile :: Load ( uint32_t * Status )
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
	
	TriangleCount = LittleToHostEndian32 ( TriangleCount );
	
	std :: cout << "triangle count: " << TriangleCount << std :: endl;
	
	TriangleList = new Triangle [ TriangleCount ];
	
	for ( uint32_t I = 0; I < TriangleCount; I ++ )
	{
		
		// TODO: Fill triangles
		
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
	
	return NULL;
	
}

#endif
