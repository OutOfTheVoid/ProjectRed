#include <Xenon/Math/ConstantBoolUniformSource.h>

Xenon::Math::ConstantBoolUniformSource :: ConstantBoolUniformSource ( GLboolean Value ):
	RefCounted ( 0 ),
	Value ( Value ),
	Iteration ( 0 )
{
}

Xenon::Math::ConstantBoolUniformSource :: ~ConstantBoolUniformSource ()
{
}

GLboolean Xenon::Math::ConstantBoolUniformSource :: GetValue () const
{
	
	return Value;
	
}

void Xenon::Math::ConstantBoolUniformSource :: Write ( GLboolean Value )
{
	
	this -> Value = Value;
	
	Iteration ++;
	
}
int64_t Xenon::Math::ConstantBoolUniformSource :: GetIteration () const
{
	
	return Iteration;
	
}
