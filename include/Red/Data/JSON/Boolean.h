#ifndef RED_DATA_JSON_BOOLEAN_H
#define RED_DATA_JSON_BOOLEAN_H

#include <Red/Data/JSON/JSON.h>
#include <Red/Data/JSON/IType.h>

#include <Red/Util/RefCounted.h>

namespace Red
{
	
	namespace Data
	{
		
		namespace JSON
		{
			
			class Boolean : public virtual IType, public Util :: RefCounted
			{
			public:
				
				Boolean ( bool Value );
				~Boolean ();
				
				DataType GetType () const;
				
				bool Get ();
				void Set ( bool Value );
				
			private:
				
				bool Value;
				
			};
			
		}
		
	}
	
}

#endif
