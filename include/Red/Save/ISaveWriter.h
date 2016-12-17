#ifndef RED_SAVE_ISAVEWRITER_H
#define RED_SAVE_ISAVEWRITER_H

#include <Red/Save/Save.h>
#include <Red/Save/ISavable.h>

namespace Red
{
	
	namespace Save
	{
		
		class ISaveWriter
		{
		public:
			
			virtual inline ~ISaveWriter () {};
			
			virtual void SetSaveObject ( ISavable * SetSaveRoot ) = 0;
			
			virtual void RunSave () = 0;
			
		}
		
	}
	
}

#endif
