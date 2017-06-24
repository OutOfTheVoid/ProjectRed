#include <Xenon/GPU/FrameBuffer.h>

#include <Xenon/GPU/Context.h>
#include <Xenon/GPU/Texture2D.h>
#include <Xenon/GPU/RenderBuffer.h>

Xenon::GPU::FrameBuffer :: FrameBuffer ():
	RefCounted ( 0 ),
	Allocated ( false ),
	FHandle ( 0 )
{
}

Xenon::GPU::FrameBuffer :: FrameBuffer ( GLuint FHandle ):
	RefCounted ( 0 ),
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
	
	glClearColor ( Red, Green, Blue, Alpha );
	
}

void Xenon::GPU::FrameBuffer :: SetClearDepth ( GLfloat Depth )
{
	
	glClearDepth ( Depth );
	
}

void Xenon::GPU::FrameBuffer :: SetClearStencil ( GLint Value )
{
	
	glClearStencil ( Value );
	
}

void Xenon::GPU::FrameBuffer :: Clear ( FrameBufferComponent Components )
{
	
	Bind ( kFrameBufferBindingFlag_Draw );
	
	glClear ( Components );
	
}

void Xenon::GPU::FrameBuffer :: SetRenderTexture2D ( OutputAttachment Attachment, GLuint AttachmentIndex, Texture2D & Texture, GLuint Level )
{
	
	Bind ( kFrameBufferBindingFlag_ReadDraw );
	
	glFramebufferTexture2D ( GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + AttachmentIndex, GL_TEXTURE_2D, Texture.THandle, Level );
	
}

void Xenon::GPU::FrameBuffer :: SetRenderBuffer ( OutputAttachment Attachment, GLuint AttachmentIndex, RenderBuffer & Buffer )
{
	
	Bind ( kFrameBufferBindingFlag_ReadDraw );
	
	glFramebufferRenderbuffer ( GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + AttachmentIndex, GL_RENDERBUFFER, Buffer.RHandle );
	
}
