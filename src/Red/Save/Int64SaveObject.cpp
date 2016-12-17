#include <Red/Save/Int64SaveObject.h>

Red::Save::Int64SaveObject :: Int64SaveObject ( const std :: string & Name, int64_t DefaultState ):
	RefCounted ( 0 ),
	Name ( Name ),
	State ( DefaultState )
{
}

Red::Save::Int64SaveObject :: ~Int64SaveObject ()
{
}

void Red::Save::Int64SaveObject :: SetState ( int64_t State )
{
	
	this -> State.store ( State );
	
}

int64_t Red::Save::Int64SaveObject :: GetState ()
{
	
	return State.load ();
	
}

Red::Save::ISaveObject :: SaveType Red::Save::Int64SaveObject :: GetType ()
{
	
	return ISaveObject :: kSaveType_Int64;
	
}

const std :: string & Red::Save::Int64SaveObject :: GetName ()
{
	
	return Name;
	
}