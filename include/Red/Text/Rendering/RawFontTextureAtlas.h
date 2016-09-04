#ifndef RED_TEXT_RENDERING_RAWFONTTEXTUREATLAS_H
#define RED_TEXT_RENDERING_RAWFONTTEXTUREATLAS_H

#include <Red/Text/Rendering/Rendering.h>

#include <Red/Util/RefCounted.h>
#include <Red/Util/RCMem.h>

#include <stdint.h>

namespace Red
{
	
	namespace Text
	{
		
		namespace Rendering
		{
			
			class RawFontTextureAtlas : public Util :: RefCounted
			{
			public:
				
				typedef struct
				{
					
					uint32_t OffsetX;
					uint32_t OffsetY;
					uint32_t Width;
					uint32_t Height;
					
				} GlyphMetrics;
				
				typedef uint32_t BitmapFormat;
				
				static const BitmapFormat kBitmapFormat_Alpha_8 = 0;
				static const BitmapFormat kBitmapFormat_ARGB_32 = 1;
				
				RawFontTextureAtlas ( Util :: RCMem * BitmapMemory, uint32_t BitmapWidth, uint32_t BitmapHeight, const BitmapFormat Format, uint32_t GlyphCount, const GlyphMetrics * Metrics, char32_t MaxCodePoint, int32_t * CodePointToMetricsIndex, int32_t BitmapFontSize );
				~RawFontTextureAtlas ();
				
				const void * GetBitmapData () const;
				
				void DisposeBitmap ();
				
				uint32_t GetBitmapWidth () const;
				uint32_t GetBitmapHeight () const;
				
				BitmapFormat GetFormat () const;
				
				bool GlyphExists ( char32_t CodePoint ) const;
				GlyphMetrics GetGlyphMetrics ( char32_t CodePoint ) const;
				
				int32_t GetBitmapFontSize () const;
				
				void StartUsage ();
				void EndUsage ();
				
				uint32_t GetUsageCount ();
				
			private:
				
				Util :: RCMem * BitmapMemory;
				uint32_t BitmapWidth;
				uint32_t BitmapHeight;
				const BitmapFormat Format;
				
				const uint32_t GlyphCount;
				
				const GlyphMetrics * Metrics;
				
				const uint32_t MaxCodePoint;
				const int32_t * CodePointToMetricsIndex;
				
				int32_t BitmapFontSize;
				
				uint32_t UsageCount;
				
			};
			
		}
		
	}
	
}

#endif
