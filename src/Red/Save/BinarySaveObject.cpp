#include <Red/Save/BinarySaveObject.h>

Red::Save::BinarySaveObject :: BinarySaveObject ( const std :: string & Name, Util :: RCMem * Data, uint64_t Size ):
	RefCounted ( 0 ),
	Name ( Name ),
	Data ( Data ),
	Size ( Size ),
	DataLock ()
{
	
	if ( Data != NULL )
		Data -> Reference ();
	
}

Red::Save::BinarySaveObject :: ~BinarySaveObject ()
{
	
	if ( Data != NULL )
		Data -> Dereference ();
	
}

void Red::Save::BinarySaveObject :: LockData ()
{
	
	DataLock.Lock ();
	
}

bool Red::Save::BinarySaveObject :: TryLockData ()
{
	
	return DataLock.TryLock ();
	
}

void Red::Save::BinarySaveObject :: UnlockData ()
{
	
	DataLock.Unlock ();
	
}

void Red::Save::BinarySaveObject :: SetData ( Util :: RCMem * Data, uint32_t DataSize )
{
	
	if ( this -> Data != NULL )
		this -> Data -> Dereference ();
	
	this -> Data = Data;
	
	if ( this -> Data != NULL )
		this -> Data -> Reference ();
	
	Size = DataSize;
	
}

void Red::Save::BinarySaveObject :: SetData_AutoLock ( Util :: RCMem * Data, uint32_t DataSize )
{
	
	DataLock.Lock ();
	
	SetData ( Data, DataSize );
	
	DataLock.Unlock ();
	
}

bool Red::Save::BinarySaveObject :: SetData_AutoLock_Try ( Util :: RCMem * Data, uint32_t DataSize )
{
	
	if ( DataLock.TryLock () )
	{
		
		SetData ( Data, DataSize );
		
		DataLock.Unlock ();
		
		return true;
		
	}
	
	return false;
	
}

Red::Util :: RCMem * Red::Save::BinarySaveObject :: GetData ()
{
	
	return Data;
	
}

uint32_t Red::Save::BinarySaveObject :: GetDataSize ()
{
	
	return Size;
	
}

Red::Save::ISaveObject :: SaveType Red::Save::BinarySaveObject :: GetType () const
{
	
	return ISaveObject :: kSaveType_Binary;
	
}

const std :: string & Red::Save::BinarySaveObject :: GetName () const
{
	
	return Name;
	
}

