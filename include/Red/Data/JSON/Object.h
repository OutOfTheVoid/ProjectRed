#ifndef RED_DATA_JSON_OBJECT_H
#define RED_DATA_JSON_OBJECT_H

#include <Red/Data/JSON/JSON.h>
#include <Red/Data/JSON/IType.h>

#include <Red/Util/RefCounted.h>

#include <string>
#include <map>

namespace Red
{
	
	namespace Data
	{
		
		namespace JSON
		{
			
			class Object : public virtual IType, public Util :: RefCounted
			{
			public:
				
				Object ();
				~Object ();
				
				DataType GetType () const;
				
				void Set ( const std :: string & ValueName, IType * Value );
				IType * Get ( const std :: string & ValueName );
				void Clear ( const std :: string & ValueName );
				bool Exists ( const std :: string & ValueName );
				
			private:
				
				std :: map <std :: string, IType *> ValueMap;
				
			};
			
		}
		
	}
	
}

#endif
