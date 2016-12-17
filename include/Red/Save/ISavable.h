#ifndef RED_SAVE_ISAVABLE_H
#define RED_SAVE_ISAVABLE_H

#include <Red/Save/Save.h>

#include <Red/Save/ISaveObject.h>

#include <Red/Util/IRefCounted.h>

namespace Red
{
	
	namespace Save
	{
		
		class ISavable : public virtual Util :: IRefCounted
		{
		public:
			
			typedef enum
			{
				
				kSaveAction_Restore_Prepare,
				kSaveAction_Restore_Failure,
				kSaveAction_Restore_Success,
				kSaveAction_Save_Prepare,
				kSaveAction_Save_Success,
				kSaveAction_Save_Failure
				
			} SaveAction;
			
			virtual inline ~ISavable () {};
			
			virtual ISaveObject * GetRootSaveObject () = 0;
			
			virtual void NotifySaveAction ( SaveAction Action ) = 0;
			
		};
		
	}
	
}

#endif
