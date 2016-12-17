#include <Red/Data/JSON/String.h>

Red::Data::JSON::String :: String ( const std :: string & Value ):
	RefCounted ( 0 ),
	Value ( Value )
{	
}

Red::Data::JSON::String :: ~String ()
{
}

Red::Data::JSON::IType :: DataType Red::Data::JSON::String :: GetType () const
{
	
	return kDataType_String;
	
}

void Red::Data::JSON::String :: Get ( std :: string & OutString )
{
	
	OutString.assign ( Value );
	
}

void Red::Data::JSON::String :: Set ( const std :: string & Value )
{
	
	this -> Value.assign ( Value );
	
}
