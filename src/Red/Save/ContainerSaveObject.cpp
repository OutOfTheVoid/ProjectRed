#include <Red/Save/ContainerSaveObject.h>

Red::Save::ContainerSaveObject :: ContainerSaveObject ( const std :: string & Name ):
	RefCounted ( 0 ),
	Name ( Name ),
	ChildLock (),
	Children ()
{
}

Red::Save::ContainerSaveObject :: ~ContainerSaveObject ()
{
	
	for ( uint32_t I = 0; I < Children.size (); I ++ )
		Children [ I ] -> Dereference ();
	
}

Red::Save::ISaveObject :: SaveType Red::Save::ContainerSaveObject :: GetType () const
{
	
	return kSaveType_Container;
	
}

const std :: string & Red::Save::ContainerSaveObject :: GetName () const
{
	
	return Name;
	
}

void Red::Save::ContainerSaveObject :: LockChildren ()
{
	
	ChildLock.Lock ();
	
}

bool Red::Save::ContainerSaveObject :: TryLockChildren ()
{
	
	return ChildLock.TryLock ();
	
}

void Red::Save::ContainerSaveObject :: UnlockChildren ()
{
	
	ChildLock.Unlock ();
	
}

void Red::Save::ContainerSaveObject :: AddChild ( ISaveObject * Object )
{
	
	if ( Object == NULL )
		return;
	
	Object -> Reference ();
	
	Children.push_back ( Object );
	
}

void Red::Save::ContainerSaveObject :: RemoveChild ( ISaveObject * Object )
{
	
	if ( Object == NULL )
		return;
	
	uint32_t ChildCount = Children.size ();
	
	for ( uint32_t I = 0; I < ChildCount; I ++ )
	{
		
		if ( Children [ I ] == Object )
		{
			
			Children.erase ( Children.begin () + I );
			
			Object -> Dereference ();
			
		}
			
	}
	
}

void Red::Save::ContainerSaveObject :: AddChild_AutoLock ( ISaveObject * Object )
{
	
	if ( Object == NULL )
		return;
	
	ChildLock.Lock ();
	
	AddChild ( Object );
	
	ChildLock.Unlock ();
	
}

bool Red::Save::ContainerSaveObject :: AddChild_AutoLock_Try ( ISaveObject * Object )
{
	
	if ( Object == NULL )
		return false;
	
	if ( ChildLock.TryLock () )
	{
		
		AddChild ( Object );
		
		ChildLock.Unlock ();
		
		return true;
		
	}
	
	return false;
	
}

void Red::Save::ContainerSaveObject :: RemoveChild_AutoLock ( ISaveObject * Object )
{
	
	if ( Object == NULL )
		return;
	
	ChildLock.Lock ();
	
	RemoveChild ( Object );
	
	ChildLock.Unlock ();
	
}

uint32_t Red::Save::ContainerSaveObject :: GetChildCount ()
{
	
	return Children.size ();
	
}

Red::Save :: ISaveObject * Red::Save::ContainerSaveObject :: GetChild ( uint32_t Index )
{
	
	if ( Index < Children.size () )
		return Children [ Index ];
	
	return NULL;
	
}

Red::Save :: ISaveObject * Red::Save::ContainerSaveObject :: FindChildWithName ( const std :: string & ChildName )
{
	
	uint32_t ChildCount = Children.size ();
	
	for ( uint32_t I = 0; I < ChildCount; I ++ )
	{
		
		if ( Children [ I ] -> GetName () == ChildName )
			return Children [ I ];
		
	}
	
	return NULL;
	
}
