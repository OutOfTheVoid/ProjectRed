#ifndef RED_SAVE_CONTAINTERSAVEOBJECT_H
#define RED_SAVE_CONTAINTERSAVEOBJECT_H

#include <Red/Save/Save.h>
#include <Red/Save/ISaveObject.h>

#include <Red/Util/RefCounted.h>

#include <Red/Threading/Mutex.h>

#include <Red/Util/RCMem.h>

#include <string>
#include <vector>

namespace Red
{
	
	namespace Save
	{
		
		class BooleanSaveObject;
		class BinarySaveObject;
		class ContainerSaveObject;
		class DoubleSaveObject;
		class FloatSaveObject;
		class Int32SaveObject;
		class Int64SaveObject;
		class UInt32SaveObject;
		class UInt64SaveObject;
		class StringSaveObject;
		
		class ContainerSaveObject : public virtual ISaveObject, public Util :: RefCounted
		{
		public:
			
			ContainerSaveObject ( const std :: string & Name );
			~ContainerSaveObject ();
			
			SaveType GetType () const;
			
			const std :: string & GetName () const;
			
			void LockChildren ();
			bool TryLockChildren ();
			void UnlockChildren ();
			
			void AddChild ( ISaveObject * Object );
			void RemoveChild ( ISaveObject * Object );
			
			void AddChild_AutoLock ( ISaveObject * Object );
			bool AddChild_AutoLock_Try ( ISaveObject * Object );
			
			void RemoveChild_AutoLock ( ISaveObject * Object );
			
			uint32_t GetChildCount ();
			ISaveObject * GetChild ( uint32_t Index );
			
			ISaveObject * FindChildWithName ( const std :: string & ChildName );
			
			ContainerSaveObject * FindOrCreateContainerChild ( const std :: string & ChildName );
			
			BooleanSaveObject * FindOrCreateBooleanChild ( const std :: string & ChildName, bool DefaultValue );
			BinarySaveObject * FindOrCreateBinaryChild ( const std :: string & ChildName, Util :: RCMem * DefaultData, uint32_t DefaultDataSize );
			DoubleSaveObject * FindOrCreateDoubleChild ( const std :: string & ChildName, double DefaultValue );
			FloatSaveObject * FindOrCreateFloatChild ( const std :: string & ChildName, float DefaultValue );
			Int32SaveObject * FindOrCreateInt32Child ( const std :: string & ChildName, int32_t DefaultValue );
			Int64SaveObject * FindOrCreateInt64Child ( const std :: string & ChildName, int64_t DefaultValue );
			UInt32SaveObject * FindOrCreateUInt32Child ( const std :: string & ChildName, uint32_t DefaultValue );
			UInt64SaveObject * FindOrCreateUInt64Child ( const std :: string & ChildName, uint64_t DefaultValue );
			StringSaveObject * FindOrCreateStringChild ( const std :: string & ChildName, const std :: string & DefaultValue );
			
			BooleanSaveObject * SetOrCreateBooleanChild_AutoLock ( const std :: string & ChildName, bool Value );
			BinarySaveObject * SetOrCreateBinaryChild_AutoLock ( const std :: string & ChildName, Util :: RCMem * Data, uint32_t DataSize );
			DoubleSaveObject * SetOrCreateDoubleChild_AutoLock ( const std :: string & ChildName, double Value );
			FloatSaveObject * SetOrCreateFloatChild_AutoLock ( const std :: string & ChildName, float Value );
			Int32SaveObject * SetOrCreateInt32Child_AutoLock ( const std :: string & ChildName, int32_t Value );
			Int64SaveObject * SetOrCreateInt64Child_AutoLock ( const std :: string & ChildName, int64_t Value );
			UInt32SaveObject * SetOrCreateUInt32Child_AutoLock ( const std :: string & ChildName, uint32_t Value );
			UInt64SaveObject * SetOrCreateUInt64Child_AutoLock ( const std :: string & ChildName, uint64_t Value );
			StringSaveObject * SetOrCreateStringChild_AutoLock ( const std :: string & ChildName, const std :: string & Value );
			
		private:
			
			const std :: string Name;
			
			Threading :: Mutex ChildLock;
			std :: vector <ISaveObject *> Children;
			
		};
		
	}
	
}

#endif
