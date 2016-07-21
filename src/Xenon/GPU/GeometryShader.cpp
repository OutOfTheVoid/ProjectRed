#include <Xenon/GPU/GeometryShader.h>
#include <stdlib.h>

Xenon::GPU::GeometryShader :: GeometryShader ( const std :: string Source, const std :: string Name ):
	ShaderCode ( Source ),
	DiscardableSource ( false ),
	Allocated ( false ),
	Compiled ( false ),
	CompileLog ( "" ),
	Name ( Name ),
	SHandle ( 0 )
{
}

Xenon::GPU::GeometryShader :: ~GeometryShader ()
{
	
	GPUResourceFree ();
	
}

void Xenon::GPU::GeometryShader :: GPUResourceAlloc ()
{
	
	if ( Allocated )
		return;
	
	SHandle = glCreateShader ( GL_GEOMETRY_SHADER );
	
	Allocated = ( SHandle != 0 );
	
}

void Xenon::GPU::GeometryShader :: GPUResourceFree ()
{
	
	if ( ! Allocated )
		return;
	
	glDeleteShader ( SHandle );
	
	Allocated = false;
	Compiled = false;
	
}

bool Xenon::GPU::GeometryShader :: GPUResourceAllocated ()
{
	
	return Allocated;
	
}

const std :: string & Xenon::GPU::GeometryShader :: GetName ()
{
	
	return Name;
	
}

bool Xenon::GPU::GeometryShader :: Compile ( bool StoreCompilationLog, bool FreeSource )
{
	
	if ( Compiled )
		return true;
	
	if ( ! Allocated )
		GPUResourceAlloc ();
	
	const char * Temp = ShaderCode.c_str ();
	
	glShaderSource ( SHandle, 1, & Temp, NULL );
	glCompileShader ( SHandle );
	
	GLint CompilationStatus = GL_FALSE;
	glGetShaderiv ( SHandle, GL_COMPILE_STATUS, & CompilationStatus );
	
	if ( FreeSource )
	{
		
		ShaderCode.clear ();
		ShaderCode.shrink_to_fit ();
		
	}
	
	if ( CompilationStatus == GL_TRUE )
	{
		
		Compiled = true;
		
		return true;
		
	}
	
	if ( StoreCompilationLog )
	{
		
		FreeCompilationLog ();
		
		GLint MaxLength = 0;
		glGetShaderiv ( SHandle, GL_INFO_LOG_LENGTH, & MaxLength );
		
		char * TempLogStore = reinterpret_cast <char *> ( malloc ( sizeof ( char ) * ( MaxLength + 1 ) ) );
		
		if ( TempLogStore != NULL )
		{
			
			glGetShaderInfoLog ( SHandle, MaxLength, & MaxLength, TempLogStore );
			TempLogStore [ MaxLength ] = '\0';
			
			CompileLog = TempLogStore;
			
		}
		
	}
		
	
}

const std :: string & Xenon::GPU::GeometryShader :: GetCompilationLog ()
{
	
	return CompileLog;
	
}

void Xenon::GPU::GeometryShader :: FreeCompilationLog ()
{
	
	CompileLog.clear ();
	CompileLog.shrink_to_fit ();
	
}

GLuint Xenon::GPU::GeometryShader :: GetSHandle ()
{
	
	return SHandle;
	
}
