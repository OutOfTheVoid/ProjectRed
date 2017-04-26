#include <Red/Graphics/Laminar/RenderLayout.h>

Red::Graphics::Laminar::RenderLayout :: RenderLayout ( RenderMode Mode, const Xenon::Math :: Vec2 & SpriteArea, const Xenon::Math :: Vec2 & BaseCoordinateOffset ):
	Mode ( Mode ),
	SpriteArea ( SpriteArea ),
	BaseCoordinateOffset ( BaseCoordinateOffset )
{
}

Red::Graphics::Laminar::RenderLayout :: RenderLayout ( const RenderLayout & Layout ):
	Mode ( Layout.Mode ),
	SpriteArea ( Layout.SpriteArea ),
	BaseCoordinateOffset ( Layout.BaseCoordinateOffset )
{
}

Red::Graphics::Laminar::RenderLayout :: ~RenderLayout ()
{
}

Red::Graphics::Laminar :: RenderMode Red::Graphics::Laminar::RenderLayout :: GetRenderMode () const
{
	
	return Mode;
	
}

const Xenon::Math :: Vec2 & Red::Graphics::Laminar::RenderLayout :: GetSpriteArea () const
{
	
	return SpriteArea;
	
}

const Xenon::Math :: Vec2 & Red::Graphics::Laminar::RenderLayout :: GetBaseCoordinateOffset () const
{
	
	return BaseCoordinateOffset;
	
}
