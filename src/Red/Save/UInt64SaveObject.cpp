#include <Red/Save/UInt64SaveObject.h>

Red::Save::UInt64SaveObject :: UInt64SaveObject ( const std :: string & Name, uint64_t DefaultState ):
	RefCounted ( 0 ),
	Name ( Name ),
	State ( DefaultState )
{
}

Red::Save::UInt64SaveObject :: ~UInt64SaveObject ()
{
}

void Red::Save::UInt64SaveObject :: SetState ( uint64_t State )
{
	
	this -> State.store ( State );
	
}

uint64_t Red::Save::UInt64SaveObject :: GetState ()
{
	
	return State.load ();
	
}

Red::Save::ISaveObject :: SaveType Red::Save::UInt64SaveObject :: GetType ()
{
	
	return ISaveObject :: kSaveType_UInt64;
	
}

const std :: string & Red::Save::UInt64SaveObject :: GetName ()
{
	
	return Name;
	
}