#ifndef XENON_MATH_MATRIX3X3UNIFORMSOURCE_H
#define XENON_MATH_MATRIX3X3UNIFORMSOURCE_H

#include <Xenon/Math/RawMatrix3x3UniformSource.h>

Xenon::Math::RawMatrix3x3UniformSource :: RawMatrix3x3UniformSource ( const Matrix3x3 * Source, bool Transposed ):
	RefCounted ( 0 ),
	Source ( Source ),
	Transposed ( Transposed ),
	Iteration ( 0 )
{
}

Xenon::Math::RawMatrix3x3UniformSource :: ~RawMatrix3x3UniformSource ()
{
}

const GLfloat * Xenon::Math::RawMatrix3x3UniformSource :: GetFloatArray () const
{
	
	return reinterpret_cast <const GLfloat *> ( Source );
	
}

void Xenon::Math::RawMatrix3x3UniformSource :: SetSource ( const Matrix3x3 * Source, bool Transposed )
{
	
	this -> Source = Source;
	this -> Transposed = Transposed;
	
	Iteration ++;
	
}

void Xenon::Math::RawMatrix3x3UniformSource :: SetDirty ()
{
	
	Iteration ++;
	
}

int64_t Xenon::Math::RawMatrix3x3UniformSource :: GetIteration () const
{
	
	return Iteration;
	
}

bool Xenon::Math::RawMatrix3x3UniformSource :: IsTransposed () const
{
	
	return Transposed;
	
}

#endif
