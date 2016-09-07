#include <Red/Text/Rendering/FreeType/FreeTypeFontRenderData.h>

#ifdef RED_OPT_TEXT_RENDERING_FREETYPE

#include <string.h>
#include <math.h>

#include <iostream>

Red::Text::Rendering :: FontRenderData * Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: CreateRenderData ( FontFace * Face, const std :: u32string & CharSet, FontRenderData :: AtlasGenerationMode GenerationMode, FreeTypeRenderFlag Flags )
{
	
	FreeTypeFontRenderData * RenderDataInternal = new FreeTypeFontRenderData ( Face, Flags );
	return new FontRenderData ( Face, RenderDataInternal, RenderDataInternal, CharSet, GenerationMode );
	
}

Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: ~FreeTypeFontRenderData ()
{
}

Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: FreeTypeFontRenderData ( FontFace * Font, FreeTypeRenderFlag Flags ):
	RefCounted (),
	Font ( Font ),
	Flags ( Flags )
{
	
	Font -> Reference ();
	
}

void Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: GetAdvance ( RawFontTextureAtlas * Atlas, char32_t Current, char32_t Last, double & AdvanceX, double & AdvanceY ) const
{
	
	if ( ( ( Flags & kFreeTypeRenderFlag_ComputeMetrics ) != 0 ) || ( ( Font -> GetFaceFlags () & FontFace :: kFaceFlag_Kerning ) == 0 ) )
		return GetAdvance ( Atlas, Last, AdvanceX, AdvanceY );
	
	uint32_t CurrentIndex = Font -> GlyphIndexFromChar ( Current );
	
	if ( CurrentIndex == 0 )
		return GetAdvance ( Atlas, Last, AdvanceX, AdvanceY );
	
	uint32_t LastIndex = Font -> GlyphIndexFromChar ( Last );
	
	if ( LastIndex == 0 )
	{
		
		AdvanceX = 0;
		AdvanceY = 0;
		
		return;
		
	}
	
	FT_Vector Kerning;
	
	Font -> SetPixelSize ( Atlas -> GetBitmapFontSize () );
	
	if ( FT_Get_Kerning ( Font -> FHandle, LastIndex, CurrentIndex, FT_KERNING_UNSCALED, & Kerning ) != 0 )
		return GetAdvance ( Atlas, Last, AdvanceX, AdvanceY );
	
	AdvanceX = static_cast <double> ( Kerning.x ) * 0.015625;
	AdvanceY = static_cast <double> ( Kerning.y ) * 0.015625;
	
}

void Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: GetAdvance ( RawFontTextureAtlas * Atlas, char32_t Last, double & AdvanceX, double & AdvanceY ) const
{
	
	Font -> SetPixelSize ( Atlas -> GetBitmapFontSize () );
	
	uint32_t LastIndex = Font -> GlyphIndexFromChar ( Last );
	
	if ( LastIndex == 0 )
	{
		
		AdvanceX = 0;
		AdvanceY = 0;
		
		return;
		
	}
	
	if ( Font -> LoadGlyph ( LastIndex, ( ( Flags & kFreeTypeRenderFlag_ComputeMetrics ) != 0 ) ? FontFace :: kLoadFlag_ComputeMetrics : FontFace :: kLoadFlag_Defaults ) )
	{
		
		AdvanceX = static_cast <double> ( Font -> FHandle -> glyph -> advance.x ) * 0.015625;
		AdvanceY = static_cast <double> ( Font -> FHandle -> glyph -> advance.y ) * 0.015625;
		
	}
	else
	{
		
		AdvanceX = 0;
		AdvanceY = 0;
		
	}
	
}

void Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: GetOffset ( RawFontTextureAtlas * Atlas, char32_t Current, double & OffsetX, double & OffsetY ) const
{
	
	(void) Atlas;
	
	uint32_t CurrentIndex = Font -> GlyphIndexFromChar ( Current );
	
	if ( CurrentIndex == 0 )
	{
		
		OffsetX = 0;
		OffsetY = 0;
		
		return;
		
	}
	
	if ( Font -> LoadGlyph ( CurrentIndex, ( ( Flags & kFreeTypeRenderFlag_ComputeMetrics ) != 0 ) ? FontFace :: kLoadFlag_ComputeMetrics : FontFace :: kLoadFlag_Defaults ) )
	{
		
		if ( ( Font -> GetFaceFlags () & FT_FACE_FLAG_VERTICAL ) == 0 )
		{
			
			OffsetX = static_cast <double> ( Font -> FHandle -> glyph -> metrics.horiBearingX ) * 0.015625;
			OffsetY = static_cast <double> ( Font -> FHandle -> glyph -> metrics.horiBearingY ) * 0.015625;
			
		}
		else
		{
			
			OffsetX = static_cast <double> ( Font -> FHandle -> glyph -> metrics.vertBearingX ) * 0.015625;
			OffsetY = static_cast <double> ( Font -> FHandle -> glyph -> metrics.vertBearingY ) * 0.015625;
			
		}
		
	}
	else
	{
		
		OffsetX = 0;
		OffsetY = 0;
		
	}
	
}

double Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: GetFontHeight ( RawFontTextureAtlas * Atlas ) const
{
	
	(void) Atlas;
	
	Font -> SetPixelSize ( Atlas -> GetBitmapFontSize () );
	
	return Font -> FHandle -> size -> metrics.height * 0.015625;
	
}

double Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: GetScalingFactor ( RawFontTextureAtlas * Atlas, double PixelSize ) const
{
	
	return PixelSize / static_cast <double> ( Atlas -> GetBitmapFontSize () );
	
}

Red::Text::Rendering::IFontLayoutSource :: LayoutDirection Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: GetLayoutDirection () const
{
	
	return ( ( Font -> GetFaceFlags () & FT_FACE_FLAG_VERTICAL ) == 0 ) ? kLayoutDirection_Horizontal : kLayoutDirection_Vertical;
	
}

typedef struct
{
	
	char32_t Charachter;
	uint32_t GlyphID;
	
	int32_t Index;
	
	uint32_t Width;
	uint32_t Height;
	uint32_t Pitch;
	
	Red::Text::Rendering::FreeType::FontFace :: PixelMode PixMode;
	
} _GlyphPack;

void _BlitGreyToAlpha8 ( void * Target, uint32_t X, uint32_t Y, uint32_t TargetWidth, const void * Source, uint32_t Width, uint32_t Height, int32_t Pitch )
{
	
	for ( uint32_t OffsetY = 0; OffsetY < Height; OffsetY ++ )
	{
		
		uint8_t * TargetStartAddress = & ( reinterpret_cast <uint8_t *> ( Target ) [ ( TargetWidth * ( Y + OffsetY ) ) + X ] );
		const uint8_t * SourceStartAddress = ( Pitch >= 0 ) ? & ( reinterpret_cast <const uint8_t *> ( Source ) [ Pitch * OffsetY ] ) : & ( reinterpret_cast <const uint8_t *> ( Source ) [ - Pitch * ( Height - 1 - OffsetY ) + X ] );
		
		memcpy ( reinterpret_cast <void *> ( TargetStartAddress ), reinterpret_cast <const void *> ( SourceStartAddress ), sizeof ( uint8_t ) * Width );
		
	}
	
}

void _BlitMonochromeToAlpha8 ( void * Target, uint32_t X, uint32_t Y, uint32_t TargetWidth, const void * Source, uint32_t Width, uint32_t Height, int32_t Pitch )
{
	
	(void) Target;
	(void) X;
	(void) Y;
	(void) TargetWidth;
	(void) Source;
	(void) Width;
	(void) Height;
	(void) Pitch;
	// TODO: Implement
	
}

void _BlitPreMulBGRA32ToAlpha8 ( void * Target, uint32_t X, uint32_t Y, uint32_t TargetWidth, const void * Source, uint32_t Width, uint32_t Height, int32_t Pitch )
{
	
	(void) Target;
	(void) X;
	(void) Y;
	(void) TargetWidth;
	(void) Source;
	(void) Width;
	(void) Height;
	(void) Pitch;
	// TODO: Implement
	
}

void _BlitGreyToARGB32 ( void * Target, uint32_t X, uint32_t Y, uint32_t TargetWidth, const void * Source, uint32_t Width, uint32_t Height, int32_t Pitch )
{
	
	(void) Target;
	(void) X;
	(void) Y;
	(void) TargetWidth;
	(void) Source;
	(void) Width;
	(void) Height;
	(void) Pitch;
	// TODO: Implement
	
}

void _BlitMonochromeToARGB32 ( void * Target, uint32_t X, uint32_t Y, uint32_t TargetWidth, const void * Source, uint32_t Width, uint32_t Height, int32_t Pitch )
{
	
	(void) Target;
	(void) X;
	(void) Y;
	(void) TargetWidth;
	(void) Source;
	(void) Width;
	(void) Height;
	(void) Pitch;
	// TODO: Implement
	
}

void _BlitPreMulBGRA32ToARGB32 ( void * Target, uint32_t X, uint32_t Y, uint32_t TargetWidth, const void * Source, uint32_t Width, uint32_t Height, int32_t Pitch )
{
	
	(void) Target;
	(void) X;
	(void) Y;
	(void) TargetWidth;
	(void) Source;
	(void) Width;
	(void) Height;
	(void) Pitch;
	// TODO: Implement
	
}

void _BlitToAlpha8 ( void * Target, uint32_t X, uint32_t Y, uint32_t TargetWidth, const void * Source, uint32_t Width, uint32_t Height, uint32_t Pitch, Red::Text::Rendering::FreeType::FontFace :: PixelMode PixMode )
{
	
	switch ( PixMode )
	{
		
		case Red::Text::Rendering::FreeType::FontFace :: kPixelMode_Monochrome:
			return _BlitMonochromeToAlpha8 ( Target, X, Y, TargetWidth, Source, Width, Height, Pitch );
			
		case Red::Text::Rendering::FreeType::FontFace :: kPixelMode_Gray:
			return _BlitGreyToAlpha8 ( Target, X, Y, TargetWidth, Source, Width, Height, Pitch );
			
		case Red::Text::Rendering::FreeType::FontFace :: kPixelMode_BGRA:
			return _BlitPreMulBGRA32ToAlpha8 ( Target, X, Y, TargetWidth, Source, Width, Height, Pitch );
			
		default:
			break;
		
	}
	
}

void _BlitToARGB32 ( void * Target, uint32_t X, uint32_t Y, uint32_t TargetWidth, const void * Source, uint32_t Width, uint32_t Height, uint32_t Pitch, Red::Text::Rendering::FreeType::FontFace :: PixelMode PixMode )
{
	
	switch ( PixMode )
	{
		
		case Red::Text::Rendering::FreeType::FontFace :: kPixelMode_Monochrome:
			return _BlitMonochromeToARGB32 ( Target, X, Y, TargetWidth, Source, Width, Height, Pitch );
			
		case Red::Text::Rendering::FreeType::FontFace :: kPixelMode_Gray:
			return _BlitGreyToARGB32 ( Target, X, Y, TargetWidth, Source, Width, Height, Pitch );
			
		case Red::Text::Rendering::FreeType::FontFace :: kPixelMode_BGRA:
			return _BlitPreMulBGRA32ToARGB32 ( Target, X, Y, TargetWidth, Source, Width, Height, Pitch );
			
		default:
			break;
		
	}
	
}

Red::Text::Rendering :: RawFontTextureAtlas * Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: CreateAtlas ( uint32_t PixelSize, const std :: u32string & CharSet, FontRenderData :: AtlasGenerationMode GenerationMode ) const
{
	
	uint32_t I;
	uint32_t GlyphCount;
	
	char32_t MaxCodePoint = 0;
	
	// We loop over this twice to avoid std::vector dynamic allocation in exchange for a single array allocation.
	// We can also take care of calculating some Atlas data here
	for ( I = 0; I < CharSet.size (); I ++ )
	{
		
		if ( Font -> GlyphIndexFromChar ( CharSet [ I ] ) != 0 )
		{
			
			Font -> SetPixelSize ( PixelSize );
			
			if ( Font -> LoadGlyph ( CharSet [ I ], ( ( Flags & kFreeTypeRenderFlag_ComputeMetrics ) != 0 ) ? FontFace :: kLoadFlag_ComputeMetrics : FontFace :: kLoadFlag_Defaults ) )
				GlyphCount ++;
			
		}
		
		if ( CharSet [ I ] > MaxCodePoint )
			MaxCodePoint = CharSet [ I ];
		
	}
	
	// If there aren't any glyphs to render, then why go to all the trouble?
	if ( GlyphCount == 0 )
		return NULL;
	
	int32_t * CodePointToMetricsIndex = new int32_t [ MaxCodePoint + 1 ];
	
	for ( I = 0; I < static_cast <uint32_t> ( MaxCodePoint + 1 ); I ++ )
		CodePointToMetricsIndex [ I ] = - 1;
	
	_GlyphPack * GlyphedChars = new _GlyphPack [ GlyphCount ];
	uint32_t GlyphPackIndex = 0;
	
	for ( I = 0; I < CharSet.size (); I ++ )
	{
		
		uint32_t GlyphIndex = Font -> GlyphIndexFromChar ( CharSet [ I ] );
		
		if ( GlyphIndex != 0 )
		{
			
			Font -> SetPixelSize ( PixelSize );
			
			// Unfortunately we need to render in order to get bitmap metrics :(
			if ( Font -> LoadGlyph ( GlyphIndex, ( ( Flags & kFreeTypeRenderFlag_ComputeMetrics ) != 0 ) ? FontFace :: kLoadFlag_ComputeMetrics : FontFace :: kLoadFlag_Defaults ) )
			{
				
				if ( Font -> RenderGlyph () )
				{
					
					FontFace :: BitmapMetrics BMMetrics;
					Font -> GetBitmapMetrics ( BMMetrics );
					
					GlyphedChars [ GlyphPackIndex ].Charachter = CharSet [ I ];
					GlyphedChars [ GlyphPackIndex ].GlyphID = GlyphIndex;
					GlyphedChars [ GlyphPackIndex ].Index = GlyphPackIndex;
					GlyphedChars [ GlyphPackIndex ].Width = BMMetrics.Width;
					GlyphedChars [ GlyphPackIndex ].Height = BMMetrics.Rows;
					GlyphedChars [ GlyphPackIndex ].Pitch = BMMetrics.Pitch;
					GlyphedChars [ GlyphPackIndex ].PixMode = BMMetrics.PixMode;
					
					GlyphPackIndex ++;
					
				}
				
			}
			
		}
		
	}
	
	// Because some glyphs may not render properly, GlyphPackIndex is the only reliable count of usable glyphs.
	GlyphCount = GlyphPackIndex;
	
	if ( ( GenerationMode == FontRenderData :: kAtlasGenerationMode_PowerOfTwo ) || ( GenerationMode == FontRenderData :: kAtlasGenerationMode_Rectangle ) )
	{
		
		uint32_t MaxGlyphWidth = 0;
		uint32_t MaxGlyphHeight = 0;
		
		for ( I = 0; I < GlyphCount; I ++ )
		{
			
			MaxGlyphWidth = ( GlyphedChars [ I ].Width > MaxGlyphWidth ) ? GlyphedChars [ I ].Width : MaxGlyphWidth;
			MaxGlyphHeight = ( GlyphedChars [ I ].Height > MaxGlyphHeight ) ? GlyphedChars [ I ].Height : MaxGlyphHeight;
			
		}
		
		double Area = static_cast <double> ( static_cast <uint64_t> ( MaxGlyphWidth ) * static_cast <uint64_t> ( MaxGlyphHeight ) * static_cast <uint64_t> ( GlyphCount ) );
		double SqrtArea = sqrt ( Area );
		uint32_t XCount = ceil ( SqrtArea / static_cast <double> ( MaxGlyphWidth ) );
		uint32_t YCount = ceil ( SqrtArea / static_cast <double> ( MaxGlyphHeight ) );
		
		uint32_t MaxDimensionX = XCount * MaxGlyphWidth;
		uint32_t MaxDimensionY = YCount * MaxGlyphHeight;
		
		if ( GenerationMode == FontRenderData :: kAtlasGenerationMode_PowerOfTwo )
		{
			
			MaxDimensionX --;
			MaxDimensionX |= MaxDimensionX >> 1;
			MaxDimensionX |= MaxDimensionX >> 2;
			MaxDimensionX |= MaxDimensionX >> 4;
			MaxDimensionX |= MaxDimensionX >> 8;
			MaxDimensionX |= MaxDimensionX >> 16;
			MaxDimensionX ++;
			
			MaxDimensionY --;
			MaxDimensionY |= MaxDimensionY >> 1;
			MaxDimensionY |= MaxDimensionY >> 2;
			MaxDimensionY |= MaxDimensionY >> 4;
			MaxDimensionY |= MaxDimensionY >> 8;
			MaxDimensionY |= MaxDimensionY >> 16;
			MaxDimensionY ++;
			
		}
		
		FontFace :: BitmapMetrics BMMetrics;
		Font -> GetBitmapMetrics ( BMMetrics );
		
		
		Util :: RCMem * AtlasImageMemory = new Util :: RCMem ( MaxDimensionX * MaxDimensionY * ( ( ( Flags & kFreeTypeRenderFlag_Color ) != 0 ) ? sizeof ( uint32_t ) : sizeof ( uint8_t ) ) );
		
		if ( AtlasImageMemory -> GetData () == NULL )
		{
			
			delete AtlasImageMemory;
			
			delete [] GlyphedChars;
			
			return NULL;
			
		}
		
		// TODO: Add way to render to ARGB32
		
		RawFontTextureAtlas :: GlyphMetrics * GlyphMetricsList = new RawFontTextureAtlas :: GlyphMetrics [ GlyphCount ];
		
		for ( I = 0; I < GlyphCount; I ++ )
		{
			
			if ( ( ! Font -> LoadGlyph ( GlyphedChars [ I ].GlyphID, ( ( Flags & kFreeTypeRenderFlag_ComputeMetrics ) != 0 ) ? FontFace :: kLoadFlag_ComputeMetrics : FontFace :: kLoadFlag_Defaults ) ) || ( ! Font -> RenderGlyph () ) )
			{
				
				GlyphMetricsList [ I ].OffsetX = 0;
				GlyphMetricsList [ I ].OffsetY = 0;
				GlyphMetricsList [ I ].Width = 0;
				GlyphMetricsList [ I ].Height = 0;
				
				continue;
				
			}
			
			if ( ( Flags & kFreeTypeRenderFlag_Color ) != 0 )
				_BlitToARGB32 ( AtlasImageMemory -> GetData (), ( I % XCount ) * MaxGlyphWidth, ( I / XCount ) * MaxGlyphHeight, MaxDimensionX, Font -> GetBitmapPointer (), GlyphedChars [ I ].Width, GlyphedChars [ I ].Height, GlyphedChars [ I ].Pitch, GlyphedChars [ I ].PixMode );
			else
				_BlitToAlpha8 ( AtlasImageMemory -> GetData (), ( I % XCount ) * MaxGlyphWidth, ( I / XCount ) * MaxGlyphHeight, MaxDimensionX, Font -> GetBitmapPointer (), GlyphedChars [ I ].Width, GlyphedChars [ I ].Height, GlyphedChars [ I ].Pitch, GlyphedChars [ I ].PixMode );
			
			GlyphMetricsList [ I ].OffsetX = ( I % XCount ) * MaxGlyphWidth;
			GlyphMetricsList [ I ].OffsetY = ( I / XCount ) * MaxGlyphHeight;
			GlyphMetricsList [ I ].Width = GlyphedChars [ I ].Width;
			GlyphMetricsList [ I ].Height = GlyphedChars [ I ].Height;
			
			CodePointToMetricsIndex [ GlyphedChars [ I ].Charachter ] = I;
			
		}
		
		return new RawFontTextureAtlas ( AtlasImageMemory, MaxDimensionX, MaxDimensionY, RawFontTextureAtlas :: kBitmapFormat_Alpha_8, GlyphCount, GlyphMetricsList, MaxCodePoint, CodePointToMetricsIndex, PixelSize );
		
	}
	
	return NULL;
	
}

#endif

