#include <Red/Data/JSON/Boolean.h>

Red::Data::JSON::Boolean :: Boolean ( bool Value ):
	RefCounted ( 0 ),
	Value ( Value )
{	
}

Red::Data::JSON::Boolean :: ~Boolean ()
{
}

Red::Data::JSON::IType :: DataType Red::Data::JSON::Boolean :: GetType () const
{
	
	return kDataType_Boolean;
	
}

bool Red::Data::JSON::Boolean :: Get ()
{
	
	return Value;
	
}

void Red::Data::JSON::Boolean :: Set ( bool Value )
{
	
	this -> Value = Value;
	
}
