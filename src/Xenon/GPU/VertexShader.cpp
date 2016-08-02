#include <Xenon/GPU/VertexShader.h>
#include <stdlib.h>

const char * Xenon::GPU::VertexShader :: kErrorLog_GPUResourceFreedAfterShaderCodeFreed = "VertexShader: Shader code was freed before compilation ( Likely an early call to VertexShader :: GPUResourceFree () ).";

Xenon::GPU::VertexShader :: VertexShader ( const GLchar * Source, const char * Name ):
	ShaderCode ( Source ),
	DiscardableSource ( false ),
	SHandle ( 0 ),
	Allocated ( false ),
	Compiled ( false ),
	CompileLog ( "" ),
	Name ( Name )
{
}

Xenon::GPU::VertexShader :: ~VertexShader ()
{
	
	GPUResourceFree ();
	
}

void Xenon::GPU::VertexShader :: GPUResourceAlloc ()
{
	
	if ( Allocated )
		return;
	
	SHandle = glCreateShader ( GL_VERTEX_SHADER );
	
	if ( SHandle != 0 )
	{
		
		Allocated = true;
		
	}
	
}

void Xenon::GPU::VertexShader :: GPUResourceFree ()
{
	
	if ( ! Allocated )
		return;
	
	glDeleteShader ( SHandle );
	
	Allocated = false;
	Compiled = false;
	
}

bool Xenon::GPU::VertexShader :: GPUResourceAllocated ()
{
	
	return Allocated;
	
}

const std :: string & Xenon::GPU::VertexShader :: GetName ()
{
	
	return Name;
	
}

bool Xenon::GPU::VertexShader :: Compile ( bool StoreCompilationLog, bool FreeSource )
{
	
	if ( Compiled )
		return true;
	
	if ( ! Allocated )
		GPUResourceAlloc ();
	
	const char * const Temp = ShaderCode.c_str ();
	
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
	
	return false;
	
}

const std :: string & Xenon::GPU::VertexShader :: GetCompilationLog ()
{
	
	return CompileLog;
	
}

void Xenon::GPU::VertexShader :: FreeCompilationLog ()
{
	
	CompileLog.clear ();
	CompileLog.shrink_to_fit ();
	
}

GLuint Xenon::GPU::VertexShader :: GetSHandle ()
{
	
	return SHandle;
	
}
