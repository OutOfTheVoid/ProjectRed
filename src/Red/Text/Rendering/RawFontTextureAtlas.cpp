#include <Red/Text/Rendering/RawFontTextureAtlas.h>

#include <stdlib.h>

Red::Text::Rendering::RawFontTextureAtlas :: RawFontTextureAtlas ( Util :: RCMem * BitmapMemory, uint32_t BitmapWidth, uint32_t BitmapHeight, const BitmapFormat Format, uint32_t GlyphCount, const GlyphMetrics * Metrics, char32_t MaxCodePoint, int32_t * CodePointToMetricsIndex, int32_t BitmapFontSize ):
	RefCounted (),
	BitmapMemory ( BitmapMemory ),
	BitmapWidth ( BitmapWidth ),
	BitmapHeight ( BitmapHeight ),
	Format ( Format ),
	GlyphCount ( GlyphCount ),
	Metrics ( Metrics ),
	MaxCodePoint ( MaxCodePoint ),
	CodePointToMetricsIndex ( CodePointToMetricsIndex ),
	BitmapFontSize ( BitmapFontSize )
{
	
	BitmapMemory -> Reference ();
	
}

Red::Text::Rendering::RawFontTextureAtlas :: ~RawFontTextureAtlas ()
{
	
	DisposeBitmap ();
	
}

const void * Red::Text::Rendering::RawFontTextureAtlas :: GetBitmapData () const
{
	
	if ( BitmapMemory == NULL )
		return NULL;
	
	return BitmapMemory -> GetData ();
	
}

void Red::Text::Rendering::RawFontTextureAtlas :: DisposeBitmap ()
{
	
	if (  BitmapMemory == NULL )
		return;
	
	BitmapMemory -> Dereference ();
	BitmapMemory = NULL;
	
}

uint32_t Red::Text::Rendering::RawFontTextureAtlas :: GetBitmapWidth () const
{
	
	return BitmapWidth;
	
}

uint32_t Red::Text::Rendering::RawFontTextureAtlas :: GetBitmapHeight () const
{
	
	return BitmapHeight;
	
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

int32_t Red::Text::Rendering::RawFontTextureAtlas :: GetBitmapFontSize () const
{
	
	return BitmapFontSize;
	
}
