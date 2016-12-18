#ifndef RED_SAVE_BINARYSAVEOBJECT_H
#define RED_SAVE_BINARYSAVEOBJECT_H

#include <Red/Save/Save.h>
#include <Red/Save/ISaveObject.h>

#include <Red/Util/RCMem.h>
#include <Red/Util/RefCounted.h>

#include <stdint.h>

#include <string>

namespace Red
{
	
	namespace Save
	{
		
		class BinarySaveObject : public virtual ISaveObject, public Util :: RefCounted
		{
		public:
			
			BinarySaveObject ( const std :: string & Name, void * InitialData = NULL, uint32_t DataSize = 0, uint32_t Alignment = 8 );
			~BinarySaveObject ();
			
			void LockData ();
			bool TryLockData ();
			void UnlockData ();
			
			void SetData ( void * Data, uint32_t DataSize, uint32_t Alignment = 8 );
			
			void * GetDataPTR ();
			uint32_t GetDataSize ();
			uint32_t GetDataAlign ();
			
			SaveType GetType () const;
			
			const std :: string & GetName () const;
			
		private:
			
			const std :: string Name;
			
		};
		
	}
	
}

#endif
