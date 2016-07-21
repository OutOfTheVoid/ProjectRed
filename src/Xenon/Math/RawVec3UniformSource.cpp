#include <Xenon/Math/RawVec3UniformSource.h>

Xenon::Math::RawVec3UniformSource :: RawVec3UniformSource ( const Vec3 * Source ):
	Source ( Source ),
	Iteration ( Iteration )
{
}

Xenon::Math::RawVec3UniformSource :: ~RawVec3UniformSource ()
{
}

const GLfloat * Xenon::Math::RawVec3UniformSource :: GetFloatVector () const
{
	
	return reinterpret_cast <const GLfloat *> ( Source );
	
}

void Xenon::Math::RawVec3UniformSource :: SetSource ( const Vec3 * Source )
{
	
	this -> Source = Source;
	
	Iteration ++;
	
}

void Xenon::Math::RawVec3UniformSource :: SetDirty ()
{
	
	Iteration ++;
	
}

int64_t Xenon::Math::RawVec3UniformSource :: GetIteration () const
{
	
	return Iteration;
	
}

