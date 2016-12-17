#include <Red/Save/StringSaveObject.h>

Red::Save::StringSaveObject :: StringSaveObject ( const std :: string & Name, const std :: string & DefaultValue ):
	Name ( Name ),
	AccessLock (),
	Value ( DefaultValue )
{
}
	
Red::Save::StringSaveObject :: ~StringSaveObject ()
{
}

void Red::Save::StringSaveObject :: LockStringAccess ()
{
	
	AccessLock.Lock ();
	
}

bool Red::Save::StringSaveObject :: TryLockStringAccess ()
{
	
	return AccessLock.TryLock ();
	
}

void Red::Save::StringSaveObject :: UnlockStringAccess ()
{
	
	AccessLock.Unlock ();
	
}

std :: string & Red::Save::StringSaveObject :: GetStringRef ()
{
	
	return Value;
	
}

void Red::Save::StringSaveObject :: SetString_AutoLock ( const std :: string & Value )
{
	
	AccessLock.Lock ();
	
	this -> Value.assign ( Value );
	
	AccessLock.Unlock ();
	
}

bool Red::Save::StringSaveObject :: SetString_AutoLock_Try ( const std :: string & Value )
{
	
	if ( AccessLock.TryLock () )
	{
		
		this -> Value.assign ( Value );
		
		AccessLock.Unlock ();
		
		return true;
		
	}
	
	return false;
	
}
void Red::Save::StringSaveObject :: GetString_AutoLock ( std :: string & ValueOut )
{
	
	AccessLock.Lock ();
	
	ValueOut.assign ( Value );
	
	AccessLock.Unlock ();
	
}

bool Red::Save::StringSaveObject :: SetString_AutoLock_Try ( std :: string & ValueOut )
{
	
	if ( AccessLock.TryLock () )
	{
		
		ValueOut.assign ( Value );
		
		AccessLock.Unlock ();
		
		return true;
		
	}
	
	return false;
	
}

Red::Save::ISaveObject :: SaveType Red::Save::StringSaveObject :: GetType () const
{
	
	return kSaveType_String;
	
}

const std :: string & Red::Save::StringSaveObject :: GetName () const
{
	
	return Name;
	
}

