#ifndef XENON_MATH_MATRIX4X4UNIFORMSOURCE_H
#define XENON_MATH_MATRIX4X4UNIFORMSOURCE_H

#include <Xenon/Math/RawMatrix4x4UniformSource.h>

Xenon::Math::RawMatrix4x4UniformSource :: RawMatrix4x4UniformSource ( const Matrix4x4 * Source, bool Transposed ):
	Source ( Source ),
	Transposed ( Transposed ),
	Iteration ( 0 )
{
};

Xenon::Math::RawMatrix4x4UniformSource :: ~RawMatrix4x4UniformSource ()
{
};

const GLfloat * Xenon::Math::RawMatrix4x4UniformSource :: GetFloatArray () const
{
	
	return reinterpret_cast <const GLfloat *> ( Source );
	
};

void Xenon::Math::RawMatrix4x4UniformSource :: SetSource ( const Matrix4x4 * Source, bool Transposed )
{
	
	this -> Source = Source;
	this -> Transposed = Transposed;
	
	Iteration ++;
	
};

void Xenon::Math::RawMatrix4x4UniformSource :: SetDirty ()
{
	
	Iteration ++;
	
};

int64_t Xenon::Math::RawMatrix4x4UniformSource :: GetIteration () const
{
	
	return Iteration;
	
};

const bool Xenon::Math::RawMatrix4x4UniformSource :: IsTransposed () const
{
	
	return Transposed;
	
};

#endif
