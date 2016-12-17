#include <Red/Data/JSON/Array.h>

#include <stddef.h>

Red::Data::JSON::Array :: Array ():
	RefCounted ( 0 ),
	Items ()
{
}

Red::Data::JSON::Array :: ~Array ()
{
	
	for ( uint32_t I = 0; I < Items.size (); I ++ )
	{
		
		if ( Items [ I ] != NULL ) 
			Items [ I ] -> Dereference ();
		
	}
	
}

Red::Data::JSON::IType :: DataType Red::Data::JSON::Array :: GetType () const
{
	
	return kDataType_Array;
	
}

uint32_t Red::Data::JSON::Array :: GetItemCount ()
{
	
	return Items.size ();
	
}

Red::Data::JSON :: IType * Red::Data::JSON::Array :: GetItem ( uint32_t I )
{
	
	if ( I >= Items.size () )
		return NULL;
	
	return Items [ I ];
	
}

void Red::Data::JSON::Array :: AddItem ( IType * Item )
{
	
	if ( Item != NULL )
		Item -> Reference ();
	
	Items.push_back ( Item );
	
}

void Red::Data::JSON::Array :: RemoveItem ( uint32_t I )
{
	
	if ( I >= Items.size () )
		return;
	
	if ( Items [ I ] != NULL )
		Items [ I ] -> Dereference ();
	
	Items.erase ( Items.begin () + I );
	
}
