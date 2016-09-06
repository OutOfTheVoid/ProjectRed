#include <Red/Text/Rendering/FreeType/FreeTypeFontRenderData.h>

#ifdef RED_OPT_TEXT_RENDERING_FREETYPE

#include <string.h>
#include <iostream>

Red::Text::Rendering :: FontRenderData * Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: CreateRenderData ( FontFace * Face, const std :: u32string & CharSet, FontRenderData :: AtlasGenerationMode GenerationMode )
{
	
	FreeTypeFontRenderData * RenderDataInternal = new FreeTypeFontRenderData ( Face );
	return new FontRenderData ( Face, RenderDataInternal, RenderDataInternal, CharSet, GenerationMode );
	
}

Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: ~FreeTypeFontRenderData ()
{
}

Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: FreeTypeFontRenderData ( FontFace * Font ):
	RefCounted (),
	Font ( Font )
{
	
	Font -> Reference ();
	
}

void Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: GetAdvance ( RawFontTextureAtlas * Atlas, char32_t Current, char32_t Last, double & AdvanceX, double & AdvanceY ) const
{
	
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
	
	FT_Get_Kerning ( Font -> FHandle, LastIndex, CurrentIndex, FT_KERNING_UNFITTED, & Kerning );
	
	AdvanceX = static_cast <double> ( Kerning.x ) * 0.015625;
	AdvanceY = static_cast <double> ( Kerning.y ) * 0.015625;
	
}

void Red::Text::Rendering::FreeType::FreeTypeFontRenderData :: GetAdvance ( RawFontTextureAtlas * Atlas, char32_t Last, double & AdvanceX, double & AdvanceY ) const
{
	
	uint32_t LastIndex = Font -> GlyphIndexFromChar ( Last );
	
	if ( LastIndex == 0 )
	{
		
		AdvanceX = 0;
		AdvanceY = 0;
		
		return;
		
	}
	
	Font -> SetPixelSize ( Atlas -> GetBitmapFontSize () );
	
	if ( Font -> LoadGlyph ( LastIndex, FontFace :: kLoadFlag_Defaults ) )
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
	
	if ( Font -> LoadGlyph ( CurrentIndex, FontFace :: kLoadFlag_Defaults ) )
	{
		
		if ( ( Font -> GetFaceFlags () & FT_FACE_FLAG_VERTICAL ) == 0 )
		{
			
			OffsetX = static_cast <double> ( Font -> FHandle -> glyph -> metrics.horiBearingX ) * 0.015625;
			OffsetY = 0.0;
			
		}
		else
		{
			
			OffsetX = 0.0;
			OffsetY = static_cast <double> ( Font -> FHandle -> glyph -> metrics.horiBearingY ) * 0.015625;
			
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
	
	return Font -> FHandle -> height;
	
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
	uint32_t X;
	uint32_t Y;
	
} _GlyphPack;

typedef struct
{
	
	uint32_t X;
	uint32_t Y;
	uint32_t Width;
	uint32_t Height;
	
} _Rectangle;

typedef struct PackingTreeNode_Struct
{
	
	bool Leaf;
	
	struct PackingTreeNode_Struct * LeftChild;
	struct PackingTreeNode_Struct * RightChild;
	
	_Rectangle Rect;
	
	int32_t GlyphPackIndex;
	
} _PackingTreeNode;

_PackingTreeNode * _New_PackingTreeNode ()
{
	
	_PackingTreeNode * New = new _PackingTreeNode ();
	
	New -> LeftChild = NULL;
	New -> RightChild = NULL;
	New -> Leaf = true;
	
	New -> Rect.X = 0;
	New -> Rect.Y = 0;
	New -> Rect.Width = 0xFFFFFFFF;
	New -> Rect.Height = 0xFFFFFFFF;
	
	New -> GlyphPackIndex = - 1;
	
	return New;
	
}

void _Delete_PackingTree ( _PackingTreeNode * Root )
{
	
	if ( Root -> LeftChild != NULL )
		_Delete_PackingTree ( Root -> LeftChild );
	
	if ( Root -> RightChild != NULL )
		_Delete_PackingTree ( Root -> RightChild );
	
	delete Root;
	
}

void _FindMaxDimensions_PackingTreeNode ( _PackingTreeNode * Node, uint32_t & MaxX, uint32_t & MaxY )
{
	
	if ( Node == NULL )
		return;
	
	_FindMaxDimensions_PackingTreeNode ( Node -> LeftChild, MaxX, MaxY );
	_FindMaxDimensions_PackingTreeNode ( Node -> RightChild, MaxX, MaxY );
	
	if ( Node -> GlyphPackIndex == - 1 )
		return;
	
	if ( ( Node -> Rect.X + Node -> Rect.Width ) > MaxX )
		MaxX = ( Node -> Rect.X + Node -> Rect.Width );
	
	if ( ( Node -> Rect.Y + Node -> Rect.Height ) > MaxY )
		MaxY = ( Node -> Rect.Y + Node -> Rect.Height );
	
}

_PackingTreeNode * _Insert_PackingTreeNode ( _PackingTreeNode * Node, _GlyphPack * Pack )
{
	
	if ( ! Node -> Leaf )
	{
		
		_PackingTreeNode * NewNode = _Insert_PackingTreeNode ( Node -> LeftChild, Pack );
		
		if ( NewNode != NULL )
		{
			
			return NewNode;
			
		}
		
		NewNode = _Insert_PackingTreeNode ( Node -> RightChild, Pack );
		
		return NewNode;
		
	}
	else
	{
		
		if ( Node -> GlyphPackIndex != - 1 )
			return NULL;
		
		if ( ( Pack -> Width > Node -> Rect.Width ) || ( Pack -> Height > Node -> Rect.Height ) )
			return NULL;
		
		if ( ( Pack -> Width == Node -> Rect.Width ) && ( Pack -> Height == Node -> Rect.Height ) )
		{
			
			Node -> GlyphPackIndex = Pack -> Index;
			Pack -> X = Node -> Rect.X;
			Pack -> Y = Node -> Rect.Y;
			
			return Node;
			
		}
		
		Node -> Leaf = false;
		
		Node -> LeftChild = _New_PackingTreeNode ();
		Node -> RightChild = _New_PackingTreeNode ();
		
		uint32_t DiffX = Node -> Rect.Width - Pack -> Width;
		uint32_t DiffY = Node -> Rect.Height - Pack -> Height;
		
		if ( DiffX > DiffY )
		{
			
			Node -> LeftChild -> Rect.X = Node -> Rect.X;
			Node -> LeftChild -> Rect.Y = Node -> Rect.Y;
			Node -> LeftChild -> Rect.Width = Pack -> Width;
			Node -> LeftChild -> Rect.Height = Node -> Rect.Height;
			
			Node -> RightChild -> Rect.X = Node -> Rect.X + Pack -> Width;
			Node -> RightChild -> Rect.Y = Node -> Rect.Y;
			Node -> RightChild -> Rect.Width = Node -> Rect.Width - Pack -> Width;
			Node -> RightChild -> Rect.Height = Node -> Rect.Height;
			
		}
		else
		{
			
			Node -> LeftChild -> Rect.X = Node -> Rect.X;
			Node -> LeftChild -> Rect.Y = Node -> Rect.Y;
			Node -> LeftChild -> Rect.Width = Node -> Rect.Width;
			Node -> LeftChild -> Rect.Height = Pack -> Height;
			
			Node -> RightChild -> Rect.X = Node -> Rect.X;
			Node -> RightChild -> Rect.Y = Node -> Rect.Y + Pack -> Height;
			Node -> RightChild -> Rect.Width = Node -> Rect.Width;
			Node -> RightChild -> Rect.Height = Node -> Rect.Height - Pack -> Height;
			
		}
		
		_PackingTreeNode * ReturnNode = _Insert_PackingTreeNode ( Node -> LeftChild, Pack );
		
		return ReturnNode;
		
	}
	
}

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

void _PerformTreeBlitToAlpha8 ( void * TargetAtlas, uint32_t TargetWidth, _PackingTreeNode * Node, Red::Text::Rendering::FreeType :: FontFace * Font, _GlyphPack * GlyphedChars, uint32_t PixelSize )
{
	
	if ( Node == NULL )
		return;
	
	_PerformTreeBlitToAlpha8 ( TargetAtlas, TargetWidth, Node -> LeftChild, Font, GlyphedChars, PixelSize );
	_PerformTreeBlitToAlpha8 ( TargetAtlas, TargetWidth, Node -> RightChild, Font, GlyphedChars, PixelSize );
	
	if ( Node -> GlyphPackIndex == - 1 )
		return;
	
	_GlyphPack & Pack = GlyphedChars [ Node -> GlyphPackIndex ];
	
	Font -> SetPixelSize ( PixelSize );
	
	if ( ! Font -> LoadGlyph ( Pack.GlyphID, Red::Text::Rendering::FreeType :: FontFace :: kLoadFlag_Defaults ) )
		return;
	
	if ( ! Font -> RenderGlyph () )
		return;
	
	if ( Font -> GetBitmapPointer () == NULL )
		return;
	
	Red::Text::Rendering::FreeType::FontFace :: BitmapMetrics BMMetrics;
	Font -> GetBitmapMetrics ( BMMetrics );
	
	if ( BMMetrics.PixMode == Red::Text::Rendering::FreeType :: FontFace :: kPixelMode_Gray )
		_BlitGreyToAlpha8 ( TargetAtlas, Node -> Rect.X, Node -> Rect.Y, TargetWidth, Font -> GetBitmapPointer (), BMMetrics.Width, BMMetrics.Rows, BMMetrics.Pitch );
	else if ( BMMetrics.PixMode == Red::Text::Rendering::FreeType :: FontFace :: kPixelMode_Monochrome )
		_BlitMonochromeToAlpha8 ( TargetAtlas, Node -> Rect.X, Node -> Rect.Y, TargetWidth, Font -> GetBitmapPointer (), BMMetrics.Width, BMMetrics.Rows, BMMetrics.Pitch );
	else if ( BMMetrics.PixMode == Red::Text::Rendering::FreeType :: FontFace :: kPixelMode_BGRA )
		_BlitPreMulBGRA32ToAlpha8 ( TargetAtlas, Node -> Rect.X, Node -> Rect.Y, TargetWidth, Font -> GetBitmapPointer (), BMMetrics.Width, BMMetrics.Rows, BMMetrics.Pitch );
	
}

void _PerformTreeBlitToARGB32 ( void * TargetAtlas, uint32_t TargetWidth, _PackingTreeNode * Node, Red::Text::Rendering::FreeType :: FontFace * Font, _GlyphPack * GlyphedChars )
{
	
	(void) TargetAtlas;
	(void) TargetWidth;
	(void) Node;
	(void) Font;
	(void) GlyphedChars;
	
	// TODO: Implement
	
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
			
			if ( Font -> LoadGlyph ( CharSet [ I ], FontFace :: kLoadFlag_Defaults ) )
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
			if ( Font -> LoadGlyph ( GlyphIndex, FontFace :: kLoadFlag_Defaults ) )
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
					GlyphedChars [ GlyphPackIndex ].X = 0;
					GlyphedChars [ GlyphPackIndex ].Y = 0;
					
					GlyphPackIndex ++;
					
				}
				
			}
			
		}
		
	}
	
	// Because some glyphs may not render properly, GlyphPackIndex is the only reliable count of usable glyphs.
	GlyphCount = GlyphPackIndex;
	
	if ( ( GenerationMode == FontRenderData :: kAtlasGenerationMode_PowerOfTwo ) || ( GenerationMode == FontRenderData :: kAtlasGenerationMode_Rectangle ) )
	{
		
		_PackingTreeNode * RootNode = _New_PackingTreeNode ();
		
		// Build our tree. I could have stuck this in the upper loop, but say i wanted to sort the list, i'd have to seperate them.
		// TODO: Consider sorting GlyphedChars based on maximum dimension.
		for ( I = 0; I < GlyphCount; I ++ )
			_Insert_PackingTreeNode ( RootNode, & GlyphedChars [ I ] );
		
		uint32_t MaxDimensionX = 0;
		uint32_t MaxDimensionY = 0;
		
		_FindMaxDimensions_PackingTreeNode ( RootNode, MaxDimensionX, MaxDimensionY );
		
		std :: cout << "Dimensions: [ " << MaxDimensionX << ", " << MaxDimensionY << " ]" << std :: endl;
		
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
		
		// TODO: Add way to render to ARGB32
		
		Util :: RCMem * AtlasImageMemory = new Util :: RCMem ( MaxDimensionX * MaxDimensionY * sizeof ( uint8_t ) );
		
		if ( AtlasImageMemory -> GetData () == NULL )
		{
			
			delete AtlasImageMemory;
			
			_Delete_PackingTree ( RootNode );
			
			delete [] GlyphedChars;
			
			return NULL;
			
		}
		
		
		// Perform tree-blit
		_PerformTreeBlitToAlpha8 ( AtlasImageMemory -> GetData (), MaxDimensionX, RootNode, Font, GlyphedChars, PixelSize );
		_Delete_PackingTree ( RootNode );
		
		RawFontTextureAtlas :: GlyphMetrics * GlyphMetricsList = new RawFontTextureAtlas :: GlyphMetrics [ GlyphCount ];
		
		for ( I = 0; I < GlyphCount; I ++ )
		{
			
			GlyphMetricsList [ I ].OffsetX = GlyphedChars [ I ].X;
			GlyphMetricsList [ I ].OffsetY = GlyphedChars [ I ].Y;
			GlyphMetricsList [ I ].Width = GlyphedChars [ I ].Width;
			GlyphMetricsList [ I ].Height = GlyphedChars [ I ].Height;
			
		}
		
		return new RawFontTextureAtlas ( AtlasImageMemory, MaxDimensionX, MaxDimensionY, RawFontTextureAtlas :: kBitmapFormat_Alpha_8, GlyphCount, GlyphMetricsList, MaxCodePoint, CodePointToMetricsIndex, PixelSize );
		
	}
	
	return NULL;
	
}

#endif

