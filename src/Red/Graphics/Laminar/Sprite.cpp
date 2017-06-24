#include <Red/Graphics/Laminar/Sprite.h>

Red::Graphics::Laminar::Sprite :: Sprite ( I2DTextureSource * TextureSource, const RenderLayout & Layout ):
	Transform (),
	TextureSource ( TextureSource ),
	Layout ( Layout ),
	Next ( NULL ),
	Last ( NULL ),
	RenderInstance ( NULL )
{
	
	TextureSource -> Reference ();
	
}

Red::Graphics::Laminar::Sprite :: ~Sprite ()
{
	
	TextureSource -> Dereference ();
	
	if ( Next != NULL )
		Next -> Last = Last;
	
	if ( Last != NULL )
		Last -> Next = Next;
	
}

const Red::Graphics::Laminar :: RenderLayout & Red::Graphics::Laminar::Sprite :: GetRenderLayout () const
{
	
	return Layout;
	
}
Red::Graphics::Laminar :: RenderLayout & Red::Graphics::Laminar::Sprite :: GetRenderLayout ()
{
	
	return Layout;
	
}
const Xenon::Math :: Transform2D & Red::Graphics::Laminar::Sprite :: GetTransform () const
{
	
	return Transform;
	
}

Xenon::Math :: Transform2D & Red::Graphics::Laminar::Sprite :: GetTransform ()
{
	
	return Transform;
	
}

Red::Graphics::Laminar :: I2DTextureSource * Red::Graphics::Laminar::Sprite :: GetTextureSource () const
{
	
	return TextureSource;
	
}
