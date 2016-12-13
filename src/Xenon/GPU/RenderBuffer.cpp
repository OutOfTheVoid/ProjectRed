#include <Xenon/GPU/RenderBuffer.h>
#include <Xenon/GPU/Context.h>

Xenon::GPU::RenderBuffer :: RenderBuffer ():
	RefCounted ( 0 ),
	Allocated ( false ),
	RHandle ( false )
{
}

Xenon::GPU::RenderBuffer :: ~RenderBuffer ()
{
	
	GPUResourceFree ();
	
}

void Xenon::GPU::RenderBuffer :: GPUResourceAlloc ()
{
	
	if ( Allocated )
		return;
	
	glGenRenderbuffers ( 1, & RHandle );
	
	Allocated = ( RHandle != 0 );
	
}

void Xenon::GPU::RenderBuffer :: GPUResourceFree ()
{
	
	if ( ! Allocated )
		return;
	
	glDeleteRenderbuffers ( 1, & RHandle );
	
	Allocated = false;
	
}

bool Xenon::GPU::RenderBuffer :: GPUResourceAllocated ()
{
	
	return Allocated;
	
}

void Xenon::GPU::RenderBuffer :: Bind ()
{
	
	if ( ! Allocated )
		GPUResourceAlloc ();
	
	if ( Context :: CurrentBoundContext -> CurrentBoundRenderBuffer != this )
	{
		
		glBindRenderbuffer ( GL_RENDERBUFFER, RHandle );
		
		Context :: CurrentBoundContext -> CurrentBoundRenderBuffer = this;
		
	}
	
}

void Xenon::GPU::RenderBuffer :: AllocateStorage ( Texture2D :: InternalFormat Format, GLuint Width, GLuint Height, GLuint MultisampleLevel )
{
	
	Bind ();
	
	if ( MultisampleLevel == 0 )
		glRenderbufferStorage ( GL_RENDERBUFFER, Format, Width, Height );
	else
		glRenderbufferStorageMultisample ( GL_RENDERBUFFER, MultisampleLevel, Format, Width, Height );
	
}
