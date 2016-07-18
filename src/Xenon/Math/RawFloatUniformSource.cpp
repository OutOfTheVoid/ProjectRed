#include <Xenon/Math/RawFloatUniformSource.h>

Xenon::Math::RawFloatUniformSource :: RawFloatUniformSource ( GLfloat ValueInitial ):
	Value ( ValueInitial ),
	Iteration ( 0 )
{
};

Xenon::Math::RawFloatUniformSource :: ~RawFloatUniformSource ()
{
};

void Xenon::Math::RawFloatUniformSource :: SetValue ( GLfloat Value )
{
	
	this -> Value = Value;
	
	Iteration ++;
	
};

const GLfloat Xenon::Math::RawFloatUniformSource :: GetValue () const
{
	
	return Value;
	
};

int64_t Xenon::Math::RawFloatUniformSource :: GetIteration () const
{
	
	return Iteration;
	
};
