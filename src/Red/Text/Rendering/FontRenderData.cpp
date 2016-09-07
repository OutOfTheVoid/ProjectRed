#include <Red/Text/Rendering/FontRenderData.h>
#include <Red/Text/Rendering/IFontTextureAtlasFactory.h>

Red::Text::Rendering::FontRenderData :: FontRenderData ( IFontReference * FontReference, IFontLayoutSource * LayoutSource, IFontTextureAtlasFactory * AtlasFactory, const std :: u32string & CharSet, AtlasGenerationMode GenerationMode ):
	RefCounted (),
	FontReference ( FontReference ),
	LayoutSource ( LayoutSource ),
	AtlasFactory ( AtlasFactory ),
	CharSet ( CharSet ),
	GenerationMode ( GenerationMode ),
	AltasSet ( & CompareAtlasSize )
{
	
	FontReference -> Reference ();
	LayoutSource -> Reference ();
	AtlasFactory -> Reference ();
	
}

Red::Text::Rendering::FontRenderData :: ~FontRenderData ()
{
	
	for ( std :: set <RawFontTextureAtlas *, bool ( * ) ( const RawFontTextureAtlas * A, const RawFontTextureAtlas * B )> :: iterator Iter = AltasSet.begin (); Iter != AltasSet.end (); ++ Iter )
	{
		
		if ( ( * Iter ) -> GetUsageCount () == 0 )
		{
			
			RawFontTextureAtlas * ToRemove = ( * Iter );
			ToRemove -> Dereference ();
			AltasSet.erase ( ToRemove );
			
		}
		
	}
	
	FontReference -> Dereference ();
	LayoutSource -> Dereference ();
	AtlasFactory -> Dereference ();
	
}

const Red::Text::Rendering :: IFontLayoutSource * Red::Text::Rendering::FontRenderData :: GetLayoutSource () const
{
	
	return LayoutSource;
	
}

Red::Text::Rendering :: RawFontTextureAtlas * Red::Text::Rendering::FontRenderData :: CreateFontTextureAtlas ( double PixelSize, double PixelSizeThresholdScale )
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
	
	RawFontTextureAtlas * Atlas = AtlasFactory -> CreateAtlas ( PixelSize, CharSet, GenerationMode );
	
	if ( Atlas != NULL )
	{
		
		AltasSet.insert ( Atlas );
		
		Atlas -> Reference ();
		Atlas -> StartUsage ();
		
	}
	
	return Atlas;
	
}

void Red::Text::Rendering::FontRenderData :: RetireFontTextureAtlas ( Red::Text::Rendering :: RawFontTextureAtlas * Atlas )
{
	
	Atlas -> EndUsage ();
	Atlas -> Dereference ();
	
}

void Red::Text::Rendering::FontRenderData :: TrimUnusedAtlasEntries ( double PixelSizeThreshold )
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

const std :: u32string & Red::Text::Rendering::FontRenderData :: GetCharSet () const
{
	
	return CharSet;
	
}

bool Red::Text::Rendering::FontRenderData :: CompareAtlasSize ( const RawFontTextureAtlas * A, const RawFontTextureAtlas * B )
{
	
	return A -> GetBitmapFontSize () < B -> GetBitmapFontSize ();
	
}
