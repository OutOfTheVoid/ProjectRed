#include <Red/Save/FloatSaveObject.h>

Red::Save::FloatSaveObject :: FloatSaveObject ( const std :: string & Name, float DefaultState ):
	RefCounted ( 0 ),
	Name ( Name ),
	State ( DefaultState )
{
}

Red::Save::FloatSaveObject :: ~FloatSaveObject ()
{
}

void Red::Save::FloatSaveObject :: SetState ( float State )
{
	
	this -> State.store ( State );
	
}

float Red::Save::FloatSaveObject :: GetState ()
{
	
	return State.load ();
	
}

Red::Save::ISaveObject :: SaveType Red::Save::FloatSaveObject :: GetType ()
{
	
	return ISaveObject :: kSaveType_Float;
	
}

const std :: string & Red::Save::FloatSaveObject :: GetName ()
{
	
	return Name;
	
}