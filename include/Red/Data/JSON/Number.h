#ifndef RED_DATA_JSON_NUMBER_H
#define RED_DATA_JSON_NUMBER_H

#include <Red/Data/JSON/JSON.h>
#include <Red/Data/JSON/IType.h>

#include <Red/Util/RefCounted.h>

namespace Red
{
	
	namespace Data
	{
		
		namespace JSON
		{
			
			class Number : public virtual IType, public Util :: RefCounted
			{
			public:
				
				Number ( double Value );
				~Number ();
				
				DataType GetType () const;
				
				double Get ();
				void Set ( double Value );
				
			private:
				
				double Value;
				
			};
			
		}
		
	}
	
}

#endif
