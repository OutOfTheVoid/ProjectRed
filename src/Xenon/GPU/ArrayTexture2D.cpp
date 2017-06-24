#include <Xenon/GPU/ArrayTexture2D.h>
#include <Xenon/GPU/GLInclude.h>

Xenon::GPU::ArrayTexture2D :: ArrayTexture2D ():
	RefCounted ( 0 ),
	Allocated ( false ),
	THandle ( 0 )
{
}

Xenon::GPU::ArrayTexture2D :: ~ArrayTexture2D ()
{
	
	GPUResourceFree ();
	
}

void Xenon::GPU::ArrayTexture2D :: GPUResourceAlloc ()
{
	
	if ( Allocated )
		return;
	
	glGenTextures ( 1, & THandle );
	
	if ( THandle != 0 )
		Allocated = true;
	
}

void Xenon::GPU::ArrayTexture2D :: GPUResourceFree ()
{
	
	if ( ! Allocated )
		return;
	
	glDeleteTextures ( 1, & THandle );
	
}

bool Xenon::GPU::ArrayTexture2D :: GPUResourceAllocated ()
{
	
	return Allocated;
	
}

void Xenon::GPU::ArrayTexture2D :: BlankTextureImage ( GLint DetailLevel, InternalFormat FInternal, GLsizei Width, GLsizei Height, GLsizei LayerCount )
{
	
	Bind ();
	
	glTexImage3D ( GL_TEXTURE_2D_ARRAY, DetailLevel, FInternal, Width, Height, LayerCount, 0, GL_RGBA, kExternalLayout_UByte, NULL );
	
}

void Xenon::GPU::ArrayTexture2D :: TextureImage ( GLint DetailLevel, InternalFormat FInternal, GLsizei Width, GLsizei Height, GLsizei LayerCount, GLsizei XOffset, GLsizei YOffset, GLsizei LayerOffset, ExternalFormat EFormat, ExternalLayout ELayout, const GLvoid * Data, GLuint Alignment, GLuint Pitch )
{
	
	Bind ();
	
	glPixelStorei ( GL_UNPACK_ROW_LENGTH, Pitch );
	glPixelStorei ( GL_UNPACK_ALIGNMENT, Alignment );
	
	glTexImage3D ( GL_TEXTURE_2D_ARRAY, DetailLevel, FInternal, Width, Height, LayerCount, 0, EFormat, ELayout, Data );
	
	glPixelStorei ( GL_UNPACK_ROW_LENGTH, 0 );
	glPixelStorei ( GL_UNPACK_ALIGNMENT, 4 );
	
}

void Xenon::GPU::ArrayTexture2D :: TextureSubImage ( GLint DetailLevel, GLsizei Width, GLsizei Height, GLsizei LayerCount, GLsizei XOffset, GLsizei YOffset, GLsizei LayerOffset, ExternalFormat EFormat, ExternalLayout ELayout, const GLvoid * Data, GLuint Alignment, GLuint Pitch )
{
	
	Bind ();
	
	glPixelStorei ( GL_UNPACK_ROW_LENGTH, Pitch );
	glPixelStorei ( GL_UNPACK_ALIGNMENT, Alignment );
	
	glTexSubImage3D ( GL_TEXTURE_2D_ARRAY, DetailLevel, XOffset, YOffset, LayerOffset, Width, Height, LayerCount, EFormat, ELayout, Data );
	
	glPixelStorei ( GL_UNPACK_ROW_LENGTH, 0 );
	glPixelStorei ( GL_UNPACK_ALIGNMENT, 4 );
	
}

void Xenon::GPU::ArrayTexture2D :: TextureSubImageLayer ( GLint DetailLevel, GLsizei Width, GLsizei Height, GLsizei XOffset, GLsizei YOffset, GLsizei Layer, ExternalFormat EFormat, ExternalLayout ELayout, const GLvoid * Data, GLuint Alignment, GLuint Pitch )
{
	
	TextureSubImage ( DetailLevel, Width, Height, 1, XOffset, YOffset, Layer, EFormat, ELayout, Data, Alignment, Pitch );
	
}

void Xenon::GPU::ArrayTexture2D :: CopySubImageLayerFromFrameBuffer ( GLint DetailLevel, GLint XOffset, GLint YOffset, GLint Layer, GLsizei Width, GLsizei Height, GLint FrameBufferXOffset, GLint FrameBufferYOffset, GLuint ColorAttachment )
{
	
	
	Bind ();
	
	glReadBuffer ( GL_COLOR_ATTACHMENT0 + ColorAttachment );
	glCopyTexSubImage3D ( GL_TEXTURE_2D_ARRAY, DetailLevel, XOffset, YOffset, Layer, FrameBufferXOffset, FrameBufferYOffset, Width, Height );
	
}

void Xenon::GPU::ArrayTexture2D :: GenerateMipMaps ()
{
	
	Bind ();
	
	glGenerateMipmap ( GL_TEXTURE_2D_ARRAY );
	
}

void Xenon::GPU::ArrayTexture2D :: Bind ()
{
	
	if ( ! Allocated )
		GPUResourceAlloc ();
	
	if ( Context :: CurrentBoundContext -> CurrentBoundTextureArray2D != this )
	{
		
		glBindTexture ( GL_TEXTURE_2D_ARRAY, THandle );
		
		Context :: CurrentBoundContext -> CurrentBoundTextureArray2D = this;
		
	}
	
}
		
void Xenon::GPU::ArrayTexture2D :: SetFiltering ( MinimizingFilter MinFilter, MagnificationFilter MagFilter )
{
	
	Bind ();
	
	glTexParameteri ( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, MagFilter );
	glTexParameteri ( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, MinFilter );
	
}

void Xenon::GPU::ArrayTexture2D :: SetWrapMode ( WrapMode Mode )
{
	
	Bind ();
	
	glTexParameteri ( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, Mode );
	glTexParameteri ( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, Mode );
	glTexParameteri ( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_R, Mode );
	
}

void Xenon::GPU::ArrayTexture2D :: SetWrapMode ( WrapMode ModeS, WrapMode ModeT, WrapMode ModeR )
{
	
	Bind ();
	
	glTexParameteri ( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, ModeS );
	glTexParameteri ( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, ModeT );
	glTexParameteri ( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_R, ModeR );
	
}

void Xenon::GPU::ArrayTexture2D :: AssignToTextureUnit ( GLuint Unit )
{
	
	if ( Unit >= GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS )
		return;
	
	glActiveTexture ( GL_TEXTURE0 + Unit );
	glBindTexture ( GL_TEXTURE_2D_ARRAY, THandle );
	
	Context :: CurrentBoundContext -> CurrentBoundTextureArray2D = this;
	
}

