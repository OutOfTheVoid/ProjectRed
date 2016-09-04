#include <Xenon/Math/ConstantIntUniformSource.h>

Xenon::Math::ConstantIntUniformSource :: ConstantIntUniformSource ( GLint Value ):
	RefCounted ( 0 ),
	Value ( Value ),
	Iteration ( 0 )
{
}

Xenon::Math::ConstantIntUniformSource :: ~ConstantIntUniformSource ()
{
}

GLint Xenon::Math::ConstantIntUniformSource :: GetValue () const
{
	
	return Value;
	
}

void Xenon::Math::ConstantIntUniformSource :: Write ( GLint Value )
{
	
	this -> Value = Value;
	
	Iteration ++;
	
}

int64_t Xenon::Math::ConstantIntUniformSource :: GetIteration () const
{
	
	return Iteration;
	
}
