#include <RAUX/FragmentShaderFile.h>

#ifdef RAUX_XENON_INTERFACE

RAUX::FragmentShaderFile :: FragmentShaderFile ( const std :: string & Name ):
	FileInstance ( Name ),
	ShaderName ( "" )
{
}

RAUX::FragmentShaderFile :: FragmentShaderFile ( const std :: string & Name, const std :: string & ShaderName ):
	FileInstance ( Name ),
	ShaderName ( ShaderName )
{
	
	(void) ShaderName;
	
}

RAUX::FragmentShaderFile :: ~FragmentShaderFile ()
{
}

bool RAUX::FragmentShaderFile :: Exists () const
{
	
	return FileInstance.Exists ();
	
}

const std :: string & RAUX::FragmentShaderFile :: GetName () const
{
	
	return FileInstance.GetName ();
	
}

void RAUX::FragmentShaderFile :: Open ( uint32_t * Status )
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

void RAUX::FragmentShaderFile :: Close ()
{
	
	FileInstance.Close ();
	
}

Xenon::GPU :: FragmentShader * RAUX::FragmentShaderFile :: LoadToShader ( uint32_t * Status )
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
		return new Xenon::GPU :: FragmentShader ( Buffer.c_str () );
	
	return new Xenon::GPU :: FragmentShader ( Buffer.c_str (), ShaderName.c_str () );
	
}

#endif
