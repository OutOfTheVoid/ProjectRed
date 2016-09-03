#include <Red/Text/Rendering/RawFontTextureAtlas.h>

#include <stdlib.h>

Red::Text::Rendering::RawFontTextureAtlas :: RawFontTextureAtlas ( const void * BitmapData, const BitmapFormat Format, uint32_t GlyphCount, const GlyphMetrics * Metrics, char32_t MaxCodePoint, int32_t * CodePointToMetricsIndex ):
	BitmapData ( BitmapData ),
	Format ( Format ),
	GlyphCount ( GlyphCount ),
	Metrics ( Metrics ),
	MaxCodePoint ( MaxCodePoint ),
	CodePointToMetricsIndex ( CodePointToMetricsIndex )
{
}

Red::Text::Rendering::RawFontTextureAtlas :: ~RawFontTextureAtlas ()
{
	
	DisposeBitmap ();
	
}

const void * Red::Text::Rendering::RawFontTextureAtlas :: GetBitmapData () const
{
	
	return BitmapData;
	
}

void Red::Text::Rendering::RawFontTextureAtlas :: DisposeBitmap ()
{
	
	free ( const_cast <void *> ( BitmapData ) );
	
	BitmapData = NULL;
	
}

Red::Text::Rendering::RawFontTextureAtlas :: BitmapFormat Red::Text::Rendering::RawFontTextureAtlas :: GetFormat () const
{
	
	return Format;
	
}

bool Red::Text::Rendering::RawFontTextureAtlas :: GlyphExists ( char32_t CodePoint ) const
{
	
	if ( CodePoint > MaxCodePoint )
		return false;
	
	if ( CodePointToMetricsIndex [ CodePoint ] < 0 )
		return false;
	
	return true;
	
}

Red::Text::Rendering::RawFontTextureAtlas :: GlyphMetrics Red::Text::Rendering::RawFontTextureAtlas :: GetGlyphMetrics ( char32_t CodePoint ) const
{
	
	return Metrics [ CodePointToMetricsIndex [ CodePoint ] ];
	
}
