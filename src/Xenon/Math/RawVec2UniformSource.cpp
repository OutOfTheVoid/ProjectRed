#include <Xenon/Math/RawVec2UniformSource.h>

Xenon::Math::RawVec2UniformSource :: RawVec2UniformSource ( const Vec2 * Source ):
	RefCounted ( 0 ),
	Source ( Source ),
	Iteration ( 0 )
{
}

Xenon::Math::RawVec2UniformSource :: ~RawVec2UniformSource ()
{
}

const GLfloat * Xenon::Math::RawVec2UniformSource :: GetFloatVector () const
{
	
	return reinterpret_cast <const GLfloat *> ( Source );
	
}

void Xenon::Math::RawVec2UniformSource :: SetSource ( const Vec2 * Source )
{
	
	this -> Source = Source;
	
	Iteration ++;
	
}

void Xenon::Math::RawVec2UniformSource :: SetDirty ()
{
	
	Iteration ++;
	
}

int64_t Xenon::Math::RawVec2UniformSource :: GetIteration () const
{
	
	return Iteration;
	
}


