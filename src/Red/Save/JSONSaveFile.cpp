#include <Red/Save/JSONSaveFile.h>

#include <Red/Save/BooleanSaveObject.h>
#include <Red/Save/Int32SaveObject.h>
#include <Red/Save/UInt32SaveObject.h>
#include <Red/Save/Int64SaveObject.h>
#include <Red/Save/UInt64SaveObject.h>
#include <Red/Save/FloatSaveObject.h>
#include <Red/Save/DoubleSaveObject.h>
#include <Red/Save/StringSaveObject.h>
#include <Red/Save/ContainerSaveObject.h>

#include <Red/Data/JSON/Array.h>
#include <Red/Data/JSON/Object.h>
#include <Red/Data/JSON/Number.h>
#include <Red/Data/JSON/Boolean.h>
#include <Red/Data/JSON/String.h>

#include <iostream>

Red::Save::JSONSaveFile :: JSONSaveFile ( const std :: string & Name ):
	FileInstance ( Name, true ),
	SaveRoot ( NULL ),
	RootLock ()
{
}

Red::Save::JSONSaveFile :: ~JSONSaveFile ()
{
	
	if ( SaveRoot != NULL )
		SaveRoot -> Dereference ();
	
}

bool Red::Save::JSONSaveFile :: Open ( bool ForInitialReadback )
{
	
	uint32_t Status;
	
	FileInstance.Load ( ForInitialReadback, & Status );
	
	return ( Status == RAUX::JSONFile :: kStatus_Success );
	
}

void Red::Save::JSONSaveFile :: Close ()
{
	
	FileInstance.Close ();
	
}

void Red::Save::JSONSaveFile :: SetSaveObject ( ISavable * SaveRoot )
{
	
	RootLock.Lock ();
	
	if ( this -> SaveRoot == SaveRoot )
		return;
	
	if ( this -> SaveRoot != NULL )
		this -> SaveRoot -> Dereference ();
	
	this -> SaveRoot = SaveRoot;
	
	if ( this -> SaveRoot != NULL )
		this -> SaveRoot -> Reference ();
	
	RootLock.Unlock ();
	
}

bool Red::Save::JSONSaveFile :: RunSave ()
{
	
	RootLock.Lock ();
	
	if ( SaveRoot == NULL )
	{
		
		RootLock.Unlock ();
		
		return false;
		
	}
	
	SaveRoot -> NotifySaveAction ( ISavable :: kSaveAction_Save_Prepare );
	
	std :: string DummyRootName;
	
	ISaveObject * RootSaveObject = SaveRoot -> GetRootSaveObject ();
	
	Data::JSON :: IType * JSONRoot = SaveToJSON ( RootSaveObject, DummyRootName );
	
	if ( JSONRoot != NULL )
		SaveRoot -> NotifySaveAction ( ISavable :: kSaveAction_Save_Success );
	else
		SaveRoot -> NotifySaveAction ( ISavable :: kSaveAction_Save_Failure );
	
	RootLock.Unlock ();
	
	uint32_t Status;
	
	FileInstance.Encode ( JSONRoot, & Status );
	
	if ( Status != RAUX::JSONFile :: kStatus_Success )
	{
		
		if ( JSONRoot != NULL )
			delete JSONRoot;
		
		return false;
		
	}
	
	if ( JSONRoot != NULL )
		delete JSONRoot;
	
	FileInstance.Commit ( & Status );
	
	return Status == RAUX::JSONFile :: kStatus_Success;
	
}

Red::Data::JSON :: IType * Red::Save::JSONSaveFile :: SaveToJSON ( ISaveObject * Object, std :: string & ObjName )
{
	
	if ( Object == NULL )
		return NULL;
	
	switch ( Object -> GetType () )
	{
		
		case ISaveObject :: kSaveType_Boolean:
		{
			
			BooleanSaveObject * BoolObj = dynamic_cast <BooleanSaveObject *> ( Object );
			
			if ( BoolObj == NULL )
				return NULL;
			
			ObjName.assign ( BoolObj -> GetName () );
			
			return new Data::JSON :: Boolean ( BoolObj -> GetState () );
			
		}
		break;
		
		case ISaveObject :: kSaveType_Int32:
		{
			
			Int32SaveObject * IntObj = dynamic_cast <Int32SaveObject *> ( Object );
			
			if ( IntObj == NULL )
				return NULL;
			
			ObjName.assign ( std :: string ( "i32_" ) + IntObj -> GetName () );
			
			return new Data::JSON :: Number ( IntObj -> GetState () );
			
		}
		break;
		
		case ISaveObject :: kSaveType_UInt32:
		{
			
			UInt32SaveObject * UIntObj = dynamic_cast <UInt32SaveObject *> ( Object );
			
			if ( UIntObj == NULL )
				return NULL;
			
			ObjName.assign ( std :: string ( "u32_" ) + UIntObj -> GetName () );
			
			return new Data::JSON :: Number ( UIntObj -> GetState () );
			
		}
		break;
		
		case ISaveObject :: kSaveType_Int64:
		{
			
			Int64SaveObject * IntObj = dynamic_cast <Int64SaveObject *> ( Object );
			
			if ( IntObj == NULL )
				return NULL;
			
			ObjName.assign ( std :: string ( "i64_" ) + IntObj -> GetName () );
			
			return new Data::JSON :: Number ( IntObj -> GetState () );
			
		}
		break;
		
		case ISaveObject :: kSaveType_UInt64:
		{
			
			UInt64SaveObject * UIntObj = dynamic_cast <UInt64SaveObject *> ( Object );
			
			if ( UIntObj == NULL )
				return NULL;
			
			ObjName.assign ( std :: string ( "u64_" ) + UIntObj -> GetName () );
			
			return new Data::JSON :: Number ( UIntObj -> GetState () );
			
		}
		break;
		
		case ISaveObject :: kSaveType_String:
		{
			
			StringSaveObject * StrObj = dynamic_cast <StringSaveObject *> ( Object );
			
			if ( StrObj == NULL )
				return NULL;
			
			ObjName.assign ( StrObj -> GetName () );
			
			StrObj -> LockStringAccess ();
			Data::JSON :: String * NewStr = new Data::JSON :: String ( StrObj -> GetStringRef () );
			StrObj -> UnlockStringAccess ();
			
			return NewStr;
			
		}
		break;
		
		case ISaveObject :: kSaveType_Float:
		{
			
			FloatSaveObject * FloatObj = dynamic_cast <FloatSaveObject *> ( Object );
			
			if ( FloatObj == NULL )
				return NULL;
			
			ObjName.assign ( std :: string ( "f_" ) + FloatObj -> GetName () );
			
			return new Data::JSON :: Number ( FloatObj -> GetState () );
			
		}
		break;
		
		case ISaveObject :: kSaveType_Double:
		{
			
			DoubleSaveObject * FloatObj = dynamic_cast <DoubleSaveObject *> ( Object );
			
			if ( FloatObj == NULL )
				return NULL;
			
			ObjName.assign ( std :: string ( "d_" ) + FloatObj -> GetName () );
			
			return new Data::JSON :: Number ( FloatObj -> GetState () );
			
		}
		break;
		
		case ISaveObject :: kSaveType_Container:
		{
			
			ContainerSaveObject * ContObj = dynamic_cast <ContainerSaveObject *> ( Object );
			
			if ( ContObj == NULL )
				return NULL;
			
			ObjName.assign ( ContObj -> GetName () );
			
			ContObj -> LockChildren ();
			
			uint32_t ChildCount = ContObj -> GetChildCount ();
			
			Data::JSON :: Object * NewObj = new Data::JSON :: Object ();
			
			for ( uint32_t I = 0; I < ChildCount; I ++ )
			{
				
				ISaveObject * Child = ContObj -> GetChild ( I );
				
				std :: string ChildName;
				Data::JSON :: IType * ChildRoot = SaveToJSON ( Child, ChildName );
				
				if ( ChildRoot == NULL )
				{
					
					ContObj -> UnlockChildren ();
					
					return NULL;
					
				}
				
				NewObj -> Set ( ChildName, ChildRoot );
				
			}
			
			ContObj -> UnlockChildren ();
			
			return NewObj;
			
		}
		break;
		
	}
	
}

bool Red::Save::JSONSaveFile :: RunRestore ()
{
	
	RootLock.Lock ();
	
	if ( SaveRoot == NULL )
	{
		
		RootLock.Unlock ();
		
		return false;
		
	}
	
	SaveRoot -> NotifySaveAction ( ISavable :: kSaveAction_Restore_Prepare );
	
	// Todo: Red::Save translation from Red::Data::JSON format
	
	RootLock.Unlock ();
	
	return true;
	
}
