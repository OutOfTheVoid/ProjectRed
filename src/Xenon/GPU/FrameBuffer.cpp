#include <Xenon/GPU/FrameBuffer.h>
#include <Xenon/GPU/Context.h>

Xenon::GPU::FrameBuffer :: FrameBuffer ():
	Allocated ( false ),
	FHandle ( 0 )
{
}

Xenon::GPU::FrameBuffer :: FrameBuffer ( GLuint FHandle ):
	Allocated ( true ),
	FHandle ( FHandle )
{
}

Xenon::GPU::FrameBuffer :: ~FrameBuffer ()
{
	
	GPUResourceFree ();
	
}

void Xenon::GPU::FrameBuffer :: GPUResourceAlloc ()
{
	
	if ( Allocated )
		return;
	
	glGenFramebuffers ( 1, & FHandle );
	
	if ( FHandle != 0 )
		Allocated = true;
	
}

void Xenon::GPU::FrameBuffer :: GPUResourceFree ()
{
	
	if ( ! Allocated )
		return;
	
	if ( FHandle == 0 )
		return;
	
	glDeleteFramebuffers ( 1, & FHandle );
	
	Allocated = false;
	FHandle = 0;
	
}

bool Xenon::GPU::FrameBuffer :: GPUResourceAllocated ()
{
	
	return Allocated;
	
}

void Xenon::GPU::FrameBuffer :: Bind ( FrameBufferBindingFlag FrameBuffers )
{
	
	if ( ! Allocated )
	{
		
		GPUResourceAlloc ();
		
		if ( ! Allocated )
			return;
		
	}
	
	switch ( FrameBuffers )
	{
		
		case kFrameBufferBindingFlag_Draw:
		{
			
			if ( Context :: CurrentBoundContext -> CurrentBoundDrawFrameBuffer != this )
			{
				
				glBindFramebuffer ( GL_DRAW_FRAMEBUFFER, FHandle );
				
				Context :: CurrentBoundContext -> CurrentBoundDrawFrameBuffer = this;
				
			}
			
			break;
			
		}
		
		case kFrameBufferBindingFlag_Read:
		{
			
			if ( Context :: CurrentBoundContext -> CurrentBoundReadFrameBuffer != this )
			{
				
				glBindFramebuffer ( GL_READ_FRAMEBUFFER, FHandle );
				
				Context :: CurrentBoundContext -> CurrentBoundReadFrameBuffer = this;
				
			}
			
			break;
			
		}
		
		case kFrameBufferBindingFlag_ReadDraw:
		{
			
			if ( ( Context :: CurrentBoundContext -> CurrentBoundReadFrameBuffer != this ) || ( Context :: CurrentBoundContext -> CurrentBoundDrawFrameBuffer != this ) )
			{
				
				glBindFramebuffer ( GL_FRAMEBUFFER, FHandle );
				
				Context :: CurrentBoundContext -> CurrentBoundReadFrameBuffer = this;
				Context :: CurrentBoundContext -> CurrentBoundDrawFrameBuffer = this;
				
			}
			
			break;
			
		}
		
	}
	
}

void Xenon::GPU::FrameBuffer :: SetClearColor ( GLfloat Red, GLfloat Green, GLfloat Blue, GLfloat Alpha )
{
	
	Bind ( kFrameBufferBindingFlag_Draw );
	
	glClearColor ( Red, Green, Blue, Alpha );
	
}

void Xenon::GPU::FrameBuffer :: SetClearDepth ( GLfloat Depth )
{
	
	Bind ( kFrameBufferBindingFlag_Draw );
	
	glClearDepth ( Depth );
	
}

void Xenon::GPU::FrameBuffer :: SetClearStencil ( GLint Value )
{
	
	Bind ( kFrameBufferBindingFlag_Draw );
	
	glClearStencil ( Value );
	
}

void Xenon::GPU::FrameBuffer :: Clear ( FrameBufferComponent Components )
{
	
	Bind ( kFrameBufferBindingFlag_Draw );
	
	glClear ( Components );
	
}

