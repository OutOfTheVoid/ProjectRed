#ifndef RED_DATA_JSON_STRING_H
#define RED_DATA_JSON_STRING_H

#include <Red/Data/JSON/JSON.h>
#include <Red/Data/JSON/IType.h>

#include <Red/Util/RefCounted.h>

#include <string>

namespace Red
{
	
	namespace Data
	{
		
		namespace JSON
		{
			
			class String : public virtual IType, public Util :: RefCounted
			{
			public:
				
				String ( const std :: string & Value );
				~String ();
				
				DataType GetType () const;
				
				void Get ( std :: string & OutValue );
				void Set ( const std :: string & Value );
				
			private:
				
				std :: string Value;
				
			};
			
		}
		
	}
	
}

#endif
