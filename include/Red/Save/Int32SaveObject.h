#ifndef RED_SAVE_INT32SAVEOBJECT_H
#define RED_SAVE_INT32SAVEOBJECT_H

#include <Red/Save/Save.h>
#include <Red/Save/ISaveObject.h>

#include <Red/Util/RefCounted.h>

#include <stdint.h>

#include <string>

namespace Red
{
	
	namespace Save
	{
		
		class Int32SaveObject : public virtual ISaveObject, public Util :: RefCounted
		{
		public:
			
			Int32SaveObject ( const std :: string & Name, int32_t DefaultState = 0 );
			~Int32SaveObject ();
			
			void SetState ( int32_t State );
			int32_t GetState ();
			
			SaveType GetType () const;
			
			const std :: string & GetName () const;
			
		private:
			
			const std :: string Name;
			
			std :: atomic <int32_t> State;
			
		};
		
	}
	
}

#endif
