#include <Red/Save/Int32SaveObject.h>

Red::Save::Int32SaveObject :: Int32SaveObject ( const std :: string & Name, int32_t DefaultState ):
	RefCounted ( 0 ),
	Name ( Name ),
	State ( DefaultState )
{
}

Red::Save::Int32SaveObject :: ~Int32SaveObject ()
{
}

void Red::Save::Int32SaveObject :: SetState ( int32_t State )
{
	
	this -> State.store ( State );
	
}

int32_t Red::Save::Int32SaveObject :: GetState ()
{
	
	return State.load ();
	
}

Red::Save::ISaveObject :: SaveType Red::Save::Int32SaveObject :: GetType () const
{
	
	return ISaveObject :: kSaveType_Int32;
	
}

const std :: string & Red::Save::Int32SaveObject :: GetName () const
{
	
	return Name;
	
}