#ifndef RED_DATA_JSON_ARRAY_H
#define RED_DATA_JSON_ARRAY_H

#include <Red/Data/JSON/JSON.h>
#include <Red/Data/JSON/IType.h>

#include <Red/Util/RefCounted.h>

#include <vector>

namespace Red
{
	
	namespace Data
	{
		
		namespace JSON
		{
			
			class Array : public virtual IType, public Util :: RefCounted
			{
			public:
				
				Array ();
				~Array ();
				
				DataType GetType () const;
				
				uint32_t GetItemCount ();
				
				IType * GetItem ( uint32_t I );
				
				void AddItem ( IType * Item );
				void RemoveItem ( uint32_t I );
				
			private:
				
				std :: vector <IType *> Items;
				
			};
			
		}
		
	}
	
}

#endif
