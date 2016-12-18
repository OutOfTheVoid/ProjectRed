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
			
			BinarySaveObject ( const std :: string & Name, Util :: RCMem * Data = NULL, uint64_t Size = 0, uint32_t Alignment = 4 );
			~BinarySaveObject ();
			
			void LockData ();
			bool TryLockData ();
			void UnlockData ();
			
			void SetData ( Util :: RCMem * Data, uint32_t DataSize, uint32_t Alignment = 8 );
			
			void SetData_AutoLock ( Util :: RCMem * Data, uint32_t DataSize, uint32_t Alignment = 8 );
			bool SetData_AutoLock_Try ( Util :: RCMem * Data, uint32_t DataSize, uint32_t Alignment = 8 );
			
			Red::Util :: RCMem * GetData ();
			uint32_t GetDataSize ();
			uint32_t GetDataAlign ();
			
			SaveType GetType () const;
			
			const std :: string & GetName () const;
			
		private:
			
			const std :: string Name;
			
			Util :: RCMem * Data;
			
			uint64_t Size;
			uint32_t Alignment;
			
			Threading :: Mutex DataLock;
			
		};
		
	}
	
}

#endif
