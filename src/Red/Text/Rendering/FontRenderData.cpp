#include <Red/Text/Rendering/FontRenderData.h>

Red::Text::Rendering::FontRenderingData :: FontRenderingData ( IFontReference * FontReference, IFontLayoutSource * LayoutSource, IFontTextureAtlasFactory * AtlasFactory, const std :: u32string & CharSet ):
	RefCounted (),
	FontReference ( FontReference ),
	LayoutSource ( LayoutSource ),
	AtlasFactory ( AtlasFactory ),
	CharSet ( CharSet ),
	AltasSet ( & CompareAtlasSize )
{
	
	FontReference -> Reference ();
	LayoutSource -> Reference ();
	
}

Red::Text::Rendering::FontRenderingData :: ~FontRenderingData ()
{
	
	FontReference -> Dereference ();
	LayoutSource -> Dereference ();
	
}

const Red::Text::Rendering :: IFontLayoutSource * Red::Text::Rendering::FontRenderingData :: GetLayoutSource () const
{
	
	return LayoutSource;
	
}

Red::Text::Rendering :: RawFontTextureAtlas * Red::Text::Rendering::FontRenderingData :: CreateFontTextureAtlas ( double PixelSize, double PixelSizeThresholdScale )
{
	
	for ( std :: set <RawFontTextureAtlas *, bool ( * ) ( const RawFontTextureAtlas * A, const RawFontTextureAtlas * B )> :: iterator Iter = AltasSet.begin (); Iter != AltasSet.end (); ++ Iter )
	{
		
		double CantidateSize = ( * Iter ) -> GetBitmapFontSize ();
		
		if ( CantidateSize > PixelSize )
		{
			
			if ( CantidateSize / PixelSizeThresholdScale >= PixelSize )
			{
				
				( * Iter ) -> StartUsage ();
				return ( * Iter );
				
			}
			else
				break;
			
		}
		
	}
	
	RawFontTextureAtlas * Atlas = AtlasFactory -> CreateAtlas ( PixelSize, CharSet );
	
	if ( Atlas != NULL )
	{
		
		AltasSet.insert ( Atlas );
		
		Atlas -> Reference ();
		Atlas -> StartUsage ();
		
	}
	
	return Atlas;
	
}

void Red::Text::Rendering::FontRenderingData :: TrimUnusedAtlasEntries ( double PixelSizeThreshold )
{
	
	for ( std :: set <RawFontTextureAtlas *, bool ( * ) ( const RawFontTextureAtlas * A, const RawFontTextureAtlas * B )> :: iterator Iter = AltasSet.begin (); Iter != AltasSet.end (); ++ Iter )
	{
		
		double CantidateSize = ( * Iter ) -> GetBitmapFontSize ();
		
		if ( CantidateSize >= PixelSizeThreshold )
		{
			
			if ( ( * Iter ) -> GetUsageCount () == 0 )
			{
				
				RawFontTextureAtlas * ToRemove = ( * Iter );
				AltasSet.erase ( ToRemove );
				
				ToRemove -> Dereference ();
				
			}
			
		}
		
	}
	
}

const std :: u32string & Red::Text::Rendering::FontRenderingData :: GetCharSet () const
{
	
	return CharSet;
	
}

bool Red::Text::Rendering::FontRenderingData :: CompareAtlasSize ( const RawFontTextureAtlas * A, const RawFontTextureAtlas * B )
{
	
	return A -> GetBitmapFontSize () < B -> GetBitmapFontSize ();
	
}
