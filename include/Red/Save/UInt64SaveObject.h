#ifndef RED_SAVE_UINT64SAVEOBJECT_H
#define RED_SAVE_UINT64SAVEOBJECT_H

#include <Red/Save/Save.h>
#include <Red/Save/ISaveObject.h>

#include <Red/Util/RefCounted.h>

#include <stdint.h>

#include <string>

namespace Red
{
	
	namespace Save
	{
		
		class UInt64SaveObject : public virtual ISaveObject, public Util :: RefCounted
		{
		public:
			
			UInt64SaveObject ( const std :: string & Name, uint64_t DefaultState );
			~UInt64SaveObject ();
			
			void SetState ( uint64_t State );
			uint64_t GetState ();
			
			SaveType GetType ();
			
			const std :: string & GetName ();
			
		private:
			
			const std :: string Name;
			
			std :: atomic <uint64_t> State;
			
		};
		
	}
	
}

#endif
