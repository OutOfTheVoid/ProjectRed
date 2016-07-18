#include <Xenon/GPU/ShaderProgram.h>
#include <Xenon/GPU/Context.h>

Xenon::GPU::ShaderProgram :: ShaderProgram ( std :: string Name ):
	Name ( Name ),
	Allocated ( false ),
	SHandle ( 0 ),
	LinkIteration ( - 1 )
{
};

Xenon::GPU::ShaderProgram :: ~ShaderProgram ()
{
};

void Xenon::GPU::ShaderProgram :: GPUResourceAlloc ()
{
	
	if ( Allocated )
		return;
	
	SHandle = glCreateProgram ();
	
	if ( SHandle != 0 )
		Allocated = true;
	
};

void Xenon::GPU::ShaderProgram :: GPUResourceFree ()
{
	
	if ( ! Allocated )
		return;
	
	glDeleteProgram ( SHandle );
	
	Allocated = false;
	
};

void Xenon::GPU::ShaderProgram :: Bind ()
{
	
	if ( ! Allocated )
		return;
	
	if ( Context :: CurrentBoundContext -> CurrentBoundShader != this )
	{
		
		glUseProgram ( SHandle );
		
		Context :: CurrentBoundContext -> CurrentBoundShader = this;
	
	}
	
};

void Xenon::GPU::ShaderProgram :: Link ()
{
	
	glLinkProgram ( SHandle );
	
	LinkIteration ++;
	
};

bool Xenon::GPU::ShaderProgram :: GPUResourceAllocated ()
{
	
	return Allocated;
	
};

void Xenon::GPU::ShaderProgram :: AddShader ( IShader & Shader )
{
	
	if ( ! Allocated )
	{
		
		GPUResourceAlloc ();
		
		if ( ! Allocated )
		{
			
			XENON_LOG_ERROR ( "Failed to allocate shader program \"%s\" for adding shader \"%s\"!\n", Name.c_str (), Shader.GetName ().c_str () );
			
			return;
			
		}
		
	}
	
	glAttachShader ( SHandle, Shader.GetSHandle () );
	
};

void Xenon::GPU::ShaderProgram :: RemoveShader ( IShader & Shader )
{
	
	if ( ! Allocated )
	{
		
		XENON_LOG_ERROR ( "Attempted to remove a shader from non-allocated shader program \"%s\"!\n", Name.c_str () );
		
		return;
		
	}
	
	glDetachShader ( SHandle, Shader.GetSHandle () );
	
};

GLint Xenon::GPU::ShaderProgram :: GetAttributeLocation ( const GLchar * Attribute )
{
	
	if ( ! Allocated )
	{
		
		XENON_LOG_ERROR ( "Attempted to fetch attribute location from non-allocated shader program \"%s\"!\n", Name.c_str () );
		
		return 0;
		
	}
	
	return glGetAttribLocation ( SHandle, Attribute );
	
};

GLint Xenon::GPU::ShaderProgram :: GetUniformLocation ( const GLchar * Attribute )
{
	
	if ( ! Allocated )
	{
		
		XENON_LOG_ERROR ( "Attempted to fetch attribute location from non-allocated shader program \"%s\"!\n", Name.c_str () );
		
		return 0;
		
	}
	
	return glGetUniformLocation ( SHandle, Attribute );
	
};

const std :: string & Xenon::GPU::ShaderProgram :: GetName ()
{
	
	return Name;
	
};

int64_t Xenon::GPU::ShaderProgram :: GetLinkIteration ()
{
	
	return LinkIteration;
	
};
