#include <Red/Save/UInt32SaveObject.h>

Red::Save::UInt32SaveObject :: UInt32SaveObject ( const std :: string & Name, uint32_t DefaultState ):
	RefCounted ( 0 ),
	Name ( Name ),
	State ( DefaultState )
{
}

Red::Save::UInt32SaveObject :: ~UInt32SaveObject ()
{
}

void Red::Save::UInt32SaveObject :: SetState ( uint32_t State )
{
	
	this -> State.store ( State );
	
}

uint32_t Red::Save::UInt32SaveObject :: GetState ()
{
	
	return State.load ();
	
}

Red::Save::ISaveObject :: SaveType Red::Save::UInt32SaveObject :: GetType ()
{
	
	return ISaveObject :: kSaveType_UInt32;
	
}

const std :: string & Red::Save::UInt32SaveObject :: GetName ()
{
	
	return Name;
	
}