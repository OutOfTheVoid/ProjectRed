#ifndef RED_TEXT_RENDERING_IFONTREFERENCE_H
#define RED_TEXT_RENDERING_IFONTREFERENCE_H

#include <Red/Text/Rendering/Rendering.h>

#include <Red/Util/IRefCounted.h>

#include <string>

namespace Red
{
	
	namespace Text
	{
		
		namespace Rendering
		{
			
			class IFontReference : public virtual Util :: IRefCounted
			{
			public:
				
				virtual inline ~IFontReference ()
				{
				};
				
				const std :: string & GetName () const;
				
			};
			
		}
		
	}
	
}

#endif
