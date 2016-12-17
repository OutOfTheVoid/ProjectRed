#ifndef RED_SAVE_STRINGSAVEOBJECT_H
#define RED_SAVE_STRINGSAVEOBJECT_H

#include <Red/Save/Save.h>
#include <Red/Save/ISaveObject.h>

#include <Red/Util/RefCounted.h>

#include <Red/Threading/Mutex.h>

#include <string>

namespace Red
{
	
	namespace Save
	{
		
		class StringSaveObject : public virtual ISaveObject, public Util :: RefCounted
		{
		public:
			
			StringSaveObject ( const std :: string & Name, const std :: string & DefaultValue );
			~StringSaveObject ();
			
			void LockStringAccess ();
			bool TryLockStringAccess ();
			void UnlockStringAccess ();
			
			std :: string & GetStringRef ();
			
			void SetString_AutoLock ( const std :: string & Value );
			bool SetString_AutoLock_Try ( const std :: string & Value );
			void GetString_AutoLock ( std :: string & ValueOut );
			bool SetString_AutoLock_Try ( std :: string & ValueOut );
			
			SaveType GetType () const;
			
			const std :: string & GetName () const;
			
		private:
			
			const std :: string Name;
			
			Threading :: Mutex AccessLock;
			
			std :: string Value;
			
		};
		
	}
	
}

#endif
