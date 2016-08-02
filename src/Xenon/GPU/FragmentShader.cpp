#include <Xenon/GPU/FragmentShader.h>
#include <stdlib.h>

Xenon::GPU::FragmentShader :: FragmentShader ( const std :: string Source, std :: string Name ):
	RefCounted ( 0 ),
	ShaderCode ( Source ),
	SHandle ( 0 ),
	Allocated ( false ),
	Compiled ( false ),
	CompileLog ( "" ),
	Name ( Name )
{
}

Xenon::GPU::FragmentShader :: ~FragmentShader ()
{
	
	GPUResourceFree ();
	
}

void Xenon::GPU::FragmentShader :: GPUResourceAlloc ()
{
	
	if ( Allocated )
		return;
	
	SHandle = glCreateShader ( GL_FRAGMENT_SHADER );
	
	if ( SHandle != 0 )
		Allocated = true;
	
}

void Xenon::GPU::FragmentShader :: GPUResourceFree ()
{
	
	if ( ! Allocated )
		return;
	
	glDeleteShader ( SHandle );
	
	Allocated = false;
	Compiled = false;
	
}

bool Xenon::GPU::FragmentShader :: GPUResourceAllocated ()
{
	
	return Allocated;
	
}

const std :: string & Xenon::GPU::FragmentShader :: GetName ()
{
	
	return Name;
	
}

bool Xenon::GPU::FragmentShader :: Compile ( bool StoreCompilationLog, bool FreeSource )
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
		
	return false;
	
}

const std :: string & Xenon::GPU::FragmentShader :: GetCompilationLog ()
{
	
	return CompileLog;
	
}

void Xenon::GPU::FragmentShader :: FreeCompilationLog ()
{
	
	CompileLog.clear ();
	CompileLog.shrink_to_fit ();
	
}

GLuint Xenon::GPU::FragmentShader :: GetSHandle ()
{
	
	return SHandle;
	
}
