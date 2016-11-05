#include <RAUX/PNGFile.h>
#include <RAUX/File.h>

#include <stdlib.h>
#include <string.h>

#include <png.h>

RAUX::PNGFile :: PNGFile ( const std :: string & FileName ):
	FileInstance ( FileName, false ),
	Data ( NULL )
{
}

RAUX::PNGFile :: ~PNGFile ()
{
	
	CloseFile ();
	
	if ( Data != NULL )
	{
		
		free ( Data );
		Data = NULL;
		
	}
	
}

bool RAUX::PNGFile :: Exists () const
{
	
	return FileInstance.Exists ();
	
}

void RAUX::PNGFile :: Load ( uint32_t * Status )
{
	
	if ( ! FileInstance.Exists () )
	{
		
		* Status = kStatus_Failure_NonExistantFile;
		
		return;
		
	}
	
	FileInstance.Open ( Status );
	
	if ( * Status != kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	png_structp LibPNGRuntimeInfo = png_create_read_struct ( PNG_LIBPNG_VER_STRING, NULL, NULL, NULL );
	
	if ( LibPNGRuntimeInfo == NULL )
	{
		
		* Status = kStatus_Failure_Init;
		
		return;
		
	}
	
	png_infop ImageInfo = png_create_info_struct ( LibPNGRuntimeInfo );
	
	if ( ImageInfo == NULL )
	{
		
		png_destroy_read_struct ( & LibPNGRuntimeInfo, NULL, NULL );
		
		* Status = kStatus_Failure_Init;
		
		return;
		
	}
	
	if ( setjmp ( png_jmpbuf ( LibPNGRuntimeInfo ) ) )
	{
		
		png_destroy_read_struct ( & LibPNGRuntimeInfo, NULL, NULL );
		
		* Status = kStatus_Failure_Init;
		
		return;
		
	}
	
	png_init_io ( LibPNGRuntimeInfo, FileInstance.GetFilePointer () );
	png_set_sig_bytes ( LibPNGRuntimeInfo, 0 );
	
	png_read_png ( LibPNGRuntimeInfo, ImageInfo, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, NULL );
	
	int ColorType;
	int BitDepth;
	int InterlaceType;

	png_uint_32 W;
	png_uint_32 H;
	
	png_get_IHDR ( LibPNGRuntimeInfo, ImageInfo, & W, & H, & BitDepth, & ColorType, & InterlaceType, NULL, NULL );
	
	Width = W;
	Height = H;

	Alpha = ( ColorType & PNG_COLOR_MASK_ALPHA ) != 0;
	
	size_t BytesPerRow = png_get_rowbytes ( LibPNGRuntimeInfo, ImageInfo );
	
	Data = malloc ( BytesPerRow * Height );
	
	if ( Data == NULL )
	{
		
		png_destroy_read_struct ( & LibPNGRuntimeInfo, & ImageInfo, NULL );
		
		* Status = kStatus_Failure_Memory;
		
		return;
		
	}
	
	png_bytepp RowPointers = png_get_rows ( LibPNGRuntimeInfo, ImageInfo );
	
	for ( uint32_t I = 0; I < Height; I ++ )
		memcpy ( & reinterpret_cast <uint8_t *> ( Data ) [ BytesPerRow * ( Height - 1 - I ) ], RowPointers [ I ], BytesPerRow );
	
	png_destroy_read_struct ( & LibPNGRuntimeInfo, & ImageInfo, NULL );
	
	* Status = kStatus_Success;
	
}

void RAUX::PNGFile :: CloseFile ()
{
	
	uint32_t Status;
	
	FileInstance.Close ( & Status );
	
}

bool RAUX::PNGFile :: Valid () const
{
	
	return Data != NULL;
	
}

const void * RAUX::PNGFile :: GetBitmapData () const
{
	
	return Data;
	
}

bool RAUX::PNGFile :: HasAlpha () const
{
	
	return Alpha;
	
}

uint32_t RAUX::PNGFile :: GetWidth () const
{
	
	return Width;
	
}

uint32_t RAUX::PNGFile :: GetHeight () const
{
	
	return Height;
	
}
