#include <Red/Data/JSON/Number.h>

Red::Data::JSON::Number :: Number ( double Value ):
	RefCounted ( 0 ),
	Value ( Value )
{	
}

Red::Data::JSON::Number :: ~Number ()
{
}

Red::Data::JSON::IType :: DataType Red::Data::JSON::Number :: GetType () const
{
	
	return kDataType_Number;
	
}

double Red::Data::JSON::Number :: Get ()
{
	
	return Value;
	
}

void Red::Data::JSON::Number :: Set ( double Value )
{
	
	this -> Value = Value;
	
}
