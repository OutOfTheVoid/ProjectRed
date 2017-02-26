#include <Red/Graphics/Laminar/RenderLayout.h>

Red::Graphics::Laminar::RenderLayout :: RenderLayout ( RenderMode Mode, bool ZSortRequired, const Xenon::Math :: Vec2 & SpriteArea, const Xenon::Math :: Vec2 & BaseCoordinateOffset ):
	Mode ( Mode ),
	ZSortRequired ( ZSortRequired ),
	SpriteArea ( SpriteArea ),
	BaseCoordinateOffset ( BaseCoordinateOffset )
{
}

Red::Graphics::Laminar::RenderLayout :: ~RenderLayout ()
{
}

Red::Graphics::Laminar::RenderLayout :: RenderMode Red::Graphics::Laminar::RenderLayout :: GetRenderMode () const
{
	
	return Mode;
	
}

bool Red::Graphics::Laminar::RenderLayout :: GetZSortRequired () const
{
	
	return ZSortRequired;
	
}

const Xenon::Math :: Vec2 & Red::Graphics::Laminar::RenderLayout :: GetSpriteArea () const
{
	
	return SpriteArea;
	
}

const Xenon::Math :: Vec2 & Red::Graphics::Laminar::RenderLayout :: GetBaseCoordinateOffset () const
{
	
	return BaseCoordinateOffset;
	
}
