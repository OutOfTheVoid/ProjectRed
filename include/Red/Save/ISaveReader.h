#ifndef RED_SAVE_ISAVEREADER_H
#define RED_SAVE_ISAVEREADER_H

#include <Red/Save/Save.h>
#include <Red/Save/ISavable.h>

namespace Red
{
	
	namespace Save
	{
		
		class ISaveReader
		{
		public:
			
			virtual inline ~ISaveWriter () {};
			
			virtual void SetSaveObject ( ISavable * SetSaveRoot ) = 0;
			
			virtual void RunRead () = 0;
			
		}
		
	}
	
}

#endif
