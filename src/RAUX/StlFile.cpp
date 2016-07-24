#include <RAUX/StlFile.h>

#include <limits>

RAUX::StlFile :: StlFile ( const std :: string & Name ):
	FileInstance ( Name )
{
}

RAUX::StlFile :: ~StlFile ()
{
	
	
	
}

bool RAUX::StlFile :: Exists () const
{
	
	return FileInstance.Exists ();
	
}

void RAUX::StlFile :: Load ( uint32_t * Status )
{
	
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
