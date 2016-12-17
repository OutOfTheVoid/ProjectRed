#ifndef RED_SAVE_FLOATSAVEOBJECT_H
#define RED_SAVE_FLOATSAVEOBJECT_H

#include <Red/Save/Save.h>
#include <Red/Save/ISaveObject.h>

#include <Red/Util/RefCounted.h>

#include <stdint.h>

#include <string>

namespace Red
{
	
	namespace Save
	{
		
		class FloatSaveObject : public virtual ISaveObject, public Util :: RefCounted
		{
		public:
			
			FloatSaveObject ( const std :: string & Name, float DefaultState );
			~FloatSaveObject ();
			
			void SetState ( float State );
			float GetState ();
			
			SaveType GetType ();
			
			const std :: string & GetName ();
			
		private:
			
			const std :: string Name;
			
			std :: atomic <float> State;
			
		};
		
	}
	
}

#endif
