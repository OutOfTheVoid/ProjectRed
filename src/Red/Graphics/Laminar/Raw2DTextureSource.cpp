#include <Red/Graphics/Laminar/Raw2DTextureSource.h>

Red::Graphics::Laminar::Raw2DTextureSource :: Raw2DTextureSource ( Xenon::GPU :: Texture2D * Tex, const Xenon::Math :: Matrix3x3 & Transform ):
	Tex ( Tex ),
	Transform ( Transform )
{
	
	Tex -> Reference ();
	
}

Red::Graphics::Laminar::Raw2DTextureSource :: ~Raw2DTextureSource ()
{
	
	if ( Tex != NULL )
	{
		
		Tex -> Dereference ();
		
		Tex = NULL;
		
	}
	
}

Xenon::GPU :: ITexture * Red::Graphics::Laminar::Raw2DTextureSource :: GetOutputTexture ()
{
	
	return Tex;
	
}

Xenon::Math :: Matrix3x3 * Red::Graphics::Laminar::Raw2DTextureSource :: GetOutputTextureTransform ()
{
	
	return & Transform;
	
}
