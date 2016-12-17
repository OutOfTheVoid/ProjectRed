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
		
		class Int64SaveObject : public virtual ISaveObject, public Util :: RefCounted
		{
		public:
			
			Int64SaveObject ( const std :: string & Name, int64_t DefaultState );
			~Int64SaveObject ();
			
			void SetState ( int64_t State );
			int64_t GetState ();
			
			SaveType GetType ();
			
			const std :: string & GetName ();
			
		private:
			
			const std :: string Name;
			
			std :: atomic <int64_t> State;
			
		};
		
	}
	
}

#endif
