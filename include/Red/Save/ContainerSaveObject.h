#ifndef RED_SAVE_CONTAINTERSAVEOBJECT_H
#define RED_SAVE_CONTAINTERSAVEOBJECT_H

#include <Red/Save/Save.h>
#include <Red/Save/ISaveObject.h>

#include <Red/Util/RefCounted.h>

#include <Red/Threading/Mutex.h>

#include <string>
#include <vector>

namespace Red
{
	
	namespace Save
	{
		
		class ContainerSaveObject : public virtual ISaveObject, public Util :: RefCounted
		{
		public:
			
			ContainerSaveObject ( const std :: string & Name );
			~ContainerSaveObject ();
			
			SaveType GetType ();
			
			const std :: string & GetName ();
			
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
			
		private:
			
			const std :: string & Name;
			
			Threading :: Mutex ChildLock;
			std :: vector <ISaveObject *> Children;
			
		};
		
	}
	
}

#endif
