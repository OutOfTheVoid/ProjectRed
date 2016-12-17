#include <Red/Save/DoubleSaveObject.h>

Red::Save::DoubleSaveObject :: DoubleSaveObject ( const std :: string & Name, double DefaultState ):
	RefCounted ( 0 ),
	Name ( Name ),
	State ( DefaultState )
{
}

Red::Save::DoubleSaveObject :: ~DoubleSaveObject ()
{
}

void Red::Save::DoubleSaveObject :: SetState ( double State )
{
	
	this -> State.store ( State );
	
}

double Red::Save::DoubleSaveObject :: GetState ()
{
	
	return State.load ();
	
}

Red::Save::ISaveObject :: SaveType Red::Save::DoubleSaveObject :: GetType ()
{
	
	return ISaveObject :: kSaveType_Double;
	
}

const std :: string & Red::Save::DoubleSaveObject :: GetName ()
{
	
	return Name;
	
}