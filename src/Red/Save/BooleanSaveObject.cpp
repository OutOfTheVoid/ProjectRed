#include <Red/Save/BooleanSaveObject.h>

Red::Save::BooleanSaveObject :: BooleanSaveObject ( const std :: string & Name, bool DefaultState ):
	RefCounted ( 0 ),
	Name ( Name ),
	State ( DefaultState )
{
}

Red::Save::BooleanSaveObject :: ~BooleanSaveObject ()
{
}

void Red::Save::BooleanSaveObject :: SetState ( bool State )
{
	
	this -> State.store ( State );
	
}

bool Red::Save::BooleanSaveObject :: GetState ()
{
	
	return State.load ();
	
}

Red::Save::ISaveObject :: SaveType Red::Save::BooleanSaveObject :: GetType ()
{
	
	return ISaveObject :: kSaveType_Boolean;
	
}

const std :: string & Red::Save::BooleanSaveObject :: GetName ()
{
	
	return Name;
	
}