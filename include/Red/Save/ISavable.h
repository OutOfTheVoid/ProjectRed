#ifndef RED_SAVE_ISAVABLE_H
#define RED_SAVE_ISAVABLE_H

#include <Red/Save/Save.h>

#include <Red/Save/ISaveObject.h>

namespace Red
{
	
	namespace Save
	{
		
		class ISavable
		{
		public:
			
			typedef enum
			{
				
				kSaveAction_Restore,
				kSaveAction_Save
				
			} SaveAction;
			
			virtual inline ~ISavable () {};
			
			virtual ISaveObject * GetRootSaveObject () = 0;
			
			virtual void NotifySaveAction ( SaveAction Action ) = 0;
			
		}
		
	}
	
}

#endif
