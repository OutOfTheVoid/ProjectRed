#ifndef RED_DATA_JSON_ITYPE_H
#define RED_DATA_JSON_ITYPE_H

#include <Red/Data/JSON/JSON.h>

#include <Red/Util/IRefCounted.h>

namespace Red
{
	
	namespace Data
	{
		
		namespace JSON
		{
			
			class IType : public virtual Util :: IRefCounted
			{
			public:
				
				typedef enum
				{
					
					kDataType_Boolean,
					kDataType_Number,
					kDataType_String,
					kDataType_Object,
					kDataType_Array
					
				} DataType;
				
				virtual inline ~IType () {};
				
				virtual DataType GetType () const = 0;
				
			};
			
		}
		
	}
	
}

#endif
