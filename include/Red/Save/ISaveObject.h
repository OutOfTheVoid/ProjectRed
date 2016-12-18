#ifndef RED_SAVE_ISAVEOBJECT_H
#define RED_SAVE_ISAVEOBJECT_H

#include <Red/Save/Save.h>

#include <Red/Util/IRefCounted.h>

#include <string>

namespace Red
{
	
	namespace Save
	{
		
		class ISaveObject : public virtual Util :: IRefCounted
		{
		public:
			
			typedef enum
			{
				
				kSaveType_Boolean,
				
				kSaveType_Int32,
				kSaveType_UInt32,
				
				kSaveType_Int64,
				kSaveType_UInt64,
				
				kSaveType_Float,
				kSaveType_Double,
				
				kSaveType_String,
				
				kSaveType_Container,
				
				kSaveType_Binary
				
			} SaveType;
			
			virtual inline ~ISaveObject () {};
			
			virtual SaveType GetType () const = 0;
			
			virtual const std :: string & GetName () const = 0;
			
		};
		
	}
	
}

#endif
