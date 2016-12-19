#include <Red/Save/ContainerSaveObject.h>

#include <Red/Save/BooleanSaveObject.h>
#include <Red/Save/DoubleSaveObject.h>
#include <Red/Save/FloatSaveObject.h>
#include <Red/Save/Int32SaveObject.h>
#include <Red/Save/Int64SaveObject.h>
#include <Red/Save/UInt32SaveObject.h>
#include <Red/Save/UInt64SaveObject.h>
#include <Red/Save/StringSaveObject.h>
#include <Red/Save/BinarySaveObject.h>

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

Red::Save :: ContainerSaveObject * Red::Save::ContainerSaveObject :: FindOrCreateContainerChild ( const std :: string & ChildName )
{
	
	ContainerSaveObject * Container = dynamic_cast <ContainerSaveObject *> ( FindChildWithName ( ChildName ) );
	
	if ( Container != NULL )
		return Container;
	
	Container = new ContainerSaveObject ( ChildName );
	AddChild ( Container );
	
	return Container;
	
}

Red::Save :: BooleanSaveObject * Red::Save::ContainerSaveObject :: FindOrCreateBooleanChild ( const std :: string & ChildName, bool DefaultValue )
{
	
	BooleanSaveObject * Bool = dynamic_cast <BooleanSaveObject *> ( FindChildWithName ( ChildName ) );
	
	if ( Bool != NULL )
		return Bool;
	
	Bool = new BooleanSaveObject ( ChildName, DefaultValue );
	AddChild ( Bool );
	
	return Bool;
	
}

Red::Save :: BinarySaveObject * Red::Save::ContainerSaveObject :: FindOrCreateBinaryChild ( const std :: string & ChildName, Util :: RCMem * DefaultData, uint32_t DefaultDataSize )
{
	
	BinarySaveObject * Bin = dynamic_cast <BinarySaveObject *> ( FindChildWithName ( ChildName ) );
	
	if ( Bin != NULL )
		return Bin;
	
	Bin = new BinarySaveObject ( ChildName, DefaultData, DefaultDataSize );
	AddChild ( Bin );
	
	return Bin;
	
}

Red::Save :: DoubleSaveObject * Red::Save::ContainerSaveObject :: FindOrCreateDoubleChild ( const std :: string & ChildName, double DefaultValue )
{
	
	DoubleSaveObject * Double = dynamic_cast <DoubleSaveObject *> ( FindChildWithName ( ChildName ) );
	
	if ( Double != NULL )
		return Double;
	
	Double = new DoubleSaveObject ( ChildName, DefaultValue );
	AddChild ( Double );
	
	return Double;
	
}

Red::Save :: FloatSaveObject * Red::Save::ContainerSaveObject :: FindOrCreateFloatChild ( const std :: string & ChildName, float DefaultValue )
{
	
	FloatSaveObject * Float = dynamic_cast <FloatSaveObject *> ( FindChildWithName ( ChildName ) );
	
	if ( Float != NULL )
		return Float;
	
	Float = new FloatSaveObject ( ChildName, DefaultValue );
	AddChild ( Float );
	
	return Float;
	
}

Red::Save :: Int32SaveObject * Red::Save::ContainerSaveObject :: FindOrCreateInt32Child ( const std :: string & ChildName, int32_t DefaultValue )
{
	
	Int32SaveObject * Int = dynamic_cast <Int32SaveObject *> ( FindChildWithName ( ChildName ) );
	
	if ( Int != NULL )
		return Int;
	
	Int = new Int32SaveObject ( ChildName, DefaultValue );
	AddChild ( Int );
	
	return Int;
	
}

Red::Save :: Int64SaveObject * Red::Save::ContainerSaveObject :: FindOrCreateInt64Child ( const std :: string & ChildName, int64_t DefaultValue )
{
	
	Int64SaveObject * Int = dynamic_cast <Int64SaveObject *> ( FindChildWithName ( ChildName ) );
	
	if ( Int != NULL )
		return Int;
	
	Int = new Int64SaveObject ( ChildName, DefaultValue );
	AddChild ( Int );
	
	return Int;
	
}

Red::Save :: UInt32SaveObject * Red::Save::ContainerSaveObject :: FindOrCreateUInt32Child ( const std :: string & ChildName, uint32_t DefaultValue )
{
	
	UInt32SaveObject * UInt = dynamic_cast <UInt32SaveObject *> ( FindChildWithName ( ChildName ) );
	
	if ( UInt != NULL )
		return UInt;
	
	UInt = new UInt32SaveObject ( ChildName, DefaultValue );
	AddChild ( UInt );
	
	return UInt;
	
}

Red::Save :: UInt64SaveObject * Red::Save::ContainerSaveObject :: FindOrCreateUInt64Child ( const std :: string & ChildName, uint64_t DefaultValue )
{
	
	UInt64SaveObject * UInt = dynamic_cast <UInt64SaveObject *> ( FindChildWithName ( ChildName ) );
	
	if ( UInt != NULL )
		return UInt;
	
	UInt = new UInt64SaveObject ( ChildName, DefaultValue );
	AddChild ( UInt );
	
	return UInt;
	
}

Red::Save :: StringSaveObject * Red::Save::ContainerSaveObject :: FindOrCreateStringChild ( const std :: string & ChildName, const std :: string & DefaultValue )
{
	
	StringSaveObject * StringObj = dynamic_cast <StringSaveObject *> ( FindChildWithName ( ChildName ) );
	
	if ( StringObj != NULL )
		return StringObj;
	
	StringObj = new StringSaveObject ( ChildName, DefaultValue );
	AddChild ( StringObj );
	
	return StringObj;
	
}

Red::Save :: BooleanSaveObject * Red::Save::ContainerSaveObject :: SetOrCreateBooleanChild_AutoLock ( const std :: string & ChildName, bool Value )
{
	
	LockChildren ();
	
	BooleanSaveObject * Child = FindOrCreateBooleanChild ( ChildName, Value );
	Child -> SetState ( Value );
	
	UnlockChildren ();
	
	return Child;
	
}

Red::Save :: BinarySaveObject * Red::Save::ContainerSaveObject :: SetOrCreateBinaryChild_AutoLock ( const std :: string & ChildName, Util :: RCMem * Data, uint32_t DataSize )
{
	
	LockChildren ();
	
	BinarySaveObject * Child = FindOrCreateBinaryChild ( ChildName, Data, DataSize );
	
	if ( ( Children.size () != 0 ) && ( Children [ Children.size () - 1 ] == Child ) )
		Child -> SetData_AutoLock ( Data, DataSize );
	
	UnlockChildren ();
	
	return Child;
	
}

Red::Save :: DoubleSaveObject * Red::Save::ContainerSaveObject :: SetOrCreateDoubleChild_AutoLock ( const std :: string & ChildName, double Value )
{
	
	LockChildren ();
	
	DoubleSaveObject * Child = FindOrCreateDoubleChild ( ChildName, Value );
	Child -> SetState ( Value );
	
	UnlockChildren ();
	
	return Child;
	
}

Red::Save :: FloatSaveObject * Red::Save::ContainerSaveObject :: SetOrCreateFloatChild_AutoLock ( const std :: string & ChildName, float Value )
{
	
	LockChildren ();
	
	FloatSaveObject * Child = FindOrCreateFloatChild ( ChildName, Value );
	Child -> SetState ( Value );
	
	UnlockChildren ();
	
	return Child;
	
}

Red::Save :: Int32SaveObject * Red::Save::ContainerSaveObject :: SetOrCreateInt32Child_AutoLock ( const std :: string & ChildName, int32_t Value )
{
	
	LockChildren ();
	
	Int32SaveObject * Child = FindOrCreateInt32Child ( ChildName, Value );
	Child -> SetState ( Value );
	
	UnlockChildren ();
	
	return Child;
	
}

Red::Save :: Int64SaveObject * Red::Save::ContainerSaveObject :: SetOrCreateInt64Child_AutoLock ( const std :: string & ChildName, int64_t Value )
{
	
	LockChildren ();
	
	Int64SaveObject * Child = FindOrCreateInt64Child ( ChildName, Value );
	Child -> SetState ( Value );
	
	UnlockChildren ();
	
	return Child;
	
}

Red::Save :: UInt32SaveObject * Red::Save::ContainerSaveObject :: SetOrCreateUInt32Child_AutoLock ( const std :: string & ChildName, uint32_t Value )
{
	
	LockChildren ();
	
	UInt32SaveObject * Child = FindOrCreateUInt32Child ( ChildName, Value );
	Child -> SetState ( Value );
	
	UnlockChildren ();
	
	return Child;
	
}

Red::Save :: UInt64SaveObject * Red::Save::ContainerSaveObject :: SetOrCreateUInt64Child_AutoLock ( const std :: string & ChildName, uint64_t Value )
{
	
	LockChildren ();
	
	UInt64SaveObject * Child = FindOrCreateUInt64Child ( ChildName, Value );
	Child -> SetState ( Value );
	
	UnlockChildren ();
	
	return Child;
	
}

Red::Save :: StringSaveObject * Red::Save::ContainerSaveObject :: SetOrCreateStringChild_AutoLock ( const std :: string & ChildName, const std :: string & Value )
{
	
	LockChildren ();
	
	StringSaveObject * Child = FindOrCreateStringChild ( ChildName, Value );
	
	if ( ( Children.size () != 0 ) && ( Children [ Children.size () - 1 ] == Child ) )
		Child -> SetString_AutoLock ( Value );
	
	UnlockChildren ();
	
	return Child;
	
}
