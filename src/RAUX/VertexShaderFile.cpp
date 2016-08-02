#include <RAUX/VertexShaderFile.h>

#ifdef RAUX_XENON_INTERFACE

RAUX::VertexShaderFile :: VertexShaderFile ( const std :: string & Name ):
	FileInstance ( Name ),
	ShaderName ( "" )
{
}

RAUX::VertexShaderFile :: VertexShaderFile ( const std :: string & Name, const std :: string & ShaderName ):
	FileInstance ( Name ),
	ShaderName ( ShaderName )
{
	
	(void) ShaderName;
	
}

RAUX::VertexShaderFile :: ~VertexShaderFile ()
{
}

bool RAUX::VertexShaderFile :: Exists () const
{
	
	return FileInstance.Exists ();
	
}

const std :: string & RAUX::VertexShaderFile :: GetName () const
{
	
	return FileInstance.GetName ();
	
}

void RAUX::VertexShaderFile :: Open ( uint32_t * Status )
{
	
	uint32_t SubStatus;
	
	FileInstance.Open ( & SubStatus );
	
	if ( SubStatus != TextFile :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	* Status = kStatus_Success;
	
}

void RAUX::VertexShaderFile :: Close ()
{
	
	FileInstance.Close ();
	
}

Xenon::GPU :: VertexShader * RAUX::VertexShaderFile :: LoadToShader ( uint32_t * Status )
{
	
	if ( ! FileInstance.IsOpen () )
		Open ( Status );
	
	uint32_t SubStatus;
	
	std :: string Buffer;
	
	FileInstance.LoadToString ( & SubStatus, Buffer, 0 );
	
	if ( SubStatus != TextFile :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return NULL;
		
	}
	
	if ( ShaderName == "" )
		return new Xenon::GPU :: VertexShader ( Buffer.c_str () );
	
	return new Xenon::GPU :: VertexShader ( Buffer.c_str (), ShaderName.c_str () );
	
}

#endif
