#include <Red/Text/Rendering/FreeType/FontFace.h>

#ifdef RED_OPT_TEXT_RENDERING_FREETYPE

#include <Red/Text/Rendering/FreeType/FTLibrary.h>

#include <freetype/fttypes.h>

Red::Text::Rendering::FreeType :: FontFace * Red::Text::Rendering::FreeType::FontFace :: NewFromFile ( const std :: string & FileName, uint32_t FaceIndex )
{
	
	FT_Library * LHandle = FTLibrary :: GetLibrary ();
	
	if ( LHandle == NULL )
		return NULL;
	
	FontFace * New = new FontFace ();
	
	if ( FT_New_Face ( * LHandle, FileName.c_str (), FaceIndex, & New -> FHandle ) == 0 )
	{
		
		New -> Valid = true;
		return New;
		
	}
	
	delete New;
	
	return NULL;
	
}

Red::Text::Rendering::FreeType :: FontFace * Red::Text::Rendering::FreeType::FontFace :: NewFromMemory ( Util :: RCMem * FileMemory, uint32_t FileSize, uint32_t FaceIndex )
{
	
	FT_Library * LHandle = FTLibrary :: GetLibrary ();
	
	if ( LHandle == NULL )
		return NULL;
	
	FontFace * New = new FontFace ();
	
	if ( FT_New_Memory_Face ( * LHandle, reinterpret_cast <FT_Byte *> ( FileMemory -> GetData () ), FileSize, FaceIndex, & New -> FHandle ) == 0 )
	{
		
		FileMemory -> Reference ();
		
		New -> MemFile = FileMemory;
		New -> Valid = true;
		
		New -> FamilyName.assign ( const_cast <const char *> ( New -> FHandle -> family_name ) );
		New -> StyleName.assign ( const_cast <const char *> ( New -> FHandle -> style_name ) );
		
		return New;
		
	}
	
	delete New;
	
	return NULL;
	
}

Red::Text::Rendering::FreeType::FontFace :: FontFace ():
	FHandle (),
	Valid ( false ),
	MemFile ( NULL ),
	FamilyName ( "" ),
	StyleName ( "" ),
	RMode ( kRenderMode_Normal )
{
}

Red::Text::Rendering::FreeType::FontFace :: ~FontFace ()
{
	
	if ( Valid )
		FT_Done_Face ( FHandle );
	
	if ( MemFile != NULL )
		MemFile -> Dereference ();
	
	MemFile = NULL;
	
}

uint32_t Red::Text::Rendering::FreeType::FontFace :: GetNumFaces ()
{
	
	return FHandle -> num_faces;
	
}

uint32_t Red::Text::Rendering::FreeType::FontFace :: GetFaceIndex ()
{
	
	return FHandle -> face_index;
	
}

Red::Text::Rendering::FreeType::FontFace :: FaceFlag Red::Text::Rendering::FreeType::FontFace :: GetFaceFlags ()
{
	
	return FHandle -> face_flags;
	
}

Red::Text::Rendering::FreeType::FontFace :: StyleFlag Red::Text::Rendering::FreeType::FontFace :: GetStyleFlags ()
{
	
	return FHandle -> style_flags;
	
}

uint32_t Red::Text::Rendering::FreeType::FontFace :: GetNumGlyphs ()
{
	
	return FHandle -> num_glyphs;
	
}

const std :: string & Red::Text::Rendering::FreeType::FontFace :: GetFamilyName ()
{
	
	return FamilyName;
	
}

const std :: string & Red::Text::Rendering::FreeType::FontFace :: GetStyleName ()
{
	
	return StyleName;
	
}

void Red::Text::Rendering::FreeType::FontFace :: SetSize ( double PointSize, uint32_t DPI )
{
	
	PointSize *= 64.0;
	
	FT_Set_Char_Size ( FHandle, static_cast <FT_F26Dot6> ( PointSize ), 0, DPI, 0 );
	
}

void Red::Text::Rendering::FreeType::FontFace :: SetPixelSize ( uint32_t PixelSize )
{
	
	FT_Set_Pixel_Sizes ( FHandle, PixelSize, PixelSize );
	
}

uint32_t Red::Text::Rendering::FreeType::FontFace :: GetFixedSizeCount ()
{
	
	return FHandle -> num_fixed_sizes;
	
}

double Red::Text::Rendering::FreeType::FontFace :: GetFixedNominalWidth ( int32_t Index )
{
	
	if ( ( Index >= FHandle -> num_fixed_sizes ) || ( Index < 0 ) )
		return 0;
	
	return static_cast <double> ( FHandle -> available_sizes [ Index ].x_ppem ) / 64.0;
	
}

double Red::Text::Rendering::FreeType::FontFace :: GetFixedNominalHeight ( int32_t Index )
{
	
	if ( ( Index >= FHandle -> num_fixed_sizes ) || ( Index < 0 ) )
		return 0;
	
	return static_cast <double> ( FHandle -> available_sizes [ Index ].y_ppem ) / 64.0;
	
}

uint32_t Red::Text::Rendering::FreeType::FontFace :: GlyphIndexFromChar ( char32_t Char )
{
	
	return FT_Get_Char_Index ( FHandle, Char );
	
}

bool Red::Text::Rendering::FreeType::FontFace :: LoadGlyph ( uint32_t Index, LoadFlag Flags )
{
	
	return FT_Load_Glyph ( FHandle, Index, Flags ) == 0;
	
}

void Red::Text::Rendering::FreeType::FontFace :: RenderGlyph ()
{
	
	FT_Render_Glyph ( FHandle -> glyph, RMode );
	
}

void * Red::Text::Rendering::FreeType::FontFace :: GetBitmapPointer ()
{
	
	return reinterpret_cast <void *> ( FHandle -> glyph -> bitmap.buffer );
	
}

void Red::Text::Rendering::FreeType::FontFace :: GetBitmapMetrics ( BitmapMetrics * Metrics )
{
	
	if ( Metrics == NULL )
		return;
	
	Metrics -> Rows = FHandle -> glyph -> bitmap.rows;
	Metrics -> Width = FHandle -> glyph -> bitmap.width;
	Metrics -> Pitch = FHandle -> glyph -> bitmap.pitch;
	Metrics -> GrayCount = FHandle -> glyph -> bitmap.num_grays;
	Metrics -> PixMode = static_cast <PixelMode> ( FHandle -> glyph -> bitmap.pixel_mode );
	
}

void Red::Text::Rendering::FreeType::FontFace :: SetTransform ( double A, double B, double C, double D, double TX, double TY )
{
	
	FT_Matrix Transform;
	
	Transform.xx = static_cast <FT_Fixed> ( A * 65536.0 );
	Transform.xy = static_cast <FT_Fixed> ( B * 65536.0 );
	Transform.yx = static_cast <FT_Fixed> ( C * 65536.0 );
	Transform.yy = static_cast <FT_Fixed> ( D * 65536.0 );
	
	FT_Vector Translation;
	
	Translation.x = static_cast <FT_Pos> ( TX * 64.0 );
	Translation.x = static_cast <FT_Pos> ( TY * 64.0 );
	
	FT_Set_Transform ( FHandle, & Transform, & Translation );
	
}

void Red::Text::Rendering::FreeType::FontFace :: SetIdentityTransform ( double TX, double TY )
{
	
	FT_Vector Translation;
	
	Translation.x = static_cast <FT_Pos> ( TX * 64.0 );
	Translation.x = static_cast <FT_Pos> ( TY * 64.0 );
	
	FT_Set_Transform ( FHandle, NULL, & Translation );
	
}

#endif
