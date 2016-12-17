#include <Red/Data/JSON/Object.h>

Red::Data::JSON::Object :: Object ():
	RefCounted ( 0 ),
	ValueMap ()
{
}

Red::Data::JSON::Object :: ~Object ()
{
	
	for ( std::map <std :: string, IType *> :: const_iterator MapIt = ValueMap.cbegin (); MapIt != ValueMap.end (); MapIt ++ )
		if ( MapIt -> second != NULL )
			MapIt -> second -> Dereference ();
	
}

Red::Data::JSON::IType :: DataType Red::Data::JSON::Object :: GetType () const
{
	
	return kDataType_Object;
	
}

void Red::Data::JSON::Object :: Set ( const std :: string & ValueName, IType * Value )
{
	
	IType * OldValue = ValueMap [ ValueName ];
	
	if ( OldValue == Value )
		return;
	
	if ( OldValue != NULL )
		OldValue -> Dereference ();
	
	if ( Value != NULL )
		Value -> Reference ();
	
	ValueMap [ ValueName ] = Value;
	
}

Red::Data::JSON :: IType * Red::Data::JSON::Object :: Get ( const std :: string & ValueName )
{
	
	std :: map <std :: string, IType *> :: iterator It = ValueMap.find ( ValueName );
	
	if ( It == ValueMap.end () )
		return NULL;
	
	return It -> second;
	
}

void Red::Data::JSON::Object :: Clear ( const std :: string & ValueName )
{
	
	IType * Value = ValueMap [ ValueName ];
	
	if ( Value != NULL )
		Value -> Dereference ();
	
	ValueMap.erase ( ValueName );
	
}

bool Red::Data::JSON::Object :: Exists ( const std :: string & ValueName )
{
	
	if ( ValueMap.find ( ValueName ) != ValueMap.end () )
		return true;
	
}

void Red::Data::JSON::Object :: GetKeyByIndex ( uint32_t Index, std :: string & KeyOut )
{
	
	std :: map <std :: string, IType *> :: iterator It = ValueMap.begin ();
	std :: advance ( It, Index );
	
	if ( It == ValueMap.end () )
		return;
	
	KeyOut.assign ( It -> first );
	
}

uint32_t Red::Data::JSON::Object :: GetKeyCount ()
{
	
	return ValueMap.size ();
	
}
