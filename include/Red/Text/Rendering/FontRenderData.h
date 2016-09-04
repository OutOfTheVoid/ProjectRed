#ifndef RED_TEXT_RENDERING_FONTRENDERDATA_H
#define RED_TEXT_RENDERING_FONTRENDERDATA_H

#include <Red/Text/Rendering/Rendering.h>

#include <Red/Text/Rendering/IFontLayoutSource.h>
#include <Red/Text/Rendering/IFontReference.h>
#include <Red/Text/Rendering/IFontTextureAtlasFactory.h>
#include <Red/Text/Rendering/RawFontTextureAtlas.h>

#include <Red/Util/RefCounted.h>

#include <string>
#include <set>

namespace Red
{
	
	namespace Text
	{
		
		namespace Rendering
		{
			
			class FontRenderingData : public Util :: RefCounted
			{
			public:
				
				FontRenderingData ( IFontReference * FontReference, IFontLayoutSource * LayoutSource, IFontTextureAtlasFactory * AtlasFactory, const std :: u32string & CharSet );
				~FontRenderingData ();
				
				const IFontLayoutSource * GetLayoutSource () const;
				const IFontTextureAtlasFactory * GetFontTextureAtlasFactory () const;
				
				RawFontTextureAtlas * CreateFontTextureAtlas ( double PixelSize, double PixelSizeThresholdScale = 2.0 );
				void RetireFontTextureAtlas ( RawFontTextureAtlas * Atlas );
				
				void TrimUnusedAtlasEntries ( double PixelSizeThreshold = 0.0 );
				
				const std :: u32string & GetCharSet () const;
				
			private:
				
				static bool CompareAtlasSize ( const RawFontTextureAtlas * A, const RawFontTextureAtlas * B );
				
				IFontReference * FontReference;
				IFontLayoutSource * LayoutSource;
				IFontTextureAtlasFactory * AtlasFactory;
				
				std :: u32string CharSet;
				
				std :: set <RawFontTextureAtlas *, bool ( * ) ( const RawFontTextureAtlas * A, const RawFontTextureAtlas * B )> AltasSet;
				
			};
			
		}
		
	}
	
}

#endif
