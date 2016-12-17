#ifndef RED_SAVE_UINT32SAVEOBJECT_H
#define RED_SAVE_UINT32SAVEOBJECT_H

#include <Red/Save/Save.h>
#include <Red/Save/ISaveObject.h>

#include <Red/Util/RefCounted.h>

#include <stdint.h>

#include <string>

namespace Red
{
	
	namespace Save
	{
		
		class UInt32SaveObject : public virtual ISaveObject, public Util :: RefCounted
		{
		public:
			
			UInt32SaveObject ( const std :: string & Name, uint32_t DefaultState );
			~UInt32SaveObject ();
			
			void SetState ( uint32_t State );
			uint32_t GetState ();
			
			SaveType GetType ();
			
			const std :: string & GetName ();
			
		private:
			
			const std :: string Name;
			
			std :: atomic <uint32_t> State;
			
		};
		
	}
	
}

#endif
