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
			
			virtual void SetSaveObject ( ISavable * SaveRoot ) = 0;
			
			virtual bool RunSave () = 0;
			
		};
		
	}
	
}

#endif
