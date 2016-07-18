#include <Xenon/Math/RawVec4UniformSource.h>

Xenon::Math::RawVec4UniformSource :: RawVec4UniformSource ( const Vec4 * Source ):
	Source ( Source ),
	Iteration ( 0 )
{
};

Xenon::Math::RawVec4UniformSource :: ~RawVec4UniformSource ()
{
};

const GLfloat * Xenon::Math::RawVec4UniformSource :: GetFloatVector () const
{
	
	return reinterpret_cast <const GLfloat *> ( Source );
	
};

void Xenon::Math::RawVec4UniformSource :: SetSource ( const Vec4 * Source )
{
	
	this -> Source = Source;
	
	Iteration ++;
	
};

void Xenon::Math::RawVec4UniformSource :: SetDirty ()
{
	
	Iteration ++;
	
};

int64_t Xenon::Math::RawVec4UniformSource :: GetIteration () const
{
	
	return Iteration;
	
};

