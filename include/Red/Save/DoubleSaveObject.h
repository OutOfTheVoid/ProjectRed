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
		
		class DoubleSaveObject : public virtual ISaveObject, public Util :: RefCounted
		{
		public:
			
			DoubleSaveObject ( const std :: string & Name, double DefaultState );
			~DoubleSaveObject ();
			
			void SetState ( double State );
			double GetState ();
			
			SaveType GetType ();
			
			const std :: string & GetName ();
			
		private:
			
			const std :: string Name;
			
			std :: atomic <double> State;
			
		};
		
	}
	
}

#endif
