#ifndef RED_SAVE_BINARYSAVEOBJECT_H
#define RED_SAVE_BINARYSAVEOBJECT_H

#include <Red/Save/Save.h>
#include <Red/Save/ISaveObject.h>

#include <Red/Util/RCMem.h>
#include <Red/Util/RefCounted.h>

#include <Red/Threading/Mutex.h>

#include <stdint.h>

#include <string>

namespace Red
{
	
	namespace Save
	{
		
		class BinarySaveObject : public virtual ISaveObject, public Util :: RefCounted
		{
		public:
			
			BinarySaveObject ( const std :: string & Name, Util :: RCMem * Data = NULL, uint64_t Size = 0 );
			~BinarySaveObject ();
			
			void LockData ();
			bool TryLockData ();
			void UnlockData ();
			
			void SetData ( Util :: RCMem * Data, uint32_t DataSize );
			
			void SetData_AutoLock ( Util :: RCMem * Data, uint32_t DataSize );
			bool SetData_AutoLock_Try ( Util :: RCMem * Data, uint32_t DataSize );
			
			Red::Util :: RCMem * GetData ();
			uint32_t GetDataSize ();
			
			SaveType GetType () const;
			
			const std :: string & GetName () const;
			
		private:
			
			const std :: string Name;
			
			Util :: RCMem * Data;
			
			uint64_t Size;
			
			Threading :: Mutex DataLock;
			
		};
		
	}
	
}

#endif
