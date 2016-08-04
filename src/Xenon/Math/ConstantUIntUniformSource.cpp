#include <Xenon/Math/ConstantUIntUniformSource.h>

Xenon::Math::ConstantUIntUniformSource :: ConstantUIntUniformSource ( GLuint Value ):
	RefCounted ( 0 ),
	Value ( Value ),
	Iteration ( 0 )
{
}

Xenon::Math::ConstantUIntUniformSource :: ~ConstantUIntUniformSource ()
{
}

GLuint Xenon::Math::ConstantUIntUniformSource :: GetValue () const
{
	
	return Value;
	
}

void Xenon::Math::ConstantUIntUniformSource :: Write ( GLuint Value )
{
	
	this -> Value = Value;
	
	Iteration ++;
	
}

int64_t Xenon::Math::ConstantUIntUniformSource :: GetIteration () const
{
	
	return Iteration;
	
}
