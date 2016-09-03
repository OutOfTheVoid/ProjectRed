#ifndef RED_TEXT_RENDERING_RAWFONTTEXTUREATLAS_H
#define RED_TEXT_RENDERING_RAWFONTTEXTUREATLAS_H

#include <stdint.h>

namespace Red
{
	
	namespace Text
	{
		
		namespace Rendering
		{
			
			class RawFontTextureAtlas
			{
			public:
				
				typedef struct
				{
					
					uint32_t OffsetX;
					uint32_t Width;
					uint32_t Height;
					
				} GlyphMetrics;
				
				typedef uint32_t BitmapFormat;
				
				static const BitmapFormat kBitmapFormat_Alpha_8 = 0;
				static const BitmapFormat kBitmapFormat_ARGB_32 = 1;
				
				RawFontTextureAtlas ( const void * BitmapData, const BitmapFormat Format, uint32_t GlyphCount, const GlyphMetrics * Metrics, char32_t MaxCodePoint, int32_t * CodePointToMetricsIndex );
				~RawFontTextureAtlas ();
				
				const void * GetBitmapData () const;
				void DisposeBitmap ();
				
				BitmapFormat GetFormat () const;
				
				bool GlyphExists ( char32_t CodePoint ) const;
				GlyphMetrics GetGlyphMetrics ( char32_t CodePoint ) const;
				
			private:
				
				const void * BitmapData;
				const BitmapFormat Format;
				
				const uint32_t GlyphCount;
				
				const GlyphMetrics * Metrics;
				
				const uint32_t MaxCodePoint;
				const int32_t * CodePointToMetricsIndex;
				
			};
			
		}
		
	}
	
}

#endif
