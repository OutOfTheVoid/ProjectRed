#ifndef RED_SAVE_JSONSAVEFILE_H
#define RED_SAVE_JSONSAVEFILE_H

#include <Red/Save/Save.h>

#include <Red/Data/JSON/IType.h>
// #include <Red/Data/JSON/Array.h>
// #include <Red/Data/JSON/Object.h>
// #include <Red/Data/JSON/Number.h>
// #include <Red/Data/JSON/Boolean.h>
// #include <Red/Data/JSON/String.h>

#include <Red/Save/ISaveObject.h>
#include <Red/Save/ISavable.h>
#include <Red/Save/ISaveReader.h>
#include <Red/Save/ISaveWriter.h>

#include <RAUX/JSONFile.h>

#include <string>

namespace Red
{
	
	namespace Save
	{
		
		class JSONSaveFile : public virtual ISaveReader, public virtual ISaveWriter
		{
		public:
			
			JSONSaveFile ( const std :: string & Name );
			~JSONSaveFile ();
			
			bool Open ( bool ForInitialReadback );
			void Close ();
			
			void SetSaveObject ( ISavable * SaveRoot );
			
			bool RunSave ();
			bool RunRead ();
			
		private:
			
			RAUX :: JSONFile FileInstance;
			
			ISavable * SaveRoot;
			
		}
		
	}
	
}

#endif
