#include <Xenon/GPU/Texture2D.h>

Xenon::GPU::Texture2D :: Texture2D ():
	Allocated ( false ),
	THandle ( 0 )
{	
};

Xenon::GPU::Texture2D :: ~Texture2D ()
{
};

void Xenon::GPU::Texture2D :: GPUResourceAlloc ()
{
	
	if ( Allocated )
		return;
	
	glGenTextures ( 1, & THandle );
	
	if ( THandle != 0 )
		Allocated = true;
	
};

void Xenon::GPU::Texture2D :: GPUResourceFree ()
{
	
	if ( ! Allocated )
		return;
	
	glDeleteTextures ( 1, & THandle );
	
};

bool Xenon::GPU::Texture2D :: GPUResourceAllocated ()
{
	
	return Allocated;
	
};

void Xenon::GPU::Texture2D :: Bind ()
{
	
	if ( ! Allocated )
		GPUResourceAlloc ();
	
	if ( Context :: CurrentBoundContext -> CurrentBoundTexture2D != this )
	{
		
		glBindTexture ( GL_TEXTURE_2D, THandle );
		
		Context :: CurrentBoundContext -> CurrentBoundTexture2D = this;
		
	}
	
};

void Xenon::GPU::Texture2D :: BlankTextureImage ( GLint DetailLevel, InternalFormat FInternal, GLsizei Width, GLsizei Height, ExternalFormat EFormat, ExternalLayout ELayout )
{
	
	Bind ();
	
	glTexImage2D ( GL_TEXTURE_2D, DetailLevel, FInternal, Width, Height, 0, EFormat, ELayout, NULL );
	
};

void Xenon::GPU::Texture2D :: TextureImage ( GLint DetailLevel, InternalFormat FInternal, GLsizei Width, GLsizei Height, ExternalFormat EFormat, ExternalLayout ELayout, GLvoid * Data, GLuint Alignment )
{
	
	Bind ();
	
	glPixelStorei ( GL_UNPACK_ALIGNMENT, Alignment );
	glTexImage2D ( GL_TEXTURE_2D, DetailLevel, FInternal, Width, Height, 0, ELayout, EFormat, Data );
	
};

void Xenon::GPU::Texture2D :: GenerateMipMaps ()
{
	
	Bind ();
	
	glGenerateMipmap ( GL_TEXTURE_2D );
	
};

void Xenon::GPU::Texture2D :: AssignToTextureUnit ( GLuint Unit )
{
	
	if ( Unit >= GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS )
		return;
	
	glActiveTexture ( GL_TEXTURE0 + Unit );
	glBindTexture ( GL_TEXTURE_2D, THandle );
	
	Context :: CurrentBoundContext -> CurrentBoundTexture2D = this;
	
};
		
void Xenon::GPU::Texture2D :: SetFiltering ( MinimizingFilter MinFilter, MagnificationFilter MagFilter )
{
	
	Bind ();
	
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, MagFilter );
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, MinFilter );
	
};

void Xenon::GPU::Texture2D :: SetWrapMode ( WrapMode Mode )
{
	
	Bind ();
	
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Mode );
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Mode );
	
};

void Xenon::GPU::Texture2D :: SetWrapMode ( WrapMode ModeS, WrapMode ModeT )
{
	
	Bind ();
	
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, ModeS );
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, ModeT );
	
};
