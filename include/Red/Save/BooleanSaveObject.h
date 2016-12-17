#ifndef RED_SAVE_BOOLEANSAVEOBJECT_H
#define RED_SAVE_BOOLEANSAVEOBJECT_H

#include <Red/Save/Save.h>
#include <Red/Save/ISaveObject.h>

#include <Red/Util/RefCounted.h>

#include <string>

namespace Red
{
	
	namespace Save
	{
		
		class BooleanSaveObject : public virtual ISaveObject, public Util :: RefCounted
		{
		public:
			
			BooleanSaveObject ( const std :: string & Name, bool DefaultState = false );
			~BooleanSaveObject ();
			
			void SetState ( bool State );
			bool GetState ();
			
			SaveType GetType () const;
			
			const std :: string & GetName () const;
			
		private:
			
			const std :: string Name;
			
			std :: atomic <bool> State;
			
		};
		
	}
	
}

#endif
