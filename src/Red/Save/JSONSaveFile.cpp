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
#include <Red/Save/BinarySaveObject.h>

#include <Red/Data/JSON/Array.h>
#include <Red/Data/JSON/Object.h>
#include <Red/Data/JSON/Number.h>
#include <Red/Data/JSON/Boolean.h>
#include <Red/Data/JSON/String.h>

#include <string.h>

#include <stdlib.h>

#include <iostream>

Red::Save::JSONSaveFile :: JSONSaveFile ( const std :: string & Name ):
	FileInstance ( Name, true ),
	SaveRoot ( NULL ),
	RootLock (),
	B64Encoder (),
	B64Decoder ()
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

bool Red::Save::JSONSaveFile :: RunRestore ()
{
	
	std :: cout << "A" << std :: endl;
	
	uint32_t Status;
	
	FileInstance.Load ( true, & Status );
	
	std :: cout << "B" << std :: endl;
	
	if ( Status != RAUX::JSONFile :: kStatus_Success )
		return false;
	
	std :: cout << "C" << std :: endl;
	
	Data::JSON :: IType * JSONRoot = FileInstance.Decode ( & Status );
	
	if ( Status != RAUX::JSONFile :: kStatus_Success )
		return false;
	
	std :: cout << "D" << std :: endl;
	
	RootLock.Lock ();
	
	if ( SaveRoot == NULL )
	{
		
		RootLock.Unlock ();
		
		return false;
		
	}
	
	std :: cout << "E" << std :: endl;
	
	SaveRoot -> NotifySaveAction ( ISavable :: kSaveAction_Restore_Prepare );
	
	ContainerSaveObject * RootSaveObject = SaveRoot -> GetRootSaveObject ();
	
	if ( RootSaveObject == NULL )
	{
		
		RootLock.Unlock ();
		
		return false;
		
	}
	
	std :: cout << "F" << std :: endl;
	
	ContainerSaveObject TempRootContainer ( "" );
	
	TempRootContainer.AddChild ( RootSaveObject );
	bool Success = RestoreFromJSON ( & TempRootContainer, JSONRoot, RootSaveObject -> GetName () ) != NULL;
	TempRootContainer.RemoveChild ( RootSaveObject );
	
	RootLock.Unlock ();
	
	std :: cout << "G" << std :: endl;
	
	if ( Success )
	{
		
		SaveRoot -> NotifySaveAction ( ISavable :: kSaveAction_Restore_Success );
		
		return true;
		
	}
	
	std :: cout << "H" << std :: endl;
	
	SaveRoot -> NotifySaveAction ( ISavable :: kSaveAction_Restore_Failure );
	
	return false;
	
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
			
			ObjName.assign ( std :: string ( "s_" ) + StrObj -> GetName () );
			
			StrObj -> LockStringAccess ();
			Data::JSON :: String * NewStr = new Data::JSON :: String ( StrObj -> GetStringRef () );
			StrObj -> UnlockStringAccess ();
			
			return NewStr;
			
		}
		break;
		
		case ISaveObject :: kSaveType_Binary:
		{
			
			BinarySaveObject * BinObj = dynamic_cast <BinarySaveObject *> ( Object );
			
			if ( BinObj == NULL )
				return NULL;
			
			ObjName.assign ( std :: string ( "b64_" ) + BinObj -> GetName () );
			
			BinObj -> LockData ();
			
			std :: string B64Out;
			
			Util :: RCMem * BinData = BinObj -> GetData ();
			uint64_t BinSize = BinObj -> GetDataSize ();
			
			if ( BinData != NULL )
				B64Encoder.Encode ( BinData -> GetData (), BinSize, B64Out );
			
			BinObj -> UnlockData ();
			
			Data::JSON :: String * NewStr = new Data::JSON :: String ( B64Out );
			
			return NewStr;
			
			return NULL;
			
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
		
		default:
			return NULL;
			break;
		
	}
	
}

Red::Save :: ISaveObject * Red::Save::JSONSaveFile :: RestoreFromJSON ( ContainerSaveObject * RootSaveObject, Data::JSON :: IType * RootObject, const std :: string & ObjName )
{
	
	if ( RootObject == NULL )
		return NULL;
	
	ContainerSaveObject * RootSaveContainer = ( RootSaveObject != NULL ) ? dynamic_cast <ContainerSaveObject *> ( RootSaveObject ) : NULL;
	
	switch ( RootObject -> GetType () )
	{
		
		case Data::JSON::IType :: kDataType_Boolean:
		{
			
			Data::JSON :: Boolean * BoolValue = dynamic_cast <Data::JSON :: Boolean *> ( RootObject );
			
			if ( BoolValue == NULL )
				return NULL;
			
			if ( RootSaveContainer != NULL )
				return RootSaveContainer -> SetOrCreateBooleanChild_AutoLock ( ObjName, BoolValue -> Get () );
			
			return new BooleanSaveObject ( ObjName, BoolValue -> Get () );
			
		}
		break;
		
		case Data::JSON::IType :: kDataType_Number:
		{
			
			Data::JSON :: Number * NumberValue = dynamic_cast <Data::JSON :: Number *> ( RootObject );
			
			if ( NumberValue == NULL )
				return NULL;
			
			if ( ObjName.size () < 2 )
			{
				
				if ( RootSaveContainer != NULL )
					return RootSaveContainer -> SetOrCreateDoubleChild_AutoLock ( ObjName, NumberValue -> Get () );
				
				return new DoubleSaveObject ( ObjName, NumberValue -> Get () );
				
			}
			
			if ( strncmp ( ObjName.c_str (), "f_", 2 ) == 0 )
			{
				
				if ( RootSaveContainer != NULL )
					return RootSaveContainer -> SetOrCreateFloatChild_AutoLock ( ObjName.substr ( 2 ), NumberValue -> Get () );
				
				return new FloatSaveObject ( ObjName.substr ( 2 ), NumberValue -> Get () );
				
			}
			
			if ( strncmp ( ObjName.c_str (), "d_", 2 ) == 0 )
			{
				
				if ( RootSaveContainer != NULL )
					return RootSaveContainer -> SetOrCreateDoubleChild_AutoLock ( ObjName.substr ( 2 ), NumberValue -> Get () );
				
				
				return new DoubleSaveObject ( ObjName.substr ( 2 ), NumberValue -> Get () );
				
			}
			
			if ( ObjName.size () < 4 )
			{
				
				if ( RootSaveContainer != NULL )
					return RootSaveContainer -> SetOrCreateDoubleChild_AutoLock ( ObjName, NumberValue -> Get () );
				
				new DoubleSaveObject ( ObjName, NumberValue -> Get () );
				
			}
			
			if ( strncmp ( ObjName.c_str (), "i32_", 4 ) == 0 )
			{
				
				if ( RootSaveContainer != NULL )
					return RootSaveContainer -> SetOrCreateInt32Child_AutoLock ( ObjName.substr ( 4 ), NumberValue -> Get () );
				
				return new Int32SaveObject ( ObjName.substr ( 4 ), NumberValue -> Get () );
				
			}
			
			if ( strncmp ( ObjName.c_str (), "u32_", 4 ) == 0 )
			{
				
				if ( RootSaveContainer != NULL )
					return RootSaveContainer -> SetOrCreateUInt32Child_AutoLock ( ObjName.substr ( 4 ), NumberValue -> Get () );
				
				return new UInt32SaveObject ( ObjName.substr ( 4 ), NumberValue -> Get () );
				
			}
			
			if ( strncmp ( ObjName.c_str (), "i64_", 4 ) == 0 )
			{
				
				if ( RootSaveContainer != NULL )
					return RootSaveContainer -> SetOrCreateInt64Child_AutoLock ( ObjName.substr ( 4 ), NumberValue -> Get () );
				
				return new Int64SaveObject ( ObjName.substr ( 4 ), NumberValue -> Get () );
				
			}
			
			if ( strncmp ( ObjName.c_str (), "u64_", 4 ) == 0 )
			{
				
				if ( RootSaveContainer != NULL )
					return RootSaveContainer -> SetOrCreateUInt64Child_AutoLock ( ObjName.substr ( 4 ), NumberValue -> Get () );
				
				return new UInt64SaveObject ( ObjName.substr ( 4 ), NumberValue -> Get () );
				
			}
			
			if ( RootSaveContainer != NULL )
				return RootSaveContainer -> SetOrCreateDoubleChild_AutoLock ( ObjName, NumberValue -> Get () );
			
			return new DoubleSaveObject ( ObjName, NumberValue -> Get () );
			
		}
		break;
		
		case Data::JSON::IType :: kDataType_String:
		{
			
			Data::JSON :: String * StringValue = dynamic_cast <Data::JSON :: String *> ( RootObject );
			
			if ( StringValue == NULL )
				return NULL;
			
			std :: string ValueData;
			StringValue -> Get ( ValueData );
			
			if ( ObjName.size () < 2 )
			{
				
				if ( RootSaveContainer != NULL )
					return RootSaveContainer -> SetOrCreateStringChild_AutoLock ( ObjName, ValueData );
				
				return new StringSaveObject ( ObjName, ValueData );
				
			}
			
			if ( strncmp ( ObjName.c_str (), "s_", 2 ) )
			{
				
				if ( RootSaveContainer != NULL )
					return RootSaveContainer -> SetOrCreateStringChild_AutoLock ( ObjName.substr ( 2 ), ValueData );
				
				return new StringSaveObject ( ObjName.substr ( 2 ), ValueData );
				
			}
			
			if ( ObjName.size () < 4 )
			{
				
				if ( RootSaveContainer != NULL )
					return RootSaveContainer -> SetOrCreateStringChild_AutoLock ( ObjName, ValueData );
				
				return new StringSaveObject ( ObjName, ValueData );
				
			}
			
			if ( strncmp ( ObjName.c_str (), "b64_", 4 ) )
			{
				
				void * DataPTR = NULL;
				uint64_t MemSize = 0;
				
				if ( B64Decoder.Decode ( ValueData, & DataPTR, & MemSize ) )
				{
					
					if ( RootSaveContainer != NULL )
						return RootSaveContainer -> SetOrCreateBinaryChild_AutoLock ( ObjName, new Util :: RCMem ( DataPTR, & free ), MemSize );
					
					return new BinarySaveObject ( ObjName, new Util :: RCMem ( DataPTR, & free ), MemSize );
					
				}
				else
					return NULL;
				
			}
			
			if ( RootSaveContainer != NULL )
				return RootSaveContainer -> SetOrCreateStringChild_AutoLock ( ObjName, ValueData );
			
			return new StringSaveObject ( ObjName, ValueData );
			
		}
		break;
		
		case Data::JSON::IType :: kDataType_Object:
		{
			
			Data::JSON :: Object * ObjectValue = dynamic_cast <Data::JSON :: Object *> ( RootObject );
			
			if ( ObjectValue == NULL )
				return NULL;
			
			RootSaveContainer -> LockChildren ();
			
			ContainerSaveObject * Container = RootSaveContainer -> FindOrCreateContainerChild ( ObjName );
			
			RootSaveContainer -> UnlockChildren ();
			
			for ( uint32_t I = 0; I < ObjectValue -> GetKeyCount (); I ++ )
			{
				
				std :: string ChildName;
				
				ObjectValue -> GetKeyByIndex ( I, ChildName );
				Data::JSON :: IType * Child = ObjectValue -> GetItemByIndex ( I );
				
				RestoreFromJSON ( Container, Child, ChildName );
				
			}
			
			return Container;
			
		}
		break;
		
		case Data::JSON::IType :: kDataType_Array:
		{
			
			return NULL;
			
		}
		break;
		
		default:
			return NULL;
		
	}
	
}
